#include <iostream>
#include <limits>
#include "Date.h"  // Make sure your updated Date class is in the same folder

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
    cout << "5. Run operator overload tests\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

// Option 1: Create a date and display in formats
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
    }
    else {
        cout << "Invalid date entered. Defaulted to " << myDate.printNumeric() << "\n";
    }
}

// Option 2: Check if a year is leap
void checkLeapYear() {
    int year = getInput("Enter year: ");
    Date temp;
    if (temp.isLeapYear(year)) {
        cout << year << " is a leap year.\n";
    }
    else {
        cout << year << " is not a leap year.\n";
    }
}

// Option 3: Get last day of month
void getLastDay() {
    int month = getInput("Enter month (1-12): ");
    int year = getInput("Enter year: ");
    Date temp;
    int lastDay = temp.lastDayOfMonth(month, year);
    cout << "The last day of month " << month << " in year " << year << " is " << lastDay << "\n";
}

// Option 4: Show date formats
void showDateFormats() {
    int m = getInput("Enter month: ");
    int d = getInput("Enter day: ");
    int y = getInput("Enter year: ");
    Date myDate(m, d, y);
    cout << "Numeric: " << myDate.printNumeric() << "\n";
    cout << "Long: " << myDate.printLongFormat() << "\n";
    cout << "Day-First: " << myDate.printLongDayFirst() << "\n";
}

// Option 5: Run operator overload tests
void runTests() {
    cout << "Running operator overload tests...\n";

    // Test subtraction operator
    Date date1(4, 10, 2014);
    Date date2(4, 18, 2014);
    cout << "Days between " << date1.printNumeric() << " and " << date2.printNumeric() << ": "
        << date2 - date1 << "\n";

    Date date3(2, 2, 2006);
    Date date4(11, 10, 2003);
    cout << "Days between " << date4.printNumeric() << " and " << date3.printNumeric() << ": "
        << date3 - date4 << "\n";

    // Test increment and decrement operators
    Date leapDate(2, 29, 2008);
    cout << "Original date: " << leapDate.printNumeric() << "\n";
    ++leapDate;
    cout << "After pre-increment: " << leapDate.printNumeric() << "\n";
    --leapDate;
    cout << "After pre-decrement: " << leapDate.printNumeric() << "\n";

    Date endOfYear(12, 31, 2024);
    cout << "Original date: " << endOfYear.printNumeric() << "\n";
    endOfYear++;
    cout << "After post-increment: " << endOfYear.printNumeric() << "\n";
    endOfYear--;
    cout << "After post-decrement: " << endOfYear.printNumeric() << "\n";

    // Test stream extraction and insertion
    Date userDate;
    cout << "Enter a date (mm dd yyyy): ";
    cin >> userDate;
    cout << "You entered: " << userDate << "\n";
}

int main() {
    int choice;
    do {
        showMenu();
        choice = getInput("");
        switch (choice) {
        case 1: createDate(); break;
        case 2: checkLeapYear(); break;
        case 3: getLastDay(); break;
        case 4: showDateFormats(); break;
        case 5: runTests(); break;
        case 0: cout << "Exiting program.\n"; break;
        default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
