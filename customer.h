
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<Travel.h>



class Customer
{
private:

    long id;
    std::string name;
    std::vector<std::shared_ptr<Travel>>travelliste;
public:
    Customer(long id,std::string name):id(id),name(name){};
    void addTravel(std::shared_ptr<Travel> travel) ;

    void setname(std::string name){
        this->name=name;
    }
    long getid();
    Customer();
    std::string getname();
    int getcustomertotalprice();
    std::vector<std::shared_ptr<Travel> > getTravelliste();
};

#endif // CUSTOMER_H
