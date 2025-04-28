#include "NumberArray.h"
#include <iostream>
using namespace std;

int main() {
    NumberArray arr(5);

    arr.storeNumber(0, 10.5);
    arr.storeNumber(1, 20.3);
    arr.storeNumber(2, 15.2);
    arr.storeNumber(3, 5.6);
    arr.storeNumber(4, 8.9);

    arr.print();

    cout << "Highest: " << arr.getHighest() << endl;
    cout << "Lowest: " << arr.getLowest() << endl;
    cout << "Average: " << arr.getAverage() << endl;

    return 0;
}
