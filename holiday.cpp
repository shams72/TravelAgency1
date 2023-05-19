
#include "holiday.h"
#include "ui_holiday.h"
#include"travelagency.h"
#include"QString"
#include"qdialog.h"
#include"qlabel.h"
#include"QDialogButtonBox"
#include"QLineEdit"
#include"QHBoxLayout"
#include"qmessagebox.h"
#include"booking.h"
#include"car_rental.h"
#include<QListWidgetItem>
#include<flight.h>
#include<hotel.h>
#include<string>
#include<QDate>
#include<QTableWidget>
#include<Customer.h>
#include<travel.h>
#include<QDateEdit>
holiday::holiday(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::holiday)
{

    ui->setupUi(this);
}

holiday::~holiday()
{

    delete ui;
}



void holiday::readFile()
{
    travel.readfile();

}

void holiday::on_actionInformation_Anzieigen_triggered()
{
    travel.readfile();



}





void holiday::on_actionAnzeigen_nach_ID_triggered()
{


    QDialog bookingIdDialog(this);
    bookingIdDialog.setWindowTitle("Anzeigen nach id");
    QLabel* label = new QLabel("Booking Id", &bookingIdDialog);
    QLineEdit* LineEdit = new QLineEdit(&bookingIdDialog);
    QHBoxLayout* layout = new QHBoxLayout(&bookingIdDialog);
    layout->addWidget(label); layout->addWidget(LineEdit);

    QDialogButtonBox* buttonbox = new QDialogButtonBox(&bookingIdDialog);
    buttonbox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonbox->setOrientation(Qt::Horizontal);

    layout->addWidget(buttonbox);

    connect(buttonbox, &QDialogButtonBox::accepted, &bookingIdDialog, &QDialog::accept);
    connect(buttonbox, &QDialogButtonBox::rejected, &bookingIdDialog, &QDialog::reject);

    std::string bookingId; bool found = false;
    QString Qbookingid ;int row =0;int coloumn=0;

    if(bookingIdDialog.exec()){
        QString Qlinedit=LineEdit->text();
        for(int i=0;i<travel.allcustomers.size();i++){
            auto t=travel.allcustomers[i];
            if(t->getid()==Qlinedit.toLong()){

                std::string Qname=t->getname();
                QString kundenname=QString::fromStdString(Qname);
                ui->KundenId->setText(Qlinedit);
                ui->Kundenname->setText(kundenname);
                int rowCount =t->travelliste.size();
                ui->ReisenBox->setRowCount(rowCount);
                ui->ReisenBox->setColumnCount(3);

                for(int j=0;j<t->travelliste.size();j++){
                auto a = t->travelliste[j];
                int travelid =  a->gettravelid();
                std::string t_id=std::to_string(travelid);

                QString Qtravelid = QString::fromStdString(t_id);
                QTableWidgetItem* tableitem= new QTableWidgetItem();//travel id
                QTableWidgetItem* fromtabledate= new QTableWidgetItem();
                QTableWidgetItem* totabledate= new QTableWidgetItem();

                tableitem->setText(Qtravelid);
                for(auto b:travel.bookings){
                    if(a->gettravelid()==b->gettravelid()){
                        QDate fromdate =QDate::fromString(QString::fromStdString(b->getfromdate()),"yyyyMMdd");
                        fromtabledate->setText(fromdate.toString());
                        QDate todate =QDate::fromString(QString::fromStdString(b->gettodate()),"yyyyMMdd");
                        totabledate->setText(todate.toString());
                    }
                }


                ui->ReisenBox->setItem(row,coloumn,tableitem);
                ui->ReisenBox->setItem(row,1,fromtabledate);
                ui->ReisenBox->setItem(row,2,totabledate);

                row++;

            }

            }
        }

    }
}



void holiday::on_ReisenBox_itemClicked(QTableWidgetItem *item)
{

    ui->BuchungenBox->selectColumn(3);


    int row=0;
    for(auto a:travel.alltravels){
        if(a->gettravelid()==item->text().toInt()){
            id.push_back(a->gettravelid());
            ui->ReiseID->setText(QString::number(a->gettravelid()));
            ui->BuchungenBox->setRowCount(a->bokingliste.size());

            for(auto b:a->bokingliste){

            QTableWidgetItem* table= new QTableWidgetItem();
            QTableWidgetItem* table1= new QTableWidgetItem();
            QTableWidgetItem* table2= new QTableWidgetItem();
            QTableWidgetItem* table3= new QTableWidgetItem();



            if (Rentalcarreservation* rental = dynamic_cast<Rentalcarreservation*>(b)){
                table->setText("RentalCar");
                QDate date1=QDate::fromString(QString::fromStdString(b->getfromdate()),"yyyyMMdd");
                table1->setText(date1.toString());
                QDate date2=QDate::fromString(QString::fromStdString(b->gettodate()),"yyyyMMdd");
                table2->setText(date2.toString());

                ui->BuchungenBox->setItem(row,0,table);
                ui->BuchungenBox->setItem(row,1,table2);
                ui->BuchungenBox->setItem(row,2,table1);
                ui->BuchungenBox->setItem(row,3,table3);


            }

            if(Flightbooking* flight =dynamic_cast<Flightbooking*>((b)) ) {
                table->setText("Flight");
                QDate date1=QDate::fromString(QString::fromStdString(b->getfromdate()),"yyyyMMdd");
                table1->setText(date1.toString());
                QDate date2=QDate::fromString(QString::fromStdString(b->gettodate()),"yyyyMMdd");
                table2->setText(date2.toString());
                table3->setText(QString::fromStdString(b->getprice()));

                ui->BuchungenBox->setItem(row,0,table);
                ui->BuchungenBox->setItem(row,1,table2);
                ui->BuchungenBox->setItem(row,2,table1);
                ui->BuchungenBox->setItem(row,3,table3);

            }
            if (Hotelreservation* hotel = dynamic_cast<Hotelreservation*>(b)) {
                table->setText("Hotel");
                QDate date1=QDate::fromString(QString::fromStdString(b->getfromdate()),"yyyyMMdd");
                table1->setText(date1.toString());
                QDate date2=QDate::fromString(QString::fromStdString(b->gettodate()),"yyyyMMdd");
                table2->setText(date2.toString());
                table3->setText(QString::fromStdString(b->getprice()));

                ui->BuchungenBox->setItem(row,0,table);
                ui->BuchungenBox->setItem(row,1,table2);
                ui->BuchungenBox->setItem(row,2,table1);
                ui->BuchungenBox->setItem(row,3,table3);


            }
            row++;



            }
        }

    }
}






void holiday::on_BuchungenBox_itemDoubleClicked(QTableWidgetItem *item)
{
    Booking* d=nullptr;
    for(auto a:travel.alltravels){
        if(a->gettravelid()==id.back()){


        Booking* c =a->bokingliste[item->tableWidget()->row(item)];
        for(auto b:a->bokingliste){

            if(b->getid()==c->getid()){
            d=b;

            }
         }
        }
    }





    if(Rentalcarreservation* rental = dynamic_cast<Rentalcarreservation*>(d)){

        QDate date1=QDate::fromString(QString::fromStdString(rental->getfromdate()),"yyyyMMdd");
        QDate date2=QDate::fromString(QString::fromStdString(rental->gettodate()),"yyyyMMdd");

        ui->BuchungID->setText(QString::fromStdString(rental->getid()));
        ui->Preis->setText(QString::fromStdString(rental->getprice()));
        ui->StartDate->setDate(date1);
        ui->Enddate->setDate(date2);
        ui->Pickup->setText(QString::fromStdString(rental->getpickuplocation()));
        ui->Return->setText(QString::fromStdString(rental->getreturnlocation()));
        ui->Vehicleclass->setText(QString::fromStdString(rental->getvehicleclass()));
        ui->Company->setText(QString::fromStdString(rental->getcompany()));



    }

    if(Flightbooking* flight =dynamic_cast<Flightbooking*>(d)) {


        QDate date1=QDate::fromString(QString::fromStdString(flight->getfromdate()),"yyyyMMdd");
        QDate date2=QDate::fromString(QString::fromStdString(flight->gettodate()),"yyyyMMdd");

        ui->FromDest->setText(QString::fromStdString(flight->getfromdestination()));
        ui->ToDest->setText(QString::fromStdString(flight->gettodestination()));
        ui->Airline->setText(QString::fromStdString(flight->getairline()));
        ui->BuchungID->setText(QString::fromStdString(flight->getid()));
        ui->Preis->setText(QString::fromStdString(flight->getprice()));
        ui->StartDate->setDate(date1);
        ui->Enddate->setDate(date2);



    }
    if (Hotelreservation* hotel = dynamic_cast<Hotelreservation*>(d)) {


        QDate date1=QDate::fromString(QString::fromStdString(hotel->getfromdate()),"yyyyMMdd");
        QDate date2=QDate::fromString(QString::fromStdString(hotel->gettodate()),"yyyyMMdd");

        ui->BuchungID->setText(QString::fromStdString(hotel->getid()));
        ui->Zimmer->setText(QString::fromStdString(hotel->getroomtype()));
        ui->Hotelname->setText(QString::fromStdString(hotel->gethotel()));
        ui->Stadt->setText(QString::fromStdString(hotel->gettown()));
        ui->Preis->setText(QString::fromStdString(hotel->getprice()));
        ui->StartDate->setDate(date1);
        ui->Enddate->setDate(date2);


    }





}

