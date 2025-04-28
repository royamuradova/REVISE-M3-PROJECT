#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

// NumberArray class header
class NumberArray {
private:
    float* numbers; // Pointer to dynamically allocated array
    int size;       // Size of the array

public:
    // Default constructor (initialize empty array)
    NumberArray();

    // Parameterized constructor
    NumberArray(int s);

    // Destructor
    ~NumberArray();

    // Member functions
    void storeNumber(int index, float value);
    float getNumber(int index) const;
    float getHighest() const;
    float getLowest() const;
    float getAverage() const;
    void print() const; // Print all array elements
};

#endif
