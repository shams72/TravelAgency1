#include "New_Customer.h"
#include "ui_mainwindow.h"
#include<QUuid>
#include<QMessageBox>
#include<hotel.h>
#include<car_rental.h>
#include<flight.h>
MainWindow::MainWindow( Travelagency* travelagency,QWidget *parent) :
    travelagency(travelagency),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox_3->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->ReiseID_2->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    bool found=false;
    for(auto a:travelagency->getAllcustomers()){  //Search existence of customers in Vector
        if(a->getname()==ui->Kundenname->toPlainText().toStdString()){
            customersid=a->getid();
            found=true;


        }
    }if(found == false){   //if name is not found.......
        QMessageBox msgbox;
        msgbox.setText("NAME NOT FOUND");
        ui->groupBox_3->setEnabled(true);
        customerid_needed=true;

        msgbox.exec();
    }else{  // if name is found

        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);

        if(addtravel==true){
            ui->groupBox_3->setEnabled(true);


        }
        if(addbooking==true){
            ui->groupBox_3->setEnabled(true);
            ui->ReiseID->setEnabled(false);
            ui->ReiseID_2->setEnabled(true);

        }

        QMessageBox msgbox;
        msgbox.setText("NAME FOUND");        
        customerid_needed=false;// No need to add new Customer ID if name is found
        msgbox.exec();
    }
}


void MainWindow::on_pushButton_3_clicked()
{  //This function is in order to add new hotel;

    int customerid=1;int travelid=1;

    if(customerid_needed==true){ //If completely new customer
        while(travelagency->findCustomer(customerid)!=nullptr){
        customerid=customerid+1;
        }
        while(travelagency->findTravel(travelid)!=nullptr){
        travelid=travelid+1;
        }
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);

    }
    else{
    customerid=customersid;
    ui->KundenId->setText(QString::number(customersid));
    }


    if(addtravel==true){ // if Radio button add Travelid is selected
    while(travelagency->findTravel(travelid)!=nullptr){
        travelid=travelid+1;

      }
    }


    if(addbooking==true){ //if add bookong is desired
      travelid = ui->ReiseID_2->toPlainText().toDouble();
      addbooking=false;

      /*for(auto& t:travelagency->alltravels){
        for(auto& a:travelagency->bookings){
            if(a->gettravelid()==ui->ReiseID_2->toPlainText().toDouble()){
                t->addBoking((a));
            }
        }
      }


      for(auto& c:travelagency->allcustomers){
        for(auto& a:travelagency->alltravels){
            if(c->getid()==customerid){
                c->addTravel(a);
            }
        }
      }*/
    }





    QUuid Bookingid= QUuid::createUuid();
    std::string name = ui->Kundenname->toPlainText().toStdString();
    std::string hotel=(ui->Hotelname->toPlainText().toStdString());
    double price=(ui->Preis->toPlainText().toDouble());
    std::string fromdate=(ui->StartDate->date().toString("yyyyMMdd").toStdString());
    std::string todate=(ui->Enddate->date().toString("yyyyMMdd").toStdString());
    std::string roomtype=(ui->Zimmer->toPlainText().toStdString());
    std::string town=(ui->Stadt->toPlainText().toStdString());
    std::string hotellatitude=ui->Zimmer_2->toPlainText().toStdString();
    std::string hotellongitude=ui->Zimmer_3->toPlainText().toStdString();
    std::string bookingid=Bookingid.toString().toStdString();

    ui->KundenId->setText(QString::number(customerid));
    ui->ReiseID->setText((QString::number(travelid)));
    ui->BuchungID->setText(QString::fromStdString(bookingid));

    std::shared_ptr<Customer> cusotmer =std::make_shared <Customer>(customerid,name);
    travelagency->getAllcustomers().push_back(cusotmer);

    std::shared_ptr<Travel> travel=std::make_shared <Travel>(customerid,travelid);
    travelagency->getAlltravels().push_back(travel);

    std::shared_ptr<Hotelreservation> Hotel=std::make_shared <Hotelreservation>(bookingid, price,fromdate,todate,travelid,hotel,
                                   town,roomtype,hotellatitude,hotellongitude);


    travelagency->addBoking(Hotel);
    //travelagency->getBookings().push_back(Hotel);
    bool added=false;
    /*for(auto& t:travelagency->alltravels){
        for(auto& a:travelagency->bookings){
            if(a->gettravelid()==t->gettravelid()){
                t->addBoking((a));
                added=true;
            }
        }
    }
    int b=0;
    for(auto& c:travelagency->allcustomers){
        for(auto& a:travelagency->alltravels){
            if(c->getid()==a->getcustomerid()){
                c->addTravel(a);


            }
        }
    }*/
    QMessageBox msgbox;
    if(added==false){

        msgbox.setText("Not added");
        msgbox.exec();
    }else{
       msgbox.setText("Added");
       msgbox.exec();
    }
    ui->groupBox_3->setEnabled(false);


}


void MainWindow::on_pushButton_2_clicked()
{
    int customerid=1;int travelid=1;
    if(customerid_needed==true){
       while(travelagency->findCustomer(customerid)!=nullptr){
            customerid=customerid+1;
        }
       while(travelagency->findTravel(travelid)!=nullptr){
            travelid=travelid+1;

       }
       ui->radioButton->setEnabled(false);
       ui->radioButton_2->setEnabled(false);

    }
    else{
        customerid=customersid;
        ui->KundenId->setText(QString::number(customersid));
    }

    if(addtravel==true){
        while(travelagency->findTravel(travelid)!=nullptr){
        travelid=travelid+1;
    }
    }

    if(addbooking==true){
    travelid = ui->ReiseID_2->toPlainText().toDouble();
    addbooking=false;
    /*for(auto& t:travelagency->alltravels){
        for(auto& a:travelagency->bookings){
            if(a->gettravelid()==ui->ReiseID_2->toPlainText().toDouble()){
                t->addBoking((a));
            }
        }
    }


    for(auto& c:travelagency->allcustomers){
        for(auto& a:travelagency->alltravels){
            if(c->getid()==customerid){
                c->addTravel(a);
            }
        }
    }*/
    }

    QUuid Bookingid= QUuid::createUuid();
    std::string name = ui->Kundenname->toPlainText().toStdString();
    std::string Pickup = ui->Pickup->toPlainText().toStdString();
    std::string Return=(ui->Return->toPlainText().toStdString());
    std::string Company=(ui->Company->toPlainText().toStdString());
    std::string Vehileclass(ui->Vehicleclass->toPlainText().toStdString());
    double Preis=(ui->Preis->toPlainText().toDouble());
    std::string StartDte=(ui->StartDate->date().toString("yyyyMMdd").toStdString());
    std::string EndDate =(ui->Enddate->date().toString("yyyyMMdd").toStdString());
    std::string bookingid=Bookingid.toString().toStdString();
    std::string pickuplatitude =ui->Vehicleclass_2->toPlainText().toStdString();
    std::string pickuplongitude=ui->Vehicleclass_3->toPlainText().toStdString();
    std::string droplongitude=ui->Vehicleclass_4->toPlainText().toStdString();
    std::string droplatitude=ui->Vehicleclass_5->toPlainText().toStdString();

    std::shared_ptr<Rentalcarreservation> rental = std::make_shared< Rentalcarreservation>(bookingid, Preis, StartDte, EndDate, travelid, Pickup, Return, Company, Vehileclass, pickuplatitude, pickuplongitude, droplatitude, droplongitude);
    travelagency->addBoking(rental);

   // travelagency->getBookings().push_back(rental);
    ui->KundenId->setText(QString::number(customerid));
    ui->ReiseID->setText((QString::number(travelid)));



    std::shared_ptr<Customer> cusotmer =std::make_shared <Customer>(customerid,name);
    travelagency->addcustomer(cusotmer);

    //travelagency->getAllcustomers().push_back(cusotmer);

    std::shared_ptr<Travel> travel=std::make_shared <Travel>(customerid,travelid);
    travelagency->addtravel(travel);

    //travelagency->getAlltravels().push_back(travel);

/*
    for(auto& t:travelagency->alltravels){
        for(auto& a:travelagency->bookings){
            if(a->gettravelid()==t->gettravelid()){
                t->addBoking((a));
            }
        }
    }

    for(auto& c:travelagency->allcustomers){
        for(auto& a:travelagency->alltravels){
            if(c->getid()==a->getcustomerid()){
                c->addTravel(a);
            }
        }
    }*/
    ui->groupBox_3->setEnabled(false);
}


void MainWindow::on_pushButton_clicked()
{
    int customerid=1;int travelid=1;
    if(customerid_needed==true){
    while(travelagency->findCustomer(customerid)!=nullptr){
            customerid=customerid+1;
        }
    while(travelagency->findTravel(travelid)!=nullptr){
            travelid=travelid+1;

    }
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);

    }
    else{
        customerid=customersid;
        ui->KundenId->setText(QString::number(customersid));
    }
    if(addtravel==true){
        while(travelagency->findTravel(travelid)!=nullptr){
        travelid=travelid+1;
    }
    }

    if(addbooking==true){
    travelid = ui->ReiseID_2->toPlainText().toDouble();
    addbooking=false;

   /* for(auto& t:travelagency->alltravels){
        for(auto& a:travelagency->bookings){
            if(a->gettravelid()==ui->ReiseID_2->toPlainText().toDouble()){
                t->addBoking((a));
            }
        }
    }


    for(auto& c:travelagency->allcustomers){
        for(auto& a:travelagency->alltravels){
            if(c->getid()==customerid){
                c->addTravel(a);
            }
        }
    }*/
    }


     QUuid Bookingid= QUuid::createUuid();
     std::string name = ui->Kundenname->toPlainText().toStdString();
     std::string airline=(ui->Airline->toPlainText().toStdString());
     std::string fromdestination=(ui->FromDest->toPlainText().toStdString());
     std::string fromdate=(ui->StartDate->date().toString("yyyyMMdd").toStdString());
     std::string todate=(ui->Enddate->date().toString("yyyyMMdd").toStdString());
     double price=(ui->Preis->toPlainText().toDouble());
     std::string todestination=(ui->ToDest->toPlainText().toStdString());
     std::string fromlatitude =ui->Vehicleclass_6->toPlainText().toStdString();
     std::string fromlongitude=ui->Vehicleclass_8->toPlainText().toStdString();
     std::string tolongitude=ui->Vehicleclass_9->toPlainText().toStdString();
     std::string tolatitude=ui->Vehicleclass_7->toPlainText().toStdString();
     std::string bookingid=Bookingid.toString().toStdString();

     std::shared_ptr<Flightbooking> booking =  std::make_shared<Flightbooking>(bookingid, price, fromdate, todate, travelid, fromdestination, todestination, airline, fromlatitude, fromlongitude, tolatitude, tolongitude);
     travelagency->addBoking(booking);

     //travelagency->getBookings().push_back(booking);

     ui->KundenId->setText(QString::number(customerid));
     ui->ReiseID->setText((QString::number(travelid)));

     std::shared_ptr<Customer> cusotmer =std::make_shared <Customer>(customerid,name);
     travelagency->addcustomer(cusotmer);

     //travelagency->getAllcustomers().push_back(cusotmer);

     std::shared_ptr<Travel> travel=std::make_shared <Travel>(customerid,travelid);
     travelagency->addtravel(travel);

     //travelagency->getAlltravels().push_back(travel);

    ui->groupBox_3->setEnabled(false);
}



void MainWindow::on_pushButton_5_clicked()
{
    for(auto& t:travelagency->getAlltravels()){
    for(auto& a:travelagency->getBookings()){
            if(a->gettravelid()==t->gettravelid()){
            t->getBokingliste().clear();
                t->addBoking((a));
            }
        }
    }


    for(auto& c:travelagency->getAllcustomers()){
        for(auto& a:travelagency->getAlltravels()){
            if(c->getid()==a->getcustomerid()){
                c->getTravelliste().clear();
                c->addTravel(a);
            }
        }
    }

}


void MainWindow::on_radioButton_clicked()
{
    addtravel=false;
    addbooking=true;
}


void MainWindow::on_radioButton_2_clicked()
{
    addbooking=false;
    addtravel=true;
}

