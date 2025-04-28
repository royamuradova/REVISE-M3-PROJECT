#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    Date today(4, 28, 2025); // Example: April 28, 2025

    cout << "Format 1: ";
    today.printFormat1();

    cout << "Format 2: ";
    today.printFormat2();

    cout << "Format 3: ";
    today.printFormat3();

    if (today.isLeapYear())
        cout << today.getYear() << " is a leap year." << endl;
    else
        cout << today.getYear() << " is not a leap year." << endl;

    return 0;
}
