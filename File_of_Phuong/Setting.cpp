#include "Setting.h"

// Constructor
Setting::Setting() {
    // initialize
    language[0][0] = "  New game  ";
    language[0][1] = "  Load game  ";
    language[0][2] = "  Rank  ";
    language[0][3] = "  Setting  ";
    language[0][4] = "  Quit  ";

    language[1][0] = "  Ván mới  ";
    language[1][1] = "  Chơi tiếp  ";
    language[1][2] = "  Hạng  ";
    language[1][3] = "  Cài đặt  ";
    language[1][4] = "  Thoát  ";

    // Default language is English
    chosenLanguage = 0;
    sound = 1;
}

// Some feature
void Setting::TurnOnMusic() {
    sound = 1;
}

void Setting::TurnOffMusic() {
    sound = 0;
}

void Setting::VietNamese() {
    chosenLanguage = 1;
}

void Setting::English() {
    chosenLanguage = 0;
}

// Get Status
bool Setting::MusicStatus() {
    return sound;
}

bool Setting::LanguageStatus() {
    return chosenLanguage;
}

string Setting::getLanguage(int sentence) {
    return language[LanguageStatus()][sentence];
}

void Setting::drawSetting() {
    textColor(255);
    
    // draw top edge
    gotoXY(69, 25);
    for(int i = 0; i < 20; i++)
        cout << char(178);
    // draw bot edge
    gotoXY(69, 31);
    for(int i = 0; i < 20; i++)
        cout << char(178);
    // draw left and right
    for(int i = 0; i < 5; i++) {
        gotoXY(69, 26 + i);
        cout << char(178);
        gotoXY(89, 26 + i);
        cout << char(178);
    }

    // Print command
    gotoXY(71, 27);
    cout << "LANGUAGE:      ENGLISH";
    gotoXY(73, 27);
    cout << "MUSIC:         ON";
}