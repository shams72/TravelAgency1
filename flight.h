
#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include "Booking.h"
class Flightbooking:public Booking
{
    std::string fromdestination;
    std::string todestination;
    std::string airline;
    std::string fromdestlatitude;
    std::string fromdestlongitude;
    std::string todestlatitude;
    std::string todestlongitude;


public:
    std::string getfromdestination();
    std::string gettodestination();
    std::string getairline();
    void setfromdestination(std::string fromdestnation){
        this->fromdestination=fromdestnation;
    }
    void settodestination(std::string todestination){
        this->todestination=todestination;
    }
    void setairline(std::string airline){
        this->airline=airline;
    }

    std::string getfromdestlatitude();


    std::string  gettodestlongitude();
    std::string  gettodestlatitude();

    Flightbooking(std::string id, double price, std::string fromdate, std::string todate,long travelid,std::string fromdestination, std::string todestination,
    std::string airline,std::string fromdestlatitude, std::string fromdestlongitude,std::string todestlatitude,
                  std::string todestlongitude);


    Flightbooking(std::string id, double price, std::string fromdate, std::string todate,long travelid,std::string predecessor1,std::string predecessor2,
                  std::string fromdestination, std::string todestination,
                  std::string airline,std::string fromdestlatitude, std::string fromdestlongitude,std::string todestlatitude,
                  std::string todestlongitude);

    std::string showdetails();
};
#endif
