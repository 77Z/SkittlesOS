#include "../libc/Skittles.h"

//A simple game

void drawBoard() {
    //Fill the screen with a green background
    for (int i = 0; i < SKIT_MAX_ROWS; i++) {
        for (int j = 0; j < SKIT_MAX_COLS; j++) {
            SKIT_printColor(" ", SKIT_WHITE_ON_GREEN);
        }
    }
}

void drawTitle() {
    int titleSprite[] = { 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2,
                          1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 2,
                          1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 2,
                          1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2,
                          1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2,
                          1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 2 };
    int yCoord = 2; // Y position of the sign
    //30 is perfect in the middle of the screen because MAX_COLS is 80, 80 / 2 is 40, the width of the title sign is 20, so 20 / 2 is 10, 40 - 10 is 30, voilà
    int xCoord = 30; // Dynamic X position of the sign
    for (int i = 0; i < sizeof titleSprite / sizeof titleSprite[0]; i++) {
        switch (titleSprite[i])
        {
        case 0:
            SKIT_printAtColor(" ", xCoord, yCoord, SKIT_GREEN_ON_GREEN);
            xCoord++;
            break;
        
        case 1:
            SKIT_printAtColor(" ", xCoord, yCoord, SKIT_GREEN_ON_WHITE);
            xCoord++;
            break;
        
        case 2:
            // 2 Means break line to go down a row
            xCoord = 30; // Reset X Postion
            yCoord++;

        default:
            break;
        }
    }

}

void drawPlayer() {
    int playerX = 39;
    int playerY = 15;
    SKIT_printAtColor("@", playerX, playerY, SKIT_WHITE_ON_GREEN);
    SKIT_printAtColor("This is you", playerX + 2, playerY - 1, SKIT_WHITE_ON_GREEN);
}

void GAME_main() {
    drawBoard();
    drawTitle();
    drawPlayer();
    while(1) {}
}