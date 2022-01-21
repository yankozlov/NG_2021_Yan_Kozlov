#ifndef MAPS_H
#define MAPS_H

#include <iostream>

using namespace std;

class Maps
{
public:
    Maps maps();

    void setDefault();

    void show(bool playWithComputer, char mode, bool currPlayer);

    void discover(int player);

    void clear(int currPlayer, int shipsList[2][4]);

    void markVerifiedEmptyCells (bool isShipAlive, int currPlayer, int x, int y, char moveCoord[2]);

    int playersMaps[2][10][10];
    int gameMaps[2][10][10];
};

#endif // MAPS_H
