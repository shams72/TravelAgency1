
#include "travel.h"

Travel::Travel()
{

}

int Travel::gettravelid(){
    return id;
}

void Travel::addBoking(Booking* booking){
    bokingliste.push_back(booking);
}

long Travel::getcustomerid(){
    return customerID;
}
