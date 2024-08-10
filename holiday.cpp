#include<New_Customer.h>
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
#include<QApplication>
#include<QDesktopServices>
#include<QUrl>
#include <json.hpp>
#include<fstream>
#include <sortfunktor.h>
#include<QDebug>
#include"checkui.h"
#include"abc_analyse.h"
using json = nlohmann::json;

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
    travelagency.readfile();

}

void holiday::on_actionInformation_Anzieigen_triggered()
{
    travelagency.readfile();



}


void holiday::on_actionAnzeigen_nach_ID_triggered()// show by id
{



    QDialog bookingIdDialog(this);
    bookingIdDialog.setWindowTitle("Anzeigen nach id");
    QLabel* label = new QLabel("Booking Id", &bookingIdDialog);
    QLineEdit* inputid = new QLineEdit(&bookingIdDialog);
    QHBoxLayout* layout = new QHBoxLayout(&bookingIdDialog);
    layout->addWidget(label); layout->addWidget(inputid);

    QDialogButtonBox* buttonbox = new QDialogButtonBox(&bookingIdDialog);
    buttonbox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonbox->setOrientation(Qt::Horizontal);

    layout->addWidget(buttonbox);

    connect(buttonbox, &QDialogButtonBox::accepted, &bookingIdDialog, &QDialog::accept);
    connect(buttonbox, &QDialogButtonBox::rejected, &bookingIdDialog, &QDialog::reject);

    sort=true;
    qDebug()<<"Hello";
    //Sort to keep all the travel id from a customer in one container
    if (sort==true){
        for(auto& t:travelagency.getAlltravels()){
            for(auto& a:travelagency.getBookings()){
                if(a->gettravelid()==t->gettravelid()){
                    t->addBoking((a));
                }
            }
        }

  //Sort to keep all the buchung from a travelid in one container
        for(auto& c:travelagency.getAllcustomers()){
            for(auto& a:travelagency.getAlltravels()){
                if(c->getid()==a->getcustomerid()){
                    c->addTravel(a);
                }
            }
        }
    }
    sort=false;





    qDebug()<<"Hello";
    ui->ReisenBox->setColumnCount(3);
    bool found=false;
    std::shared_ptr<Customer> selected_customer = nullptr;
    if(bookingIdDialog.exec()){
        for(auto& customer:travelagency.getAllcustomers()){
            if(customer->getid()==inputid->text().toDouble()){
                ui->KundenId->setText(QString::number(customer->getid()));
                ui->Kundenname->setText(QString::fromStdString(customer->getname()));
                selected_customer= customer;
                found=true;

            }
        }
        if(found==false){
            QMessageBox box;

            default_file(d);
            box.setText("Name Not found");
            box.exec();
            return;
        }

        std::vector<std::shared_ptr<Travel>>customer_travellist = (selected_customer->getTravelliste());
        int row=0;
        ui->ReisenBox->setRowCount(customer_travellist.size());

        for(auto& a:customer_travellist){

            std::shared_ptr<Travel> travel=travelagency.findTravel(a->gettravelid());

            QTableWidgetItem* ID = new QTableWidgetItem();
            QTableWidgetItem* fromdate = new QTableWidgetItem();
            QTableWidgetItem* todate = new QTableWidgetItem();

            ID->setText(QString::number(a->gettravelid()));
            ui->ReisenBox->setItem(row,0,ID);

            start_fromDate =QDate::fromString(QString::fromStdString(travel->getBokingliste()[0]->getfromdate()),"yyyyMMdd");
            star_enddtate  =QDate::fromString(QString::fromStdString(travel->getBokingliste()[0]->gettodate()),"yyyyMMdd");


            for(auto& bookings:travel->getBokingliste()){
                QDate bookings_fromDate =QDate::fromString(QString::fromStdString(bookings->getfromdate()),"yyyyMMdd");
                QDate bookings_enddtate  =QDate::fromString(QString::fromStdString(bookings->gettodate()),"yyyyMMdd");

                if(start_fromDate>bookings_fromDate){
                    start_fromDate=bookings_fromDate;

                }
                if(star_enddtate<bookings_enddtate){
                    star_enddtate=bookings_enddtate;
                }
                fromdate->setText(start_fromDate.toString());
                ui->ReisenBox->setItem(row,1,fromdate);
                todate->setText(star_enddtate.toString());
                ui->ReisenBox->setItem(row,2,todate);


            }row++;

        }
    }
}



void holiday::on_ReisenBox_itemClicked(QTableWidgetItem *item)
{

    ui->BuchungenBox->selectColumn(3);

    reisenbox_row=item->tableWidget()->row(item);

    QString c;
    QString f;
    QString h;


    int row=0;QString geoJson="{ \"type\": \"LineString\",\"coordinates\": [";
    bool firstbooking=true;
    for(auto& a:travelagency.getAlltravels()){



        c.clear();
        f.clear();
        h.clear();

        if(a->gettravelid()==item->text().toInt()){
            id.push_back(a->gettravelid());
            ui->ReiseID->setText(QString::number(a->gettravelid()));
            ui->BuchungenBox->setRowCount(a->getBokingliste().size());

            for(auto& b:a->getBokingliste()){

                QTableWidgetItem* table = new QTableWidgetItem();
                QTableWidgetItem* table1= new QTableWidgetItem();
                QTableWidgetItem* table2= new QTableWidgetItem();
                QTableWidgetItem* table3= new QTableWidgetItem();



                if (std::shared_ptr<Rentalcarreservation> rental = std::dynamic_pointer_cast<Rentalcarreservation>(b)){
                    table->setText("RentalCar");
                    QDate date1=QDate::fromString(QString::fromStdString(b->getfromdate()),"yyyyMMdd");
                    table1->setText(date1.toString());
                    QDate date2=QDate::fromString(QString::fromStdString(b->gettodate()),"yyyyMMdd");
                    table2->setText(date2.toString());
                    table3->setText(QString::fromStdString(rental->getprice()));


                    QString pickuplatitude = QString::fromStdString((rental->getpickuplatitude()));
                    QString pickuplongitude =QString::fromStdString((rental->getpickuplongitude()));
                    QString returnlatitude = QString::fromStdString(rental->getreturnlatitude());
                    QString returnlongitude = QString::fromStdString(rental->getreturnlongiude());
                    QString pickupLocation = QString::fromStdString(rental->getpickuplocation());
                    QString returnLocation = QString::fromStdString(rental->getreturnlocation());
                    if(firstbooking==true){
                        c= "["+pickuplatitude+","+pickuplongitude+"],"+"["+returnlatitude+","+returnlongitude+"]";
                        firstbooking=false;
                    }else{
                        c=",["+pickuplatitude+","+pickuplongitude+"],"+"["+returnlatitude+","+returnlongitude+"]";
                    }

                     // c=",["+pickuplatitude+","+pickuplongitude+"],"+"["+returnlatitude+","+returnlongitude+"]";

                    geoJson+=c;



                    ui->BuchungenBox->setItem(row,0,table);
                    ui->BuchungenBox->setItem(row,2,table2);
                    ui->BuchungenBox->setItem(row,1,table1);
                    ui->BuchungenBox->setItem(row,3,table3);


                   // maps(b,geoJson);



                }

                if(std::shared_ptr<Flightbooking> flight =std::dynamic_pointer_cast<Flightbooking>((b)) ) {
                    table->setText("Flight");
                    QDate date1=QDate::fromString(QString::fromStdString(b->getfromdate()),"yyyyMMdd");
                    table1->setText(date1.toString());
                    QDate date2=QDate::fromString(QString::fromStdString(b->gettodate()),"yyyyMMdd");
                    table2->setText(date2.toString());
                    table3->setText(QString::fromStdString(b->getprice()));

                    QString fromdestlatitude = QString::fromStdString(flight->getfromdestlatitude());
                    QString fromdestlongitude = QString::fromStdString(flight->gettodestlongitude());
                    QString todestlatitude = QString::fromStdString(flight->gettodestlongitude());
                    QString todestlongitude = QString::fromStdString(flight->gettodestlongitude());
                    QString fromairport = QString::fromStdString(flight->getfromdestination());
                    QString toairport = QString::fromStdString(flight->gettodestination());

                    if(firstbooking==true){
                        f= "["+fromdestlatitude+","+fromdestlongitude+"],"+"["+todestlatitude+","+todestlongitude+"]";
                        firstbooking=false;
                    }else{
                        f= ",["+fromdestlatitude+","+fromdestlongitude+"],"+"["+todestlatitude+","+todestlongitude+"]";
                    }

                   // f= ",["+fromdestlatitude+","+fromdestlongitude+"],"+"["+todestlatitude+","+todestlongitude+"]";


                    geoJson+=f;

                    ui->BuchungenBox->setItem(row,0,table);
                    ui->BuchungenBox->setItem(row,2,table2);
                    ui->BuchungenBox->setItem(row,1,table1);
                    ui->BuchungenBox->setItem(row,3,table3);


                   // maps(b,geoJson);

                }
                if (std::shared_ptr<Hotelreservation> hotel = std::dynamic_pointer_cast<Hotelreservation>(b)) {
                    table->setText("Hotel");
                    QDate date1=QDate::fromString(QString::fromStdString(b->getfromdate()),"yyyyMMdd");
                    table1->setText(date1.toString());
                    QDate date2=QDate::fromString(QString::fromStdString(b->gettodate()),"yyyyMMdd");
                    table2->setText(date2.toString());
                    table3->setText(QString::fromStdString(b->getprice()));

                    QString hotellatitude = QString::fromStdString(hotel->gethotellatitude());
                    QString hotellongitude = QString::fromStdString(hotel->gethotellongitude());
                    QString hotelname = QString::fromStdString(hotel->gethotel());


                    if(firstbooking==true){
                       h= "["+hotellatitude+","+hotellongitude+"]";
                       firstbooking=false;
                    }else{
                       h= ",["+hotellatitude+","+hotellongitude+"]";
                   }

                    //h= ",["+hotellatitude+","+hotellongitude+"]";



                    geoJson+=h;







                    ui->BuchungenBox->setItem(row,0,table);
                    ui->BuchungenBox->setItem(row,2,table2);
                    ui->BuchungenBox->setItem(row,1,table1);
                    ui->BuchungenBox->setItem(row,3,table3);

                   // maps(b,geoJson);




                }




                row++;



            }
        }

    }
    //QString encodedGeoJson = QUrl::toPercentEncoding(geoJson);
    QString url = "http://townsendjennings.com/geo/?geojson=" + geoJson+"]}";
    QDesktopServices::openUrl(QUrl(url));
}






void holiday::default_file(std::shared_ptr<Booking> d)// when Cancell is clicked..it calls this function to reset
{
    if(std::shared_ptr<Rentalcarreservation> rental = std::dynamic_pointer_cast<Rentalcarreservation>(d)){

        ui->Tabs->setCurrentIndex(2);
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
        ui->Vehicleclass_2->setText(QString::fromStdString(rental->getpickuplatitude()));
        ui->Vehicleclass_3->setText(QString::fromStdString(rental->getpickuplongitude()));
        ui->Vehicleclass_4->setText(QString::fromStdString(rental->getreturnlatitude()));
        ui->Vehicleclass_5->setText(QString::fromStdString(rental->getreturnlatitude()));
       // ui->Preis_2->setText(QString::fromStdString(rental->getPredecessor1()));
       // ui->Preis_3->setText(QString::fromStdString(rental->getPredecessor2()));




    }

    if(std::shared_ptr<Flightbooking> flight =std::dynamic_pointer_cast<Flightbooking>(d)) {

        ui->Tabs->setCurrentIndex(1);
        QDate date1=QDate::fromString(QString::fromStdString(flight->getfromdate()),"yyyyMMdd");
        QDate date2=QDate::fromString(QString::fromStdString(flight->gettodate()),"yyyyMMdd");

        ui->FromDest->setText(QString::fromStdString(flight->getfromdestination()));
        ui->ToDest->setText(QString::fromStdString(flight->gettodestination()));
        ui->Airline->setText(QString::fromStdString(flight->getairline()));
        ui->BuchungID->setText(QString::fromStdString(flight->getid()));
        ui->Preis->setText(QString::fromStdString(flight->getprice()));
        ui->StartDate->setDate(date1);
        ui->Enddate->setDate(date2);
        ui->Vehicleclass_6->setText(QString::fromStdString(flight->gettodestlatitude()));
        ui->Vehicleclass_7->setText(QString::fromStdString(flight->getfromdestlatitude()));
        ui->Vehicleclass_8->setText(QString::fromStdString(flight->gettodestlongitude()));
        ui->Vehicleclass_9->setText(QString::fromStdString(flight->getfromdestlatitude()));
       // ui->Preis_2->setText(QString::fromStdString(flight->getPredecessor1()));
       // ui->Preis_3->setText(QString::fromStdString(flight->getPredecessor2()));



    }
    if (std::shared_ptr<Hotelreservation> hotel = std::dynamic_pointer_cast<Hotelreservation>(d)) {

        ui->Tabs->setCurrentIndex(0);
        QDate date1=QDate::fromString(QString::fromStdString(hotel->getfromdate()),"yyyyMMdd");
        QDate date2=QDate::fromString(QString::fromStdString(hotel->gettodate()),"yyyyMMdd");

        ui->BuchungID->setText(QString::fromStdString(hotel->getid()));
        ui->Zimmer->setText(QString::fromStdString(hotel->getroomtype()));
        ui->Hotelname->setText(QString::fromStdString(hotel->gethotel()));
        ui->Stadt->setText(QString::fromStdString(hotel->gettown()));
        ui->Preis->setText(QString::fromStdString(hotel->getprice()));
        ui->StartDate->setDate(date1);
        ui->Enddate->setDate(date2);
        ui->Zimmer_3->setText(QString::fromStdString(hotel->gethotellatitude()));
        ui->Zimmer_2->setText(QString::fromStdString(hotel->gethotellongitude()));
       // ui->Preis_2->setText(QString::fromStdString(hotel->getPredecessor1()));
       // ui->Preis_3->setText(QString::fromStdString(hotel->getPredecessor2()));


    }
}

void holiday::maps(std::shared_ptr<Booking> d, QString geoJson)
{

    QString c;
    QString f;
    QString h;
    // For Rentalcarreservation
    if (std::shared_ptr<Rentalcarreservation> rental = std::dynamic_pointer_cast<Rentalcarreservation>(d)) {
        QString pickuplatitude = QString::number(std::stod(rental->getpickuplatitude()));
        QString pickuplongitude = QString::number(std::stod(rental->getpickuplongitude()));
        QString returnlatitude = QString::fromStdString(rental->getreturnlatitude());
        QString returnlongitude = QString::fromStdString(rental->getreturnlongiude());
        QString pickupLocation = QString::fromStdString(rental->getpickuplocation());
        QString returnLocation = QString::fromStdString(rental->getreturnlocation());

        if (pickupLocation == returnLocation) {
            QString pointName1 = QString::fromStdString(rental->getpickuplocation());
            QString pointName2 = QString::fromStdString(rental->getpickuplocation());

            c += QString("{\"type\":\"Point\",\"coordinates\":[%1,%2],\"properties\":{\"pickupLocation\":\"%3\",\"returnLocation\":\"%4\"}}")
                           .arg(pickuplongitude)
                           .arg(pickuplatitude)
                           .arg(pickupLocation)
                           .arg(returnLocation)
                           .arg(pointName1.replace("\"", "\\\"")) // Replace pointName1 with the name of the first point
                           .arg(pointName2.replace("\"", "\\\"")); // Replace pointName2 with the name of the second point
        }
        else {
            QString pointName1 = QString::fromStdString(rental->getpickuplocation());
            QString pointName2 = QString::fromStdString(rental->getreturnlocation());

            c += QString("{\"type\":\"LineString\",\"coordinates\":[[%1,%2],[%3,%4]],\"properties\":{\"pickupLocation\":\"%5\",\"returnLocation\":\"%6\",\"pointNames\":[\"%7\",\"%8\"]}}")
                           .arg(pickuplongitude)
                           .arg(pickuplatitude)
                           .arg(returnlongitude)
                           .arg(returnlatitude)
                           .arg(pickupLocation)
                           .arg(returnLocation)
                           .arg(pointName1.replace("\"", "\\\"")) // Replace pointName1 with the name of the first point
                           .arg(pointName2.replace("\"", "\\\"")); // Replace pointName2 with the name of the second point
        }

        geoJson+=c;
    }

    // For Flightbooking
    if (std::shared_ptr<Flightbooking> flight = std::dynamic_pointer_cast<Flightbooking>(d)) {
        QString fromdestlatitude = QString::fromStdString(flight->getfromdestlatitude());
        QString fromdestlongitude = QString::fromStdString(flight->gettodestlongitude());
        QString todestlatitude = QString::fromStdString(flight->gettodestlongitude());
        QString todestlongitude = QString::fromStdString(flight->gettodestlongitude());
        QString fromairport = QString::fromStdString(flight->getfromdestination());
        QString toairport = QString::fromStdString(flight->gettodestination());

        f += QString(R"({
        "type": "FeatureCollection",
        "features": [
            {
                "type": "Feature",
                "geometry": {
                    "type": "Point",
                    "coordinates": [%1, %2]
                },
                "properties": {
                    "name": "%3"
                }
            },
            {
                "type": "Feature",
                "geometry": {
                    "type": "Point",
                    "coordinates": [%4, %5]
                },
                "properties": {
                    "name": "%6"
                }
            },
            {
                "type": "Feature",
                "geometry": {
                    "type": "LineString",
                    "coordinates": [[%1, %2], [%4, %5]]
                },
                "properties": {}
            }
        ]
    })").arg(fromdestlongitude).arg(fromdestlatitude).arg(fromairport).arg(todestlongitude).arg(todestlatitude).arg(toairport);

        geoJson+=f;

    }

    // For Hotelreservation
    if (std::shared_ptr<Hotelreservation> hotel = std::dynamic_pointer_cast<Hotelreservation>(d)) {
        QString hotellatitude = QString::fromStdString(hotel->gethotellatitude());
        QString hotellongitude = QString::fromStdString(hotel->gethotellongitude());
        QString hotelname = QString::fromStdString(hotel->gethotel());

        h += QString("{\"type\":\"Point\",\"coordinates\":[%1,%2],\"properties\":{\"name\":\"%3\"}}")
                       .arg(hotellongitude)
                       .arg(hotellatitude)
                       .arg(hotelname);

        geoJson+=h;
    }





}

void holiday::on_BuchungenBox_itemDoubleClicked(QTableWidgetItem *item)
{

    for(auto& a:travelagency.getAlltravels()){
        if(a->gettravelid()==id.back()){
            travelid.push_back(a->gettravelid());

            std::shared_ptr<Booking> c =a->getBokingliste()[item->tableWidget()->row(item)];
            row.push_back(item->tableWidget()->row(item));
            for(auto& b:a->getBokingliste()){

                if(b->getid()==c->getid()){
                    bokingid.push_back(b->getid());

                }
                d=a->getBokingliste()[item->tableWidget()->row(item)];
                bokingid.push_back(d->getid());




            }

        }
    }





    default_file(d);







}




void holiday::on_pushButton_clicked()// setter for changing data in existing customer
{
    bool found=false;

    for(auto& t:travelagency.getAlltravels()){
        if(t->gettravelid()==travelid.back()){
            for(auto& b:t->getBokingliste()){
                if(b->getid()==bokingid.back()){
                    QTableWidgetItem* table = new QTableWidgetItem();
                    QTableWidgetItem* table1 = new QTableWidgetItem();
                    QTableWidgetItem*table2 = new QTableWidgetItem();
                    QTableWidgetItem* reisenbox=new QTableWidgetItem();
                    QTableWidgetItem* reisenbox1=new QTableWidgetItem();
                    if (std::shared_ptr<Hotelreservation> hotel = std::dynamic_pointer_cast<Hotelreservation>(b)){

                        hotel->sethotel(ui->Hotelname->toPlainText().toStdString());
                        hotel->setprice(ui->Preis->toPlainText().toDouble());
                        hotel->setfromdate(ui->StartDate->date().toString("yyyyMMdd").toStdString());
                        hotel->settodate(ui->Enddate->date().toString("yyyyMMdd").toStdString());
                        hotel->setroomtype(ui->Zimmer->toPlainText().toStdString());
                        hotel->settown(ui->Stadt->toPlainText().toStdString());

                        QDate date1=QDate::fromString(QString::fromStdString(hotel->getfromdate()),"yyyyMMdd");
                        QDate date2=QDate::fromString(QString::fromStdString(hotel->gettodate()),"yyyyMMdd");

                        table2->setText(date2.toString());
                        table1->setText(date1.toString());
                        table->setText(ui->Preis->toPlainText());

                        if(start_fromDate>=date1){
                            start_fromDate =date1;
                            reisenbox->setText(start_fromDate.toString());
                            ui->ReisenBox->setItem(reisenbox_row,1,reisenbox);
                        }
                        if(star_enddtate<=date2){
                            star_enddtate=date2;
                            reisenbox1->setText(star_enddtate.toString());
                            ui->ReisenBox->setItem(reisenbox_row,2,reisenbox1);
                        }



                        ui->BuchungenBox->setItem(row.back(),2,table2);
                        ui->BuchungenBox->setItem(row.back(),1,table1);
                        ui->BuchungenBox->setItem(row.back(),3,table);
                        found=true;

                    }
                    if(std::shared_ptr<Flightbooking> flight =std::dynamic_pointer_cast<Flightbooking>(b)){

                        flight->setairline(ui->Airline->toPlainText().toStdString());
                        flight->setfromdestination(ui->FromDest->toPlainText().toStdString());
                        flight->setfromdate(ui->StartDate->date().toString("yyyyMMdd").toStdString());
                        flight->settodate(ui->Enddate->date().toString("yyyyMMdd").toStdString());
                        flight->setprice(ui->Preis->toPlainText().toDouble());
                        flight->settodestination(ui->ToDest->toPlainText().toStdString());

                        QDate date1=QDate::fromString(QString::fromStdString(flight->getfromdate()),"yyyyMMdd");
                        QDate date2=QDate::fromString(QString::fromStdString(flight->gettodate()),"yyyyMMdd");

                        table2->setText(date2.toString());
                        table1->setText(date1.toString());
                        table->setText(ui->Preis->toPlainText());

                        if(start_fromDate>=date1){
                            start_fromDate =date1;
                            reisenbox->setText(start_fromDate.toString());
                            ui->ReisenBox->setItem(reisenbox_row,1,reisenbox);
                        }
                        if(star_enddtate<=date2){
                            star_enddtate=date2;
                            reisenbox1->setText(star_enddtate.toString());
                            ui->ReisenBox->setItem(reisenbox_row,2,reisenbox1);
                        }

                        ui->BuchungenBox->setItem(row.back(),2,table2);
                        ui->BuchungenBox->setItem(row.back(),1,table1);
                        ui->BuchungenBox->setItem(row.back(),3,table);
                        found =true;
                    }
                    if(std::shared_ptr<Rentalcarreservation> rental = std::dynamic_pointer_cast<Rentalcarreservation>(b)){

                        rental->setpickuplocation(ui->Pickup->toPlainText().toStdString());
                        rental->setreturnlocation(ui->Return->toPlainText().toStdString());
                        rental->setcompany(ui->Company->toPlainText().toStdString());
                        rental->setvehicleclass(ui->Vehicleclass->toPlainText().toStdString());
                        rental->setprice(ui->Preis->toPlainText().toDouble());
                        rental->setfromdate(ui->StartDate->date().toString("yyyyMMdd").toStdString());
                        rental->settodate(ui->Enddate->date().toString("yyyyMMdd").toStdString());

                        QDate date1=QDate::fromString(QString::fromStdString(rental->getfromdate()),"yyyyMMdd");
                        QDate date2=QDate::fromString(QString::fromStdString(rental->gettodate()),"yyyyMMdd");



                        table2->setText(date2.toString());
                        table1->setText(date1.toString());
                        table->setText(ui->Preis->toPlainText());

                        if(start_fromDate>=date1){
                            start_fromDate =date1;
                            reisenbox->setText(start_fromDate.toString());
                            ui->ReisenBox->setItem(reisenbox_row,1,reisenbox);
                        }
                        if(star_enddtate<=date2){
                            star_enddtate=date2;
                            reisenbox1->setText(star_enddtate.toString());
                            ui->ReisenBox->setItem(reisenbox_row,2,reisenbox1);
                        }

                        ui->BuchungenBox->setItem(row.back(),2,table2);
                        ui->BuchungenBox->setItem(row.back(),1,table1);
                        ui->BuchungenBox->setItem(row.back(),3,table);
                        found=true;
                    }


                }
            }
        }


    }
    if(found==true){
        found=false;
        QMessageBox box;
        box.setText("Changes done");
        box.exec();
    }else{
        QMessageBox box;
        box.setText("No Changes to do");
        box.exec();
    }
}


void holiday::on_pushButton_2_clicked()// Cancell Button if reset wished
{
    QMessageBox box;
    default_file(d);
    box.setText("Changes Not done");
    box.exec();
}


void holiday::on_actionShow_Airport_triggered()
{
    travelagency.flughafenreadfile();
}


void holiday::on_pushButton_3_clicked()// AD Flughafen along wit eRROR INPUT
{
    bool found=false;
    std::shared_ptr<Booking> booking=nullptr;
    for(auto& travellings :travelagency.getAlltravels()){
        if(travellings->gettravelid()==travelid.back()){
            booking=travellings->getBokingliste()[row.back()];
        }
    }

    std::string from_inputtext=ui->FromDest->toPlainText().toStdString();
    std::string to_inputtext=ui->ToDest->toPlainText().toStdString();
    int numflags=0; bool find=false;
    if(std::shared_ptr<Flightbooking> flight =std::dynamic_pointer_cast<Flightbooking>(booking)){
        for(auto airport:travelagency.getAllairports()){
            if(airport.getiatacode()==from_inputtext){
                flight->setfromdestination(from_inputtext);
                default_file(booking);
                found=true;

            }

            if(airport.getiatacode()==to_inputtext){
                flight->settodestination(to_inputtext);
                default_file(booking);
                find =true;
            }
        }
        if (found == false) {
            default_file(booking);
            QMessageBox::warning(nullptr, "Error", "<font color='red'>Invalid destination input for 'TO'.</font>");
            return;
        }

        if (find == false) {
            default_file(booking);
            QMessageBox::warning(nullptr, "Error", "<font color='red'>Invalid destination input for 'FROM'.</font>");
            return;
        }

        if (find == false && found == false) {
            QMessageBox::warning(nullptr, "Error", "<font color='red'>Invalid destination inputs for 'TO' and 'FROM'.</font>");
            return;
        }

    }
}

void holiday::on_actionAlle_Anzeigen_triggered()//New Customer Menu
{
    //Constructor von New Customer.Cpp...die Constructor heisst Mainwindow.


   // std::shared_ptr<Travelagency> travelagencyptr = std::make_shared<Travelagency>(travelagency);
    MainWindow* main = new MainWindow(&travelagency);
    main->show();



}


void holiday::on_Createfile_clicked()
{
    json Allbookingdata=json::array();


    for(auto& booking:travelagency.getBookings()){
        json bookingdata=json::object();
        if(std::shared_ptr<Flightbooking> flight =std::dynamic_pointer_cast<Flightbooking>(booking)){
            bookingdata["Type"]="Flight";
            bookingdata["Airline"]=flight->getairline();
            bookingdata["Price"]=flight->getprice();
            bookingdata["FromDate"]=flight->getfromdate();
            bookingdata["ToDate"]=flight->gettodate();
            bookingdata["TravelID"]=flight->gettravelid();
            bookingdata["BookingID"]=flight->getid();
            bookingdata["fromdestination"]=flight->getfromdestination();
            bookingdata["todestination"]=flight->gettodestination();
            bookingdata["fromdestlatitude"]=flight->getfromdestlatitude();
            bookingdata["fromdestlongitude"]=flight->getfromdestlatitude();
            bookingdata["todestlatitude"]=flight->gettodestlatitude();
            bookingdata["todestlongitude"]=flight->gettodestlongitude();
            Allbookingdata.push_back(bookingdata);

        }

        if(std::shared_ptr<Rentalcarreservation> rental = std::dynamic_pointer_cast<Rentalcarreservation>(booking)){
            bookingdata["Type"]="RentalCar";
            bookingdata["Price"]=rental->getprice();
            bookingdata["FromDate"]=rental->getfromdate();
            bookingdata["ToDate"]=rental->gettodate();
            bookingdata["TravelID"]=rental->gettravelid();
            bookingdata["BookingID"]=rental->getid();
            bookingdata["pickuplocation"]=rental->getpickuplocation();
            bookingdata["returnlocation"]=rental->getreturnlocation();
            bookingdata["company"]=rental->getcompany();
            bookingdata["vehicleclass"]=rental->getvehicleclass();
            bookingdata["pickuplatitude"]=rental->getpickuplatitude();
            bookingdata["pickuplongitude"]=rental->getpickuplongitude();
            bookingdata["returnlatitude"]=rental->getreturnlongiude();
            bookingdata["returnlongiude"]=rental->getreturnlongiude();
            Allbookingdata.push_back(bookingdata);

        }

        if(std::shared_ptr<Hotelreservation> hotel = std::dynamic_pointer_cast<Hotelreservation>(booking)){
            bookingdata["Type"]="Hotel";
            bookingdata["Price"]=hotel->getprice();
            bookingdata["FromDate"]=hotel->getfromdate();
            bookingdata["ToDate"]=hotel->gettodate();
            bookingdata["TravelID"]=hotel->gettravelid();
            bookingdata["BookingID"]=hotel->getid();
            bookingdata["Town"]=hotel->gettown();
            bookingdata["Roomtype"]=hotel->getroomtype();
            bookingdata["Hotel"]=hotel->gethotel();
            bookingdata["Hotellatitude"]=hotel->gethotellatitude();
            bookingdata["Hotellongiude"]=hotel->gethotellongitude();
            Allbookingdata.push_back(bookingdata);

        }


    }


    std::ofstream outputfile("newjson1.json");
    if(outputfile.is_open()){
        outputfile<<Allbookingdata.dump(4);
        QString message="Done\n";
        QMessageBox msgbox;
        msgbox.setText(message);
        msgbox.exec();
        outputfile.close();
    }else{
        QMessageBox::warning(nullptr,"Error","Not Done\n");

    }
}


void holiday::on_actionhello_triggered()
{
  /*  Option = new Options(&travelagency);
    option->show();
*/

}


void holiday::on_pushButton_4_clicked()// Sorting Button to sort based on price
{

    travelagency.sort();

}


void holiday::on_pushButton_5_clicked()
{
    CheckUI* checkui=new CheckUI(&travelagency);
    checkui->show();
}


void holiday::on_pushButton_6_clicked()
{
    travelagency.abcanayse();
    ABC_Analyse* abc = new ABC_Analyse(&travelagency);
    abc->show();

}

