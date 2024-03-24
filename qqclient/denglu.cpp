#include "denglu.h"
#include "ui_denglu.h"
#include <QIcon>
#include<QWidget>
#include<QList>
#include"mainwindow.h"
#include<QToolButton>
#include<QMessageBox>
#include <QPixmap>
denglu::denglu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::denglu)
{
    ui->setupUi(this);
    this->setWindowTitle("QQ 2024");
    this->setWindowIcon(QIcon(":/images/qq.jpg"));
    QList<QString> nameList;
    nameList<<"蔡徐坤"<<"华晨宇"<<"隔壁老樊"<<"丢火车"<<"南征北战"<<"陈奕迅"<<"周杰伦"<<"尚世达"<<"林俊杰";
    QStringList iconNameList;
    iconNameList<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9";
    QVector<QToolButton*> vect;
    for(int i=0;i<9;i++)
    {
        //设置头像
        QToolButton *btn = new QToolButton(this);
        QString str = QString(":/images/%1.png").arg(iconNameList.at(i));
        //加载图标
        btn->setIcon(QPixmap(str));
        //设置图标大小
        btn->setIconSize(QSize(150,100));
        btn->setText(nameList[i]);
        //设置透明
        btn->setAutoRaise(true);
        //设置文字图片一块显示
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->vlayout_2->addWidget(btn);
        vect.push_back(btn);
        Isshow.push_back(false);
    }
    for(int i=0;i<9;i++)
    {
        connect(vect[i],&QToolButton::clicked,[=](){
            if(Isshow[i])
            {
                QMessageBox::warning(this,"警告","该聊天框已被打开");
                return;
            }
            Isshow[i] = true;
            MainWindow *widget = new MainWindow(nullptr,vect[i]->text(),Isshow,nameList);
            widget->setWindowIcon(vect[i]->icon());
            widget->setWindowTitle(vect[i]->text());
            widget->show();
            //关闭时将对于的IsShow设为false
            connect(widget,&MainWindow::closeWidget,this,[=]()
            {
                Isshow[i] = false;
            });
        });
    }
}

denglu::~denglu()
{
    delete ui;
}
