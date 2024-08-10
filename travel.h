
#ifndef TRAVEL_H
#define TRAVEL_H
#include<booking.h>
#include"graph.h"
#include"flight.h"

class Travel
{
private:

    long id;
    long customerID;
    std::vector<std::shared_ptr<Booking>>bokingliste;
    std::vector<int> dependencies;
     std::vector<int> sortiere();
    Graph<std::shared_ptr<Booking>, 20> graph;
    //Graph graph;
public:
    Travel(long customerID,long id):customerID(customerID),id(id){};
    void addBoking(std::shared_ptr<Booking> booking);
    int gettravelid();
    long getcustomerid();
    int gettravelltotalprice();
    std::shared_ptr<Booking> findBookingByID(std::string bookingID);
    Travel();
    bool checkroundtrip();
    void topologicalsort();
    int searchindex(std::string id);
    std::vector<std::shared_ptr<Booking> > getBokingliste();
    bool checkenoughhotels();
    bool checknouselessrentalcar();
    std::shared_ptr<Flightbooking> findfirstflight();
    std::shared_ptr<Flightbooking> findlastflight();
    bool checkoverflowhotel();

};

#endif // TRAVEL_H
