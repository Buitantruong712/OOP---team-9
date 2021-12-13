#include "CGame.h"

CGAME::CGAME() {
	Console::setConsole();
    exit_game = true;       // Lúc đầu sẽ vào main menu thay vì game thật sự
    runMenu();
}

CGAME::~CGAME() {
    delete[] cars_2;
    delete[] birds;
    delete[] birds_2;
    delete[] cars;
    delete[] trucks;
}

// Tạo đối tượng mobs
template<class T> 
void createObj(T*& obj, int size, short row, bool direction) {
    int column = (short)Border::LEFT;
    int distance = ((short)Border::RIGHT - (short)Border::LEFT) / size;
    if (obj != NULL)
        delete[] obj;
    obj = new T[size];
    for (int i = 0; i < size; i++) {
        obj[i].setX(column);
        obj[i].setDirection(direction);
        obj[i].setmY(row);
        column += distance;
    }    
}

// Tiêu đề game
void CGAME::drawTitle() {
    short i = 0;
    for (i; i < 10; i++) {
        COORD pos = { i,3 };
        Console::drawFromFile("Menu/Car.txt", pos, (int)Color::RED);
        Sleep(100);
    }
    
    COORD pos = { 75 ,1 };
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::LIGHT_GRAY);
	Sleep(300);
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::LIGHT_YELLOW);
	Sleep(300);
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::YELLOW);
    Sleep(300);

    pos = { 145, 5 };
    Console::drawFromFile("Menu/Road.txt", pos, (int)Color::GREEN);
    pos = { (short)(i - 1),3 };
    Console::drawFromFile("Menu/Car.txt", pos, (int)Color::RED);
    Sleep(100);
}

// Vẽ Menu chính 
void CGAME::drawMainMenu(short choice) {
    short count = 0;
    short midHoritonal = Console::getMidHoritonal(),
        midVertical = Console::getMidVertical();
    COORD pos = { midHoritonal - 5,midVertical };
    Console::drawFromFile("Menu/MainMenuFrame.txt", pos, (int)Color::WHITE);
    for (auto &i : MAIN_MENU) {
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

void CGAME::drawPauseMenu(short choice) {
    short count = 0;
    short midHoritonal = Console::getMidHoritonal(),
        midVertical = Console::getMidVertical();
    COORD pos = { midHoritonal - 5, midVertical };
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

// Thao tác trên menu chính
void CGAME::runMenu() {
    short menuChoice = 0;
    bool exit = false;
    drawTitle();
    while (!exit) {
        drawMainMenu(menuChoice);
        char c = toupper(_getch());
        switch (c)
        {
        case (int)Key::UP: case (int)Key::LEFT: case 'W': case 'A':
            menuChoice--;
            if (menuChoice < 0)
                menuChoice = 3;
            break;
        case (int)Key::DOWN: case (int)Key::RIGHT: case 'S': case 'D':
            menuChoice++;
            if (menuChoice > 3)
                menuChoice = 0;
            break;
        case (int)Key::ENTER:
            switch (menuChoice) {
            case 0:
                drawGame();  
                drawTitle();
                break;
            case 1:
                drawTitle();
                break;
            case 2:
                drawTitle();
                break;
            case 3:
                exit = true;
                break;
            default:
                break;
            }
        default:
            break;
        }
    }
}


void CGAME::drawGame() {
    Console::clearScreen();
    Console::drawFromFile("Map/Frame.txt", COORD{(short)Border::LEFT - 2, (short)Border::TOP - 1}, (int)Color::WHITE);
    cn.initPeople();
    startGame();
}

void CGAME::startGame() {
    resetGame();
    char c = 0;
    exit_game = false;
    while (!exit_game) {
        updatePosAnimal();
        updatePosVehical();
        
        // Kiểm tra va chạm
        const CVEHICLE* temp_cvehicle = cars_2;
        const CANIMAL* temp_canimal = birds;
        const CANIMAL* temp_canimal_2 = birds_2;
        const CVEHICLE* temp_cvehicle_2 = cars;
        const CVEHICLE* temp_cvehicle_3 = trucks;

        if (
            cn.isImpact(temp_cvehicle, cars_2_size) ||
            cn.isImpact(temp_canimal, birds_size) ||
            cn.isImpact(temp_canimal_2, birds_2_size) ||
            cn.isImpact(temp_cvehicle_2, cars_2_size) ||
            cn.isImpact(temp_cvehicle_3, trucks_size)
            ) {
            cn.setHeart(cn.getHearts() - 1);
            cn.drawHealthBar();
            Console::removeSpace(cn.getX(), cn.getY());     // Va chạm = reset lại vị trí ban đầu
            cn.resetPosition();
        }

        // Kiểm tra hết mạng
        if (cn.isDead()) {
            Console::clearScreen();
            cn.gameOver();
            Console::clearScreen();
            return;
        }

        cn.Control(c);

        // Kiểm tra đến đích 
        if (cn.isFinish()) {
            //level++;
            cn.resetPosition();
        }

        // Kiểm tra có nhấn Esc để dừng game không
        if (c == 27) {
            pauseGame();
            c = 1;      // Nếu không có c = 27, và kẹt ở đây
        }

        // Thời gian giãn cách
        Sleep(60);
    }
}

void CGAME::resetGame() {
    cars_2_size = 3;
    createObj(cars_2, cars_2_size, 1, false);
    birds_size = 3;
    createObj(birds, birds_size, 2, true);
    birds_2_size = 3;
    createObj(birds_2, birds_2_size, 3, false);
    cars_size = 3;
    createObj(cars, cars_size, 4, true);
    trucks_size = 2;
    createObj(trucks, trucks_size, 5, true);
}

void CGAME::pauseGame() {
    short menuChoice = 0;
    bool exit = false;
    while (!exit) {
        drawPauseMenu(menuChoice);
        char c = toupper(_getch());
        switch (c)
        {
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
            switch (menuChoice) {
            case 0:
                exit = true;
                break;
            case 1:
                //saveGame(cin);
                break;
            case 2:
                exit = true;
                exit_game = true;
                break;
            default:
                break;
            }
        default:
            break;
        }
    }
    
    // Xoá cái khung
    short midHoritonal = Console::getMidHoritonal(),
        midVertical = Console::getMidVertical();
    COORD pos = { midHoritonal - 5, midVertical };
    for (int i = 0; i < 5; i++) {
        Console::gotoXY(midHoritonal - 5, midVertical + i);
        cout << string(16, ' ');
    }
    // Vẽ lại phần khung bị chồng lên
    Console::drawFromFile("Menu/OverLappingLine.txt", COORD{ midHoritonal - 5, midVertical }, (int)Color::WHITE);
    // Vẽ lại người nếu nó bị chồng lên
    cn.drawBody();
    // Không cần vẽ lại con vật vì nó chạy liên tục => tự động vẽ
}

// Getter
CPEOPLE CGAME::getPeople() {
    return cn;
}

// Update position
void CGAME::updatePosAnimal() {
    for (int i = 0; i < birds_size; i++) {
        birds[i].move();
    }
    for (int i = 0; i < birds_2_size; i++) {
        birds_2[i].move();
    }
}

void CGAME::updatePosVehical() {
    for (int i = 0; i < cars_size; i++) {
        cars[i].move();
    }
    for (int i = 0; i < cars_2_size; i++) {
        cars_2[i].move();
    }
    for (int i = 0; i < trucks_size; i++) {
        trucks[i].move();
    }
}