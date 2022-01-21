#ifndef SHIPS_H
#define SHIPS_H

#include <random>
#include <iostream>

using namespace std;

class Ships
{
public:
    Ships ships();

    void setDefault();

    void showList(int currPlayer, char option);

    bool noShipsLeft(int currPlayer);

    bool isShipAlive(int gameMaps[2][10][10], int currPlayer, int x, int y);

    bool areCoordCorrect(char shipCoord[4], int gameMaps[2][10][10], int currPlayer, bool playWithComputer);

    void setRandomCoords(int currPlayer, char shipCoord[4]);

    void set(char shipCoord[2], int gameMaps[2][10][10], int currPlayer);

    void remove(char shipCoord[2], int gameMaps[2][10][10], int currPlayer);

    int shipsList[2][4];
};

#endif // SHIPS_H
