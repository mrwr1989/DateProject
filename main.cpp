#include <iostream>
#include <limits>
#include "Date.h"  // Assuming you already have Date class implemented

using namespace std;

// Clear any bad input from cin
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Ask user for a number and return it
int getInput(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val)
            return val;

        cout << "Please enter a valid number.\n";
        clearInput();
    }
}

// Print the main menu
void showMenu() {
    cout << "\n=== Date Program Menu ===\n";
    cout << "1. Create and test a date\n";
    cout << "2. Check leap year\n";
    cout << "3. Get last day of month\n";
    cout << "4. Show date formats\n";
    cout << "5. Run tests\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

// Option 1
void createDate() {
    int m = getInput("Enter month (1-12): ");
    int d = getInput("Enter day: ");
    int y = getInput("Enter year: ");

    Date myDate(m, d, y);

    if (myDate.getMonth() == m && myDate.getDay() == d && myDate.getYear() == y) {
        cout << "Date is valid.\n";
        cout << "Numeric: " << myDate.printNumeric() << "\n";
        cout << "Long: " << myDate.printLongFormat() << "\n";
        cout << "Day-First: " << myDate.printLongDayFirst() << "\n";
    } else {
        cout << "Invalid date entered. Defaulted to " << myDate.printNumeric() << "\n";
    }
}

// Option 2
void checkLeapYear() {
    int year = getInput("Enter year: ");
    Date temp;
    if (temp.isLeapYear(year)) {
        cout << year << " is a leap year.\n";
    } else {
        cout << year << " is not a leap year.\n";
    }
}
