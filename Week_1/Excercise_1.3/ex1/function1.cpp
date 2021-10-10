#include"Header1.h"

void nhap(PhanSo& ps) {
	cout << "Nhap vao tu so: ";
	cin >> ps.tuso;
	do
	{
	cout << "Nhap vao mau so: ";
	cin >> ps.mauso;
	if (ps.mauso == 0) cout << "Mau so khong hop le !\n";
	} while (ps.mauso==0);
}


PhanSo nghichDao(PhanSo& ps) {
	PhanSo nd;
	nd.tuso = ps.mauso;
	nd.mauso = ps.tuso;
	return nd;
}

int gcd(int a, int b) {
	while (a * b != 0) {
		if (a > b)	a %= b;
		else 		b %= a;
	}
	return a + b;
}

void rutGonPs(PhanSo &ps) {
	int uc = gcd(abs(ps.tuso), abs(ps.mauso));
	if (ps.mauso < 0) {
		ps.tuso *= -1;
		ps.mauso *= -1;
	}
	ps.tuso /= uc;
	ps.mauso /= uc;
}

void xuat(PhanSo ps) {
	rutGonPs(ps);
	if (ps.tuso == 0) cout <<  0;
	else if (ps.mauso == 1)  cout <<  ps.tuso;
	else if (ps.mauso == -1)  cout << -1*ps.tuso;
	else if (ps.mauso == 0) cout << "Phan so khong xac dinh !";
	else cout  << ps.tuso << "/" << ps.mauso;
}
PhanSo Cong(PhanSo ps1, PhanSo ps2) {
	PhanSo kq;
	kq.tuso = ps1.tuso * ps2.mauso + ps1.mauso * ps2.tuso;
	kq.mauso = ps1.mauso * ps2.mauso;
	return kq;
}

PhanSo Tru(PhanSo ps1, PhanSo ps2) {
	PhanSo kq;
	kq.tuso = ps1.tuso * ps2.mauso - ps1.mauso * ps2.tuso;
	kq.mauso = ps1.mauso * ps2.mauso;
	return kq;
}

PhanSo Nhan(PhanSo ps1, PhanSo ps2) {
	PhanSo kq;
	kq.tuso = ps1.tuso * ps2.tuso;
	kq.mauso = ps1.mauso * ps2.mauso;
	return kq;
}

PhanSo Chia(PhanSo ps1, PhanSo ps2) {
	PhanSo kq;
	kq.tuso = ps1.tuso * ps2.mauso;
	kq.mauso = ps1.mauso * ps2.tuso;
	return kq;
}