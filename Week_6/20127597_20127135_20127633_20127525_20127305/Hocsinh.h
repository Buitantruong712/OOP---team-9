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
    // Constructor
    HocSinh();
    HocSinh(const HocSinh&);

    // operator
    friend istream& operator >> (istream&, HocSinh&);
    friend ostream& operator << (ostream&, HocSinh&);
    HocSinh& operator = (const HocSinh&);
    bool operator > (const HocSinh&);
    bool operator < (const HocSinh&);
    bool operator == (const HocSinh&);
    bool operator != (const HocSinh&);
    bool operator <= (const HocSinh&);
    bool operator >= (const HocSinh&);

    // type - cast
    operator char* ();

    // Destructor
    ~HocSinh();
};