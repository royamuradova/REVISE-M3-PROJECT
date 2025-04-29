#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;
    bool isValidDate(int m, int d, int y) const;
    int dateToDays() const;

public:
    Date(); // Default constructor
    Date(int m, int d, int y); // Parameterized constructor

    bool setDate(int m, int d, int y); // Set the date

    // Operator Overloads
    Date& operator++();      // Prefix increment
    Date operator++(int);    // Postfix increment
    Date& operator--();      // Prefix decrement
    Date operator--(int);    // Postfix decrement
    int operator-(const Date& other) const; // Subtract two dates

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
};

#endif
