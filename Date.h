#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

// Date class header file
class Date {
private:
    int month; // Month (1-12)
    int day;   // Day (1-31)
    int year;  // Year

public:
    // Default constructor
    Date();

    // Parameterized constructor
    Date(int m, int d, int y);

    // Setter (Mutators)
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    // Getter (Accessors)
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Utility functions
    bool isLeapYear() const;

    // Output formats
    void printFormat1() const; // MM/DD/YYYY
    void printFormat2() const; // MonthName DD, YYYY
    void printFormat3() const; // DD MonthName YYYY
};

#endif
