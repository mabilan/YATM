//
// Created by andre on 4/28/2019.
//
#include "datetime.hpp"
#include <iostream>
#include <string>
#include <ctime>

using std::string;


Time::Time(const int hour, const int minute): _hour(hour), _minute(minute){}

Time::Time(const Time &obj)
{
    _hour = obj._hour;
    _minute = obj._minute;
}

void Time::setTime(const int hour, const int minute)
{
    _hour = hour;
    _minute = minute;
}

std::vector<int> Time::getTime()const
{
    return std::vector<int> {_hour, _minute};
}


Date::Date(int day, int month, int year)
        :_day(day),  _month(month), _year(year){}

void Date::currentDate()
{
    struct tm *currtime;
    std::time_t tim;
    time(&tim);
    currtime = localtime(&tim);

    _day = currtime->tm_mday;
    _month = currtime->tm_mon + 1;
    _year = currtime->tm_year + 1900;
}

void Date::setDate(const int day, const int month, const int year)
{
    _day = day;
    _month = month;
    _year = year;
}

std::vector<int> Date::getDate() const
{
    return std::vector<int> {_day, _month, _year};
}

bool Date::isDayValid(int d) const
{
    if(_day > d)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Date::isValidDate()
{
    if(_day < 1)
    {
        return false;
    }

    if(_month == 1)
    {
        return isDayValid(31);
    }
    else if(_month == 2)
    {
        if(_year % 4 != 0)
        {
            return isDayValid(28);
        }
        else if(_year % 100 != 0)
        {
            return isDayValid(29);
        }
        else if(_year % 400 != 0)
        {
            return isDayValid(28);
        }
        else
        {
            return isDayValid(29);
        }
    }
    else if(_month == 3)
    {
        return isDayValid(31);
    }
    else if(_month == 4)
    {
        return isDayValid(30);
    }
    else if(_month == 5)
    {
        return isDayValid(31);
    }
    else if(_month == 6)
    {
        return isDayValid(30);
    }
    else if(_month == 7)
    {
        return isDayValid(31);
    }
    else if(_month == 8)
    {
        return isDayValid(31);
    }
    else if(_month == 9)
    {
        return isDayValid(30);
    }
    else if(_month == 10)
    {
        return isDayValid(31);
    }
    else if(_month == 11)
    {
        return isDayValid(30);
    }
    else if(_month == 12)
    {
        return isDayValid(31);
    }
    else
    {
        return false;
    }
}