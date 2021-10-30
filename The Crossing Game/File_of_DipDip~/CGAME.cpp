#include "CGAME.h"

CGAME::CGAME() {
    initConsole();
    drawTitle();
    runMenu();
}

CGAME::~CGAME() {

}

void CGAME::drawTitle() {
    ifstream title("title.txt", ios::in);
    if (title.fail()) {
        cout << "Can't open file" << endl;
        return;
    }
    string temp;
    srand(time(0));
    int count = 0;
    while (!title.eof()) {
        getline(title, temp);
        GotoXY(30, count + 5);
        textcolor(rand() % 14 + 1);
        cout << temp << endl;
        Sleep(50);
        count++;
    }
    title.close();
}

void CGAME::drawMenu(short choice) {
    short count = 0;
    int midHoritonal = getMidHoritonal(),
        midVertical = getMidVertical();
    for (auto i : MENU) { 
        if (count == choice) {
            textcolor((int)Color::RED);
            GotoXY(midHoritonal - i.size() / 2, midVertical + count - 3);
            cout << i;
        }
        else {
            textcolor((int)Color::WHITE);
            GotoXY(midHoritonal - i.size() / 2, midVertical + count - 3);
            cout << i;
        }
        count++;
    }
}

void drawCarMenu() {
    ifstream car("Car.txt", ios::in);
    string temp;
    getline(car, temp);
    const int n = stoi(temp);
    string* s = new string[n];
    int i = 0;
    while (!car.eof() && i < n) {
        getline(car, temp);
        s[i++] = temp;
    }
    car.close();

    i = 0;
    int columns = getSize() / HELPGETSIZE;
    bool flag = 0;
    while (true) {
        for (int j = 0; j < n; j++) {
            textcolor((int)Color::BLUE);
            GotoXY(i, j + 28);
            cout << s[j];
        }
        if (flag == 0)
            i++;
        else
            i--;
        if (i == columns - 55)
            flag = 1;
        else if (i == 0)
            flag = 0;
        Sleep(100);
    }
    delete[]s;
}

void CGAME::runMenu() {
    short menuChoice = 0;
    bool exit = false;
    thread car(drawCarMenu);
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
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                exit = true;
                car.detach();
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
}