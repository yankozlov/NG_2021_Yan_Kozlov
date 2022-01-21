#include <bot.h>

void Bot::chooseRandomDirection(int playersMaps[2][10][10], int currPlayer, bool *checkTheShip)
{
    while (true) {
        switch (rand()%4) {
            case 0:
                direction = 'u';
                break;
            case 1:
                direction = 'r';
                break;
            case 2:
                direction = 'd';
                break;
            case 3:
                direction = 'l';
                break;
        }

        if ((compMove[0] == 0 || playersMaps[(currPlayer+1)%2][compMove[0]-1][compMove[1]] == 2) &&
            (compMove[1] == 9 || playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]+1] == 2) &&
            (compMove[0] == 9 || playersMaps[(currPlayer+1)%2][compMove[0]+1][compMove[1]] == 2) &&
            (compMove[1] == 0 || playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]-1] == 2)) {

            *checkTheShip = true;
            break;
        }

        if (direction == 'u') {
            if (compMove[0] != 0 && playersMaps[(currPlayer+1)%2][compMove[0]-1][compMove[1]] != 2) {
                compMove[0] -= 1;
                break;
            }
        }
        else if (direction == 'r') {
            if (compMove[1] != 9 && playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]+1] != 2) {
                compMove[1] += 1;
                break;
            }
        }
        else if (direction == 'd') {
            if (compMove[0] != 9 && playersMaps[(currPlayer+1)%2][compMove[0]+1][compMove[1]] != 2) {
                compMove[0] += 1;
                break;
            }
        }
        else {
            if (compMove[1] != 0 && playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]-1] != 2) {
                compMove[1] -= 1;
                break;
            }
        }
    }
}


void Bot::checkCellsNearby(int playersMaps[2][10][10], int currPlayer, bool *checkTheShip)
{
    if (direction == 'd') {
        if (compMove[0] == 9 || playersMaps[(currPlayer+1)%2][compMove[0]+1][compMove[1]] == 2) {
            *checkTheShip = true;
        }
        else compMove[0]++;
    }
    else if (direction == 'l') {
        if (compMove[1] == 0 || playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]-1] == 2) {
            *checkTheShip = true;
        }
        else compMove[1]--;
    }
    else if (direction == 'u') {
        if (compMove[0] == 0 || playersMaps[(currPlayer+1)%2][compMove[0]-1][compMove[1]] == 2) {
            *checkTheShip = true;
        }
        else compMove[0]--;
    }
    else if (direction == 'r') {
        if (compMove[1] == 9 || playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]+1] == 2) {
            *checkTheShip = true;
        }
        else compMove[1]++;
    }
    else {
        chooseRandomDirection(playersMaps, currPlayer, checkTheShip);
    }
}


void Bot::makeAMove(char moveCoord[2], int playersMaps[2][10][10], int currPlayer)
{
    bool checkTheShip = false;
    do {
        if (checkTheShip) {
            if (compMove[0] != 9 && direction == 'd' && playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3) {
                compMove[0]++;

                if (playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3 ||
                    playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 2) {

                    continue;
                }
                moveCoord[0] = compMove[0]+'0';
                moveCoord[1] = compMove[1]+'a';
                break;
            }
            else if (compMove[1] != 0 && direction == 'l' && playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3) {
                compMove[1]--;

                if (playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3 ||
                    playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 2) {

                    continue;
                }
                moveCoord[0] = compMove[0]+'0';
                moveCoord[1] = compMove[1]+'a';
                break;
            }
            else if (compMove[0] != 0 && direction == 'u' && playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3) {
                compMove[0]--;

                if (playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3 ||
                    playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 2) {

                    continue;
                }
                moveCoord[0] = compMove[0]+'0';
                moveCoord[1] = compMove[1]+'a';
                break;
            }
            else if (compMove[1] != 9 && direction == 'r' && playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3) {
                compMove[1]++;

                if (playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3 ||
                    playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 2) {

                    continue;
                }
                moveCoord[0] = compMove[0]+'0';
                moveCoord[1] = compMove[1]+'a';
                break;
            }
            else {
                compMove[0] = -1;
                compMove[1] = -1;
            }
        }

        if (compMove[0] != -1 && compMove[1] != -1 && playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3 && !checkTheShip) {

            checkCellsNearby(playersMaps, currPlayer, &checkTheShip);

            if (checkTheShip) {
                if (direction == 'l') direction = 'r';
                else if (direction == 'r') direction = 'l';
                else if (direction == 'u') direction = 'd';
                else if (direction == 'd') direction = 'u';

                continue;
            }

            moveCoord[0] = compMove[0]+'0';
            moveCoord[1] = compMove[1]+'a';
        }
        else if (compMove[0] != -1 && compMove[1] != -1 && playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 2 && direction != 'n') {

            if (direction == 'l') direction = 'r';
            else if (direction == 'r') direction = 'l';
            else if (direction == 'u') direction = 'd';
            else if (direction == 'd') direction = 'u';

            if (compMove[0] != 9 && direction == 'd') {
                compMove[0]++;
                if (compMove[0] == 9 || playersMaps[(currPlayer+1)%2][compMove[0]+1][compMove[1]] != 3) {
                    direction = 'n';
                }
                continue;
            }
            else if (compMove[1] != 0 && direction == 'l') {
                compMove[1]--;
                if (compMove[1] == 0 || playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]-1] != 3) {
                    direction = 'n';
                }
                continue;
            }
            else if (compMove[0] != 0 && direction == 'u') {
                compMove[0]--;
                if (compMove[0] == 0 || playersMaps[(currPlayer+1)%2][compMove[0]-1][compMove[1]] != 3) {
                    direction = 'n';
                }
                continue;
            }
            else if (compMove[1] != 9 && direction == 'r') {
                compMove[1]++;
                if (compMove[1] == 9 || playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]+1] != 3) {
                    direction = 'n';
                }
                continue;
            }
        }
        else {          //random coordinates
            do {
                compMove[0] = rand()%10;
                compMove[1] = rand()%10;
                moveCoord[0] = compMove[0]+'0';
                moveCoord[1] = compMove[1]+'a';
                direction = 'n';
            } while (playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 2 || playersMaps[(currPlayer+1)%2][compMove[0]][compMove[1]] == 3);
        }
    } while (!(moveCoord[0] >= '0' && moveCoord[0] <= '9' && moveCoord[1] >= 'a' && moveCoord[1] <= 'j'));
}
