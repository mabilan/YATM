//
// Created by andre on 4/28/2019.
//

#ifndef YATM_DATETIME_H
#define YATM_DATETIME_H

#include <vector>

class DateTime{
public:
    DateTime();

    DateTime(int month, int date, int year, int hour, int minute, bool am);
    ~DateTime() = default;

    void setDateTime(int month, int date, int year, int hour, int minute, bool am);
    std::vector<int> getDateTime();



private:

    int _month;
    int _date;
    int _year;
    int _hour;
    int _minute;
    bool _am;     // True: AM, False: PM
};



#endif //YATM_DATETIME_H

