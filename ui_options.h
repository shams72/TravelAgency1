/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QWidget *centralwidget;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName("Options");
        Options->resize(288, 302);
        centralwidget = new QWidget(Options);
        centralwidget->setObjectName("centralwidget");
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(80, 40, 107, 24));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(80, 80, 107, 24));
        radioButton_3 = new QRadioButton(centralwidget);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(80, 120, 107, 24));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 180, 131, 41));
        Options->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Options);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 288, 26));
        Options->setMenuBar(menubar);
        statusbar = new QStatusBar(Options);
        statusbar->setObjectName("statusbar");
        Options->setStatusBar(statusbar);

        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QMainWindow *Options)
    {
        Options->setWindowTitle(QCoreApplication::translate("Options", "MainWindow", nullptr));
        radioButton->setText(QCoreApplication::translate("Options", "Price", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Options", "FromDate", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Options", "ToDate", nullptr));
        pushButton->setText(QCoreApplication::translate("Options", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
