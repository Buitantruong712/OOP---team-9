#pragma once

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class HocSinh {
private:
    string fullname;
    float math, literature, gpa;

public:
    HocSinh();                  // Default constructor
    HocSinh(const HocSinh&);    // Constructor from another HocSinh object

    // operator >>, <<
    friend istream& operator >> (istream&, HocSinh&);
    friend ostream& operator << (ostream&, HocSinh&);
    // operator =
    HocSinh& operator = (const HocSinh&);
    // Comparison operator GPA
    bool operator > (const HocSinh&);
    bool operator < (const HocSinh&);
    bool operator == (const HocSinh&);
    bool operator != (const HocSinh&);
    bool operator <= (const HocSinh&);
    bool operator >= (const HocSinh&);

    // type - casting (char*)
    operator char* ();

    // Destructor
    ~HocSinh();
};