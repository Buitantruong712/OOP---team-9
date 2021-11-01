#include"Console.h"
#include"CPeople.h"
#include"Bird.h"
using namespace std;

template <class T>
void updatePositon(vector<T>& obj, int speed) {
	for (auto& i : obj) {
		if (i.getState() == 1) i.move();
		else {
			for (auto& j : obj) {
				if (&i != &j) {
					if (j.getState() == 1)
						if (abs(i.getCoordX() - j.getCoordX()) < speed) {
							i.setState(0);
							break;
						}
					if (rand() % 100 == 1) 	i.setState(1);
				}
			}
		}
	}
}

template <class T>
void creatBird(vector<T>& obj, int numberOfBird, int x, int y, int trangThai, int huongDiChuyen) {
	for (int i = 0; i < numberOfBird; i++) {
		obj.push_back(T(x, y, trangThai, huongDiChuyen));
	}
}

int main() {
	Console::setConsole();
	int checkTF = 1;
	int running = 1;
	while (checkTF == 1) {
		//vẽ các đối tượng cơ bản
		Console::drawGameBot();
		// tạo vehicle 
		vector<Bird> bir1, bir2, bir3, bir4, bir5;
		creatBird(bir1, 5, 20, 9, 0, 0);
		creatBird(bir2, 5, 138, 14, 0, 1);
		creatBird(bir3, 5, 20, 19, 0, 0);
		creatBird(bir4, 5, 138, 24, 0, 1);
		creatBird(bir5, 5, 20, 29, 0, 0);
		// tạo đối tượng people
		CPEOPLE cp;
		// các biến hỗ trợ up level
		int level = 0, speed = 0, time = 0;
		// options new game or load game
		int options = 0;
		if (options == 0)	level = 0, speed = 35, time = 30;
		else {
			string fileName;
			cp.loadGame(level, speed, time, bir1, bir2, bir3, bir4, bir5);
		}
		cp.upLevel(level, speed, time, bir1, bir2, bir3, bir4, bir5);
		while (running) {
			int pausE = 0;
			// di chuyển people
			cp.Control(pausE);
			// pause and options 
			if (pausE == 1) cp.pauseGame(pausE, level, speed, time, bir1, bir2, bir3, bir4, bir5);
			// vehicle hoạt động
			updatePositon(bir1, speed);
			updatePositon(bir2, speed);
			updatePositon(bir3, speed);
			updatePositon(bir4, speed);
			updatePositon(bir5, speed);
			if (pausE == 1) cp.pauseGame(pausE, level, speed, time, bir1, bir2, bir3, bir4, bir5);
			// đụng độ => thua
			if (cp.isImpact(bir1) || cp.isImpact(bir2) || cp.isImpact(bir3) || cp.isImpact(bir4) || cp.isImpact(bir5)) break;
			// vượt qua hết
			if (cp.isFinish()) cp.upLevel(level, speed, time, bir1, bir2, bir3, bir4, bir5); // tăng độ khó khi up level
			Sleep(time);
		}
		// sau khi va chạm thua
		cp.isDead(checkTF);
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}