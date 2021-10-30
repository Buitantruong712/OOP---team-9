#include "Menu.h"

int Menu::getLength() { return Logo[0].size(); }

// Constructor
Menu::Menu() {
    // Input logo information
    fstream file;
    file.open("Logo.txt", ios::in);
    for (int i = 0; i < 13; i++) getline(file, Logo[i]);

    realChoice = 0;
}

// Draw logo
void Menu::DrawLogo() {
    for (int i = 1; i <= 15; i++) {
        textColor(i);
        for (int i = 0; i < 13; i++) {
            gotoXY(30, 10 + i);
            cout << Logo[i];
        }
        Sleep(150);
    }
}

// Draw items
void Menu::DrawItems(int choose) {
    int mid = (60 + getLength()) / 2;

    for (int i = 0; i < 5; i++) {
        if (i == choose) {
            textColor(240);
            gotoXY(mid - S.getLanguage(0).size() / 2, 26 + i);
            cout << S.getLanguage(0);
        } else {
            textColor(15);
            gotoXY(mid - S.getLanguage(i).size() / 2, 26 + i);
            cout << S.getLanguage(i);
        }
    }
}

// Start Menu
void Menu::StartMenu() {
    system("cls");
    if(S.MusicStatus())
        PlaySound(TEXT("preview.wav"), NULL, SND_FILENAME | SND_ASYNC);
    DrawLogo();
    DrawItems(0);
}
