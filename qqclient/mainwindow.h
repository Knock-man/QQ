#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include"windows.h"
#include <QHostAddress>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum MsgType{
        msg = 1,
        enter,
        left,
        file
    };
    MainWindow(QWidget *parent,QString name_,QVector<bool> vct_,QStringList iconNameList_);
    //重写关闭事件
    void closeEvent(QCloseEvent *);
    ~MainWindow();
    void sendMsg();
    void getMsg();
    void entryMsg();
    void initNet();
    //void inituser();
    void sendfile();
signals:
    //关闭窗口信号
    void closeWidget();

private:
    Ui::MainWindow *ui;
    QString name;
    QString ipAddress = "127.0.0.1";
    int port = 8765;
    QTcpSocket *socket;
    QVector<bool> vct;//在线用户
     QStringList iconNameList;
    int cnt;
};
#endif // MAINWINDOW_H
