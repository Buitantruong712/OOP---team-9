#include "Console.h"
#include "Vehical.h"

int main() {
	//fixConsoleWindow();
	/*Truck tr;
	tr.Lane(81, 2, 1);*/
	Car c;
	c.Lane(0, 2, 1);

	/*Car c;
	c.draw(1,10);*/
	return 0;
}





//DWORD WINAPI task1(Truck tr) 
//{
//	HWND hWin;
//	EnableWindow(hWin, true);
//
//	while (1)
//	{
//		tr.Lane(80, 2, 1);
//		Sleep(1000);
//	}
//
//	return 0;
//}
//DWORD WINAPI task2(Truck tr)
//{
//	while (1)
//	{
//		tr.Lane(80, 2, 1);
//		Sleep(1000);
//	}
//	return 0;
//}
//
//int main()
//
//{   
//	HANDLE thr[NUM_OF_THREAD]; //tao mang thr 2 ptu kieu Handle
//	DWORD thrid;
//	Truck tr;
//
//	//tao thread cho task1()
//	thr[0] = CreateThread(NULL, 0, task1,(Truck) tr, 0, &thrid);
//
//	Sleep(2000);
//	//tao thread cho task2()
//	//Truyen bien text vao và ep kieu LPVOID o tham so thu 4
//	thr[1] = CreateThread(NULL, 0, task2,(Truck)tr, 0, &thrid);
//	///Sleep(500);
//	//luc nay 2 thread dang lam viec
//
//	getch(); //doi an 1 nut bat ly
//	CloseHandle(thr[0]); //dong thread 1
//	CloseHandle(thr[1]); //dong thred 2
//	return 0;
//}