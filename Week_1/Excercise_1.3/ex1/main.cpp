#include"Header1.h"
#include"Header2.h"


int main() {
	cout << "EX1: \n\n";
	PhanSo ps1,ps2;
	cout << "Nhap phan so thu nhat: \n";
	nhap(ps1);
	cout << "Nhap phan so thu hai: \n";
	nhap(ps2);

	cout << "\n\nPhan so 1: ";
	xuat(ps1);
	cout << "\nPhan so 2: ";
	xuat(ps2);
	
	cout << "\n\nNghich dao phan so 1: ";
	PhanSo ndps1;
	ndps1=nghichDao(ps1);
	xuat(ndps1);
	cout << "\nNghich dao phan so 2: ";
	PhanSo ndps2;
	ndps2=nghichDao(ps2);
	xuat(ndps2);

	PhanSo tong, hieu, tich, thuong;
	tong = Cong(ps1, ps2);
	hieu = Tru(ps1, ps2);
	tich = Nhan(ps1, ps2);
	thuong = Chia(ps1, ps2);

	cout << "\n\nTong : ";
	rutGonPs(tong);
	xuat(tong);
	cout << "\nHieu : ";
	rutGonPs(hieu);
	xuat(hieu);
	cout << "\nTich : ";
	rutGonPs(tich);
	xuat(tich);
	cout << "\nThuong : ";
	rutGonPs(thuong);
	xuat(thuong);
	cout << endl << endl;
}