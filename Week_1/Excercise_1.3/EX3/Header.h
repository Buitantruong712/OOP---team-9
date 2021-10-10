#pragma once
#include<iostream>

using namespace std;

struct DonThuc {
	float heso, bac;
};


void Nhap(DonThuc& dt);
void Xuat(DonThuc dt);

bool KiemTraCungBac(DonThuc dt1, DonThuc dt2);
DonThuc Cong(DonThuc dt1, DonThuc dt2);
DonThuc Tru(DonThuc dt1, DonThuc dt2);
DonThuc Nhan(DonThuc dt1, DonThuc dt2);
DonThuc Chia(DonThuc dt1, DonThuc dt2);

DonThuc DaoHam(DonThuc dt);
void NguyenHam(DonThuc dt);