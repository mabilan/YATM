//
// Created by andre on 4/28/2019.
//

#ifndef YATM_DATETIME_H
#define YATM_DATETIME_H

#include <vector>

class Time{
public:
    Time(int hour, int date);
    Time(const Time &obj);
    ~Time() = default;

    void setTime(int hour, int date);
    std::vector<int> getTime()const;
private:
    int _hour;
    int _date;
};


class Date{
public:
    Date() = default;
    ~Date() = default;

    Date(int hour, int month, int date, int year);

    void setDate(int hour, int month, int date, int year);
    void currentDate();
    std::vector<int> getDate() const;
    void addDate(Time time);
    Time getTimeDiff(const Date &dt1) const;

private:
    int _hour;
    int _month;
    int _date;
    int _year;
    std::vector<int> _daysinmonths {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};


#endif //YATM_DATETIME_H

