#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H



#include "booking.h"
class Rentalcarreservation:public Booking
{
    std::string pickuplocation;
    std::string returnlocation;
    std::string company;
    std::string vehicleclass;
    std::string pickuplatitude ;
    std::string pickuplongitude;
    std::string returnlatitude;
    std::string returnlongiude;

public:
    std::string getpickuplocation();    
    std::string getreturnlocation();
    std::string getcompany();
    std::string getvehicleclass();

    void setpickuplocation(std::string pickuplocation){
        this->pickuplocation=pickuplocation;
    }

    void setreturnlocation(std::string returnlocation){
        this->returnlocation=returnlocation;
    }
    void setcompany(std::string company){
        this->company=company;
    }

    void setvehicleclass(std::string vehicleclass){
        this->vehicleclass=vehicleclass;
    }

    std::string getpickuplatitude();
    std::string  getpickuplongitude();
    std::string getreturnlatitude();
    std::string getreturnlongiude();
    Rentalcarreservation(std::string id, double price, std::string fromdate,
                         std::string todate,long travelid, std::string pickuplocation, std::string returnlocation, std::string company,
                         std::string vehicleclass,std::string pickuplatitude,std::string pickuplongitude,std::string returnlatitude,
                         std::string returnlongiude);

    Rentalcarreservation(std::string id, double price, std::string fromdate,
                         std::string todate,long travelid,std::string predecessor1,std::string predecessor2, std::string pickuplocation, std::string returnlocation, std::string company,
                         std::string vehicleclass,std::string pickuplatitude,std::string pickuplongitude,std::string returnlatitude,
                         std::string returnlongiude);
    std::string showdetails();


};
#endif
