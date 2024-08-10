

#include "hotel.h"


Hotelreservation::Hotelreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid, std::string hotel, std::string town,
                                   std::string roomtype,std::string hotellatitude,std::string hotellongitude):Booking(id, price, fromdate, todate,travelid),hotel(hotel),town(town),roomtype(roomtype),
    hotellatitude(hotellatitude),hotellongitude(hotellongitude) {}


Hotelreservation::Hotelreservation(std::string id, double price, std::string fromdate, std::string todate,long travelid, std::string hotel, std::string town,
                                   std::string roomtype,std::string hotellatitude,std::string hotellongitude,std::string predecessor1,std::string predecessor2):Booking(id, price, fromdate, todate,travelid,predecessor1,predecessor2),hotel(hotel),town(town),roomtype(roomtype),
    hotellatitude(hotellatitude),hotellongitude(hotellongitude) {}


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
        return "Doppelzimmer";
    }
    if(roomtype=="AP"){
        return "Aprtment";
    }
    if(roomtype=="SU"){
        return "Suite";
    }


}

std::string Hotelreservation::gethotellatitude()
{
    return hotellatitude;
}

std::string Hotelreservation::gethotellongitude(){
    return hotellongitude;
}
