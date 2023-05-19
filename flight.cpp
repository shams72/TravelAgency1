#include "flight.h"


Flightbooking::Flightbooking(std::string id, double price, std::string fromdate, std::string todate,long travelid
                             ,std::string fromdestination, std::string todestination, std::string airline):Booking(id,price,fromdate,todate,travelid),
    fromdestination(fromdestination), todestination(todestination),airline(airline){}

std::string Flightbooking::showdetails(){
    std::string result;
    result  = Booking::showdetails();
    result+="Fromdestination  :" + std::string(fromdestination)+"\n";
    result+="Todestination    :" + std::string(todestination)+"\n";
    result+="Airline          :" + std::string(airline)+"\n";
    //result+="Booking class"+std::string(1,bookingclass) +"\n";
    return result;
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
