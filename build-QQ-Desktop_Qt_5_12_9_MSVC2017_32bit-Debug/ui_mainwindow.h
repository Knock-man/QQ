/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QTextEdit *textEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendbutton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quitbutton;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_2;
    QVBoxLayout *filelayout;
    QToolBox *filebox;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(664, 435);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(10, 0, 631, 384));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout = new QVBoxLayout(widget_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 0, 0);
        textBrowser = new QTextBrowser(widget_4);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        frame_2 = new QFrame(widget_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        fontComboBox = new QFontComboBox(frame_2);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout_2->addWidget(fontComboBox);

        comboBox = new QComboBox(frame_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        toolButton = new QToolButton(frame_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/B.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setCheckable(true);

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(frame_2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/I.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setCheckable(true);

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame_2);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/xiahuaxian.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setCheckable(true);

        horizontalLayout_2->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(frame_2);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);

        horizontalLayout_2->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(frame_2);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(frame_2);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);

        horizontalLayout_2->addWidget(toolButton_6);


        verticalLayout->addWidget(frame_2);

        textEdit = new QTextEdit(widget_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(textEdit);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        sendbutton = new QPushButton(widget_3);
        sendbutton->setObjectName(QString::fromUtf8("sendbutton"));

        horizontalLayout_3->addWidget(sendbutton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        quitbutton = new QPushButton(widget_3);
        quitbutton->setObjectName(QString::fromUtf8("quitbutton"));

        horizontalLayout_3->addWidget(quitbutton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_3);


        horizontalLayout_4->addWidget(widget_4);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        filelayout = new QVBoxLayout(widget_2);
        filelayout->setObjectName(QString::fromUtf8("filelayout"));
        filelayout->setContentsMargins(0, 9, 9, 0);
        filebox = new QToolBox(widget_2);
        filebox->setObjectName(QString::fromUtf8("filebox"));
        filebox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 174, 349));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        filebox->addItem(page, QString::fromUtf8("\346\226\207\344\273\266\344\270\213\350\275\275"));

        filelayout->addWidget(filebox);


        horizontalLayout_4->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 664, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        filebox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "5", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "6", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "7", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "8", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "9", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "10", nullptr));

#ifndef QT_NO_TOOLTIP
        toolButton->setToolTip(QApplication::translate("MainWindow", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        toolButton->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButton_2->setToolTip(QApplication::translate("MainWindow", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        toolButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButton_3->setToolTip(QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        toolButton_3->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButton_4->setToolTip(QApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        toolButton_4->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButton_5->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
        toolButton_5->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButton_6->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
#endif // QT_NO_TOOLTIP
        toolButton_6->setText(QApplication::translate("MainWindow", "...", nullptr));
        sendbutton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\234\250\347\272\277\344\272\272\346\225\2600\344\272\272", nullptr));
        quitbutton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        filebox->setItemText(filebox->indexOf(page), QApplication::translate("MainWindow", "\346\226\207\344\273\266\344\270\213\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
