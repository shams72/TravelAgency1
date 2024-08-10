
#ifndef HOTEL_H
#define HOTEL_H

#include "Booking.h"
class Hotelreservation:public Booking
{
    std::string hotel;
    std::string town;
    std::string roomtype;
    std::string hotellongitude;
    std::string hotellatitude;
public:

    std::string gethotel();
    std::string gettown();
    std::string getroomtype();
    std::string gethotellatitude();
    std::string gethotellongitude();

    void sethotel(std::string hotel){
        this->hotel=hotel;
    }
    void settown(std::string town){
        this->town=town;
    }
    void setroomtype(std::string roomtype){
        this->roomtype=roomtype;
    }
    Hotelreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid,std::string hotel, std::string town,std::string roomtype,std::string hotellatitude,std::string hotellongitude);
    Hotelreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid,std::string hotel, std::string town,
                     std::string roomtype,std::string hotellatitude,std::string hotellongitude,std::string predecessor1,std::string predecessor2);

    std::string showdetails();
};

#endif // HOTEL_H
