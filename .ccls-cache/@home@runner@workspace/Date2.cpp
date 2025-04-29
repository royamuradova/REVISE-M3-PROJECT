#include "Date2.h"
#include <iomanip>
#include <cmath>

// Array of month names for output
static const std::string MONTHS[] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Default constructor initializes to January 1, 2000
Date2::Date2() : day(1), month(1), year(2000) {}

// Parameterized constructor with validation
Date2::Date2(int m, int d, int y) {
    if (!setDate(m, d, y)) {
        day = 1;
        month = 1;
        year = 2000;
    }
}

// Check if a year is a leap year
bool Date2::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Get the number of days in a given month and year
int Date2::daysInMonth(int m, int y) const {
    if (m == 2) return isLeapYear(y) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else return 31;
}

// Validate the date
bool Date2::isValidDate(int m, int d, int y) const {
    return m >= 1 && m <= 12 && d >= 1 && d <= daysInMonth(m, y);
}

// Set the date if valid
bool Date2::setDate(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
        return true;
    }
    return false;
}

// Convert the date to the number of days since a fixed date
int Date2::dateToDays() const {
    int y = year, m = month;
    if (m < 3) {
        y--;
        m += 12;
    }
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + day - 306;
}

// Prefix increment: ++Date2
Date2& Date2::operator++() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

// Postfix increment: Date2++
Date2 Date2::operator++(int) {
    Date2 temp = *this;
    ++(*this);
    return temp;
}

// Prefix decrement: --Date2
Date2& Date2::operator--() {
    day--;
    if (day == 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
    return *this;
}

// Postfix decrement: Date2--
Date2 Date2::operator--(int) {
    Date2 temp = *this;
    --(*this);
    return temp;
}

// Subtract two dates to get the difference in days
int Date2::operator-(const Date2& other) const {
    return std::abs(this->dateToDays() - other.dateToDays());
}

// Overload << operator for output
std::ostream& operator<<(std::ostream& os, const Date2& d) {
    os << MONTHS[d.month] << ' ' << d.day << ", " << d.year;
    return os;
}

// Overload >> operator for input
std::istream& operator>>(std::istream& is, Date2& d) {
    int m, dy, y;
    is >> m >> dy >> y;
    if (!d.setDate(m, dy, y)) {
        std::cout << "Invalid date entered. Setting to default date (1/1/2000).\n";
        d.setDate(1, 1, 2000);
    }
    return is;
}
