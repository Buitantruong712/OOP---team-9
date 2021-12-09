#include "CGame.h"

char MOVING;
CGAME cg;

void main() {
    cg.drawTitle();

    int menuChoice = cg.runMenu();
    if (menuChoice == 0) {
        cg.startGame();
        int temp;
        thread t1(SubThread);
        while (1) {
            temp = toupper(_getch());

            if (!cg.getPeople()->isDead()) {
                if (temp == 27) {
                    cg.exitGame(t1);
                    return;
                }
                else if (temp == 'P') {
                    cg.pauseGame(t1);

                }
                else if(temp == 'R') {
                    cg.resumeGame(t1);
                }
                else if(cg.IS_RUNNING)
                    MOVING = temp;
            }
            else {
                if (temp == 'Y') 
                    cg.startGame();       // Nhấn Y đế chơi tiếp
                else {
                    cg.exitGame(t1);    // Nhấn nút bất kỳ để quay lại menu
                    return;
                }
            }
        }
    }   
}