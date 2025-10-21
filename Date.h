#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int month;
    int day;
    int year;

    static const std::string monthNames[13];

    bool isValidDate(int m, int d, int y) const;

public:
    Date(int m = 1, int d = 1, int y = 1900);

    void setDate(int m, int d, int y);

    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    bool isLeapYear() const;
    bool isLeapYear(int y) const;

    int lastDay() const;
    int lastDay(int m, int y) const;

    std::string printNumeric() const;
    std::string printLongFormat() const;
    std::string printLongDayFirst() const;
};

#endif
