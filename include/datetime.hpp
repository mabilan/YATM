//
// Created by andre on 4/28/2019.
//

#ifndef YATM_DATETIME_H
#define YATM_DATETIME_H

#include <vector>

class Time{
public:
    Time(int month, int date, int year);
    Time(const Time &obj);
    ~Time() = default;

    void setTime(int month, int date, int year);
    std::vector<int> getTime();
private:
    int _month;
    int _date;
    int _year;
};


class Date{
public:
    Date() = default;
    ~Date() = default;
    Date(int month, int date, int year);

    void setDate(int month, int date, int year);
    void currentTime();
    std::vector<int> getDate();
    void addDate(Time time);

private:
    int _month;
    int _date;
    int _year;
    std::vector<int> _daysinmonths {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};


#endif //YATM_DATETIME_H

