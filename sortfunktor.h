#ifndef SORTFUNKTOR_H
#define SORTFUNKTOR_H


#include"booking.h"
#include "json.hpp"
#include <fstream>

#include <algorithm>
#include<QDate>
using json = nlohmann::json;

class SortFunktor
{
private:
    std::string sortCriteria;

public:
    SortFunktor(std::string criteria) : sortCriteria(criteria) {}

    bool operator()(const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2)
    {
        if (sortCriteria == "price"){
            return booking1->d_getprice() < booking2->d_getprice();
        }
        else if (sortCriteria == "fromDate"){
             QDate start_fromDate1 =QDate::fromString(QString::fromStdString(booking1->getfromdate()),"yyyyMMdd");
             QDate start_fromDate2 =QDate::fromString(QString::fromStdString(booking2->getfromdate()),"yyyyMMdd");

            return start_fromDate1 < start_fromDate2;
        }
        else if (sortCriteria == "toDate"){
            QDate star_enddate1  =QDate::fromString(QString::fromStdString(booking1->gettodate()),"yyyyMMdd");
            QDate star_enddate2  =QDate::fromString(QString::fromStdString(booking2->gettodate()),"yyyyMMdd");

            return star_enddate1 < star_enddate2;
        }
        else if (sortCriteria == "travelId"){
            return booking1->gettravelid()< booking2->gettravelid();
        }

        return false;
    }
};
#endif // SORTFUNKTOR_H
