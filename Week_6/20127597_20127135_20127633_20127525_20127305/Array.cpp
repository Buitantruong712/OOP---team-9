#include "Array.h"

// Constructor
Array::Array() {
    size = 0;
    element = NULL;
}

Array::Array(int size) {
    this->size = size;
    element = new int[size];
    for (int i = 0; i < size; i++)
        element[i] = 0;
}

Array::Array(int value[], int size) {
    this->size = size;
    this->element = new int[size];

    for (int i = 0; i < size; i++)
        this->element[i] = value[i];
}

Array::Array(const Array& arr) {
    size = arr.size;
    element = new int[size];

    for (int i = 0; i < size; i++)
        element[i] = arr.element[i];
}

int Array::Size() {
    return size;
}

// operator
Array& Array::operator = (const Array& arr) {
    if (&arr == this)
        return *this;

    size = arr.size;
    delete[]element;
    element = new int[size];
    for (int i = 0; i < size; i++)
        element[i] = arr.element[i];

    return *this;
}

int& Array::operator [] (int index) {
    return element[index];
}

Array::operator int* () {
    return element;
}

istream& operator>>(istream& is, Array& arr) {
    do {
        cout << "Enter size of array: ";
        is >> arr.size;
    } while (arr.size <= 0 && cout << "Invalid! Please enter again\n");

    // If the array is already defined
    if (arr.element != NULL)
        delete[] arr.element;

    arr.element = new int[arr.size];

    cout << "Enter element: ";
    for (int i = 0; i < arr.size; i++) is >> *(arr.element + i);
    is.ignore();

    return is;
}
ostream& operator<<(ostream& os, const Array& arr) {
    cout << "\nArray: ";
    for (int i = 0; i < arr.size; i++) os << *(arr.element + i) << " ";
    return os;
}

// Destructor
Array::~Array() {
    size = 0;
    delete[]element;
    element = NULL;
}
