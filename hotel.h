
#ifndef HOTEL_H
#define HOTEL_H

#include "Booking.h"
class Hotelreservation:public Booking
{
    std::string hotel;
    std::string town;
    std::string roomtype;
public:

    std::string gethotel();
    std::string gettown();
    std::string getroomtype();
    Hotelreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid,std::string hotel, std::string town,std::string roomtype);
    std::string showdetails();
};

#endif // HOTEL_H
