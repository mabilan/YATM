//
// Created by andre on 4/28/2019.
//
#include "datetime.hpp"
#include <iostream>
#include <string>
#include <ctime>

using std::string;


Time::Time(const int hour, const int date): _hour(hour), _date(date){}

Time::Time(const Time &obj){
    _hour = obj._hour;
    _date = obj._date;
}

void Time::setTime(const int hour, const int date){
    _hour = hour;
    _date = date;
}

std::vector<int> Time::getTime()const{
    return std::vector<int> {_hour, _date};
}

void Date::currentDate(){
    struct tm *currtime;
    std::time_t tim;
    time(&tim);
    currtime = localtime(&tim);

    _hour = currtime->tm_hour;
    _date = currtime->tm_mday;
    _month = currtime->tm_mon + 1;
    _year = currtime->tm_year + 1900;
}

Date::Date(int hour, int month, int date, int year)
        :_hour(hour), _month(month), _date(date), _year(year){}

void Date::setDate(const int hour, const int month, const int date, const int year){
    _hour = hour;
    _month = month;
    _date = date;
    _year = year;
}

std::vector<int> Date::getDate() const{
    return std::vector<int> {_hour, _month, _date, _year};
}


void Date::addDate(const Time time){
    std::vector<int> dt = time.getTime();
    _hour += dt[0];

    while(true){
        if(_hour > 23){
            _hour -= 24;
            _date++;
        }else{
            break;
        }
    }
    _date += dt[1];
    while(true){
        if(_date > _daysinmonths[_month-1]){
            _date -= _daysinmonths[_month-1];
            _month++;
        }else{
            break;
        }
    }

    if(_month > 12){
        int overflow = _month/12;
        _month -= 12*overflow;
        _year += overflow;
    }
}

Time Date::getTimeDiff (const Date &dt) const{
    std::vector<int> temp = dt.getDate();

    int temphour = _hour - temp[0];
    int tempdate = _date - temp[2];

    while(true){
        if(temphour < 0){
            temphour += 24;
            tempdate--;
        }else{
            break;
        }
    }

    int tempmonth = _month;
    int tempyear = _year;

    while(true)
    {
        if((tempdate < 0) || (tempmonth != temp[1]) || (tempyear != temp[3])){
            if(tempmonth-1 < 1){
                tempdate += 31;
                tempmonth = 12;
                tempyear--;
            }else{
                tempdate += _daysinmonths[tempmonth-2];
                tempmonth--;
            }
        }else{
            break;
        }

    }

    Time test(temphour, tempdate);
    return test;
}

