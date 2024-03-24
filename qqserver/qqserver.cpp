#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <mutex>
#define EVENT_MAX 1024
#define EPOLL_MAX 50
#define ET // ET模式
#define PORT 8765

void *readMsg(void *arg);
void *sendMsg(char *msg, int sock);
void setnonblock(int fd);
void printSockAddr(struct sockaddr_in *addr);
int serv_sock, clnt_sock, efd_sock;
int usersock[EVENT_MAX], usercnt;
std::mutex mtx;
int main(int argc, char *argv[])
{

    int ret;
    pthread_t pthreadID;
    struct sockaddr_in serv_addr, clnt_addr;
    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    setnonblock(serv_sock);
    if (serv_sock == -1)
    {
        printf("socket error");
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ret = bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (ret == -1)
    {
        printf("bind error");
    }
    ret = listen(serv_sock, 10);

    if (ret == -1)
    {
        printf("bind error");
    }

    efd_sock = epoll_create(EPOLL_MAX);
    struct epoll_event event[EVENT_MAX], tep;
#ifdef ET
    tep.events = EPOLLIN | EPOLLET;
#else
    tep.events = EPOLLIN;
#endif
    tep.data.fd = serv_sock;
    epoll_ctl(efd_sock, EPOLL_CTL_ADD, serv_sock, &tep); // 连接套接字挂到树上

    while (1)
    {
        int event_cnt = epoll_wait(efd_sock, event, EVENT_MAX, -1);
        for (int i = 0; i < event_cnt; i++)
        {
            if (event[i].data.fd == serv_sock) // 连接事件发生
            {
                socklen_t clnt_sock_len = sizeof(clnt_addr);
                clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_sock_len);
                printSockAddr(&clnt_addr); // 打印连接信息
#ifdef ET

                setnonblock(clnt_sock);

#endif

                //  挂到树上
                tep.data.fd = clnt_sock;
#ifdef ET
                tep.events = EPOLLIN | EPOLLET;
#else
                tep.events = EPOLLIN;
#endif

                epoll_ctl(efd_sock, EPOLL_CTL_ADD, clnt_sock, &tep);
                mtx.lock();
                usersock[usercnt++] = clnt_sock;
                mtx.unlock();
            }
            else
            { // 通信事件发生
                int sock = event[i].data.fd;
                // 创建线程处理
                pthread_create(&pthreadID, NULL, readMsg, (void *)&sock);
                // pthread_create(&pthreadID[1], NULL, sendMsg, (void *)sock);
                pthread_detach(pthreadID);
                // pthread_detach(pthreadID[1]);
            }
        }
    }
    close(serv_sock);
    close(efd_sock);
    return 0;
}
// 打印套接字信息
void printSockAddr(struct sockaddr_in *addr)
{
    char ip[INET_ADDRSTRLEN];
    int port;

    inet_ntop(AF_INET, &(addr->sin_addr), ip, INET_ADDRSTRLEN);
    port = ntohs(addr->sin_port);

    printf("新连接建立：IP address: %s   Port: %d\n", ip, port);
}

void *readMsg(void *arg)
{
    int sock = *((int *)arg);
    char buf[1024];
    int str_len = 0;
    while (1)
    {
        str_len = read(sock, buf, sizeof(buf));
        if (str_len < 0)
        {
            if (errno == EAGAIN)
            {
                continue;
            }
            // printf("%dread error\n", sock);
        }
        else if (str_len > 0)
        {
            // std::cout << "接收数据" << buf << std::endl;
            sendMsg(buf, sock);
            memset(buf, 0, sizeof(buf));
        }
        else if (str_len == 0)
        {
            printf("%d客户端关闭\n", sock);
            break;
        }
    }
    epoll_ctl(efd_sock, EPOLL_CTL_DEL, sock, NULL);
    close(sock);
    mtx.lock();
    for (int i = 0; i < usercnt; i++)
    {
        if (usersock[i] == sock)
        {
            for (int j = i + 1; j <= usercnt; j++)
            {
                usersock[j - 1] = usersock[j];
            }
        }
        break;
    }
    usercnt--;
    mtx.unlock();
    return NULL;
}
void *sendMsg(char *buf, int sock)
{
    // std::cout << "准备发送数据" << buf << usercnt << std::endl;
    mtx.lock();
    for (int i = 0; i < usercnt; i++)
    {

        write(usersock[i], buf, strlen(buf));
        // std::cout << "发送数据" << buf << std::endl;
    }
    mtx.unlock();
    return NULL;
}

void setnonblock(int fd)
{
    int flag = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}