#include "NumberArray.h"
#include <iostream>
using namespace std;

// Default constructor (creates empty array)
NumberArray::NumberArray() {
    size = 0;
    numbers = nullptr;
}

// Parameterized constructor (creates array of given size)
NumberArray::NumberArray(int s) {
    size = s;
    numbers = new float[size];
}

// Destructor (free the dynamic memory)
NumberArray::~NumberArray() {
    delete[] numbers;
}

// Store a number at a specific index
void NumberArray::storeNumber(int index, float value) {
    if (index >= 0 && index < size)
        numbers[index] = value;
    else
        cout << "Error: Invalid index!" << endl;
}

// Get a number from a specific index
float NumberArray::getNumber(int index) const {
    if (index >= 0 && index < size)
        return numbers[index];
    else {
        cout << "Error: Invalid index!" << endl;
        return 0.0;
    }
}

// Return the highest number in the array
float NumberArray::getHighest() const {
    if (size == 0) return 0.0;

    float max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max)
            max = numbers[i];
    }
    return max;
}

// Return the lowest number in the array
float NumberArray::getLowest() const {
    if (size == 0) return 0.0;

    float min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min)
            min = numbers[i];
    }
    return min;
}

// Return the average of the numbers
float NumberArray::getAverage() const {
    if (size == 0) return 0.0;

    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += numbers[i];
    return sum / size;
}

// Print all array elements
void NumberArray::print() const {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
}
