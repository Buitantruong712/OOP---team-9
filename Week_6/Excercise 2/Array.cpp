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

Array::Array(int size, int value) {
    this->size = size;
    this->element = new int[size];

    for (int i = 0; i < size; i++)
        this->element[i] = value;
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

// Destructor
Array::~Array() {
    size = 0;
    delete[]element;
    element = NULL;
}