#pragma once
#include <iostream>

using namespace std;

class Array {
private:
    int size;
    int* element;

public:
    Array();            // Default constructor
    Array(int);         // Constructor with given size
    Array(int[], int);  // Constructor from int with given size
    Array(const Array&);// Constructor from another Array object

    int Size();

    Array& operator= (const Array&);    // Operator =
    int& operator[] (int);              // Operator []
    operator int* ();                   // Operator (int*)

    friend istream& operator >> (istream&, Array&);
    friend ostream& operator << (ostream&, const Array&);

    ~Array();           // Destructor
};
