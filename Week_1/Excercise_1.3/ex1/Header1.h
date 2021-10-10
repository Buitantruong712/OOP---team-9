#pragma once
#include<iostream>
using namespace std;

struct PhanSo
{
	float tuso,mauso;
};

void nhap(PhanSo& ps);
void xuat(PhanSo ps);

PhanSo nghichDao(PhanSo& ps);
void rutGonPs(PhanSo& ps);

PhanSo Cong(PhanSo ps1, PhanSo ps2);
PhanSo Tru(PhanSo ps1, PhanSo ps2);
PhanSo Nhan(PhanSo ps1, PhanSo ps2);
PhanSo Chia(PhanSo ps1, PhanSo ps2);