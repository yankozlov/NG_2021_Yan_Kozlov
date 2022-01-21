#ifndef FIGHTER_H
#define FIGHTER_H

#include <starship.h>

class Fighter: public Starship
{
public:
    Fighter();

    int getPower() { return power; }
    void setPower(int damage);
private:
    int power = 0;
};

#endif // FIGHTER_H
