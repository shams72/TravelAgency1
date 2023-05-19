
#ifndef TRAVEL_H
#define TRAVEL_H
#include<booking.h>



class Travel
{
private:

    long id;
    long customerID;

public:
    Travel(long customerID,long id):customerID(customerID),id(id){};
    void addBoking(Booking* booking);
    int gettravelid();
    long getcustomerid();
    Travel();
    std::vector<Booking*>bokingliste;


};

#endif // TRAVEL_H
