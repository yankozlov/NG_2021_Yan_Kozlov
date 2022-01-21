#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <starship.h>

class Battleship: public Starship
{
public:
    int getArmor() { return armor; }
    void setArmor(int m_armor);
protected:
    int armor = 0;
};

#endif // BATTLESHIP_H
