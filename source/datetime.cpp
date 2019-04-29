//
// Created by andre on 4/28/2019.
//

#include "datetime.hpp"


Date::Date(int month, int date, int year, int hour, int minute, bool AM)
        : _month(month), _date(date), _year(year), _hour(hour), _AM(AM){}

Date::setDateTime(int month, int date, int year, int hour, int minute, bool AM)
        : _month(month), _date(date), _year(year), _hour(hour), _AM(AM){}

Date::getDateTime(){
    return std::vector<int> {_month, _date, _year, _hour, _AM};
}
