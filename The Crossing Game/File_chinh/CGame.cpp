#include "CGame.h"

CGAME::CGAME() {
	Console::setConsole();
    IS_RUNNING = false;
    LEVEL = 1;
    cn = new CPEOPLE;
    resetGame();
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

// Car ở menu chính
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
        if (posCar.X == COLUMS - 55)
            flag = 1;
        else if (posCar.X == 0)
            flag = 0;
        Sleep(50);
    }
}

// Tiêu đề game
void CGAME::drawTitle() {
    COORD pos = { 0,0 };
    Console::drawFromFile("Menu/Title.txt", pos, (int)Color::GRAY);
    Sleep(200);
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::LIGHT_RED);
	Sleep(200);
	Console::drawFromFile("Menu/Title.txt", pos, (int)Color::RED);
}

// Vẽ level hiện tại
void CGAME::drawLevel()
{
    COORD posLevel = { (short)Border::LEFT + 98, (short)Border::TOP + 1 };

    Console::removeSpace((short)Border::LEFT + 98, (short)Border::TOP - 5);
    Console::removeSpace((short)Border::LEFT + 110, (short)Border::TOP - 5);
    if (LEVEL == 1)     Console::drawFromFile("Level/Level1.txt", posLevel, (int)Color::RED);
    else if (LEVEL == 2) Console::drawFromFile("Level/Level2.txt", posLevel, (int)Color::RED);
    else if (LEVEL == 3) Console::drawFromFile("Level/Level3.txt", posLevel, (int)Color::RED);
    else if (LEVEL == 4) Console::drawFromFile("Level/Level4.txt", posLevel, (int)Color::RED);
    else if (LEVEL == 5) Console::drawFromFile("Level/Level5.txt", posLevel, (int)Color::RED);
}

// Vẽ màn hình chơi game
void CGAME::drawGame() {
    system("cls");
    Console::drawFromFile("Map/Frame.txt", COORD{ (short)Border::LEFT - 2, (short)Border::TOP - 1 }, (int)Color::WHITE);
    Console::drawFromFile("Map/Help.txt", COORD{ (short)Border::RIGHT + 10, (short)Border::TOP - 1 }, (int)Color::WHITE);
    drawLevel();
    cn->initPeople();
}

// Vẽ Menu chính 
void CGAME::drawMainMenu(short choice) {
    short count = 0;
    short midHoritonal = Console::getMidHoritonal(),
        midVertical = Console::getMidVertical();
    COORD pos = { midHoritonal - 5, midVertical - 2 };
    Console::drawFromFile("Menu/MainMenuFrame.txt", pos, (int)Color::YELLOW);

    for (auto& i : MAIN_MENU) {
        if (count == choice) {
            Console::setColor(16 * (int)Color::YELLOW);
            Console::gotoXY(pos.X + 2, pos.Y + count + 1);
            cout << i;
        }
        else {
            Console::setColor((int)Color::YELLOW);
            Console::gotoXY(pos.X + 2, pos.Y + count + 1);
            cout << i;
        }
        count++;
    }
}

// Vẽ Setting Menu
void CGAME::drawSettingMenu(short choice) {
    short count = 0;
    short midHoritonal = Console::getMidHoritonal(), 
          midVertical = Console::getMidVertical();

    COORD pos = { midHoritonal - 5, midVertical - 2 };
    Console::drawFromFile("Menu/SettingMenuFrame.txt", pos, (int)Color::YELLOW);

    for (auto& i : SETTING_MENU) {
        if (count == choice) {
            Console::setColor(16 * (int)Color::YELLOW);
            Console::gotoXY(pos.X + 2, pos.Y + count + 1);
            if (count == 0) cout << i << ": " << (THEME ? "DARK " : "LIGHT");
            if (count == 1) cout << i << ": " << (SOUND ? "ON   " : "OFF  ");
            if (count == 2) cout << i << ": " << (MUSIC ? "ON   " : "OFF  ");
            if (count == 3) cout << i;
        }
        else {
            Console::setColor((int)Color::YELLOW);
            Console::gotoXY(pos.X + 2, pos.Y + count + 1);
            if (count == 0) cout << i << ": " << (THEME ? "DARK " : "LIGHT");
            if (count == 1) cout << i << ": " << (SOUND ? "ON   " : "OFF  ");
            if (count == 2) cout << i << ": " << (MUSIC ? "ON   " : "OFF  ");
            if (count == 3) cout << i;
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
            Console::setColor((int)Color::WHITE);
            Console::gotoXY(pos.X + 2, pos.Y + count + 1);
            cout << i;
        }
        count++;
    }
}

// Xóa khung pause menu
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
    cn->drawBody();
    // Không cần vẽ lại con vật vì nó chạy liên tục => tự động vẽ
}

// Game over -> khi kết thúc trò chơi
void CGAME::gameOver() {
    system("cls");
    short midHoritonal = Console::getMidHoritonal(),
        midVertical = Console::getMidVertical();

    COORD pos = { midHoritonal -35, midVertical - 5 };
    Sleep(300);
    Console::drawFromFile("Menu/GameOverTitle.txt", pos, (int)Color::MAGENTA);
    Sleep(300);
    Console::drawFromFile("Menu/GameOverTitle.txt", pos, (int)Color::LIGHT_MAGENTA);
    if (SOUND) {
        PlaySound(L"Sound/GameOver.wav", NULL, SND_FILENAME);
    }
    Console::gotoXY(pos.X + 25, pos.Y + 7);
    cout << "Press anything to continue";
    char c = _getch();
    system("cls");
}

// Thao tác trên menu chính
short CGAME::runMainMenu() {
    drawTitle();
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
            if (SOUND) {
                PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
            }
            break;
        case (int)Key::DOWN: case (int)Key::RIGHT: case 'S': case 'D':
            menuChoice++;
            if (menuChoice > 3)
                menuChoice = 0;
            if (SOUND) {
                PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
            }
            break;
        case (int)Key::ENTER:
            if (SOUND) {
                PlaySound(L"Sound/Enter.wav", NULL, SND_FILENAME);
            }
            carRunning = 0;
            car.join();
            return menuChoice;
            break;
        default:
            break;
        }
    }
}

// Thao tác trên PauseMenu
short CGAME::runPauseMenu() {
    Sleep(100);             // Tạm dừng để không bị các Mobs vẽ chồng lên menu khi thread chưa kịp dừng
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
            if (SOUND) {
                PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
            }
            break;
        case (int)Key::DOWN: case (int)Key::RIGHT: case 'S': case 'D':
            menuChoice++;
            if (menuChoice > 2)
                menuChoice = 0;
            if (SOUND) {
                PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
            }
            break;
        case (int)Key::ENTER:
            if (SOUND) {
                PlaySound(L"Sound/Enter.wav", NULL, SND_FILENAME);
            }
            clearPauseMenu();
            return menuChoice;
            break;
        default:
            break;
        }
    }
}

// Thao tác trên setting menu
void CGAME::runSettingMenu() {
    short menuChoice = 0;
    while (1) {
        drawSettingMenu(menuChoice);
        char c = toupper(_getch());
        switch (c)
        {
        case (int)Key::UP: case (int)Key::LEFT: case 'W': case 'A':
            menuChoice--;
            if (menuChoice < 0)
                menuChoice = 3;
            if (SOUND) {
                PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
            }
            break;
        case (int)Key::DOWN: case (int)Key::RIGHT: case 'S': case 'D':
            menuChoice++;
            if (menuChoice > 3)
                menuChoice = 0;
            if (SOUND) {
                PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
            }
            break;
        case (int)Key::ENTER:
            if (SOUND) {
                PlaySound(L"Sound/Enter.wav", NULL, SND_FILENAME);
            }
            switch (menuChoice) {
            case 0:
                THEME = !THEME;
                Console::setColor((int)Color::BLACK);
                system("cls");
                return;
            case 1:
                SOUND = !SOUND;
                break;
            case 2:
                MUSIC = !MUSIC;
                break;
            case 3:
                return;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

// Khởi tạo lại game (làm lại theo level)
void CGAME::resetGame() {
    att_size = 3;
    createObj(att, att_size, 1, true);
    ac_size = 5;
    createObj(ac, ac_size, 2, false);
    axt_size = 2;
    createObj(axt, axt_size, 3, true);
    ak_size = 4;
    createObj(ak, ak_size, 4, false);
    axh_size = 3;
    createObj(axh, axh_size, 5, true);
}

// Bắt đầu game
void CGAME::startGame() {
    resetGame();
    drawGame();
    IS_RUNNING = true;
}

// Thoát game
void CGAME::exitGame(thread* t) {
    IS_RUNNING = false;
    if(t->joinable())
        t->join();
    system("cls");
}

// Dừng game
bool CGAME::pauseGame(thread* t) {
    IS_RUNNING = false;
    int menuChoice = runPauseMenu();
    if (menuChoice == 0) {
        resumeGame(t);
    }
    else if (menuChoice == 1) {
        //
    }
    else {
        exitGame(t);
        return 0;
    }
    return 1;
}

// Tiếp tục game
void CGAME::resumeGame(thread* t) {
    IS_RUNNING = true;
    if (t->joinable()) {
        t->detach();
        *t = thread(SubThread);
    }  
}

void CGAME::setting() {
    runSettingMenu();
}

// Update level
void CGAME::upLevel() {
    LEVEL++;
}

// Update position người
void CGAME::updatePosPeople(char key, thread* t) {
    key = toupper(key);
    switch (key) {
    case 'W':
        cn->Up();
        if (t->joinable()) {
            t->detach();
            *t = thread(SoundThread);
        }
        break;
    case 'A':
        cn->Left();
        break;
    case 'S':
        cn->Down();
        if (t->joinable()) {
            t->detach();
            *t = thread(SoundThread);
        }
        break;
    case 'D':
        cn->Right();
        break;
    }
}

// Update position vật
void CGAME::updatePosAnimal() {
    for (int i = 0; i < ac_size; i++) {
        ac[i].move();
    }
    for (int i = 0; i < ak_size; i++) {
        ak[i].move();
    }
}

// Update position xe
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