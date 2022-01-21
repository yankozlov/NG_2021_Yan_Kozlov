#include <battleship_game.h>
//demo: for showing bot; lines 8, 43-48, 83, 96-99, 102, 146 (only "(demo || " and ")"), 149
int main() {
    showIntro();

    srand(time(0));
    const bool playWithComputer = true;
    const bool demo = false;             // <------ for bot's demo: playWithComuter must be true

    Maps maps;
    Ships ships;
    Bot bot;

    bool setRandom = false;
    int currPlayer = 0;
    bool isSettingComplete[2] = {0, 0};

    ships.setDefault();
    maps.setDefault();

    //setting up the maps
    while (!(isSettingComplete[0] && isSettingComplete[1])) {
        char shipCoord[4] = {0, 0, 0, 0};

        maps.show(playWithComputer, 's', currPlayer);

        if (ships.noShipsLeft(currPlayer) == false) ships.showList(currPlayer, 'a');

        cout << endl;
        cout << "You may enter the coordinates to set or remove the ship by writing two coordinates one after another (for example, 'a1a4')." << endl;
        cout << "Type 'rand' to set all ships randomly or 'clr' to clear the map. " << endl;
        cout << endl;

        //waiting for an action
        do {
            if (currPlayer == 0 && !setRandom)
                cout << "P1│ Place a ship (for example: a1a4): ";
            else if (!playWithComputer && !setRandom)
                cout << "P2│ Place a ship (for example: a1a4): ";

            if ((currPlayer == 1 && playWithComputer) || setRandom)
                ships.setRandomCoords(currPlayer, shipCoord);
            else if (demo) {
                shipCoord[0] = 'r';
                shipCoord[1] = 'a';
                shipCoord[2] = 'n';
                shipCoord[3] = 'd';
            }
            else
                cin >> shipCoord;

            formatCoords(shipCoord, 4);

            if (shipCoord[0] == 'r' && shipCoord[1] == 'a' && shipCoord[2] == 'n' && shipCoord[3] == 'd') {
                setRandom = true;
                break;
            }

            if (shipCoord[0] == 'c' && shipCoord[1] == 'l' && shipCoord[2] == 'r' && shipCoord[3] == 0) break;

        } while (ships.areCoordCorrect(shipCoord, maps.gameMaps, currPlayer, playWithComputer) == false);

        if ((shipCoord[0] == 'r' && shipCoord[1] == 'a' && shipCoord[2] == 'n' && shipCoord[3] == 'd') ||
            (shipCoord[0] == 'c' && shipCoord[1] == 'l' && shipCoord[2] == 'r' && shipCoord[3] == 0)) {

            maps.clear(currPlayer, ships.shipsList);
            continue;
        }

        if (maps.gameMaps[currPlayer][shipCoord[0]-'0'][shipCoord[1]-'a'] == 0)
            ships.set(shipCoord, maps.gameMaps, currPlayer);
        else
            ships.remove(shipCoord, maps.gameMaps, currPlayer);

        if (ships.noShipsLeft(currPlayer)) {
            setRandom = false;
            char option = 0;

            if (currPlayer != 1 || !playWithComputer) {
                maps.show(playWithComputer, 's', currPlayer);

                cout << "Would you like to change something? (y/n) ";
                if (demo) option = 'n';
                else cin >> option;

                if (option == 'y' || option == 'Y') continue;
            }
            isSettingComplete[currPlayer] = true;
        }

        if (currPlayer == 0 && isSettingComplete[0]) currPlayer = 1;
    }   

    if (playWithComputer) maps.discover(0);

    if (demo) {
        maps.discover(0);
        maps.discover(1);
    }

    currPlayer = 0;
    if (demo) currPlayer = 1;

    ships.setDefault();

    maps.show(playWithComputer, 'p', currPlayer);

    while (true) {
        char moveCoord[2] = {0, 0};
        bool b_isShipAlive = true;

        makeAMove(moveCoord, currPlayer, playWithComputer, &maps, &bot);

        int x = moveCoord[0]-'0', y = moveCoord[1]-'a';

        if (maps.gameMaps[(currPlayer+1)%2][x][y] == 0)
            maps.gameMaps[(currPlayer+1)%2][x][y] = maps.playersMaps[(currPlayer+1)%2][x][y] = 2;
        else if (maps.gameMaps[(currPlayer+1)%2][x][y] == 1)
            maps.gameMaps[(currPlayer+1)%2][x][y] = maps.playersMaps[(currPlayer+1)%2][x][y] = 3;
        else continue;

        if (maps.gameMaps[(currPlayer+1)%2][x][y] == 3 && (x == 0 || maps.gameMaps[(currPlayer+1)%2][x-1][y] != 1) &&
                                                          (x == 9 || maps.gameMaps[(currPlayer+1)%2][x+1][y] != 1) &&
                                                          (y == 0 || maps.gameMaps[(currPlayer+1)%2][x][y-1] != 1) &&
                                                          (y == 9 || maps.gameMaps[(currPlayer+1)%2][x][y+1] != 1)) {

            b_isShipAlive = ships.isShipAlive(maps.gameMaps, currPlayer, x, y);
        }

        //marking cells around bombed ship
        maps.markVerifiedEmptyCells(b_isShipAlive, currPlayer, x, y, moveCoord);

        if (gameOver(maps.gameMaps, (currPlayer+1)%2) == true) {
            showOutro(currPlayer, playWithComputer);
            maps.show(playWithComputer, 'v', currPlayer);
            break;
        }

        if (maps.playersMaps[(currPlayer+1)%2][moveCoord[0]-'0'][moveCoord[1]-'a'] == 3)
            maps.show(playWithComputer, 'm', currPlayer);
        else if (maps.playersMaps[(currPlayer+1)%2][moveCoord[0]-'0'][moveCoord[1]-'a'] == 2)
            maps.show(playWithComputer, 'm', (currPlayer+1)%2);

        showPreviousMove(currPlayer, playWithComputer, moveCoord, maps);

        if (currPlayer == 1 && playWithComputer && (demo || maps.playersMaps[(currPlayer+1)%2][moveCoord[0]-'0'][moveCoord[1]-'a'] == 3)) getchar();

        if (maps.playersMaps[(currPlayer+1)%2][moveCoord[0]-'0'][moveCoord[1]-'a'] == 2) currPlayer = (currPlayer+1)%2;
        if (demo) currPlayer = 1;

        if (currPlayer != 1 || playWithComputer == false)
            ships.showList(currPlayer, 'l');
    }
}
