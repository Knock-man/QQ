/********************************************************************************
** Form generated from reading UI file 'denglu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DENGLU_H
#define UI_DENGLU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_denglu
{
public:
    QHBoxLayout *horizontalLayout;
    QToolBox *vlayout;
    QWidget *page;
    QVBoxLayout *vlayout_2;

    void setupUi(QWidget *denglu)
    {
        if (denglu->objectName().isEmpty())
            denglu->setObjectName(QString::fromUtf8("denglu"));
        denglu->resize(219, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/qq.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        denglu->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(denglu);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        vlayout = new QToolBox(denglu);
        vlayout->setObjectName(QString::fromUtf8("vlayout"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 219, 494));
        vlayout_2 = new QVBoxLayout(page);
        vlayout_2->setObjectName(QString::fromUtf8("vlayout_2"));
        vlayout->addItem(page, QString::fromUtf8("\347\276\244\346\210\220\345\221\230"));

        horizontalLayout->addWidget(vlayout);


        retranslateUi(denglu);

        vlayout->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(denglu);
    } // setupUi

    void retranslateUi(QWidget *denglu)
    {
        denglu->setWindowTitle(QApplication::translate("denglu", "Form", nullptr));
        vlayout->setItemText(vlayout->indexOf(page), QApplication::translate("denglu", "\347\276\244\346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class denglu: public Ui_denglu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DENGLU_H
