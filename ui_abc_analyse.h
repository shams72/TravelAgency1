/********************************************************************************
** Form generated from reading UI file 'abc_analyse.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABC_ANALYSE_H
#define UI_ABC_ANALYSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ABC_Analyse
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ABC_Analyse)
    {
        if (ABC_Analyse->objectName().isEmpty())
            ABC_Analyse->setObjectName("ABC_Analyse");
        ABC_Analyse->resize(800, 600);
        centralwidget = new QWidget(ABC_Analyse);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 20, 751, 511));
        ABC_Analyse->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ABC_Analyse);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ABC_Analyse->setMenuBar(menubar);
        statusbar = new QStatusBar(ABC_Analyse);
        statusbar->setObjectName("statusbar");
        ABC_Analyse->setStatusBar(statusbar);

        retranslateUi(ABC_Analyse);

        QMetaObject::connectSlotsByName(ABC_Analyse);
    } // setupUi

    void retranslateUi(QMainWindow *ABC_Analyse)
    {
        ABC_Analyse->setWindowTitle(QCoreApplication::translate("ABC_Analyse", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ABC_Analyse: public Ui_ABC_Analyse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABC_ANALYSE_H
