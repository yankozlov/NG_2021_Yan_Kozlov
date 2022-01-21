#ifndef FLAGSHIP_H
#define FLAGSHIP_H

#include <cruiser.h>

using namespace std;

class Flagship: public Battleship
{
public:
    Flagship();

    int getFleetSpeed();

    void addCruiser(Cruiser &m_cruiser);

    vector<Cruiser> cruisers;
private:
    int fleetSpeed = speed;
};

#endif // FLAGSHIP_H
