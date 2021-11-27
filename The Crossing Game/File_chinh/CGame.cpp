#include "CGame.h"

CGAME::CGAME() {
	Console::setConsole();
    runMenu();
}

CGAME::~CGAME() {
    delete[]ac;
    delete[]axh;
}

// Tạo đối tượng mobs
template<class T> 
void createObj(T*& obj, int num, short row, bool direct = 1) {
    int col = (short)Border::LEFT;
    int distance = ((short)Border::RIGHT - (short)Border::LEFT) / num;
    obj = new T[num];
    for (int i = 0; i < num; i++) {
        obj[i].setX(col);
        obj[i].setDirection(direct);
        obj[i].setmY(row);
        col += distance;
    }    
}
// Tiêu đề game
void CGAME::drawTitle() {
    int i = 0;
    for (i; i < 10; i++) {
        COORD pos = { i,3 };
        Console::drawFromFile("Menu/Car.txt", pos, (int)Color::RED);
        Sleep(100);
    }
    
    COORD pos = { 75 ,1 };
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::WHITE);
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
void CGAME::drawMenu(short choice) {
    short count = 0;
    int midHoritonal = Console::getMidHoritonal(),
        midVertical = Console::getMidVertical();
    COORD pos = { midHoritonal - 5,midVertical };
    Console::drawFromFile("Menu/MainMenuFrame.txt", pos, (int)Color::BRIGHT_WHITE);
    for (auto i : MENU) {
        if (count == choice) {
            Console::setColor(16 * (int)Color::BRIGHT_WHITE);
            Console::gotoXY(pos.X + 2, pos.Y + count + 1);
            cout << i;
        }
        else {
            Console::setColor((int)Color::WHITE);
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
        drawMenu(menuChoice);
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
    Console::drawFromFile("Map/Frame.txt", COORD{(short)Border::LEFT - 2, (short)Border::TOP - 1}, (int)Color::BRIGHT_WHITE);
    cn.initPeople();
    startGame();
}

void CGAME::startGame() {
    resetGame();
    char c = 0;
    while (1) {
        updatePosAnimal();
        updatePosVehical();
        
        // Kiểm tra va chạm
        const CVEHICLE* tempVehi = axh;
        const CANIMAL* tempAn = ac;
        if (cn.isImpact(tempVehi, axhNumber) || cn.isImpact(tempAn, acNumber)) {
            cn.setHeart(cn.getHearts() - 1);
            cn.drawHealthBar();
            Console::removeSpace(cn.getX(), cn.getY());
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
    }
}

void CGAME::resetGame() {

    acNumber = 3;   //(level)
    createObj(ac, acNumber, 1);
    axhNumber = 3; //(levle)
    createObj(axh, axhNumber, 5);
}

// Getter
CPEOPLE CGAME::getPeople() {
    return cn;
}

// Update position
void CGAME::updatePosAnimal() {
    for (int i = 0; i < acNumber; i++) {
        ac[i].move();
    }
    Sleep(30);
}

void CGAME::updatePosVehical() {
    for (int i = 0; i < axhNumber; i++) {
        axh[i].move();
    }
    Sleep(30);
}