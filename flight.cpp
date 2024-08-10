#include "flight.h"


Flightbooking::Flightbooking(std::string id, double price, std::string fromdate, std::string todate,long travelid,std::string fromdestination, std::string todestination,
                             std::string airline,std::string fromdestlatitude, std::string fromdestlongitude,std::string todestlatitude,
                             std::string todestlongitude):Booking(id,price,fromdate,todate,travelid),
    fromdestination(fromdestination), todestination(todestination),airline(airline),fromdestlatitude(fromdestlatitude),
    fromdestlongitude(fromdestlongitude),todestlatitude(todestlatitude),todestlongitude(todestlongitude){}

Flightbooking::Flightbooking(std::string id, double price, std::string fromdate, std::string todate, long travelid, std::string predecessor1,
                             std::string predecessor2, std::string fromdestination, std::string todestination,
                             std::string airline, std::string fromdestlatitude, std::string fromdestlongitude, std::string todestlatitude,
                             std::string todestlongitude):Booking(id,price,fromdate,todate,travelid,predecessor1,predecessor2),
    fromdestination(fromdestination), todestination(todestination),airline(airline),fromdestlatitude(fromdestlatitude),
    fromdestlongitude(fromdestlongitude),todestlatitude(todestlatitude),todestlongitude(todestlongitude){}


std::string Flightbooking::showdetails(){
    std::string result;
    result  = Booking::showdetails();
    result+="Fromdestination  :" + std::string(fromdestination)+"\n";
    result+="Todestination    :" + std::string(todestination)+"\n";
    result+="Airline          :" + std::string(airline)+"\n";
    //result+="Booking class"+std::string(1,bookingclass) +"\n";
    return result;
}

std::string Flightbooking::getfromdestlatitude(){
    return fromdestlatitude;
}
std::string Flightbooking::gettodestlatitude(){
    return todestlatitude;
}
std::string  Flightbooking::gettodestlongitude(){
    return todestlongitude;
}


std::string Flightbooking::getfromdestination(){
    return fromdestination;
}
std::string Flightbooking::gettodestination(){
    return todestination;
}
std::string Flightbooking::getairline(){
    return airline;
}
