#include "booking.h"



std::string Booking::getPredecessor1()
{
    return predecessor1;
}

std::string Booking::getPredecessor2()
{
    return predecessor2;
}

void Booking::setOrd(int newOrd)
{
    ord = newOrd;
}

int Booking::getOrd() const
{
    return ord;
}

Booking::Booking(std::string id, double price, std::string fromdate, std::string todate) :id(id), price(price), fromdate(fromdate),
    todate(todate) {}


Booking::Booking(std::string id, double price, std::string fromdate, std::string todate,long travelId) :id(id), price(price), fromdate(fromdate),
    todate(todate),travelId(travelId){}

Booking::Booking(std::string id, double price, std::string fromdate, std::string todate,long travelId,std::string predecessor1,std::string predecessor2) :id(id), price(price), fromdate(fromdate),
    todate(todate),travelId(travelId),predecessor1(predecessor1),predecessor2(predecessor2) {}
std::string Booking::getid(){

    return id;
}
std::string Booking::showdetails(){
    std::string result;
    result = "id" + id + "\n";
    std::string price_s=std::to_string(price);
    result +="price"+ price_s+"\n";
    result +="fromdate"+std::string(fromdate)+"\n";
    result +="todate"+std::string(todate)+"\n";
    return result;
}


std::string Booking::getprice(){
    std::string price1 =std::to_string(price);
    return price1;
}
double Booking:: d_getprice(){
    return price;
}
std::string Booking::getfromdate(){
    return fromdate;
}
std::string Booking::gettodate(){
    return todate;
}

long Booking::gettravelid(){
    return travelId;
}
