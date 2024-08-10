/********************************************************************************
** Form generated from reading UI file 'holiday.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOLIDAY_H
#define UI_HOLIDAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_holiday
{
public:
    QAction *actionAlle_Anzeigen;
    QAction *actionAnzeigen_nach_ID;
    QAction *actionInformation_Anzieigen;
    QAction *actionShow_Airport;
    QAction *actionhello;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTableWidget *ReisenBox;
    QTextEdit *KundenId;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *Kundenname;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QTextEdit *ReiseID;
    QLabel *label_5;
    QTableWidget *BuchungenBox;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *BuchungID;
    QTextEdit *Preis;
    QLabel *label_8;
    QLabel *label_9;
    QTabWidget *Tabs;
    QWidget *Hotel;
    QTextEdit *Hotelname;
    QLabel *label_10;
    QTextEdit *Stadt;
    QLabel *label_11;
    QTextEdit *Zimmer;
    QLabel *label_12;
    QTextEdit *Zimmer_2;
    QTextEdit *Zimmer_3;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *Flight;
    QTextEdit *FromDest;
    QLabel *label_13;
    QTextEdit *ToDest;
    QLabel *label_14;
    QTextEdit *Airline;
    QLabel *label_15;
    QTextEdit *Vehicleclass_6;
    QLabel *label_26;
    QTextEdit *Vehicleclass_7;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QTextEdit *Vehicleclass_8;
    QTextEdit *Vehicleclass_9;
    QWidget *RentalCar;
    QTextEdit *Pickup;
    QLabel *label_16;
    QTextEdit *Return;
    QLabel *label_17;
    QTextEdit *Company;
    QLabel *label_18;
    QLabel *label_19;
    QTextEdit *Vehicleclass;
    QTextEdit *Vehicleclass_2;
    QTextEdit *Vehicleclass_3;
    QTextEdit *Vehicleclass_4;
    QTextEdit *Vehicleclass_5;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QDateEdit *StartDate;
    QDateEdit *Enddate;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *Createfile;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QMenu *menuEinlesen;
    QMenu *menuBuchung;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *holiday)
    {
        if (holiday->objectName().isEmpty())
            holiday->setObjectName("holiday");
        holiday->resize(1370, 985);
        actionAlle_Anzeigen = new QAction(holiday);
        actionAlle_Anzeigen->setObjectName("actionAlle_Anzeigen");
        actionAnzeigen_nach_ID = new QAction(holiday);
        actionAnzeigen_nach_ID->setObjectName("actionAnzeigen_nach_ID");
        actionInformation_Anzieigen = new QAction(holiday);
        actionInformation_Anzieigen->setObjectName("actionInformation_Anzieigen");
        actionShow_Airport = new QAction(holiday);
        actionShow_Airport->setObjectName("actionShow_Airport");
        actionhello = new QAction(holiday);
        actionhello->setObjectName("actionhello");
        centralwidget = new QWidget(holiday);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 10, 431, 421));
        ReisenBox = new QTableWidget(groupBox);
        if (ReisenBox->columnCount() < 4)
            ReisenBox->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ReisenBox->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ReisenBox->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ReisenBox->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ReisenBox->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        ReisenBox->setObjectName("ReisenBox");
        ReisenBox->setGeometry(QRect(10, 160, 391, 241));
        KundenId = new QTextEdit(groupBox);
        KundenId->setObjectName("KundenId");
        KundenId->setGeometry(QRect(110, 30, 161, 31));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 70, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 71, 31));
        Kundenname = new QTextEdit(groupBox);
        Kundenname->setObjectName("Kundenname");
        Kundenname->setGeometry(QRect(110, 90, 161, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 120, 71, 31));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 430, 581, 391));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 40, 70, 31));
        ReiseID = new QTextEdit(groupBox_2);
        ReiseID->setObjectName("ReiseID");
        ReiseID->setGeometry(QRect(150, 40, 161, 31));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 110, 81, 31));
        BuchungenBox = new QTableWidget(groupBox_2);
        if (BuchungenBox->columnCount() < 5)
            BuchungenBox->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        BuchungenBox->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        BuchungenBox->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        BuchungenBox->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        BuchungenBox->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        BuchungenBox->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        BuchungenBox->setObjectName("BuchungenBox");
        BuchungenBox->setGeometry(QRect(40, 150, 511, 231));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(630, 20, 611, 781));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 20, 91, 31));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 70, 71, 31));
        BuchungID = new QTextEdit(groupBox_3);
        BuchungID->setObjectName("BuchungID");
        BuchungID->setGeometry(QRect(170, 20, 161, 31));
        Preis = new QTextEdit(groupBox_3);
        Preis->setObjectName("Preis");
        Preis->setGeometry(QRect(170, 160, 161, 31));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 160, 71, 31));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 110, 71, 31));
        Tabs = new QTabWidget(groupBox_3);
        Tabs->setObjectName("Tabs");
        Tabs->setGeometry(QRect(60, 230, 461, 411));
        Hotel = new QWidget();
        Hotel->setObjectName("Hotel");
        Hotelname = new QTextEdit(Hotel);
        Hotelname->setObjectName("Hotelname");
        Hotelname->setGeometry(QRect(150, 20, 161, 31));
        label_10 = new QLabel(Hotel);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 60, 71, 31));
        Stadt = new QTextEdit(Hotel);
        Stadt->setObjectName("Stadt");
        Stadt->setGeometry(QRect(150, 60, 161, 31));
        label_11 = new QLabel(Hotel);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 20, 111, 31));
        Zimmer = new QTextEdit(Hotel);
        Zimmer->setObjectName("Zimmer");
        Zimmer->setGeometry(QRect(150, 110, 161, 31));
        label_12 = new QLabel(Hotel);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 110, 91, 31));
        Zimmer_2 = new QTextEdit(Hotel);
        Zimmer_2->setObjectName("Zimmer_2");
        Zimmer_2->setGeometry(QRect(150, 210, 161, 31));
        Zimmer_3 = new QTextEdit(Hotel);
        Zimmer_3->setObjectName("Zimmer_3");
        Zimmer_3->setGeometry(QRect(150, 160, 161, 31));
        label_20 = new QLabel(Hotel);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(20, 160, 121, 31));
        label_21 = new QLabel(Hotel);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 210, 121, 31));
        Tabs->addTab(Hotel, QString());
        Flight = new QWidget();
        Flight->setObjectName("Flight");
        FromDest = new QTextEdit(Flight);
        FromDest->setObjectName("FromDest");
        FromDest->setGeometry(QRect(180, 20, 161, 31));
        label_13 = new QLabel(Flight);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 60, 71, 31));
        ToDest = new QTextEdit(Flight);
        ToDest->setObjectName("ToDest");
        ToDest->setGeometry(QRect(180, 60, 161, 31));
        label_14 = new QLabel(Flight);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(30, 20, 71, 31));
        Airline = new QTextEdit(Flight);
        Airline->setObjectName("Airline");
        Airline->setGeometry(QRect(180, 110, 161, 31));
        label_15 = new QLabel(Flight);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(30, 100, 71, 31));
        Vehicleclass_6 = new QTextEdit(Flight);
        Vehicleclass_6->setObjectName("Vehicleclass_6");
        Vehicleclass_6->setGeometry(QRect(180, 150, 161, 31));
        label_26 = new QLabel(Flight);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(30, 300, 131, 31));
        Vehicleclass_7 = new QTextEdit(Flight);
        Vehicleclass_7->setObjectName("Vehicleclass_7");
        Vehicleclass_7->setGeometry(QRect(180, 300, 161, 31));
        label_27 = new QLabel(Flight);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(30, 250, 121, 31));
        label_28 = new QLabel(Flight);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(30, 200, 131, 31));
        label_29 = new QLabel(Flight);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(30, 150, 121, 31));
        Vehicleclass_8 = new QTextEdit(Flight);
        Vehicleclass_8->setObjectName("Vehicleclass_8");
        Vehicleclass_8->setGeometry(QRect(180, 200, 161, 31));
        Vehicleclass_9 = new QTextEdit(Flight);
        Vehicleclass_9->setObjectName("Vehicleclass_9");
        Vehicleclass_9->setGeometry(QRect(180, 250, 161, 31));
        Tabs->addTab(Flight, QString());
        RentalCar = new QWidget();
        RentalCar->setObjectName("RentalCar");
        Pickup = new QTextEdit(RentalCar);
        Pickup->setObjectName("Pickup");
        Pickup->setGeometry(QRect(180, 20, 161, 31));
        label_16 = new QLabel(RentalCar);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(40, 60, 71, 31));
        Return = new QTextEdit(RentalCar);
        Return->setObjectName("Return");
        Return->setGeometry(QRect(180, 60, 161, 31));
        label_17 = new QLabel(RentalCar);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(40, 20, 71, 31));
        Company = new QTextEdit(RentalCar);
        Company->setObjectName("Company");
        Company->setGeometry(QRect(180, 100, 161, 31));
        label_18 = new QLabel(RentalCar);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(40, 100, 71, 31));
        label_19 = new QLabel(RentalCar);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(40, 140, 111, 31));
        Vehicleclass = new QTextEdit(RentalCar);
        Vehicleclass->setObjectName("Vehicleclass");
        Vehicleclass->setGeometry(QRect(180, 140, 161, 31));
        Vehicleclass_2 = new QTextEdit(RentalCar);
        Vehicleclass_2->setObjectName("Vehicleclass_2");
        Vehicleclass_2->setGeometry(QRect(180, 340, 161, 31));
        Vehicleclass_3 = new QTextEdit(RentalCar);
        Vehicleclass_3->setObjectName("Vehicleclass_3");
        Vehicleclass_3->setGeometry(QRect(180, 190, 161, 31));
        Vehicleclass_4 = new QTextEdit(RentalCar);
        Vehicleclass_4->setObjectName("Vehicleclass_4");
        Vehicleclass_4->setGeometry(QRect(180, 240, 161, 31));
        Vehicleclass_5 = new QTextEdit(RentalCar);
        Vehicleclass_5->setObjectName("Vehicleclass_5");
        Vehicleclass_5->setGeometry(QRect(180, 290, 161, 31));
        label_22 = new QLabel(RentalCar);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(40, 330, 131, 31));
        label_23 = new QLabel(RentalCar);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(40, 240, 131, 31));
        label_24 = new QLabel(RentalCar);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(40, 190, 121, 31));
        label_25 = new QLabel(RentalCar);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(40, 290, 121, 31));
        Tabs->addTab(RentalCar, QString());
        StartDate = new QDateEdit(groupBox_3);
        StartDate->setObjectName("StartDate");
        StartDate->setGeometry(QRect(170, 70, 161, 31));
        Enddate = new QDateEdit(groupBox_3);
        Enddate->setObjectName("Enddate");
        Enddate->setGeometry(QRect(170, 110, 161, 31));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 650, 121, 51));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 650, 121, 51));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(160, 650, 121, 51));
        Createfile = new QPushButton(groupBox_3);
        Createfile->setObjectName("Createfile");
        Createfile->setGeometry(QRect(460, 650, 121, 51));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(50, 720, 121, 51));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(220, 720, 121, 51));
        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(390, 720, 121, 51));
        holiday->setCentralWidget(centralwidget);
        menubar = new QMenuBar(holiday);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1370, 26));
        menuEinlesen = new QMenu(menubar);
        menuEinlesen->setObjectName("menuEinlesen");
        menuBuchung = new QMenu(menubar);
        menuBuchung->setObjectName("menuBuchung");
        holiday->setMenuBar(menubar);
        statusbar = new QStatusBar(holiday);
        statusbar->setObjectName("statusbar");
        holiday->setStatusBar(statusbar);

        menubar->addAction(menuEinlesen->menuAction());
        menubar->addAction(menuBuchung->menuAction());
        menuEinlesen->addAction(actionInformation_Anzieigen);
        menuEinlesen->addAction(actionShow_Airport);
        menuEinlesen->addAction(actionhello);
        menuBuchung->addAction(actionAlle_Anzeigen);
        menuBuchung->addAction(actionAnzeigen_nach_ID);

        retranslateUi(holiday);

        Tabs->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(holiday);
    } // setupUi

    void retranslateUi(QMainWindow *holiday)
    {
        holiday->setWindowTitle(QCoreApplication::translate("holiday", "holiday", nullptr));
        actionAlle_Anzeigen->setText(QCoreApplication::translate("holiday", "New Customer", nullptr));
        actionAnzeigen_nach_ID->setText(QCoreApplication::translate("holiday", "Anzeigen nach ID", nullptr));
        actionInformation_Anzieigen->setText(QCoreApplication::translate("holiday", "Information Anzieigen", nullptr));
        actionShow_Airport->setText(QCoreApplication::translate("holiday", "Show Airport", nullptr));
        actionhello->setText(QCoreApplication::translate("holiday", "Sort", nullptr));
        groupBox->setTitle(QCoreApplication::translate("holiday", "Kunden", nullptr));
        QTableWidgetItem *___qtablewidgetitem = ReisenBox->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("holiday", "Reise ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = ReisenBox->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("holiday", "Beginn der Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = ReisenBox->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("holiday", "Ende der Reise", nullptr));
        label->setText(QCoreApplication::translate("holiday", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("holiday", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("holiday", "Reisen", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("holiday", "Reisen", nullptr));
        label_4->setText(QCoreApplication::translate("holiday", "Reise ID", nullptr));
        label_5->setText(QCoreApplication::translate("holiday", "Buchungen", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = BuchungenBox->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("holiday", "Buchungstyp", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = BuchungenBox->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("holiday", "Start", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = BuchungenBox->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("holiday", "Ende der Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = BuchungenBox->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("holiday", "Preis", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("holiday", "Buchungdetails", nullptr));
        label_6->setText(QCoreApplication::translate("holiday", "BuchungId", nullptr));
        label_7->setText(QCoreApplication::translate("holiday", "Start", nullptr));
        label_8->setText(QCoreApplication::translate("holiday", "Preis", nullptr));
        label_9->setText(QCoreApplication::translate("holiday", "Ende", nullptr));
        label_10->setText(QCoreApplication::translate("holiday", "Stadt", nullptr));
        label_11->setText(QCoreApplication::translate("holiday", "HotelNmae", nullptr));
        label_12->setText(QCoreApplication::translate("holiday", "Zimmertyp", nullptr));
        label_20->setText(QCoreApplication::translate("holiday", "Hotellongitude", nullptr));
        label_21->setText(QCoreApplication::translate("holiday", "HotelLatitude", nullptr));
        Tabs->setTabText(Tabs->indexOf(Hotel), QCoreApplication::translate("holiday", "Hotel", nullptr));
        label_13->setText(QCoreApplication::translate("holiday", "To", nullptr));
        label_14->setText(QCoreApplication::translate("holiday", "From", nullptr));
        label_15->setText(QCoreApplication::translate("holiday", "Airline", nullptr));
        label_26->setText(QCoreApplication::translate("holiday", "ToLongitude", nullptr));
        label_27->setText(QCoreApplication::translate("holiday", "ToLatitude", nullptr));
        label_28->setText(QCoreApplication::translate("holiday", "Fromlongoitude", nullptr));
        label_29->setText(QCoreApplication::translate("holiday", "FromLatitude", nullptr));
        Tabs->setTabText(Tabs->indexOf(Flight), QCoreApplication::translate("holiday", "Flight", nullptr));
        label_16->setText(QCoreApplication::translate("holiday", "Return", nullptr));
        label_17->setText(QCoreApplication::translate("holiday", "Pickup", nullptr));
        label_18->setText(QCoreApplication::translate("holiday", "Company", nullptr));
        label_19->setText(QCoreApplication::translate("holiday", "Vehicleclass", nullptr));
        label_22->setText(QCoreApplication::translate("holiday", "ReturnLongitude", nullptr));
        label_23->setText(QCoreApplication::translate("holiday", "Pickuplongoitude", nullptr));
        label_24->setText(QCoreApplication::translate("holiday", "PickupLatitude", nullptr));
        label_25->setText(QCoreApplication::translate("holiday", "ReturnLatitude", nullptr));
        Tabs->setTabText(Tabs->indexOf(RentalCar), QCoreApplication::translate("holiday", "RentalCar", nullptr));
        pushButton->setText(QCoreApplication::translate("holiday", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("holiday", "Cancel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("holiday", "Check Airport", nullptr));
        Createfile->setText(QCoreApplication::translate("holiday", "CreatFile", nullptr));
        pushButton_4->setText(QCoreApplication::translate("holiday", "Sorting ", nullptr));
        pushButton_5->setText(QCoreApplication::translate("holiday", "Check Travels", nullptr));
        pushButton_6->setText(QCoreApplication::translate("holiday", "ABC Analyse", nullptr));
        menuEinlesen->setTitle(QCoreApplication::translate("holiday", "Einlesen", nullptr));
        menuBuchung->setTitle(QCoreApplication::translate("holiday", "Buchung", nullptr));
    } // retranslateUi

};

namespace Ui {
    class holiday: public Ui_holiday {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOLIDAY_H
