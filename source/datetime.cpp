//
// Created by andre on 4/28/2019.
//
#include "datetime.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <tuple>

using std::string;
using std::endl;
using std::cout;


Time::Time(int month, int date, int year): _month(month), _date(date), _year(year){}

void Time::setTime(int month, int date, int year){
    _month = month;
    _date = date;
    _year = year;
}

std::vector<int> Time::getTime(){
    return std::vector<int> {_month, _date, _year};
}




void Date::currentTime(){
    struct tm *currtime;
    std::time_t tim;
    time(&tim);
    currtime = localtime(&tim);

    _date = currtime->tm_mday;
    _month = currtime->tm_mon + 1;
    _year = currtime->tm_year + 1900;
}

Date::Date(int month, int date, int year)
        : _month(month), _date(date), _year(year){}

void Date::setDate(int month, int date, int year){
    _month = month;
    _date = date;
    _year = year;
}

std::vector<int> Date::getDate(){
    return std::vector<int> {_month, _date, _year};
}


void Date::addDate(Time time){
    std::vector<int> dt = time.getTime();

    _date += dt[1];

    if(_date > _daysinmonths[_month-1]){
        _date -= _daysinmonths[_month-1];
        _month++;
    }

    _month += dt[0];
    _year += dt[2];

    if(_month > 12){
        int overflow = _month/12;
        _month -= 12*overflow;
        _year += overflow;
    }
}















