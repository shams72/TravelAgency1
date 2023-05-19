#include "car_rental.h"
Rentalcarreservation::Rentalcarreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid,
    std::string pickuplocation, std::string returnlocation, std::string company,std::string vehicleclass)
    : Booking(id, price, fromdate, todate,travelid), pickuplocation(pickuplocation), returnlocation(returnlocation),
    company(company),vehicleclass(vehicleclass){}

std::string Rentalcarreservation::showdetails(){
    std::string result;
    result = Booking::showdetails();
    result += "Pickuplocation :"+std::string(pickuplocation)+"\n";
    result += "returnlocation :"+std::string(returnlocation)+"\n";
    result += "company        :"+ std::string(company)+"\n";
    result += "vehivleclass   :"+std::string(vehicleclass)+"\n";
    return result;
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
