

#include "hotel.h"


Hotelreservation::Hotelreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid, std::string hotel, std::string town,
                                   std::string roomtype):Booking(id, price, fromdate, todate,travelid),hotel(hotel),town(town),roomtype(roomtype) {}

std::string Hotelreservation::showdetails(){

    std::string result;
    result = Booking::showdetails();
    result += "From     :"+std::string(hotel)+"\n";
    result += "town     :"+std::string(town)+"\n";
    result += "roomtype :" + std::string(roomtype)+"\n";

    return result;

}


std::string  Hotelreservation:: gethotel(){
    return hotel;
}
std::string  Hotelreservation::gettown(){
    return town;
}
std::string  Hotelreservation::getroomtype(){
    if(roomtype=="EZ"){
        return "Einzelzimmer";
    }
    if(roomtype=="DoppelZimmer"){
        return "Dppelzimmer";
    }
    if(roomtype=="AP"){
        return "Aprtment";
    }
    if(roomtype=="SU"){
        return "Suite";
    }


}
