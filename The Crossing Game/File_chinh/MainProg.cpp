#include "CGame.h"

void SubThread();

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

            if (!cg.getPeople().isDead()) {
                if (temp == 27) {
                    cg.exitGame((HANDLE)t1.native_handle());
                    return;
                }
                else if (temp == 'P') {
                    cg.pauseGame((HANDLE)t1.native_handle());
                }
                else {
                    cg.resumeGame((HANDLE)t1.native_handle());
                    MOVING = temp;
                }
            }
            else {
                if (temp == 'Y') cg.startGame();        // Nhấn Y đế chơi tiếp
                else {
                    cg.exitGame(t1.native_handle());    // Nhấn nút bất kỳ để quay lại menu
                    return;
                }
            }
        }
    }   
}

void SubThread() {
    while (cg.IS_RUNNING) {

        // Kiểm tra sống chết
        if (!cg.getPeople().isDead()) {
            cg.updatePosPeople(MOVING);
        }
        cg.updatePosVehical();
        cg.updatePosAnimal();

        // Kiểm tra va chạm
        if (cg.getPeople().isImpact(cg.getCar(), cg.getCarSize())
            || cg.getPeople().isImpact(cg.getTruck(), cg.getTruckSize())
            || cg.getPeople().isImpact(cg.getBird(), cg.getBirdSize())
            || cg.getPeople().isImpact(cg.getCar2(), cg.getCarSize2())
            || cg.getPeople().isImpact(cg.getBird2(), cg.getBirdSize2())
            )
        {
            cg.getPeople().setHeart(cg.getPeople().getHearts() - 1);
            cg.getPeople().drawHealthBar();
            cg.getPeople().resetPosition();
        }

        // Kiểm tra đến đích 
        if (cg.getPeople().isFinish()) {
            //level++;
            cg.getPeople().resetPosition();
        }
        
        Sleep(100);
    }
}