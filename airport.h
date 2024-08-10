
#ifndef AIRPORT_H
#define AIRPORT_H
#include<iostream>



class Airport
{
    std::string name;
    std::string iso_country;
    std::string municipality;
    std::string iata_code;


public:
    Airport(std::string name,std::string iso_country,std::string municipality,std::string iata_code):
        name(name),iso_country(iso_country),municipality(municipality),iata_code(iata_code) {}
    std::string getiatacode();
    void setiata_code(std::string iata_code);
    Airport();
};

#endif // AIRPORT_H
