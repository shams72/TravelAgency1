
#include "customer.h"

Customer::Customer()
{



}
std::string Customer::getname(){
    return name;
}

int Customer::getcustomertotalprice()
{
    int totalcustomerprice=0;
    for(auto& customer : travelliste ){
        totalcustomerprice=totalcustomerprice + customer->gettravelltotalprice();
    }
    return totalcustomerprice;
}
long Customer::getid(){
    return id;
}

std::vector<std::shared_ptr<Travel> > Customer::getTravelliste()
{
    return travelliste;
}

void Customer::addTravel(std::shared_ptr<Travel> travel) {
    bool found = false;
    for (auto a : travelliste) {
        if (a->gettravelid() == travel->gettravelid()) {
            found = true;
            break;
        }
    }

    if (!found) {
        travelliste.push_back(travel);
    }
}


