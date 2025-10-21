#include <iostream>
#include <limits>
#include "Date.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printMenu() {
    cout << "\n========== Date Utility Program ==========\n";
    cout << "1. Create and validate a date\n";
    cout << "2. Check if a year is a leap year\n";
    cout << "3. Get last day of a month\n";
    cout << "4. Display date in different formats\n";
    cout << "5. Run test suite\n";
    cout << "0. Exit\n";
    cout << "==========================================\n";
    cout << "Enter your choice: ";
}

void createAndValidateDate() {
    int month, day, year;
    cout << "\nEnter month (1-12): ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter year: ";
    cin >> year;

    Date date(month, day, year);
    
    if (date.getMonth() == month && date.getDay() == day && date.getYear() == year) {
        cout << "\n✓ Valid date!\n";
        cout << "Numeric format: " << date.printNumeric() << "\n";
        cout << "Long format: " << date.printLongFormat() << "\n";
        cout << "Day-first format: " << date.printLongDayFirst() << "\n";
    } else {
        cout << "\n✗ Invalid date! Defaulted to: " << date.printNumeric() << "\n";
        if (month < 1 || month > 12) {
            cout << "Reason: Month must be between 1 and 12\n";
        } else {
            cout << "Reason: Day must be between 1 and " << date.lastDay(month, year) << " for this month\n";
        }
    }
}

void checkLeapYear() {
    int year;
    cout << "\nEnter year: ";
    cin >> year;

    Date date;
    if (date.isLeapYear(year)) {
        cout << year << " is a leap year.\n";
        cout << "February has 29 days in " << year << ".\n";
    } else {
        cout << year << " is not a leap year.\n";
        cout << "February has 28 days in " << year << ".\n";
    }
}

void getLastDay() {
    int month, year;
    cout << "\nEnter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    if (month < 1 || month > 12) {
        cout << "Invalid month! Must be between 1 and 12.\n";
        return;
    }

    Date date;
    int lastDay = date.lastDay(month, year);
    cout << "The last day of month " << month << " in year " << year << " is: " << lastDay << "\n";
}

void displayFormats() {
    int month, day, year;
    cout << "\nEnter month (1-12): ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter year: ";
    cin >> year;

    Date date(month, day, year);
    
    if (date.getMonth() == month && date.getDay() == day && date.getYear() == year) {
        cout << "\nDate formats:\n";
        cout << "1. Numeric: " << date.printNumeric() << "\n";
        cout << "2. Long format: " << date.printLongFormat() << "\n";
        cout << "3. Day-first: " << date.printLongDayFirst() << "\n";
    } else {
        cout << "\nInvalid date! Cannot display formats.\n";
    }
}

void runTestSuite() {
    cout << "\n========== Running Test Suite ==========\n";
    
    cout << "\nTest 1: Default constructor\n";
    Date date1;
    cout << "Result: " << date1.printNumeric() << "\n";

    cout << "\nTest 2: Valid date (2/28/2009)\n";
    Date date2(2, 28, 2009);
    cout << "Result: " << date2.printNumeric() << "\n";

    cout << "\nTest 3: Invalid month (45/2/2009)\n";
    Date date3(45, 2, 2009);
    cout << "Result: " << date3.printNumeric() << " (should be 1/1/1900)\n";

    cout << "\nTest 4: Invalid day (2/29/2009 - not a leap year)\n";
    Date date4(2, 29, 2009);
    cout << "Result: " << date4.printNumeric() << " (should be 1/1/1900)\n";

    cout << "\nTest 5: Valid leap year date (2/29/2008)\n";
    Date date5(2, 29, 2008);
    cout << "Result: " << date5.printNumeric() << "\n";
    cout << "Long format: " << date5.printLongFormat() << "\n";
    cout << "Day-first: " << date5.printLongDayFirst() << "\n";

    cout << "\nTest 6: Leap year checks\n";
    cout << "2000: " << (date1.isLeapYear(2000) ? "Leap year" : "Not a leap year") << "\n";
    cout << "1900: " << (date1.isLeapYear(1900) ? "Leap year" : "Not a leap year") << "\n";
    cout << "2024: " << (date1.isLeapYear(2024) ? "Leap year" : "Not a leap year") << "\n";
    cout << "2023: " << (date1.isLeapYear(2023) ? "Leap year" : "Not a leap year") << "\n";

    cout << "\n========== Test Suite Complete ==========\n";
}

int main() {
    int choice;
    
    cout << "Welcome to the Date Utility Program!\n";
    cout << "This program helps you validate dates, check leap years,\n";
    cout << "and format dates in various ways.\n";

    while (true) {
        printMenu();
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            clearInput();
            continue;
        }

        clearInput();

        switch (choice) {
            case 1:
                createAndValidateDate();
                break;
            case 2:
                checkLeapYear();
                break;
            case 3:
                getLastDay();
                break;
            case 4:
                displayFormats();
                break;
            case 5:
                runTestSuite();
                break;
            case 0:
                cout << "\nThank you for using Date Utility Program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please select 0-5.\n";
        }
    }

    return 0;
}
