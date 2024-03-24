#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTcpSocket>
#include<QTime>
#include<QColor>
#include <QJsonDocument>
#include <QTemporaryFile>
#include <QFile>
#include <QJsonObject>
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>
#include <QFileDialog>
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
    //inituser();

    //初始化网络连接
    initNet();

    //用户加入
    entryMsg();

    //发送文件
    connect(ui->toolButton_5,&QPushButton::clicked,this,[=](){
        sendfile();
    });

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
        int type = obj["type"].toInt();
        if(type == 1)//聊天消息
        {
            QString _name = obj["name"].toString();
            QString msg = obj["msg"].toString();
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser->setTextColor(Qt::blue);
            ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
            ui->textBrowser->append("["+_name+"]"+time);
            ui->textBrowser->append(msg);
        }else if(type == 2)
        {
            QString _name = obj["name"].toString();
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser->setTextColor(Qt::gray);
            ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
            ui->textBrowser->append("["+_name+"]"+time+" 上线");
        }else if(type == 3)
        {
            QString _name = obj["name"].toString();
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser->setTextColor(Qt::gray);
            ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
            ui->textBrowser->append("["+_name+"]"+time+" 下线");
        }else if(type == 4)
        {
            QString time = QDateTime::currentDateTime().toString("hh:mm");
            qDebug()<<"接收到的是文件";
            // 提取文件名和文件数据
            QString fileName = obj["fileName"].toString();
            QString base64Data = obj["fileData"].toString();
            // 将 Base64 编码的文件数据转换为原始二进制数据
            QByteArray fileData = QByteArray::fromBase64(base64Data.toLatin1());

            //


            // 创建 QToolButton
            QToolButton *btn = new QToolButton(this);
            //加载图标
            btn->setIcon(QPixmap(":/images/file.png"));
            //设置图标大小
            btn->setIconSize(QPixmap(":/images/file.png").size());
            btn->setText("下载   "+time);
            // 设置图标和文本显示方式
            btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            btn->setAutoRaise(true);

            // 设置按钮样式
            btn->setStyleSheet("QToolButton {"
                                "background-color: #3498db;" // 背景颜色
                                "color: #ffffff;" // 文本颜色
                                "border: 1px solid #2980b9;" // 边框
                                "border-radius: 5px;" // 圆角
                                "padding: 5px 10px;" // 内边距
                                "height: 20px;" // 设定较小的高度，您可以根据实际需求调整高度
                                "}"
                                "QToolButton:hover {"
                                "background-color: #2980b9;" // 悬停时背景颜色
                                "}"
                                "QToolButton:pressed {"
                                "background-color: #1f618d;" // 按下时背景颜色
                                "}");

            // 创建阴影效果
            QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
            shadowEffect->setBlurRadius(8); // 阴影模糊半径
            shadowEffect->setOffset(2, 2); // 阴影偏移量
            shadowEffect->setColor(QColor(0, 0, 0, 150)); // 阴影颜色
            btn->setGraphicsEffect(shadowEffect);

            // 将按钮添加到布局中
            ui->filelayout->addWidget(btn);

            // 将按钮添加到布局中
            ui->filelayout->addWidget(btn);

            // 将按钮添加到布局中
            ui->filelayout->addWidget(btn);

            connect(btn,&QPushButton::clicked,[=](){
                qDebug()<<"接收到的是文件";
                // 创建临时文件
                QTemporaryFile tempFile;
                if (tempFile.open()) {
                    // 写入数据到临时文件
                    tempFile.write(fileData);
                    tempFile.close();
                    // 提示用户保存文件
                    QString filePath = QFileDialog::getSaveFileName(nullptr, "保存文件", "", "All Files (*)");
                    if (!filePath.isEmpty()) {
                        // 复制临时文件到用户指定的路径
                        if (!QFile::copy(tempFile.fileName(), filePath)) {
                            QMessageBox::warning(nullptr, "Error", "Failed to save file");
                        }
                    }
                } else {
                    QMessageBox::warning(nullptr, "Error", "Failed to create temporary file");
                }
            });


            //设置透明

            //设置文字图片一块显示



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
    socket->connectToHost(ipAddress, port);
    if (socket->waitForConnected()) {
        qDebug() << "Connected to the server";

        // 在这里可以进行数据的发送和接收
    } else {
        qDebug() << "Failed to connect to the server: " << socket->errorString();
    }
}

//void MainWindow::inituser()
//{
//    for(int i=0;i<vct.size();i++)
//    {
//        if(vct[i])
//        {
//            cnt++;
//            //加入用户表格中
//            int rowCount = ui->tableWidget->rowCount();
//            ui->tableWidget->insertRow(rowCount);
//            ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(iconNameList[i]));
//        }
//    }
//    ui->label->setText("在线人数"+QString::number(cnt)+"人");

//}

//发送文件
void MainWindow::sendfile()
{
    //打开文件
    QString filepath = QFileDialog::getOpenFileName(this,"发送文件",".");

    //用json发送文件
    QFile file(filepath);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray fileData = file.readAll();
        QString base64Data = fileData.toBase64();
        file.close();

        // 构建包含文件内容的 JSON 对象
        QJsonObject json;
        json["type"] = 4;
        json["fileName"] = filepath; // 文件名
        json["fileData"] = QString(base64Data); // Base64 编码的文件内容
        // 将 JSON 对象转换为 JSON 文档
        QJsonDocument doc(json);
        QByteArray jsonData = doc.toJson();
        socket->write(jsonData);
    }
    qDebug()<<filepath<<endl;
}
