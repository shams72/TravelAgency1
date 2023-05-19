
#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <vector>
#include<QList>
#include"Booking.h"
#include<Travel.h>
#include<customer.h>

class Travelagency
{
public:

    std::vector<Customer*>allcustomers;
    std::vector<Travel*>alltravels;


public:

    void readfile();
    std::vector<Booking*>bookings;
    Booking* findBooking(std::string id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);


    std::vector<Booking*>getbookings();
    QListWidget* liste();
    Booking* anzeigeliste(Booking* books);


};
#endif
