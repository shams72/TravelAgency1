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
#include<fehlermeldung.h>

#include"travel.h"
#include"customer.h"
void Travelagency::readfile() {
    int pricehotel = 0; int pricecar = 0; int priceflight = 0; int numhotel = 0; int numcar = 0; int numflight = 0; int line = 0;
    bool fehler = false; Customer* customer=nullptr;Travel* travel=nullptr;Customer cu;Travel tr;
    QString filename = QFileDialog::getOpenFileName(nullptr, "Open Bookings JSON File", "", "JSON Files (*.json)");
    std::string filepath = filename.toStdString();

    //std::string filename = "C://Users//Shams//Downloads//bookingsPraktikum2.json";
    std::ifstream file(filepath);

    if (!file.is_open()) {
        QMessageBox::warning(nullptr,"Error","Error opening file.\n");
        return;
    }

    Booking* booking=nullptr;
    json data;
    file >> data;

/*
     try {

            for (auto item : data) {

                std::string type = item["type"];

                if (type == "Flight") {

                    std::string id = item["id"];

                    double price1 = (item["price"]);
                    std::string price = std::to_string(price1);
                    std::string fromdate = item["fromDate"];
                    std::string todate = item["toDate"];
                    std::string fromdest = item["fromDest"];
                    std::string todest = item["toDest"];
                    std::string airline = item["airline"];
                    if (fromdest.size() != 3 || fromdest.empty()) {

                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 2);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (todest.size() != 3 || todest.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 6);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (airline.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        fehler = true;
                        std::string zeile = std::to_string(line + 0);

                        std::string mistake = error + zeile;

                        throw mistake;
                    }
                    else if (fromdate.empty() || fromdate.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 3);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (todate.empty() || todate.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 5);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (price.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 4);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (id.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 3);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }line += 10;
                }

                else if (type == "Hotel") {

                    std::string id = item["id"];
                    double price1 = (item["price"]);
                    std::string price = std::to_string(price1);
                    std::string fromdate = item["fromDate"];
                    std::string todate = item["toDate"];
                    std::string hotel = item["hotel"];
                    std::string town = item["town"];

                    if (fromdate.empty() || fromdate.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 3);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (todate.empty() || todate.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 5);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (price.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 4);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (id.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 3);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (hotel.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 7);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (town.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 6);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }line += 10;
                }

                else if (type == "RentalCar") {

                    std::string id = item["id"];
                    double price1 = (item["price"]);
                    std::string price = std::to_string(price1);
                    std::string fromdate = item["fromDate"];
                    std::string todate = item["toDate"];
                    std::string pickup = item["pickupLocation"];
                    std::string dropoff = item["returnLocation"];
                    std::string company = item["company"];
                    if (fromdate.empty() || fromdate.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 2);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (todate.empty() || todate.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 5);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (price.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 4);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (id.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 3);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (company.empty() || todate.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 6);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (dropoff.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 3);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }
                    else if (pickup.empty()) {
                        std::string error = "es gibt eine fehler an der zeile ";
                        std::string zeile = std::to_string(line + 4);
                        fehler = true;
                        std::string mistake = error + zeile;
                        throw mistake;
                    }line += 10;
                }
            }


        }
        catch (std::string error) {
            QString mistake = QString::fromStdString(error);
            QMessageBox msg;
            msg.setText(mistake);
            msg.exec();

        }
*/
    for (auto item : data) {
        std::string type = item["type"];

        if (type == "Flight") {
             long travelid =item["travelId"];
             long customerid =item["customerId"];
             std::string name=item["customerName"];
            std::string id = item["id"];
            double price = (item["price"]);
            std::string fromdate = item["fromDate"];
            std::string todate = item["toDate"];
            std::string fromdest = item["fromDest"];
            std::string todest = item["toDest"];
            std::string airline = item["airline"];
            //char bookingclass =item["bookingClass"].get<char>();           
            numflight++;
            priceflight += price;


            if(findBooking(id)==nullptr){
            booking = new Flightbooking(id, price, fromdate, todate,travelid, fromdest, todest, airline);
                bookings.push_back(booking);
            }
            if(findCustomer(customerid)==nullptr){
            customer = new Customer(customerid,name);
                allcustomers.push_back(customer);
            }

            if(findTravel(travelid)==nullptr){
            travel = new Travel(customerid,travelid);
                alltravels.push_back(travel);
            }





        }





        if (type == "Hotel") {
             long travelid =item["travelId"];
            long customerid =item["customerId"];
             std::string name=item["customerName"];

            std::string id = item["id"];
            double price = item["price"];
            std::string fromdate = item["fromDate"];
            std::string todate = item["toDate"];
            std::string hotel = item["hotel"];
            std::string town = item["town"];
            std::string roomtype = item["roomType"];
            numhotel++;
            pricehotel += price;

            if(findBooking(id)==nullptr){
                Booking* booking = new Hotelreservation(id, price, fromdate, todate,travelid,hotel, town, roomtype);
                bookings.push_back(booking);
            }
            if(findCustomer(customerid)==nullptr){
                customer = new Customer(customerid,name);
                allcustomers.push_back(customer);
            }

            if(findTravel(travelid)==nullptr){
                travel = new Travel(customerid,travelid);
                alltravels.push_back(travel);
            }



        }




        if(type=="RentalCar") {
             long travelid =item["travelId"];
            long customerid =item["customerId"];
             std::string name=item["customerName"];
            std::string id = item["id"];
            int price = item["price"];
            std::string fromdate = item["fromDate"];
            std::string todate = item["toDate"];
            std::string pickup = item["pickupLocation"];
            std::string dropoff = item["returnLocation"];
            std::string company = item["company"];
            std::string vehicleClass =item["vehicleClass"];
            numcar++;
            pricecar += price;



            if(findBooking(id)==nullptr){
                Booking* booking = new Rentalcarreservation(id, price, fromdate, todate,travelid, pickup, dropoff, company,vehicleClass);
                bookings.push_back(booking);
            }
            if(findCustomer(customerid)==nullptr){
                customer = new Customer(customerid,name);
                allcustomers.push_back(customer);
            }

            if(findTravel(travelid)==nullptr){
                travel = new Travel(customerid,travelid);
                alltravels.push_back(travel);
            }
        }
    }

        for(auto t:alltravels){
            for(auto a:bookings){
                if(a->gettravelid()==t->gettravelid()){
                    t->addBoking(a);
                }
            }

        }
        int b=0;
        for(auto c:allcustomers){
            for(auto a:alltravels){

                if(c->getid()==a->getcustomerid()){
                    c->addTravel(a);
                }
            }
        }








    int c=0;int t=0;

    int d=0;int k;
    for(auto kunden:alltravels){
        if(kunden->gettravelid()==17){
            c=kunden->bokingliste.size();
        }
        if(!kunden->bokingliste.empty()){
            t+=kunden->bokingliste.size();
        }

    }
    for(auto travel:allcustomers){
        if(travel->getid()==1){
            k=travel->travelliste.size();
        }
        if(!travel->travelliste.empty()){
            b += travel->travelliste.size();
        }
    }


    QMessageBox messageBox;
    messageBox.setWindowTitle("Summary");
    messageBox.setText(QString("Total Car: %1\nTotal price: %2\nTotal Flight: %3\nTotal price: %4\nTotal Hotel: %5\nTotal price: %6\nKunden: %7\nTravels: %8\nKunden 1:%9\nReisen 17:%10")
                           .arg(numcar).arg(pricecar).arg(numflight).arg(priceflight).arg(numhotel).arg(pricehotel).arg(b).arg(t).arg(k).arg(c));

    messageBox.exec();

}

Customer* Travelagency::findCustomer(long id){

    for(auto customer:allcustomers){
        if(customer->getid()==id){
            return customer;
        }
    }return nullptr;

}

Travel* Travelagency::findTravel(long id){

    for(auto travel:alltravels){
        if(travel->gettravelid()==id){
            return travel;
        }
    }return nullptr;
}

Booking* Travelagency::findBooking(std::string id){

    for(auto booking:bookings){
        if(booking->getid()==id){
            return booking;
        }
    }return nullptr;
}
