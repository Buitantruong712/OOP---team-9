#include "CGame.h"

CGAME::CGAME() {
	Console::setConsole();
    IS_RUNNING = false;
}

CGAME::~CGAME() {
    delete[] ac;
    delete[] ak;
    delete[] axh;
    delete[] axt;
    delete[] att;
    delete cn;
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
    COORD pos = { midHoritonal - 5, midVertical };
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

// Vẽ Setting Menu
void CGAME::drawSettingMenu(short choice, bool& theme, bool& music, bool& sound) {
    short count = 0;
    short midHoritonal = Console::getMidHoritonal(), midVertical = Console::getMidVertical();

    COORD pos = { midHoritonal - 5,midVertical };
    Console::drawFromFile("Menu/SettingMenuFrame.txt", pos, (int)Color::WHITE);

    for (auto& i : SETTING_MENU) {
        if (count == choice) {
            Console::setColor(16 * (int)Color::WHITE);
            if (count == 3) Console::gotoXY(pos.X + 5, pos.Y + count + 1);
            else Console::gotoXY(pos.X + 9, pos.Y + count + 1);
            if (i == 0) cout << (theme ? "DARK" : "LIGHT");
            else if (i == 1) cout << (music ? "ON" : "OFF");
            else if (i == 2) cout << (sound ? "ON" : "OFF");
            else cout << "BACK";
        }
        else {
            Console::setColor((int)Color::LIGHT_GRAY);
            if (count == 3)	Console::gotoXY(pos.X + 5, pos.Y + count + 1);
            else Console::gotoXY(pos.X + 9, pos.Y + count + 1);
            if (i == 0) cout << (theme ? "DARK" : "LIGHT");
            if (i == 1) cout << (music ? "ON" : "OFF");
            if (i == 2) cout << (sound ? "ON" : "OFF");
            if (i == 3) cout << "BACK";
        }
        count++;
    }
}

// Vẽ Menu khi dừng game
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

//
void CGAME::clearPauseMenu() {
    // Xoá cái khung
    short midHoritonal = Console::getMidHoritonal(),
        midVertical = Console::getMidVertical();
    COORD pos = { midHoritonal - 5, midVertical };
    for (int i = 0; i < 5; i++) {
        Console::gotoXY(midHoritonal - 5, midVertical + i);
        cout << string(16, ' ');
    }
    // Vẽ lại phần khung bị chồng lên
    Console::drawFromFile("Menu/OverLappingLine.txt", COORD{ (short)(midHoritonal - 5), midVertical}, (int)Color::WHITE);
    // Vẽ lại người nếu nó bị chồng lên
    cn->drawBody(1);
    // Không cần vẽ lại con vật vì nó chạy liên tục => tự động vẽ
}

// Thao tác trên menu chính
short CGAME::runMenu() {
    short menuChoice = 0;
    while (true) {
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
            return menuChoice;
            break;
        default:
            break;
        }
    }
}

void CGAME::setting()
{
    short menuChoice = 0;
    bool exit = false;
    while (!exit) {
        drawSettingMenu(menuChoice, theme, sound, music);

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
                if (!theme) {}
                else {}
                theme = !theme;
                break;
            case 1:
                if (!sound) {}
                else {}
                sound = !sound;
                break;
            case 2:
                if (!music) {}
                else {}
                music = !music;
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

// 
short CGAME::runPauseMenu(){
    Sleep(100);
    short menuChoice = 0;
    while (1) {
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
            clearPauseMenu();
            return menuChoice;
            break;
        default:
            break;
        }
    }
}

// Vẽ màn hình chơi game
void CGAME::drawGame() {
    Console::clearScreen();
    Console::drawFromFile("Map/Frame.txt", COORD{ (short)Border::LEFT - 2, (short)Border::TOP - 1 }, (int)Color::LIGHT_GRAY);
    Console::drawFromFile("Map/Help.txt", COORD{ (short)Border::LEFT + 128, (short)Border::TOP - 1 }, (int)Color::WHITE);
    Console::drawFromFile("Level/Level1.txt", COORD{ (short)Border::LEFT + 102, (short)Border::TOP - 5 }, (int)Color::RED);
    cn->initPeople();
}

// Bắt đầu game
void CGAME::startGame() {
    resetGame();
    drawGame();
    IS_RUNNING = true;
}

// Game over -> khi kết thúc trò chơi
void CGAME::gameOver() {
    COORD pos{ Console::getMidHoritonal() - 30, Console::getMidVertical() - 5 };
    Sleep(300);
    Console::drawFromFile("Menu/GameOverTitle.txt", pos, (int)Color::MAGENTA);
    Sleep(300);
    Console::drawFromFile("Menu/GameOverTitle.txt", pos, (int)Color::LIGHT_MAGENTA);
    Sleep(1000);
    Console::gotoXY(pos.X + 15, pos.Y + 7);
    cout << "Press anything to continue";
    _getch();
}

// Khởi tạo lại game (làm lại theo level)
void CGAME::resetGame() {
    cn = new CPEOPLE;
    ac_size = 5;
    createObj(ac, ac_size, 2, true);
    att_size = 3;
    createObj(att, att_size, 1, false);
    axt_size = 2;
    createObj(axt, axt_size, 3, true);
    ak_size = 4;
    createObj(ak, ak_size, 4, false);
    axh_size = 3;
    createObj(axh, axh_size, 5, true);
}

void CGAME::exitGame(thread &t) {
    IS_RUNNING = false;
    Console::clearScreen();
    if(t.joinable())
        t.join();
}

void CGAME::resumeGame(thread &t) {
    IS_RUNNING = true;
    if (t.joinable()) {
        t.detach();
        t = thread(SubThread);
    }  
}

// Dừng game
void CGAME::pauseGame(thread &t) {
    IS_RUNNING = false;
    int menuChoice = runPauseMenu();
    if (menuChoice == 0)
        resumeGame(t);
}

// Update position
void CGAME::updatePosPeople(char key) {
    key = toupper(key);
    switch (key) {
    case 'W':
        cn->Up();
        break;
    case 'A':
        cn->Left();
        break;
    case 'S':
        cn->Down();
        break;
    case 'D':
        cn->Right();
        break;
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

void CGAME::updatePosVehical() {
    for (int i = 0; i < att_size; i++) {
        att[i].move();
    }
    for (int i = 0; i < axh_size; i++) {
        axh[i].move();
    }
    for (int i = 0; i < axt_size; i++) {
        axt[i].move();
    }
}