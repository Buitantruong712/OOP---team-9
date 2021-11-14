#include "cgame.h"


CGAME::CGAME() {
	short quantity = 8;

	Bird new_bird(3, false, 5); // Hàng 3, đi từ trái sang phải

	for (int i = 0; i < quantity; i++) {
		new_bird.setTimer(rand() % 120 + 30);
		birds.push_back(new_bird);
		birds[i].setIndex(i);
	}

	level = 1;
	state = RESUME;
}


void CGAME::drawGame() {
	Console::drawGameBot();
}


CGAME::~CGAME() {

}

//CPEOPLE getPeople();
//CVEHICLE * getVehicle();
std::vector <Bird> CGAME::getAnimal() {
	return birds;
}

void CGAME::resetGame() {

}

void CGAME::exitGame() {
	
}

void CGAME::startGame() {
	// Reset mọi thứ
	player.setCoordinates(12, 6);
	player.resetHearts();

	// Vẽ khung
	drawGame();
	player.drawBody();
	player.drawHealthBar();

	// Đặt lại vị trí các con chim (tính trường hợp startGame chạy lần hai)
	for (auto& i : birds) {
		i.setTrueX(0); // tạm thời cho chim chạy từ trái sang phải
	}

	// Chạy vòng lặp
	resumeGame();
}

void CGAME::loadGame() {
	drawSaveMenuFrame();
	Console::gotoXY(55, 20);
	std::cout << " Press number to load ";

	char input;
	char file_number = 0;

	bool exit = false;
	bool exit_replace = false;
	std::ifstream f;

	while (not exit) {
		// Vẽ các mục menu
		drawSaveMenuLines();
		Console::gotoXY(61, 24);
		std::cout << "(X) Cancel";

		input = toupper(_getch());
		short value1, value2, value3; // dùng để nhận thông số

		switch (input) {

			// Nếu nhập số
		case '1': case '2': case '3': case '4':
			// kiểm tra file tồn tại hay không
			file_number = input;
			f.open("SaveGame/" + std::string(1, file_number) + ".txt");

			// Nếu có: thay đổi thông số
			if (f.is_open()) {
				f >> value1 >> value2;
				player.setCoordinates(value1, value2);

				f >> value1 >> value2 >> value3;
				level = value1;
				player.setHearts(value2);
				player.setMaxHearts(value3);

				f >> value1;
				// size of birds
				
				for (auto& i : birds) {
					f >> value1 >> value2 >> value3;
					i.setTrueX(value1);
					i.setY(value2);
					i.setState(value3);

					f >> value1 >> value2 >> value3;
					i.setDirection(value1);
					i.setTimer(value2);
					i.setRunningTimer(value3);

					exit = true;
				}
			}
			// Nếu không, báo lỗi
			else {
				Console::gotoXY(51, 26);
				std::cout << "Data " << file_number << " does not exist";
			}

			f.close();

			break;

		case 'X': case 27:
			exit = true;
			Console::clearScreen();
			return; // thoát đến menu thay vì nhảy vào trò chơi
			break;
		}
	}

	drawGame();
	player.drawBody();
	player.drawHealthBar();


	// Chạy vòng lặp
	resumeGame();
}


void CGAME::saveGame() {
	// Vẽ cái khung
	drawSaveMenuFrame();
	Console::gotoXY(52, 24);
	std::cout << "(X) Cancel     (Esc) Leave";
	Console::gotoXY(55, 20);
	std::cout << " Press number to save ";

	// Thao tác nhấn
	char input; // Khi dừng game, không sử dụng kbhit()
	char file_number = 0;

	bool exit = false;
	bool exit_replace = false; // vòng lặp cho thay thế file
	std::ofstream f;

	while (not exit) {
		// Vẽ các mục menu
		drawSaveMenuLines();

		input = toupper(_getch());

		switch (input) {

		// Nếu nhập số
		case '1': case '2': case '3': case '4':
			// kiểm tra file tồn tại hay không
			file_number = input;
			f.open("SaveGame/" + std::string(1, file_number) + ".txt");

			// Nếu có: cho người chơi chọn nhập hay không
			if (f.is_open()) {
				Console::gotoXY(51, 26);
				std::cout << "Replace " << file_number << " ? Yes (Z), No (X)";
				
				while (not exit_replace) {

					input = toupper(_getch());
					switch (input) {

					// Chọn có: save và thoát luôn cả khung
					case 'Z': case 'Y':
						exit = true;
						exit_replace = true;

						setSaveFile(file_number);

						removeSaveMenu(player.getX(), player.getY());
						Console::gotoXY(51, 26);
						std::cout << std::string(27, ' ');
						break;

					// Chọn không: cho người dùng thao tác tiếp
					case 'X': case 'N':
						exit_replace = true;

						Console::gotoXY(51, 26);
						std::cout << std::string(27, ' ');

						break;
					}
				}
			}
			// Nếu không, lưu trực tiếp
			else {
				exit = true;
				setSaveFile(file_number);
				removeSaveMenu(player.getX(), player.getY());
			}

			break;

		// Nếu chỉ thoát save menu
		case 'X':
			exit = true;
			removeSaveMenu(player.getX(), player.getY());
			break;

		// Nếu thoát luôn trò chơi
		case 27:
			state = EXIT;
			exit = true;
			break;
		}
	}
}

void CGAME::setSaveFile(char file_number) {
	// bắt đầu lưu
	std::ofstream f;
	f.open("SaveGame/" + std::string(1, file_number) + ".txt", std::ios::out);

	// 1) lưu vị trí player, vòng và mạng sống
	f << player.getX() << ' ' << player.getY() << '\n';
	f << level << ' ' << player.getHearts() << ' ' << player.getMaxHearts() << '\n';

	// 2) lưu vị trí con chim, trạng thái, hướng đi và thời gian chờ của nó
	f << birds.size() << '\n';
	for (auto& i : birds)
		f << i.getTrueX() << ' ' << i.getY() << ' ' << i.getState() << ' ' << i.getDirection() << ' ' << i.getTimer() << ' ' << i.getRunningTimer() << '\n';

	// đóng file
	f.close();
}

void CGAME::pauseGame() {
	// Vẽ cái khung
	drawPauseMenuFrame();

	// Thao tác nhấn
	char input; // Khi dừng game, không sử dụng kbhit()
	char line_position = 0;
	bool exit = false;

	while (not exit) {

		// Vẽ các mục menu
		drawPauseMenuLines(line_position);

		input = toupper(_getch());

		switch (input) {

		case 'W': case 'A':
			line_position--;
			if (line_position < 0)
				line_position = 2;
			break;

		case 'S': case 'D':
			line_position++;
			if (line_position > 2)
				line_position = 0;
			break;

		case 13: case 'Z': // Enter
			exit = true;
			// Phụ thuộc vào bàn phím
			switch (line_position) {
			case 0:
				state = RESUME;
				removePauseMenu(player.getX(), player.getY());
				break;
			case 1:
				saveGame();
				break;
			case 2:
				state = EXIT;
				break;
			}
			return;
			break;
		}
	}
}

void CGAME::resumeGame() {
	char get_input = 0;

	state = RESUME;

	while (1) {
		// Chạy con vật và xe cộ
		moveAnimal();
		moveVehicle();

		// Tính va chạm
		if (player.impact(birds)) { // player.impact() ảnh hưởng đến player.isDead(), và làm chính nó trả về "false" một thời gian
			player.drawHealthBar();
		}

		// Nếu hết mạng
		if (player.isDead()) {
			player.gameOver();
			Console::clearScreen();
			return;
		}

		// Chạy người chơi
		movePeople(get_input);
		if (get_input == 27) {
			pauseGame();
			get_input = 0;
		}

		// Nếu người chơi chạm đến đích, cộng thêm điểm level (tạm thời chưa code phần này)
		if (player.isFinish()) {
			level++;
			player.resetPosition();
		}

		// Nếu thoát ra trò chơi
		if (state == EXIT) {
			Console::clearScreen();
			return;
		}

		// Thời gian nghỉ
		Sleep(10);
	}
}

void CGAME::movePeople(char& get_input) {
	player.runInvulnerableTime();
	player.Control(get_input);
}

void CGAME::moveVehicle() {

}

void CGAME::moveAnimal() {
	for (auto& i : birds) {
		if (i.getTimer() == 0)
			i.setTimer(rand() % 120 + 30);
		i.cMove();
	}
}
