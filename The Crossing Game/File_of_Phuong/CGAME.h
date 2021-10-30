#include "Menu.h"

class CGAME {
private:
    Menu menu;

public:
    // Constructor
    CGAME();

    // Start
    void StartupInterface();

    // Get information about objects

    
    // Draw map
    void DrawMap();

    // Game Action
    void resetGame();
    void exitGame();
    void startGame();
    void loadGame();
    void saveGame();
    void pauseGame(HANDLE);
    void resumeGame(HANDLE);

    // update position of object
    void updatePosPeople(char);
    void updatePosVehicle();
    void updatePosAnimal();

    // Destructor
    ~CGAME();
};