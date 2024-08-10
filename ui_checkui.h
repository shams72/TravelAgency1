/********************************************************************************
** Form generated from reading UI file 'checkui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKUI_H
#define UI_CHECKUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckUI
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *TableUI;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CheckUI)
    {
        if (CheckUI->objectName().isEmpty())
            CheckUI->setObjectName("CheckUI");
        CheckUI->resize(789, 556);
        centralwidget = new QWidget(CheckUI);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        TableUI = new QTableWidget(centralwidget);
        TableUI->setObjectName("TableUI");

        verticalLayout->addWidget(TableUI);

        CheckUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CheckUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 789, 26));
        CheckUI->setMenuBar(menubar);
        statusbar = new QStatusBar(CheckUI);
        statusbar->setObjectName("statusbar");
        CheckUI->setStatusBar(statusbar);

        retranslateUi(CheckUI);

        QMetaObject::connectSlotsByName(CheckUI);
    } // setupUi

    void retranslateUi(QMainWindow *CheckUI)
    {
        CheckUI->setWindowTitle(QCoreApplication::translate("CheckUI", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckUI: public Ui_CheckUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKUI_H
