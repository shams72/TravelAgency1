
#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include "Booking.h"
class Flightbooking:public Booking
{
    std::string fromdestination;
    std::string todestination;
    std::string airline;


public:
    std::string getfromdestination();
    std::string gettodestination();
    std::string getairline();
    Flightbooking(std::string id, double price, std::string fromdate, std::string todate,long travelid,std::string fromdestination, std::string todestination, std::string airline);
    std::string showdetails();
};
#endif
