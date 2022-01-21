#include "maps.h"

void Maps::setDefault()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            playersMaps[0][i][j] = 0;
            playersMaps[1][i][j] = 0;
            gameMaps[0][i][j] = 0;
            gameMaps[1][i][j] = 0;
        }
    }
}


void Maps::show(bool playWithComputer, char mode, bool currPlayer)
{
    if (mode != 'v') system("clear");

    if (mode == 's') cout << "\t\t\t\t SETTING MAPS" << endl;
    else if (mode == 'p') cout << "\t\t\t\t    PLAY!" << endl;

    cout << "\t     ═══ Player 1 ═══" << "\t\t\t";

    if (playWithComputer) cout << "     ═══ Computer ═══" << endl;
    else cout << "     ═══ Player 2 ═══" << endl;

    cout << "\t    A B C D E F G H I J" << "\t\t\t" << "    A B C D E F G H I J" << endl;
    cout << "\t  ┌─────────────────────┐" << "\t\t" << "  ┌─────────────────────┐" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "\t";
        cout << char('0'+i) << " │ ";
        if (currPlayer == 0 || playWithComputer || mode == 'v') {
            for (int j = 0; j < 10; j++) {
                if (gameMaps[0][i][j] == 0) cout << "  ";
                else if (gameMaps[0][i][j] == 1) cout << "▓▓";
                else if (gameMaps[0][i][j] == 2) cout << "╳╳";
                else cout << "░░";
            }
        }
        else {
            for (int j = 0; j < 10; j++) {
                if (playersMaps[0][i][j] == 0) cout << "  ";
                else if (playersMaps[0][i][j] == 1) cout << "▓▓";
                else if (playersMaps[0][i][j] == 2) cout << "╳╳";
                else cout << "░░";
            }
        }
        cout << "│" << "\t\t";

        cout << char('0'+i) << " │ ";
        if ((currPlayer == 1 && !playWithComputer)|| mode == 'v') {
            for (int j = 0; j < 10; j++) {
                if (gameMaps[1][i][j] == 0) cout << "  ";
                else if (gameMaps[1][i][j] == 1) cout << "▓▓";
                else if (gameMaps[1][i][j] == 2) cout << "╳╳";
                else cout << "░░";
            }
        }
        else {
            for (int j = 0; j < 10; j++) {
                if (playersMaps[1][i][j] == 0) cout << "  ";
                else if (playersMaps[1][i][j] == 1) cout << "▓▓";
                else if (playersMaps[1][i][j] == 2) cout << "╳╳";
                else cout << "░░";
            }
        }
        cout << "│" << endl;
    }
    cout << "\t  └─────────────────────┘" << "\t\t" << "  └─────────────────────┘" << endl;

}


void Maps::discover(int player) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 0; j++) {
            playersMaps[player][i][j] = gameMaps[player][i][j];
        }
    }
}


void Maps::clear(int currPlayer, int shipsList[2][4])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            gameMaps[currPlayer][i][j] = 0;
        }
    }

    shipsList[currPlayer][0] = 1;
    shipsList[currPlayer][1] = 2;
    shipsList[currPlayer][2] = 3;
    shipsList[currPlayer][3] = 4;
}


void Maps::markVerifiedEmptyCells(bool isShipAlive, int currPlayer, int x, int y, char moveCoord[2])
{
    bool upLocked = false;
    bool leftLocked = false;
    bool isHorizontal = false;

    while (isShipAlive == false) {
        if (x != 0) {
            if (y != 0 && gameMaps[(currPlayer+1)%2][x-1][y-1] == 0)
                gameMaps[(currPlayer+1)%2][x-1][y-1] = playersMaps[(currPlayer+1)%2][x-1][y-1] = 2;

            if (gameMaps[(currPlayer+1)%2][x-1][y] == 0)
                gameMaps[(currPlayer+1)%2][x-1][y] = playersMaps[(currPlayer+1)%2][x-1][y] = 2;

            if (y != 9 && gameMaps[(currPlayer+1)%2][x-1][y+1] == 0)
                gameMaps[(currPlayer+1)%2][x-1][y+1] = playersMaps[(currPlayer+1)%2][x-1][y+1] = 2;
        }

        if (y != 0 && gameMaps[(currPlayer+1)%2][x][y-1] == 0)
            gameMaps[(currPlayer+1)%2][x][y-1] = playersMaps[(currPlayer+1)%2][x][y-1] = 2;

        if (y != 9 && gameMaps[(currPlayer+1)%2][x][y+1] == 0)
            gameMaps[(currPlayer+1)%2][x][y+1] = playersMaps[(currPlayer+1)%2][x][y+1] = 2;

        if (x != 9) {
            if (y != 0 && gameMaps[(currPlayer+1)%2][x+1][y-1] == 0)
                gameMaps[(currPlayer+1)%2][x+1][y-1] = playersMaps[(currPlayer+1)%2][x+1][y-1] = 2;

            if (gameMaps[(currPlayer+1)%2][x+1][y] == 0)
                gameMaps[(currPlayer+1)%2][x+1][y] = playersMaps[(currPlayer+1)%2][x+1][y] = 2;

            if (y != 9 && gameMaps[(currPlayer+1)%2][x+1][y+1] == 0)
                gameMaps[(currPlayer+1)%2][x+1][y+1] = playersMaps[(currPlayer+1)%2][x+1][y+1] = 2;
        }

        if (!upLocked && x != 0 && gameMaps[(currPlayer+1)%2][x-1][y] == 3) {
            x--;
            isHorizontal = true;
            continue;
        }
        if (!upLocked) {
            x = moveCoord[0]-'0';
            y = moveCoord[1]-'a';
            upLocked = true;
        }

        if (x != 9 && gameMaps[(currPlayer+1)%2][x+1][y] == 3) {
            x++;
            isHorizontal = true;
            continue;
        }
        if (isHorizontal && upLocked) break;

        if (!leftLocked && y != 0 && gameMaps[(currPlayer+1)%2][x][y-1] == 3)  {
            y--;
            continue;
        }
        if (!leftLocked) {
            x = moveCoord[0]-'0';
            y = moveCoord[1]-'a';
            leftLocked = true;
        }

        if (y != 9 && gameMaps[(currPlayer+1)%2][x][y+1] == 3)  {
            y++;
            continue;
        }
        break;
    }
}
