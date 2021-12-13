#include "CGame.h"

/// 
/// - - - - - - - - - - - - KHỞI TẠO VÀ HUỶ - - - - - - - - - - - - 
/// 

CGAME::CGAME() {
	cn = new CPEOPLE;
	att = new CHELICOPTER[1];
	ac = new CBIRD[1];
	ak = new CMONKEY[1];
	axt = new CTRUCK[1];
	axh = new CCAR[1];
	light1 = new CTRAFFIC;
	light2 = new CTRAFFIC;
	light3 = new CTRAFFIC;

	Console::setConsole();
	is_running = false;
}

CGAME::~CGAME() {
	delete[] ac;
	delete[] ak;
	delete[] axh;
	delete[] axt;
	delete[] att;
	delete[] light1;
	delete[] light2;
	delete[] light3;
	delete cn;
}

/// 
/// - - - - - - - - - - - - HÀM HỖ TRỢ - - - - - - - - - - - - 
/// 

// Tạo đối tượng mobs
template<class T>
void createObj(T*& obj, short size, short row, bool direction) {
	if (size == 0)			// Tránh trường hợp chia ra số 0
		return;

	short distance = ((short)Border::RIGHT - (short)Border::LEFT) / size;
	short column = (short)Border::LEFT + distance / 2;

	if (obj != NULL)
		delete[] obj;
	obj = new T[size];

	for (short i = 0; i < size; i++) {
		obj[i].setX(column + rand() % (distance / 3) - 10);		// Đặt random. Bên setX tính cả trưởng hợp bị âm
		obj[i].setDirection(direction);
		obj[i].setmY(row);
		column += distance;
	}
}

// Vẽ hết mobs
template<class T>
void drawObj(T*& obj, short& size) {
	for (int i = 0; i < size; i++) {
		obj[i].drawBody();
	}
}

// Lưu mobs
template<class T>
void saveObj(T*& obj, short& size, ofstream& f) {
	for (short i = 0; i < size; i++) {
		f << obj[i].getX() << ' ' << obj[i].getmY() << ' ' << obj[i].getDirection() << '\n';
	}
}

// Tải mobs 
template<class T>
void loadObj(T*& obj, short& size, ifstream& f) {
	f >> size;

	if (size == 0)			// Tránh trường hợp load khi hàng không có con nào
		return;

	if (obj != NULL)
		delete[] obj;
	obj = new T[size];
	short get_X, get_mY, get_direction;
	for (short i = 0; i < size; i++) {
		f >> get_X >> get_mY >> get_direction;
		obj[i].setX(get_X);
		obj[i].setmY(get_mY);
		obj[i].setDirection(get_direction);
	}
}

// Tải đèn giao thông
template<class T>
void loadObj2(T*& obj, ifstream& f) {
	if (obj != NULL)
		delete obj;
	short value1, value2, value3, value4, value5, value6;
	f >> value1 >> value2 >> value3 >> value4 >> value5 >> value6;
	obj = new T(static_cast<TrafficLight>(value6), value1, value2);
	obj->setTimeRed(value3);
	obj->setTimeYellow(value4);
	obj->setTimeGreen(value5);
}

// Tạo đèn giao thông
void createTraffic(CTRAFFIC*& t, TrafficLight status, short mY, bool direction) {
	if (t != NULL) {
		delete t;
	}
	t = new CTRAFFIC(status, mY, direction);
}

// Vẽ xe ở menu chính
bool carRunning = 1;
void drawMenuCar() {
	static bool flag = 0;
	static COORD posCar = { 0,26 };
	while (carRunning) {
		Console::drawFromFile("Menu/Car.txt", posCar, (int)Color::GREEN);
		if (flag == 0)
			posCar.X++;
		else
			posCar.X--;
		if (posCar.X == Console::getSize() / HELP_GET_SIZE - 55)
			flag = 1;
		else if (posCar.X == 0)
			flag = 0;
		Sleep(50);
	}
}

/// 
/// - - - - - - - - - - - - VẼ CÁC MENU - - - - - - - - - - - - 
/// 

// Tiêu đề game
void CGAME::drawTitle() {
	COORD pos = { 60, 1 };
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::DARK_RED);
	Sleep(200);
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::RED);
	Sleep(200);
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::MAGENTA);
}

// Vẽ Menu chính 
void CGAME::drawMainMenu(short choice) {
	int count = 0;
	COORD pos = { (int)Console::getMidHorizontal() - 15, (int)Console::getMidVertical() };
	Console::drawFromFile("Menu/MainMenuFrame.txt", pos, (int)Color::WHITE);
	for (auto& i : MAIN_MENU) {
		if (count == choice) {
			Console::setColor(16 * (int)Color::WHITE);
			Console::gotoXY(pos.X + 2, pos.Y + count + 1);
			cout << i;
		}
		else {
			Console::setColor((int)Color::LIGHT_GRAY);
			Console::gotoXY(pos.X + 2, pos.Y + count + 1);
			cout << i;
		}
		count++;
	}
}

// Vẽ Setting Menu
void CGAME::drawSettingsMenu(short choice) {
	COORD pos = { (short)Console::getMidHorizontal() - 20, (short)Console::getMidVertical() - 2 };
	Console::drawFromFile("Menu/SettingsMenuFrame.txt", pos, (int)Color::WHITE);

	for (short i = 0; i < 6; i++) {
		if (i == choice) {
			Console::setColor(16 * (int)Color::WHITE);
		}
		else {
			Console::setColor((int)Color::LIGHT_GRAY);
		}

		if (i == 5)
			Console::gotoXY(pos.X + 11, pos.Y + i + 1);
		else if (i == 4)
			Console::gotoXY(pos.X + 17, pos.Y + i + 1);
		else
			Console::gotoXY(pos.X + 15, pos.Y + i + 1);

		if (i == 0)
			cout << (theme ? "Dark " : "Light");
		else if (i == 1)
			cout << (music ? "On " : "Off");
		else if (i == 2)
			cout << (sound ? "On " : "Off");
		else if (i == 3)
			cout << set_max_hearts;
		else if (i == 4)
			cout << (endless_mode ? "On " : "Off");
		else
			cout << "BACK";
	}
}

// Vẽ Save Load Menu
void CGAME::drawSaveMenu() {
	short count = 0;
	short midHoritonal = Console::getMidHorizontal(),
		midVertical = Console::getMidVertical();
	COORD pos = { midHoritonal - 15, midVertical };
	Console::drawFromFile("Menu/SaveMenuFrame.txt", pos, (int)Color::WHITE);
	string file_name;
	for (short i = 0; i < 4; i++) {
		fstream f;
		file_name = "SaveGame/Data" + to_string(i + 1) + ".txt";

		f.open(file_name);
		if (f) {	// Nếu có lưu ở con số đó: in ra khung màu xanh và cả con số
			Console::drawFromFile("Menu/SaveMenuIcon.txt", COORD{ (short)pos.X + 2 + i * 7, (short)pos.Y + 1 }, (int)Color::GREEN);
			Console::gotoXY(pos.X + 4 + i * 7, pos.Y + 2);
			cout << i + 1;
		}
		else {
			Console::drawFromFile("Menu/SaveMenuIcon.txt", COORD{ (short)pos.X + 2 + i * 7, (short)pos.Y + 1 }, (int)Color::RED);
		}
		f.close();
	}
}

void CGAME::drawLoadMenu() {
	short count = 0;
	COORD pos = { Console::getMidHorizontal() - 15, Console::getMidVertical() };
	Console::drawFromFile("Menu/LoadMenuFrame.txt", pos, (int)Color::WHITE);
	string file_name;
	for (short i = 0; i < 4; i++) {
		fstream f;
		file_name = "SaveGame/Data" + to_string(i + 1) + ".txt";

		f.open(file_name);
		if (f) {	// Nếu có lưu ở con số đó: in ra khung màu xanh và cả con số
			Console::drawFromFile("Menu/SaveMenuIcon.txt", COORD{ (short)pos.X + 2 + i * 7, (short)pos.Y + 1 }, (int)Color::GREEN);
			Console::gotoXY(pos.X + 4 + i * 7, pos.Y + 2);
			cout << i + 1;
		}
		else {
			Console::drawFromFile("Menu/SaveMenuIcon.txt", COORD{ (short)pos.X + 2 + i * 7, (short)pos.Y + 1 }, (int)Color::RED);
		}
		f.close();
	}
}

// Vẽ Menu khi dừng game
void CGAME::drawPauseMenu(short choice) {
	short count = 0;
	COORD pos = { Console::getMidHorizontal() - 15, Console::getMidVertical() };
	Console::drawFromFile("Menu/PauseMenuFrame.txt", pos, (int)Color::WHITE);
	for (auto& i : PAUSE_MENU) {
		if (count == choice) {
			Console::setColor(16 * (int)Color::WHITE);
			Console::gotoXY(pos.X + 2, pos.Y + count + 1);
			cout << i;
		}
		else {
			Console::setColor((int)Color::LIGHT_GRAY);
			Console::gotoXY(pos.X + 2, pos.Y + count + 1);
			cout << i;
		}
		count++;
	}
}

/// 
/// - - - - - - - - - - - - VẼ CÁC VẬT TRONG GAME - - - - - - - - - - - - 
/// 

void CGAME::drawLevel(short lv) {
	Console::removeSpace((int)Border::LEFT + 120, 2);

	string level_file = "Level/Level title.txt";
	Console::drawFromFile(
		level_file,
		COORD{ (short)Border::LEFT + 98, 2 },
		(int)Color::RED
	);
	string level_number = to_string(lv);
	for (short i = 0; i < level_number.size(); i++) {
		level_file = "Level/Number" + string(1, level_number[i]) + ".txt";
		Console::drawFromFile(
			level_file,
			COORD{ (short)Border::LEFT + 118 + i * 4, 2 },
			(int)Color::RED
		);
	}
}

void CGAME::drawTime(short lv) {
	// Vẽ dòng Level <lv> ở chính giữa
	string level_file = "Level/Level title.txt";
	Console::drawFromFile(
		level_file,
		COORD{ (int)Border::LEFT + 51, (int)Border::TOP + 11 },
		(int)Color::YELLOW
	);
	string level_number = to_string(lv);
	for (short i = 0; i < level_number.size(); i++) {
		level_file = "Level/Number" + string(1, level_number[i]) + ".txt";
		Console::drawFromFile(
			level_file,
			COORD{ (short)Border::LEFT + 71 + i * 4, (short)Border::TOP + 11 },
			(int)Color::YELLOW
		);
	}

	// Vẽ thời gian
	string countdown_file;
	for (int time_coundown = 3; time_coundown != 0; time_coundown--) {
		countdown_file = "3s2s1s/" + to_string(time_coundown) + "s.txt";

		Console::drawFromFile(
			countdown_file,
			COORD{ (short)Border::LEFT + 58, (short)Border::TOP + 14 },
			(int)Color::YELLOW
		);
		Sleep(1000);
		Console::removeSpace(
			(int)Border::LEFT + 58,
			(int)Border::TOP + 14,
			(int)Border::LEFT + 68,
			(int)Border::TOP + 22
		);
	}

	// Vẽ lại khung (nếu bị đè)
	Console::drawFromFile(
		"Map/EmptyFrame.txt",
		COORD{ (short)Border::LEFT - 2, (short)Border::TOP + 5 },
		(int)Color::LIGHT_GRAY
	);
}

// Vẽ màn hình chơi game
void CGAME::drawGame() {
	Console::clearScreen();
	Console::drawFromFile("Map/Frame.txt", COORD{ (short)Border::LEFT - 2, (short)Border::TOP - 1 }, (int)Color::LIGHT_GRAY);
	Console::drawFromFile("Map/ScoreBoard.txt", COORD{ (short)Border::LEFT + 128, (short)Border::TOP - 1 }, (int)Color::WHITE);
	drawLevel(level);
	cn->initPeople();
}

// Vẽ các con vật
void CGAME::drawObjects() {
	// Thêm để vật hiện, không có dòng này làn nào có đèn giao thông thì sẽ không xuất hiện liền
	drawObj(att, att_size);
	drawObj(ac, ac_size);
	drawObj(ak, ak_size);
	drawObj(axt, axt_size);
	drawObj(axh, axh_size);
}

//
void CGAME::clearPauseMenu() {
	// Xoá cái khung
	COORD pos = { Console::getMidHorizontal() - 15, Console::getMidVertical() };
	for (short i = 0; i < 5; i++) {
		Console::gotoXY(pos.X, pos.Y + i);
		cout << string(16, ' ');
	}
	// Vẽ lại phần khung bị chồng lên
	Console::drawFromFile("Menu/OverLappingLine.txt", pos, (short)Color::LIGHT_GRAY);
	// Vẽ lại người nếu nó bị chồng lên
	cn->drawBody(1);
	// Không cần vẽ lại con vật vì nó chạy liên tục => tự động vẽ
}

/// 
/// - - - - - - - - - - - - CHẠY CÁC MENU - - - - - - - - - - - - 
/// 

// Thao tác trên menu chính
short CGAME::runMainMenu() {
	short menuChoice = 0;
	thread car(drawMenuCar);

	while (true) {

		carRunning = 0;
		Sleep(100);
		drawMainMenu(menuChoice);
		if (!carRunning) {
			carRunning = 1;
			car.detach();
			car = thread(drawMenuCar);
		}

		char c = toupper(_getch());

		switch (c)
		{
		case (int)Key::UP: case (int)Key::LEFT: case 'W': case 'A':
			menuChoice--;
			if (menuChoice < 0)
				menuChoice = 3;
			if (sound) {
				PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
			}
			break;

		case (int)Key::DOWN: case (int)Key::RIGHT: case 'S': case 'D':
			menuChoice++;
			if (menuChoice > 3)
				menuChoice = 0;
			if (sound) {
				PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
			}
			break;

		case (int)Key::ENTER:
			carRunning = 0;
			car.join();
			if (sound) {
				PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
			}
			return menuChoice;
			break;

		default:
			break;
		}
	}
}

// Cài đặt
void CGAME::runSettings() {
	short menuChoice = 0;
	bool exit = false;
	COORD pos{};
	while (!exit) {
		drawSettingsMenu(menuChoice);

		char c = toupper(_getch());

		switch (c) {

		case (int)Key::UP: case (int)Key::LEFT: case 'W': case 'A':
			menuChoice--;
			if (menuChoice < 0)
				menuChoice = 5;
			break;

		case (int)Key::DOWN: case (int)Key::RIGHT: case 'S': case 'D':
			menuChoice++;
			if (menuChoice > 5)
				menuChoice = 0;
			break;

		case (int)Key::ENTER:
			switch (menuChoice) {

			case 0:
				if (!theme) {}
				else {}
				theme = !theme;
				break;

			case 1:
				if (!music) {}
				else {}
				music = !music;
				break;

			case 2:
				if (!sound) {}
				else {}
				sound = !sound;
				break;

			case 3:
				if (++set_max_hearts > 5) {
					set_max_hearts = 1;
				}
				break;

			case 4:
				endless_mode = !endless_mode;
				break;

			case 5: case (int)Key::ESCAPE:
				exit = true;
				pos = { (short)Console::getMidHorizontal() - 20, (short)Console::getMidVertical() - 2 };
				Console::removeSpace(pos.X, pos.Y, pos.X + 24, pos.Y + 7);
				break;

			default:
				break;
			}
		default:
			break;
		}
	}
}

// Menu dừng game
short CGAME::runPauseMenu() {
	Sleep(100);
	int menuChoice = 0;
	while (1) {
		drawPauseMenu(menuChoice);
		char c = toupper(_getch());
		switch (c) {

		case (int)Key::UP: case (int)Key::LEFT: case 'W': case 'A':
			menuChoice--;
			if (menuChoice < 0)
				menuChoice = 2;
			break;

		case (int)Key::DOWN: case (int)Key::RIGHT: case 'S': case 'D':
			menuChoice++;
			if (menuChoice > 2)
				menuChoice = 0;
			break;

		case (int)Key::ENTER:
			clearPauseMenu();
			return menuChoice;
			break;

		default:
			break;
		}
	}
}

// Bắt đầu game
void CGAME::startGame() {
	level = 1;
	resetGame(0, 3, 1, 3, 2);
	drawGame();
	drawObjects();
	pressable = true;
	is_running = true;
}

/// 
/// - - - - - - - - - - - - THAO TÁC TRONG TRÒ CHƠI - - - - - - - - - - - - 
/// 

// Khi người chơi đạt đến giới hạn
void CGAME::gameWinner() {
	pressable = false;
	is_running = false;
	Sleep(100);
	Console::clearScreen();
	COORD pos{ Console::getMidHorizontal() - 30, Console::getMidVertical() - 5 };
	Console::gotoXY(pos.X + 24, pos.Y + 7);
	Console::drawFromFile("Map/Winner.txt", pos, (int) Color::CYAN);
	cout << "Press anything to continue";
	(void)_getch();
}

// Game over -> khi kết thúc trò chơi
void CGAME::gameOver() {
	pressable = false;
	is_running = false;
	//Console::clearScreen();
	COORD pos{ Console::getMidHorizontal() - 30, Console::getMidVertical() - 5 };
	Sleep(300);
	Console::drawFromFile("Menu/GameOverTitle.txt", pos, (int)Color::DARK_MAGENTA);
	Sleep(300);
	Console::drawFromFile("Menu/GameOverTitle.txt", pos, (int)Color::MAGENTA);
	Sleep(1000);
	Console::gotoXY(pos.X + 24, pos.Y + 7);
	cout << "Press anything to continue";
	(void)_getch();
}

// Khởi tạo lại game (làm lại theo level)
void CGAME::resetGame(short tt_size , short c_size , short xt_size , short k_size , short xh_size) {
	createTraffic(light1, TrafficLight::YELLOW, 1, true);
	createTraffic(light2, TrafficLight::GREEN, 4, true);
	createTraffic(light3, TrafficLight::RED, 5, false);

	if (cn != NULL)
		delete cn;
	cn = new CPEOPLE;
	// trực thăng
	att_size = tt_size;
	createObj(att, att_size, 1, true);
	
	// chim
	ac_size = c_size;
	createObj(ac, ac_size, 2, false);
	
	// khỉ
	ak_size = k_size;
	createObj(ak, ak_size, 3, false);

	// xe tải
	axt_size = xt_size;
	createObj(axt, axt_size, 4, true);
	
	// xe hoi
	axh_size = xh_size;
	createObj(axh, axh_size, 5, false);
}

void CGAME::exitGame(thread* t) {
	pressable = false;
	is_running = false;
	if (t->joinable())
		t->join();
	Console::clearScreen();
}

void CGAME::resumeGame(thread* t) {
	Console::gotoXY(0, 0);
	pressable = true;
	is_running = true;
	if (t->joinable()) {
		t->detach();
		*t = thread(SubThread);
	}
}

// Lưu game
void CGAME::saveGame(thread* t) {
	pressable = false;
	is_running = false;
	drawSaveMenu();
	string file_name;
	ofstream f;
	bool exit = false;

	while (!exit) {

		char c = toupper(_getch());
		switch (c) {

		case '1': case '2': case '3': case '4':
			file_name = "SaveGame/Data" + string(1, c) + ".txt";

			f.open(file_name);
			
			// Lưu vòng chơi và chế độ vô tận
			f << level << ' ' << endless_mode << '\n';

			// Lưu thông tin về người chơi: vị trí và mạng sống
			f << cn->getmX() << ' ' << cn->getmY() << ' ' << cn->getHearts() << ' ' << cn->getMaxHearts() << '\n';

			// Lưu thông tin về từng hàng: vị trí và hướng đi
			f << att_size << '\n';
			saveObj(att, att_size, f);
			f << ac_size << '\n';
			saveObj(ac, ac_size, f);
			f << ak_size << '\n';
			saveObj(ak, ak_size, f);
			f << axt_size << '\n';
			saveObj(axt, axt_size, f);
			f << axh_size << '\n';
			saveObj(axh, axh_size, f);

			// Cuối cùng, lưu đèn giao thông: vị trí, hướng nằm, thời gian các dèn chạy và trạng thái
			f << light1->getmY() << ' ' << light1->getDirection() << ' ' <<
				light1->getTimeRed() << ' ' << light1->getTimeYellow() << ' ' << light1->getTimeGreen() << ' ' << static_cast<int>(light1->getStatus()) << '\n';
			f << light2->getmY() << ' ' << light2->getDirection() << ' ' <<
				light2->getTimeRed() << ' ' << light2->getTimeYellow() << ' ' << light2->getTimeGreen() << ' ' << static_cast<int>(light2->getStatus()) << '\n';
			f << light3->getmY() << ' ' << light3->getDirection() << ' ' <<
				light3->getTimeRed() << ' ' << light3->getTimeYellow() << ' ' << light3->getTimeGreen() << ' ' << static_cast<int>(light3->getStatus()) << '\n';

			f.close();
			exit = true;
			break;

		case 27:
			exit = true;
			break;
		}
	}

	resumeGame(t);
	Console::drawFromFile(
		"Menu/OverLappingPart.txt",
		COORD{ (short)(Console::getMidHorizontal() - 15), Console::getMidVertical() },
		(int)Color::LIGHT_GRAY
	);
}

// Load game
void CGAME::loadGame() {
	pressable = false;
	is_running = false;

	drawLoadMenu();
	string file_name;
	ifstream f;
	bool exit = false;

	int value1, value2, value3, value4;

	while (!exit) {
		char c = toupper(_getch());
		switch (c) {

		case '1': case '2': case '3': case '4':
			file_name = "SaveGame/Data" + string(1, c) + ".txt";
			f.open(file_name);
			if (f.is_open()) { // Nếu tìm thấy file thì bắt đầu nhận dữ liệu

			// Tải level
				f >> level >> endless_mode;

				// Tải thông tin về người chơi: vị trí và mạng sống
				f >> value1 >> value2 >> value3 >> value4;
				if (cn != NULL)
					delete cn;
				cn = new CPEOPLE;
				cn->setCoordinates(value1, value2);
				cn->setHearts(value3);
				cn->setMaxHearts(value4);

				// Tải thông tin về từng hàng: vị trí và hướng đi
				loadObj(att, att_size, f);
				loadObj(ac, ac_size, f);
				loadObj(ak, ak_size, f);
				loadObj(axt, axt_size, f);
				loadObj(axh, axh_size, f);

				// Tải đèn giao thông: vị trí, hướng nằm, thời gian các dèn chạy và trạng thái
				loadObj2(light1, f);
				loadObj2(light2, f);
				loadObj2(light3, f);

				drawGame();
				drawObjects();
				is_running = true;
				pressable = true;
				exit = true;
			}
			f.close();
			break;

		case (int)Key::ESCAPE:
			COORD pos = { (short)(Console::getMidHorizontal() - 15), Console::getMidVertical() };
			Console::removeSpace(pos.X, pos.Y, pos.X + 31, pos.Y + 5);
			exit = true;
			break;
		}
	}
}

void CGAME::loadGame(thread* t) {
	loadGame();

	resumeGame(t);

	Console::drawFromFile(
		"Menu/OverLappingPart.txt",
		COORD{ (short)(Console::getMidHorizontal() - 15), Console::getMidVertical() },
		(int)Color::LIGHT_GRAY
	);
}

// Dừng game
void CGAME::pauseGame(thread* t) {
	is_running = false;
	int menuChoice = runPauseMenu();
	if (menuChoice == 0)
		resumeGame(t);
	else if (menuChoice == 1)
		saveGame(t);
}

/// 
/// - - - - - - - - - - - - CÁC THAO TÁC CHẠY TRONG GAME - - - - - - - - - - - - 
/// 

// Update position
void CGAME::updatePosPeople(char key, thread* t_sound) {
	key = toupper(key);
	if (pressable) {
		switch (key) {

		case 'W': case (int)Key::UP:
			cn->Up();
			if (t_sound->joinable()) {
				t_sound->detach();
				*t_sound = thread(SoundThread);
			}
			break;

		case 'A': case (int)Key::LEFT:
			cn->Left();
			break;

		case 'S': case (int)Key::DOWN:
			cn->Down();
			if (t_sound->joinable()) {
				t_sound->detach();
				*t_sound = thread(SoundThread);
			}
			break;

		case 'D': case (int)Key::RIGHT:
			cn->Right();
			break;
		}
	}
	else {
		key = 'E';
		pressable = true;
	}
}

void CGAME::updatePosAnimal() {
	for (int i = 0; i < ac_size; i++) {
		ac[i].move();
	}
	for (int i = 0; i < ak_size; i++) {
		ak[i].move();
	}
}

void CGAME::updatePosVehicle() {
	if (light1->getStatus() == TrafficLight::GREEN) {
		for (int i = 0; i < att_size; i++) {
			att[i].move();
		}
	}
	if (light2->getStatus() == TrafficLight::GREEN) {
		for (int i = 0; i < axt_size; i++) {
			axt[i].move();
		}
	}
	if (light3->getStatus() == TrafficLight::GREEN) {
		for (int i = 0; i < axh_size; i++) {
			axh[i].move();
		}
	}
}

void CGAME::runTraffic() {
	light1->runStatus();
	light2->runStatus();
	light3->runStatus();
}
