#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTcpSocket>
#include<QTime>
#include<QColor>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
MainWindow::MainWindow(QWidget *parent,QString name_,QVector<bool> vct_,QStringList iconNameList_)
    : QMainWindow(parent)
    ,name{name_}
    ,vct{vct_}
    ,iconNameList{iconNameList_}
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化在线用户
    inituser();

    //初始化网络连接
    initNet();

    //用户加入
    entryMsg();

    //发送消息
    connect(ui->sendbutton,&QPushButton::clicked,this,[=](){
        sendMsg();

    });

    //用户退出
    connect(ui->quitbutton,&QPushButton::clicked,this,[=](){
        this->close();
    });

    //接受消息
    connect(socket, &QTcpSocket::readyRead,this, [=](){
        getMsg();
    });
}

//关闭连接
void MainWindow::closeEvent(QCloseEvent *)
{
    emit this->closeWidget();
    // 关闭网络连接
    //json序列化
    QJsonObject obj;
    obj["name"] = name;
    obj["msg"] = ui->textEdit->toPlainText();
    obj["type"] = 3;
    QJsonDocument doc(obj);
    QByteArray jsonData = doc.toJson();
    //发送消息
    socket->write(jsonData);
    socket->close();

}
MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::sendMsg()
{
    //json序列化
    QJsonObject obj;
    obj["name"] = name;
    obj["msg"] = ui->textEdit->toPlainText();
    obj["type"] = 1;
    QJsonDocument doc(obj);
    QByteArray jsonData = doc.toJson();
    //发送消息
    socket->write(jsonData);
    ui->textEdit->clear();
    //socket->close();
}

void MainWindow::getMsg()
{

    QByteArray receivedData = socket->readAll();
    //反序列化
    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(receivedData, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "Error parsing JSON data:" << jsonError.errorString();
        return;
    }
    if (doc.isObject()) {
        QJsonObject obj = doc.object();

        // 提取数据
        QString _name = obj["name"].toString();
        QString msg = obj["msg"].toString();
        int type = obj["type"].toInt();
        if(type == 1)//聊天消息
        {
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser->setTextColor(Qt::blue);
            ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
            ui->textBrowser->append("["+_name+"]"+time);
            ui->textBrowser->append(msg);
        }else if(type == 2)
        {
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser->setTextColor(Qt::gray);
            ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
            ui->textBrowser->append("["+_name+"]"+time+" 上线");
        }else if(type == 3)
        {
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser->setTextColor(Qt::gray);
            ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
            ui->textBrowser->append("["+_name+"]"+time+" 下线");
        }

    }

}

void MainWindow::entryMsg()
{
    //json序列化
    QJsonObject obj;
    obj["name"] = name;
    obj["type"] = 2;
    QJsonDocument doc(obj);
    QByteArray jsonData = doc.toJson();
    //发送消息
    socket->write(jsonData);
}

void MainWindow::initNet()
{
    socket = new QTcpSocket(this);
    //连接网络
    socket->connectToHost("127.0.0.1", 8765);
    if (socket->waitForConnected()) {
        qDebug() << "Connected to the server";

        // 在这里可以进行数据的发送和接收
    } else {
        qDebug() << "Failed to connect to the server: " << socket->errorString();
    }
}

void MainWindow::inituser()
{
    for(int i=0;i<vct.size();i++)
    {
        if(vct[i])
        {
            cnt++;
            //加入用户表格中
            int rowCount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowCount);
            ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(iconNameList[i]));
        }
    }

}

