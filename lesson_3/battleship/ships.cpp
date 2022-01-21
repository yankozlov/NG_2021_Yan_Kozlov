#include "ships.h"

void Ships::setDefault()
{
    shipsList[0][0] = shipsList[1][0] = 1;
    shipsList[0][1] = shipsList[1][1] = 2;
    shipsList[0][2] = shipsList[1][2] = 3;
    shipsList[0][3] = shipsList[1][3] = 4;
}


void Ships::showList(int currPlayer, char option)
{
    if (currPlayer == 0) cout << "P1│ ";
    else cout << "P2│ ";

    if (option == 'a') cout << "Available ships: ";
    else if (option == 'l') cout << "Oponnent's ships left: ";

    if (shipsList[currPlayer][0] != 0) cout << "[* * * *] x " << shipsList[currPlayer][0] << " ";

    if (shipsList[currPlayer][1] != 0) cout << "[* * *] x " << shipsList[currPlayer][1] << " ";

    if (shipsList[currPlayer][2] != 0) cout << "[* *] x " << shipsList[currPlayer][2] << " ";

    if (shipsList[currPlayer][3] != 0) cout << "[*] x " << shipsList[currPlayer][3] << " ";

    cout << endl;
}


bool Ships::noShipsLeft(int currPlayer)
{
    if (shipsList[currPlayer][0] != 0 || shipsList[currPlayer][1] != 0 ||
        shipsList[currPlayer][2] != 0 || shipsList[currPlayer][3] != 0) return false;
    else return true;
}


bool Ships::isShipAlive(int gameMaps[2][10][10], int currPlayer, int x, int y)
{
    int length = 0;
    if (x != 0 && gameMaps[(currPlayer+1)%2][x-1][y] == 3) {
        for (int i = x-1; gameMaps[(currPlayer+1)%2][i][y] == 3; i--) {
            length++;
            if (i != 0 && gameMaps[(currPlayer+1)%2][i-1][y] == 1) {
                return true;
            }
        }
    }
    if (x != 9 && gameMaps[(currPlayer+1)%2][x+1][y] == 3) {
        for (int i = x+1; gameMaps[(currPlayer+1)%2][i][y] == 3; i++) {
            length++;
            if (i != 9 && gameMaps[(currPlayer+1)%2][i+1][y] == 1) {
                return true;
            }
        }
    }
    if (y != 0 && gameMaps[(currPlayer+1)%2][x][y-1] == 3) {
        for (int i = y-1; gameMaps[(currPlayer+1)%2][x][i] == 3; i--) {
            length++;
            if (i != 0 && gameMaps[(currPlayer+1)%2][x][i-1] == 1) {
                return true;
            }
        }
    }
    if (y != 9 && gameMaps[(currPlayer+1)%2][x][y+1] == 3) {
        for (int i = y+1; gameMaps[(currPlayer+1)%2][x][i] == 3; i++) {
            length++;
            if (i != 9 && gameMaps[(currPlayer+1)%2][x][i+1] == 1) {
                return true;
            }
        }
    }
    shipsList[currPlayer][3-length]--;
    return false;
}


bool Ships::areCoordCorrect(char shipCoord[4], int gameMaps[2][10][10], int currPlayer, bool playWithComputer) {
    //syntax error
    if (shipCoord[0] < '0' || shipCoord[0] > '9' || shipCoord[1] < 'a' || shipCoord[1] > 'j' ||
        shipCoord[2] < '0' || shipCoord[2] > '9' || shipCoord[3] < 'a' || shipCoord[3] > 'j')
        return false;

    //too wide
    if (shipCoord[0] != shipCoord[2] && shipCoord[1] != shipCoord[3]) return false;

    //too long
    if (shipCoord[2]-shipCoord[0] > 3 || shipCoord[3]-shipCoord[1] > 3) return false;

    bool isShipHorizontal = false;
    if (shipCoord[2]-shipCoord[0] == 0) isShipHorizontal = true;

    int lengthCounter = max(shipCoord[2]-shipCoord[0], shipCoord[3]-shipCoord[1])+1;

    //player enters coords of existing ship to remove it
    if (gameMaps[currPlayer][shipCoord[0]-'0'][shipCoord[1]-'a'] == 1 &&
        gameMaps[currPlayer][shipCoord[2]-'0'][shipCoord[3]-'a'] == 1 &&
        !(playWithComputer && currPlayer == 1)) {

        if ((shipCoord[0] != '0' && gameMaps[currPlayer][shipCoord[0]-'0'-1][shipCoord[1]-'a'] == 1) ||
            (shipCoord[1] != 'a' && gameMaps[currPlayer][shipCoord[0]-'0'][shipCoord[1]-'a'-1] == 1)) {
            return false;
        }
        else {
            for (int i = shipCoord[0]-'0'; i <= shipCoord[2]-'0'; i++) {
                for (int j = shipCoord[1]-'a'; j <= shipCoord[3]-'a'; j++) {
                    if (gameMaps[currPlayer][i][j] != 1) return false;
                }
            }
            if ((shipCoord[2] != '9' && gameMaps[currPlayer][shipCoord[2]-'0'+1][shipCoord[3]-'a'] == 1) ||
                (shipCoord[3] != 'j' && gameMaps[currPlayer][shipCoord[2]-'0'][shipCoord[3]-'a'+1] == 1)) {
                return false;
            }
            return true;
        }
    }

    //player enters coords for new ship
    if (shipsList[currPlayer][4-lengthCounter] > 0) {
        for (int i = shipCoord[0]-'0'; i <= shipCoord[2]-'0'; i++) {
            for (int j = shipCoord[1]-'a'; j <= shipCoord[3]-'a'; j++) {
                //first cell
                if (i == shipCoord[0]-'0' && j == shipCoord[1]-'a') {
                    if ((i != 0 && ((j != 0 && gameMaps[currPlayer][i-1][j-1] == 1) ||
                                               gameMaps[currPlayer][i-1][j] == 1 ||
                                    (j != 9 && gameMaps[currPlayer][i-1][j+1] == 1))) ||
                                    (j != 0 && gameMaps[currPlayer][i][j-1] == 1) ||
                                               gameMaps[currPlayer][i][j] == 1 ||
                                    (j != 9 && gameMaps[currPlayer][i][j+1] == 1) ||
                        (i != 9 && ((j != 0 && gameMaps[currPlayer][i+1][j-1] == 1) ||
                                               gameMaps[currPlayer][i+1][j] == 1 ||
                                    (j != 9 && gameMaps[currPlayer][i+1][j+1] == 1))))
                        return false;
                }
                else if (isShipHorizontal) {
                    if (j != 9 && (gameMaps[currPlayer][i-1][j+1] == 1 ||
                                   gameMaps[currPlayer][i][j+1] == 1 ||
                                   gameMaps[currPlayer][i+1][j+1] == 1))
                        return false;
                }
                else {
                    if (i != 9 && (gameMaps[currPlayer][i+1][j-1] == 1 ||
                                   gameMaps[currPlayer][i+1][j] == 1 ||
                                   gameMaps[currPlayer][i+1][j+1] == 1))
                        return false;
                }
            }
        }
        return true;
    }
    else return false;
}


void Ships::setRandomCoords(int currPlayer, char shipCoord[4])
{
    int length = 3;
    while (shipsList[currPlayer][3-length] == 0) length--;

    bool isHorizontal = true;
    isHorizontal = rand()%2;

    shipCoord[0] = rand()%10+'0';
    shipCoord[1] = rand()%10+'a';
    if (isHorizontal) {
        shipCoord[2] = shipCoord[0];
        shipCoord[3] = shipCoord[1]+length;
        if (shipCoord[3] > 'j')
            shipCoord[3] -= 2*length;
    }
    else {
        shipCoord[2] = shipCoord[0]+length;
        shipCoord[3] = shipCoord[1];
        if (shipCoord[2] > '9')
            shipCoord[2] -= 2*length;
    }
}


void Ships::set(char shipCoord[2], int gameMaps[2][10][10], int currPlayer)
{
    int lengthCounter = 0;
    for (int i = shipCoord[0]-'0'; i <= shipCoord[2]-'0'; i++) {
        for (int j = shipCoord[1]-'a'; j <= shipCoord[3]-'a'; j++) {
            gameMaps[currPlayer][i][j] = 1;
            lengthCounter++;
        }
    }
    shipsList[currPlayer][4-lengthCounter]--;
}


void Ships::remove(char shipCoord[2], int gameMaps[2][10][10], int currPlayer)
{
    int lengthCounter = 0;
    for (int i = shipCoord[0]-'0'; i <= shipCoord[2]-'0'; i++) {
        for (int j = shipCoord[1]-'a'; j <= shipCoord[3]-'a'; j++) {
            gameMaps[currPlayer][i][j] = 0;
            lengthCounter++;
        }
    }
    shipsList[currPlayer][4-lengthCounter]++;
}
