#include "Hocsinh.h"

// Constructor
HocSinh::HocSinh() {
    fullname = "";
    literature = math = gpa = 0;
}

HocSinh::HocSinh(const HocSinh& hs) {
    fullname = hs.fullname;
    literature = hs.literature;
    math = hs.math;
    gpa = hs.gpa;
}

istream& operator >> (istream& is, HocSinh& hs) {
    cout << "Fullname: ";
    getline(is, hs.fullname);

    do {
        cout << "Math score: ";
        is >> hs.math;
        if (hs.math >= 0 && hs.math <= 10) break;
    } while (1 && cout << "Invalid score!\n");

    do {
        cout << "Literature score: ";
        is >> hs.literature;
        if (hs.literature >= 0 && hs.literature <= 10) break;
    } while (1 && cout << "Invalid score!\n");
    
    hs.gpa = (hs.math + hs.literature) / 2;
    is.ignore();

    return is;
}

ostream& operator << (ostream& os, HocSinh& hs) {
    os << "Fullname: " << hs.fullname << endl;
    os << "Math score: " << hs.math << endl;
    os << "Literature score: " << hs.literature << endl;
    os << "GPA: " << hs.gpa << endl;
    return os;
}

HocSinh& HocSinh::operator = (const HocSinh& hs) {
    if (&hs == this)
        return *this;

    fullname = hs.fullname;
    math = hs.math;
    literature = hs.literature;
    gpa = hs.gpa;

    return *this;
}

bool HocSinh::operator> (const HocSinh& hs) {
    return this->gpa > hs.gpa;
}

bool HocSinh::operator< (const HocSinh& hs) {
    return this->gpa < hs.gpa;
}

bool HocSinh::operator==(const HocSinh& hs) {
    return (fabs(this->gpa - hs.gpa) <= 0.0000001);
}

bool HocSinh::operator<= (const HocSinh& hs) {
    return !(*this > hs);
}

bool HocSinh::operator>= (const HocSinh& hs) {
    return !(*this < hs);
}

bool HocSinh::operator!= (const HocSinh& hs) {
    return !(*this == hs);
}

HocSinh::operator char* () {
    char* c = (char*)fullname.c_str();
    return c;
}

HocSinh::~HocSinh() {}