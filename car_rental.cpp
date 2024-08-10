#include "car_rental.h"
Rentalcarreservation::Rentalcarreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid,
    std::string pickuplocation, std::string returnlocation, std::string company,std::string vehicleclass,std::string pickuplatitude,std::string pickuplongitude,std::string returnlatitude,
                                           std::string returnlongiude)
    : Booking(id, price, fromdate, todate,travelid), pickuplocation(pickuplocation), returnlocation(returnlocation),
    company(company),vehicleclass(vehicleclass),pickuplatitude(pickuplatitude),pickuplongitude(pickuplongitude),returnlatitude(returnlatitude),returnlongiude(returnlongiude){}


Rentalcarreservation::Rentalcarreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid,std::string predecessor1,std::string predecessor2
                                           ,std::string pickuplocation, std::string returnlocation, std::string company,std::string vehicleclass,std::string pickuplatitude,std::string pickuplongitude,std::string returnlatitude,
                                           std::string returnlongiude)
    : Booking(id, price, fromdate, todate,travelid,predecessor1,predecessor2), pickuplocation(pickuplocation), returnlocation(returnlocation),
    company(company),vehicleclass(vehicleclass),pickuplatitude(pickuplatitude),pickuplongitude(pickuplongitude),returnlatitude(returnlatitude),returnlongiude(returnlongiude){}

std::string Rentalcarreservation::showdetails(){
    std::string result;
    result = Booking::showdetails();
    result += "Pickuplocation :"+std::string(pickuplocation)+"\n";
    result += "returnlocation :"+std::string(returnlocation)+"\n";
    result += "company        :"+ std::string(company)+"\n";
    result += "vehivleclass   :"+std::string(vehicleclass)+"\n";
    return result;
}
std::string Rentalcarreservation::getpickuplatitude(){
    return pickuplatitude;
}
std::string Rentalcarreservation::getpickuplongitude(){
    return pickuplongitude;
}
std::string Rentalcarreservation::getreturnlatitude(){
    return returnlatitude;
}
std::string Rentalcarreservation::getreturnlongiude(){
    return returnlongiude;
}
std::string Rentalcarreservation::getpickuplocation(){
    return pickuplocation;
}
std::string Rentalcarreservation::getreturnlocation(){
    return returnlocation;
}
std::string Rentalcarreservation::getcompany(){
    return company;
}
std::string Rentalcarreservation::getvehicleclass(){
    return vehicleclass;
}
