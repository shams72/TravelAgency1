
#ifndef BOOKING_H
#define BOOKING_H
#include<iostream>
#include<string>
#include<QListWidget>
class Booking
{
protected:
    std::string id;
    double price;
    std::string fromdate;
    std::string todate;
    QListWidget* liste;
    long travelId;
public:

    Booking(std::string id, double price, std::string fromdate, std::string todate);
    Booking(std::string id, double price, std::string fromdate, std::string todate,long travelId);
    std::string getid();
    std::string getprice();
    std::string getfromdate();
    std::string gettodate();
    long gettravelid();
        virtual std::string showdetails();

};
#endif
