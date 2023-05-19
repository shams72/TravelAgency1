
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<Travel.h>



class Customer
{
private:

    long id;
    std::string name;

public:
    Customer(long id,std::string name):id(id),name(name){};
    void addTravel(Travel* travel);
    long getid();
    Customer();
    std::string getname();
    std::vector<Travel*>travelliste;
};

#endif // CUSTOMER_H
