#include <iostream>
#include "Date2.h"

int main() {
    Date2 d1;
    std::cout << "Default constructor: " << d1 << std::endl;

    Date2 d2(4, 29, 2025);
    std::cout << "Parameterized constructor: " << d2 << std::endl;

    d1.setDate(3, 15, 2024);
    std::cout << "Using setDate: " << d1 << std::endl;

    if (!d1.setDate(13, 45, 2018))
        std::cout << "Rejected invalid date: 13/45/2018" << std::endl;
    if (!d1.setDate(4, 31, 2000))
        std::cout << "Rejected invalid date: 4/31/2000" << std::endl;
    if (!d1.setDate(2, 29, 2009))
        std::cout << "Rejected invalid date: 2/29/2009" << std::endl;

    Date2 d3(4, 10, 2014);
    Date2 d4(4, 18, 2014);
    std::cout << "Days between " << d3 << " and " << d4 << ": " << d4 - d3 << " days" << std::endl;

    d3.setDate(2, 2, 2006);
    d4.setDate(11, 10, 2003);
    std::cout << "Days between " << d4 << " and " << d3 << ": " << d3 - d4 << " days" << std::endl;

    d1.setDate(2, 29, 2008);
    --d1;
    std::cout << "After pre-decrement: " << d1 << " (should be January 31, 2008)" << std::endl;
    ++d1;
    std::cout << "After pre-increment: " << d1 << " (should be February 29, 2008)" << std::endl;

    d1--;
    std::cout << "After post-decrement: " << d1 << " (should be January 31, 2008)" << std::endl;
    d1++;
    std::cout << "After post-increment: " << d1 << " (should be February 29, 2008)" << std::endl;

    d1.setDate(12, 31, 2024);
    d1++;
    std::cout << "After post-increment from Dec 31: " << d1 << " (should be Jan 1, 2025)" << std::endl;
    d1--;
    std::cout << "After post-decrement: " << d1 << " (should be Dec 31, 2024)" << std::endl;

    Date2 userDate;
    std::cout << "Enter a date (month day year): ";
    std::cin >> userDate;
    std::cout << "You entered: " << userDate << std::endl;

    return 0;
}
