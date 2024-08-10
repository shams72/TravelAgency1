
#ifndef BOOKING_TRAVEL_H
#define BOOKING_TRAVEL_H
#include<iostream>



class Booking_Travel
{

    std::string bookingid;
    int travelid;
public:
    Booking_Travel();
    Booking_Travel(std::string bookingid,int travelid):bookingid(bookingid),travelid(travelid){}
    int gettravelid(){
        return travelid;
    }
    std::string getbookingid(){
        return bookingid;
    }

};

#endif // BOOKING_TRAVEL_H
