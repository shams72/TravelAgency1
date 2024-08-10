
#include "airport.h"

Airport::Airport()
{

}

std::string Airport::getiatacode(){
    return iata_code;
}

void Airport::setiata_code(std::string iata_code){
    this->iata_code=iata_code;
}
