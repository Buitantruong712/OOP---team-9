#include"Header.h"

int main() {
	DonThuc dt1, dt2;
	cout << "Don thuc 1\n";
	Nhap(dt1);
	cout << "Don thuc 2\n";
	Nhap(dt2);

	cout << "\nDon thuc 1: ";
	Xuat(dt1);
	cout << "\nDon thuc 2: ";
	Xuat(dt2);

	if (KiemTraCungBac(dt1, dt2)) {
		cout << "\n\nTong: ";
		DonThuc tong = Cong(dt1, dt2);
		Xuat(tong);

		cout << "\nHieu: ";
		DonThuc hieu = Tru(dt1, dt2);
		Xuat(hieu);

		cout << "\nTich: ";
		DonThuc tich = Nhan(dt1, dt2);
		Xuat(tich);

		if (dt2.heso == 0) cout << "\nKhong the thuc hien phep chia!\n";
		else {
			cout << "\nThuong: ";
			DonThuc thuong = Chia(dt1, dt2);
			Xuat(thuong);
		}
	}
	else cout << "\n\n2 don thuc khong cung bac !";
	cout << endl;

	cout << "\nDao ham don thuc 1: ";
	DonThuc dh1 = DaoHam(dt1);
	Xuat(dh1);
	cout << "\nNguyen ham don thuc 1: ";
	NguyenHam(dt1);

	cout << "\n\nDao ham don thuc 2: ";
	DonThuc dh2 = DaoHam(dt2);
	Xuat(dh2);
	cout << "\nNguyen ham don thuc 2: ";
	NguyenHam(dt2);

	cout << endl;

}
