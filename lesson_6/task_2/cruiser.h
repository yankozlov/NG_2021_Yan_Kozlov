#ifndef CRUISER_H
#define CRUISER_H

#include <battleship.h>
#include <fighter.h>
#include <iostream>
#include <vector>

using namespace std;

class Cruiser: public Battleship
{
public:    
    Cruiser();

    void addFighter(Fighter &m_fighter);

    int getTotalPower();
    int getSpeed();
    int getSlots() { return slots; }

    void setCapacity(int m_capacity);

    vector<Fighter> fighters;
private:
    int capacity = 20;
    int slots = capacity;
};

#endif // CRUISER_H
