//
// Created by andre on 4/28/2019.
//

#ifndef YATM_DATETIME_H
#define YATM_DATETIME_H

#include <vector>

class Time{
public:
    Time(int hour, int minute);
    Time(const Time &obj);
    ~Time() = default;

    void setTime(int hour, int minute);

    std::vector<int> getTime()const;
private:
    int _hour;
    int _minute;
};


class Date{
public:
    Date() = default;
    ~Date() = default;

    Date(int day, int month, int year);

    void setDate(int day, int month, int year);
    void currentDate();
    std::vector<int> getDate() const;



private:
    bool isDayValid(int) const;
    bool isValidDate();
    int _day;
    int _month;
    int _year;
};


#endif //YATM_DATETIME_H

