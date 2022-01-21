#ifndef BOT_H
#define BOT_H

#include <random>

/*                      BOT
    if previous move was a direct hit, check nearby cells
        if all of them are 2 (water) or beyond borders, go random
        if they are unknown, get random direction
            if next move is miss, go to the previous cell and get random direction
            if next move is the hit, go that direction until the water
                if got the water, go backwards until the water
                then go random
    else choose random unknown cell
*/

class Bot {
public:
    Bot bot();

    void makeAMove(char moveCoord[2], int playersMaps[2][10][10], int currPlayer);

private:
    int compMove[2] = {-1, -1};
    char direction = 'n';

    void chooseRandomDirection(int playersMaps[2][10][10], int currPlayer, bool *checkTheShip);

    void checkCellsNearby(int playersMaps[2][10][10], int currPlayer, bool *checkTheShip);
};

#endif // BOT_H
