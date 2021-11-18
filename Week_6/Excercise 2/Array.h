#include <iostream>

using namespace std;

class Array {
private:
    int size;
    int* element;
    
public:
    Array();
    Array(int);
    Array(int, int);
    Array(const Array&);

    Array& operator = (const Array&);
    int& operator [] (int);

    ~Array();    
};