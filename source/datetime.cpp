//
// Created by andre on 4/28/2019.
//
#include "datetime.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using std::string;
using std::endl;
using std::cout;


DateTime::DateTime(){

}

DateTime::DateTime(int month, int date, int year, int hour, int minute, bool am)
        : _month(month), _date(date), _year(year), _hour(hour), _am(am){}

void DateTime::setDateTime(int month, int date, int year, int hour, int minute, bool am){
    _month = month;
    _date = date;
    _year = year;
    _hour = hour;
    _am = am;
}

std::vector<int> DateTime::getDateTime(){
    return std::vector<int> {_month, _date, _year, _hour, _am};
}
