
#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <vector>
#include<QList>
#include"Booking.h"
#include<Travel.h>
#include<customer.h>
#include<airport.h>
#include<memory>
#include<booking.h>
class Travelagency
{

private:


     std::vector<std::shared_ptr<Customer>> allcustomers;
     std::vector<std::shared_ptr<Travel>> alltravels;
     std::vector<Airport>allairports;
     std::vector<std::shared_ptr<Booking>>bookings;
     //Travelagency::Travelagency(){};

public:
     //Travelagency::Travelagency(){};
    void addCustomer(Customer* customer);

    void readfile();
    void flughafenreadfile();

    void addBoking(std::shared_ptr<Booking> booking);
    void addcustomer(std::shared_ptr<Customer> customer);
    void addtravel(std::shared_ptr<Travel> travel);
    std::shared_ptr<Customer> findCustomer(long id);
    void sort();

    void abcanayse();
    std::shared_ptr<Travel> findTravel(long id);
    std::shared_ptr<Booking> findBooking(std::string id);
    QListWidget* liste();
    std::shared_ptr<Booking> anzeigeliste(std::shared_ptr<Booking> books);

    int findeuropcar(std::string name);
    int findAirFrance(std::string name);
    int findSuite(std::string name);
    int gettotalprice();

    std::vector<std::shared_ptr<Booking> > getBookings() ;
    std::vector<std::shared_ptr<Customer> > getAllcustomers() ;
    std::vector<std::shared_ptr<Travel> > getAlltravels();
    std::vector<Airport> getAllairports();
};
#endif
