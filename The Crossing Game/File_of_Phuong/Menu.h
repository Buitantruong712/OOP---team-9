#pragma once
#include "Support.h"
#include "Setting.h"

class Menu {
private:
    string Logo[13];
    Setting S;
    int realChoice;
    int getLength();
public:
    // Constructor
    Menu();
    
    // Draw logo
    void DrawLogo();

    // Draw item
    void DrawItems(int);

    // Start up menu
    void StartMenu();
};