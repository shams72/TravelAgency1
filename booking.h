
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
    std::string predecessor1;
    std::string predecessor2;
    int ord;
    QListWidget* liste;
    long travelId;
public:

    Booking(std::string id, double price, std::string fromdate, std::string todate);

    Booking(std::string id, double price, std::string fromdate, std::string todate,long travelId);

    Booking(std::string id, double price, std::string fromdate, std::string todate,long travelId,std::string predecessor1,std::string predecessor2);

    std::string getid();
    double d_getprice();
    std::string getprice();
    void setprice(double price){
        this->price=price;
    }
    std::string getfromdate();
    void setfromdate(std::string fromdate){
        this->fromdate=fromdate;
    }
    std::string gettodate();
    void settodate(std::string todate){
        this->todate=todate;
    }
    long gettravelid();
        virtual std::string showdetails();

    std::string getPredecessor1() ;
        std::string getPredecessor2() ;
    void setOrd(int newOrd);
    int getOrd() const;
};
#endif
