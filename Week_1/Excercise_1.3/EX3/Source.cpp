#include"Header.h"

void Nhap(DonThuc& dt) {
	cout << "Nhap vao he so: ";
	cin >> dt.heso;
	cout << "Nhap vao so mu: ";
	cin >> dt.bac;
}

void Xuat(DonThuc dt) {
	if (dt.heso == 0) cout << 0;
	else if (dt.heso == 1) {
		if (dt.bac == 0) cout << 1;
		else if (dt.bac == 1) cout << "x";
		else cout << "x^" << dt.bac;
	}
	else if (dt.heso == -1) {
		if (dt.bac == 0) cout << -1;
		else if (dt.bac == 1) cout << "-x";
		else cout << "-x^" << dt.bac;
	}
	else {
		if (dt.bac == 0) cout << dt.heso;
		else if (dt.bac == 1) cout << dt.heso << "x";
		else cout << dt.heso << "x^" << dt.bac;
	}
}

bool KiemTraCungBac(DonThuc dt1, DonThuc dt2) {
	if (dt1.bac == dt2.bac) return true;
	return false;
}

DonThuc Cong(DonThuc dt1, DonThuc dt2) {
	DonThuc kq;
	kq.heso = dt1.heso + dt2.heso;
	kq.bac = dt1.bac;
	return kq;
}

DonThuc Tru(DonThuc dt1, DonThuc dt2) {
	DonThuc kq;
	kq.heso = dt1.heso - dt2.heso;
	kq.bac = dt1.bac;
	return kq;
}

DonThuc Nhan(DonThuc dt1, DonThuc dt2) {
	DonThuc kq;
	kq.heso = dt1.heso * dt2.heso;
	kq.bac = 2 * dt1.bac;
	return kq;
}

DonThuc Chia(DonThuc dt1, DonThuc dt2) {
	DonThuc kq;
	kq.heso = dt1.heso / dt2.heso;
	kq.bac = 0;
	return kq;
}

DonThuc DaoHam(DonThuc dt) {
	DonThuc kq;
	if (dt.heso == 0) kq.heso = 0;
	else {
		if (dt.bac == 0) kq.heso = 0;
		else if (dt.bac == 1) {
			kq.heso = dt.heso;
			kq.bac = 0;
		}
		else {
			kq.heso = dt.heso * dt.bac;
			kq.bac = dt.bac - 1;
		}
	}
	return kq;
}

void NguyenHam(DonThuc dt) {
	if (dt.heso == 0) cout << "C (C thuoc R)";
	else {
		if (dt.bac >= 0) {
			if (dt.bac == 0) cout << dt.heso << "x + C";
			else {
				cout << dt.heso / (dt.bac + 1) << "x^" << dt.bac + 1 << " + C";
			}
		}
		else {
			if (dt.bac == -1) cout << dt.heso << "ln(|x|) + C";
			else cout << dt.heso / (dt.bac + 1) << "x^" << dt.bac + 1 << " + C";
		}
	}
}