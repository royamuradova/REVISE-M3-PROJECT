#ifndef DATE2_H
#define DATE2_H

#include <iostream>

class Date2 {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;
    bool isValidDate(int m, int d, int y) const;
    int dateToDays() const;

public:
    Date2(); // Default constructor
    Date2(int m, int d, int y); // Parameterized constructor

    bool setDate(int m, int d, int y); // Set the date

    // Operator Overloads
    Date2& operator++();      // Prefix increment
    Date2 operator++(int);    // Postfix increment
    Date2& operator--();      // Prefix decrement
    Date2 operator--(int);    // Postfix decrement
    int operator-(const Date2& other) const; // Subtract two dates

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Date2& d);
    friend std::istream& operator>>(std::istream& is, Date2& d);
};

#endif
