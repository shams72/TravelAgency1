#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H



#include "booking.h"
class Rentalcarreservation:public Booking
{
    std::string pickuplocation;
    std::string returnlocation;
    std::string company;
    std::string vehicleclass;
public:
    std::string getpickuplocation();
    std::string getreturnlocation();
    std::string getcompany();
    std::string getvehicleclass();
    Rentalcarreservation(std::string id, double price, std::string fromdate,
                         std::string todate,long travelid, std::string pickuplocation, std::string returnlocation, std::string company,std::string vehicleclass);
    std::string showdetails();


};
#endif
