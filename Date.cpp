#include "Date.h"
#include <iostream>

const std::string Date::monthNames[13] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

bool Date::isValidDate(int m, int d, int y) const {
    if (m < 1 || m > 12) {
        return false;
    }

    int maxDay = lastDay(m, y);
    if (d < 1 || d > maxDay) {
        return false;
    }

    return true;
}

void Date::setDate(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
    } else {
        month = 1;
        day = 1;
        year = 1900;
    }
}

bool Date::isLeapYear() const {
    return isLeapYear(year);
}

bool Date::isLeapYear(int y) const {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

int Date::lastDay() const {
    return lastDay(month, year);
}

int Date::lastDay(int m, int y) const {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(y) ? 29 : 28;
        default:
            return 0;
    }
}

std::string Date::printNumeric() const {
    return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
}

std::string Date::printLongFormat() const {
    return monthNames[month] + " " + std::to_string(day) + ", " + std::to_string(year);
}

std::string Date::printLongDayFirst() const {
    return std::to_string(day) + " " + monthNames[month] + " " + std::to_string(year);
}
