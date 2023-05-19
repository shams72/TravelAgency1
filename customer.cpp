
#include "customer.h"

Customer::Customer()
{



}
std::string Customer::getname(){
    return name;
}
long Customer::getid(){
    return id;
}

void Customer::addTravel(Travel *travel){
    travelliste.push_back(travel);
}
