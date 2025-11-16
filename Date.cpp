#include "Date.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ------------------------------
// Static month name array
// ------------------------------
const std::string Date::monthNames[13] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// ------------------------------
// Constructor
// ------------------------------
Date::Date(int m, int d, int y) {
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

// ------------------------------
// Set Date
// ------------------------------
void Date::setDate(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
    } else {
        // Keep object unchanged on invalid date
        cout << "Invalid date: " << m << "/" << d << "/" << y << endl;
    }
}

// ------------------------------
// Validation
// ------------------------------
bool Date::isValidDate(int m, int d, int y) const {
    if (m < 1 || m > 12) return false;
    int maxDay = lastDay(m, y);
    return d >= 1 && d <= maxDay;
}

// ------------------------------
// Leap Year
// ------------------------------
bool Date::isLeapYear() const {
    return isLeapYear(year);
}

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// ------------------------------
// Last day of month
// ------------------------------
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

// ------------------------------
// Print formats
// ------------------------------
string Date::printNumeric() const {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

string Date::printLongFormat() const {
    return monthNames[month] + " " + to_string(day) + ", " + to_string(year);
}

string Date::printLongDayFirst() const {
    return to_string(day) + " " + monthNames[month] + " " + to_string(year);
}

// ------------------------------
// Operator Overloads
// ------------------------------

// ++ prefix
Date& Date::operator++() {
    day++;

    if (day > lastDay()) {
        day = 1;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

// ++ postfix
Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

// -- prefix
Date& Date::operator--() {
    day--;

    if (day < 1) {
        month--;

        if (month < 1) {
            month = 12;
            year--;
        }
        day = lastDay(month, year);
    }
    return *this;
}

// -- postfix
Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

// ------------------------------
// Subtraction operator
// Returns # of days between two dates
// ------------------------------

// Convert this date to "days since base date"
int Date::daysFromStart() const {
    int total = 0;

    for (int y = 1; y < year; y++)
        total += isLeapYear(y) ? 366 : 365;

    for (int m = 1; m < month; m++)
        total += lastDay(m, year);

    total += day;

    return total;
}

int Date::operator-(const Date& right) const {
    int d1 = daysFromStart();
    int d2 = right.daysFromStart();
    return abs(d1 - d2);
}

// ------------------------------
// Stream insertion
// ------------------------------
ostream& operator<<(ostream& out, const Date& d) {
    out << Date::monthNames[d.month] << " " << d.day << ", " << d.year;
    return out;
}

// ------------------------------
// Stream extraction
// ------------------------------
istream& operator>>(istream& in, Date& d) {
    int m, da, y;

    cout << "Enter month (1-12): ";
    in >> m;
    cout << "Enter day: ";
    in >> da;
    cout << "Enter year: ";
    in >> y;

    if (d.isValidDate(m, da, y)) {
        d.month = m;
        d.day = da;
        d.year = y;
    } else {
        cout << "Invalid date entered. Keeping previous value.\n";
    }

    return in;
}
