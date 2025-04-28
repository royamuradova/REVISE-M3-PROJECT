#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default constructor (initialize to Jan 1, 2000)
Date::Date() {
    month = 1;
    day = 1;
    year = 2000;
}

// Parameterized constructor
Date::Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

// Setters
void Date::setMonth(int m) { month = m; }
void Date::setDay(int d) { day = d; }
void Date::setYear(int y) { year = y; }

// Getters
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

// Check if the year is a leap year
bool Date::isLeapYear() const {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Print MM/DD/YYYY format
void Date::printFormat1() const {
    cout << setw(2) << setfill('0') << month << "/"
         << setw(2) << setfill('0') << day << "/"
         << year << endl;
}

// Print MonthName DD, YYYY format
void Date::printFormat2() const {
    static const string months[] = { "January", "February", "March", "April", "May", "June",
                                     "July", "August", "September", "October", "November", "December" };
    cout << months[month - 1] << " " << day << ", " << year << endl;
}

// Print DD MonthName YYYY format
void Date::printFormat3() const {
    static const string months[] = { "January", "February", "March", "April", "May", "June",
                                     "July", "August", "September", "October", "November", "December" };
    cout << day << " " << months[month - 1] << " " << year << endl;
}
