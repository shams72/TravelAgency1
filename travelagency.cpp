#include <fstream>
#include <json.hpp>
using json = nlohmann::json;
#include "Flight.h"
#include "hotel.h"
#include"car_rental.h"
#include "Travelagency.h"
#include<iostream>
#include<QVBoxLayout>
#include<QString>
#include<QFileDialog>
#include<QMessageBox>
#include<QList>
#include<QListWidget>
#include<QTextEdit>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include <memory>
#include"travel.h"
#include"customer.h"
#include"sortfunktor.h"
#include<QInputDialog>
std::vector<std::shared_ptr<Customer> > Travelagency::getAllcustomers()
{
    return allcustomers;
}

std::vector<std::shared_ptr<Travel> > Travelagency::getAlltravels()
{
    return alltravels;
}

std::vector<Airport> Travelagency::getAllairports()
{
    return allairports;
}

void Travelagency::addCustomer(Customer *customer)
{
   //allcustomers.push_back(customer);
}

void Travelagency::readfile() {
    int pricehotel = 0; int pricecar = 0; int priceflight = 0; int numhotel = 0; int numcar = 0; int numflight = 0;
    std::shared_ptr<Customer>customer=nullptr;std::shared_ptr<Travel> travel=nullptr;std::shared_ptr<Booking> booking=nullptr;

    QString filename = QFileDialog::getOpenFileName(nullptr, "Open Bookings JSON File", "", "JSON Files (*.json)");
    //std::string filepath = filename.toStdString();


    // Open the JSON file
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Error opening file.\n");
        return;
    }

    // Read the JSON data
    file.setTextModeEnabled(true);  // Enable text mode for proper encoding handling
    QString jsonData = file.readAll();
    file.close();

    // Parse the JSON document
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData.toUtf8());  // Convert to UTF-8 encoding
    if (jsonDocument.isNull()) {
        QMessageBox::warning(nullptr, "Error", "Failed to parse JSON data.\n");
        return;
    }

    //Extract data from the JSON document
        QJsonArray jsonArray = jsonDocument.array();
    for (const QJsonValue& value : jsonArray) {
        QJsonObject item = value.toObject();

        std::string type = item["type"].toString().toStdString();

        if (type == "Flight") {
            long travelid = item["travelId"].toVariant().toLongLong();
            long customerid = item["customerId"].toVariant().toLongLong();
            std::string name = item["customerName"].toString().toStdString();
            std::string id = item["id"].toString().toStdString();
            double price = item["price"].toDouble();
            std::string fromdate = item["fromDate"].toString().toStdString();
            std::string todate = item["toDate"].toString().toStdString();
            std::string fromdest = item["fromDest"].toString().toStdString();
            std::string todest = item["toDest"].toString().toStdString();
            std::string airline = item["airline"].toString().toStdString();
            std::string fromdestlatitude = item["fromDestLatitude"].toString().toStdString();
            std::string fromdestlongitude = item["fromDestLongitude"].toString().toStdString();
            std::string todestlatitude = item["toDestLatitude"].toString().toStdString();
            std::string todestlongitude = item["toDestLongitude"].toString().toStdString();


            /*
            Flightbooking::Flightbooking(std::string id, double price, std::string fromdate, std::string todate, long travelid, std::string predecessor1,
                                         std::string predecessor2, std::string fromdestination, std::string todestination,
                                         std::string airline, std::string fromdestlatitude, std::string fromdestlongitude, std::string todestlatitude,
                                         std::string todestlongitude):Booking(id,price,fromdate,todate,travelid,predecessor1,predecessor2),
                fromdestination(fromdestination), todestination(todestination),airline(airline),fromdestlatitude(fromdestlatitude),
                fromdestlongitude(fromdestlongitude),todestlatitude(todestlatitude),todestlongitude(todestlongitude){}*/

            std::string predecessor1; std::string predecessor2;
            if(item.contains("predecessor1")){
                predecessor1=item["predecessor1"].toString().toStdString();
            }else{
                predecessor1="";
            }
            if(item.contains("predecessor2")){
                predecessor2=item["predecessor2"].toString().toStdString();
            }else{
                predecessor2="";
            }

            if (findBooking(id)==nullptr) {
                booking = std::make_shared <Flightbooking>(id, price, fromdate, todate, travelid,predecessor1,predecessor2, fromdest, todest, airline, fromdestlatitude, fromdestlongitude, todestlatitude, todestlongitude);
                bookings.push_back(booking);
            }

            if (findCustomer(customerid)==nullptr) {
                customer = std::make_shared <Customer> (customerid, name);
                allcustomers.push_back(customer);
            }

            if (findTravel(travelid)==nullptr) {
                travel = std::make_shared<Travel>(customerid, travelid);
                alltravels.push_back(travel);
            }






        }





        else if (type == "Hotel") {
            long travelid = item["travelId"].toVariant().toLongLong();
            long customerid = item["customerId"].toVariant().toLongLong();
            std::string name = item["customerName"].toString().toStdString();
            std::string id = item["id"].toString().toStdString();
            double price = item["price"].toDouble();
            std::string fromdate = item["fromDate"].toString().toStdString();
            std::string todate = item["toDate"].toString().toStdString();
            std::string hotel = item["hotel"].toString().toStdString();
            std::string town = item["town"].toString().toStdString();
            std::string roomtype = item["roomType"].toString().toStdString();
            std::string hotellatitude = item["hotelLatitude"].toString().toStdString();
            std::string hotellongitude = item["hotelLongitude"].toString().toStdString();
            std::string predecessor1; std::string predecessor2;
            if(item.contains("predecessor1")){
                predecessor1=item["predecessor1"].toString().toStdString();
            }else{
                predecessor1="";
            }
            if(item.contains("predecessor2")){
                predecessor2=item["predecessor2"].toString().toStdString();
            }else{
                predecessor2="";
            }

            /*
            Hotelreservation::Hotelreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid, std::string hotel, std::string town,
                                               std::string roomtype,std::string hotellatitude,std::string hotellongitude,std::string predecessor1,std::string predecessor2):Booking(id, price, fromdate, todate,travelid,predecessor1,predecessor2),hotel(hotel),town(town),roomtype(roomtype),
                hotellatitude(hotellatitude),hotellongitude(hotellongitude) {}*/
            numhotel++;
            pricehotel += price;

            if (findBooking(id)==nullptr) {
                booking = std::make_shared<Hotelreservation>(id, price, fromdate, todate, travelid,hotel,town,roomtype, hotellatitude, hotellongitude,predecessor1,predecessor2);
                bookings.push_back(booking);
            }

            if (findCustomer(customerid)==nullptr) {
                customer = std::make_shared <Customer> (customerid, name);
                allcustomers.push_back(customer);
            }

            if (findTravel(travelid)==nullptr) {
                travel = std::make_shared<Travel>(customerid, travelid);
                alltravels.push_back(travel);
            }



        }



        else if (type == "RentalCar") {
            long travelid = item["travelId"].toVariant().toLongLong();
            long customerid = item["customerId"].toVariant().toLongLong();
            std::string name = item["customerName"].toString().toStdString();
            std::string id = item["id"].toString().toStdString();
            double price = item["price"].toDouble();
            std::string fromdate = item["fromDate"].toString().toStdString();
            std::string todate = item["toDate"].toString().toStdString();
            std::string pickup = item["pickupLocation"].toString().toStdString();
            std::string dropoff = item["returnLocation"].toString().toStdString();
            std::string company = item["company"].toString().toStdString();
            std::string vehicleClass = item["vehicleClass"].toString().toStdString();
            std::string pickuplatitude = item["pickupLatitude"].toString().toStdString();
            std::string pickuplongitude = item["pickupLongitude"].toString().toStdString();
            std::string returnlatitude = item["returnLatitude"].toString().toStdString();
            std::string returnlongiude = item["returnLongitude"].toString().toStdString();
            std::string predecessor1; std::string predecessor2;
            if(item.contains("predecessor1")){
                predecessor1=item["predecessor1"].toString().toStdString();
            }else{
                predecessor1="";
            }
            if(item.contains("predecessor2")){
                predecessor2=item["predecessor2"].toString().toStdString();
            }else{
                predecessor2="";
            }

            numcar++;
            pricecar += price;

            /*
            Hotelreservation::Hotelreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid, std::string hotel, std::string town,
                                               std::string roomtype,std::string hotellatitude,std::string hotellongitude,std::string predecessor1,std::string predecessor2):Booking(id, price, fromdate, todate,travelid,predecessor1,predecessor2),hotel(hotel),town(town),roomtype(roomtype),
                hotellatitude(hotellatitude),hotellongitude(hotellongitude) {}*/

            if (findBooking(id)==nullptr) {
                booking = std::make_shared <Rentalcarreservation>(id, price, fromdate, todate, travelid,predecessor1,predecessor2, pickup, dropoff, company, vehicleClass, pickuplatitude, pickuplongitude, returnlatitude, returnlongiude);
                bookings.push_back(booking);
            }
            if (findCustomer(customerid)==nullptr) {
                customer = std::make_shared <Customer> (customerid, name);
                allcustomers.push_back(customer);
            }

            if (findTravel(travelid)==nullptr) {
                travel = std::make_shared<Travel>(customerid, travelid);
                alltravels.push_back(travel);
            }

        }

    }

       for(auto& t:alltravels){

            for(auto& a:bookings){
            if(a->gettravelid()==t->gettravelid()){
                //t->bokingliste.clear();
                t->addBoking(a);
              //  t->topologicalsort();


               }
            }

        }
       for(auto& travel:alltravels){

            travel->topologicalsort();

       }


        int b=0;
        for(auto& c:allcustomers){
            for(auto& a:alltravels){

                if(c->getid()==a->getcustomerid()){
                    //c->travelliste.clear();
                    c->addTravel(a);
                }
            }
        }









    int c=0;int t=0;

    int k;
    for(auto& kunden:alltravels){
        if(kunden->gettravelid()==17){
            c=kunden->getBokingliste().size();
        }
        if(!kunden->getBokingliste().empty()){
            t+=kunden->getBokingliste().size();
        }

    }
    for(auto& travel:allcustomers){
        if(travel->getid()==1){
            k=travel->getTravelliste().size();
        }
        if(!travel->getTravelliste().empty()){
            b += travel->getTravelliste().size();
        }
    }





    QMessageBox messageBox;
    messageBox.setWindowTitle("Summary");
    messageBox.setText("Finished reading");
    messageBox.exec();


}

void Travelagency::flughafenreadfile(){

    QString filename = QFileDialog::getOpenFileName(nullptr, "Open Bookings JSON File", "", "JSON Files (*.json)");
    std::string filepath = filename.toStdString();

    QFile file(QString::fromStdString(filepath));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Error opening file.\n");
        return;
    }

    file.setTextModeEnabled(true);  // Enable text mode for proper encoding handling
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData.toUtf8());  // Convert to UTF-8 encoding
    if (jsonDocument.isNull()) {
        QMessageBox::warning(nullptr, "Error", "Failed to parse JSON data.\n");
        return;
    }

    QJsonArray jsonArray = jsonDocument.array();
    for (const QJsonValue& value : jsonArray) {
        QJsonObject airportObject = value.toObject();
        QString name = airportObject["name"].toString();
        QString iso_country = airportObject["iso_country"].toString();
        QString municipality = airportObject["municipality"].toString();
        QString iata_code = airportObject["iata_code"].toString();

        Airport airport(name.toStdString(), iso_country.toStdString(), municipality.toStdString(), iata_code.toStdString());
        allairports.push_back(airport);
    }



}

void Travelagency::addBoking(std::shared_ptr<Booking> booking)
{
    bookings.push_back(booking);
}

void Travelagency::addcustomer(std::shared_ptr<Customer> customer )
{
    allcustomers.push_back(customer);
}

void Travelagency::addtravel(std::shared_ptr<Travel> travel)
{
 alltravels.push_back(travel);
}
void Travelagency::sort(){

    QStringList sortOptions = { "price", "fromDate", "toDate", "travelId" };
    QString sortCriteria = QInputDialog::getItem(nullptr, "Sortierkriterium auswählen", "Bitte wählen Sie das Sortierkriterium:", sortOptions, 0, false);


    SortFunktor sortfunktor(sortCriteria.toStdString());
    std::sort(bookings.begin(), bookings.end(),sortfunktor);



}

void Travelagency::abcanayse()
{
    std::sort(allcustomers.begin(),allcustomers.end(),[](std::shared_ptr<Customer>c1,std::shared_ptr<Customer>c2){
            return c1->getcustomertotalprice()>c2->getcustomertotalprice();
        });

}


std::shared_ptr<Customer> Travelagency::findCustomer(long id) {

    for (auto& customer : allcustomers) {
        if (customer->getid() == id) {
            return customer;
        }
    }
    return nullptr;
}

std::shared_ptr<Travel> Travelagency::findTravel(long id) {
    for (auto& travel : alltravels) {
        if (travel->gettravelid() == id) {
            return travel;
        }
    }
    return nullptr;
}

std::shared_ptr<Booking> Travelagency::findBooking(std::string id) {
    for (auto& booki : bookings) {
        if (booki->getid()== id) {
            return booki;
        }
    }
    return nullptr;
}

int Travelagency::findAirFrance(std::string name)
{
    int c=0;
    for(auto& booki:bookings){
        if(std::shared_ptr<Flightbooking> flight = std::dynamic_pointer_cast<Flightbooking>(booki)){
            if(flight->getairline()==name){
                    c++;
            }
        }
    }return c;
}

int Travelagency::findeuropcar(std::string name)
{
    int c=0;
    for(auto& booki:bookings){
        if(std::shared_ptr<Rentalcarreservation> rental = std::dynamic_pointer_cast<Rentalcarreservation>(booki)){
            if(rental->getcompany()==name){
                    c++;
            }
        }
    }return c;

}


int Travelagency::findSuite(std::string name){
    int c=0;
    for(auto& booki:bookings){
        if(std::shared_ptr<Hotelreservation> hotel = std::dynamic_pointer_cast<Hotelreservation>(booki)){
        if(hotel->getroomtype()==name){
            c++;
        }

        if(hotel->getroomtype()=="Appartment"){
          c++;
        }
        }
    }
    return c;
}

int Travelagency::gettotalprice()
{
    int totalprice=0;
    for (auto each_booking:bookings){
        totalprice=totalprice + each_booking->d_getprice();
    }
    return totalprice;

}

std::vector<std::shared_ptr<Booking> > Travelagency::getBookings()
{
    return bookings;
}
