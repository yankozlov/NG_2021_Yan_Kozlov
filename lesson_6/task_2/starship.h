#ifndef STARSHIP_H
#define STARSHIP_H

class Starship
{
public:
    int getHealth() { return health; }
    void setHealth(int m_health);

    int getSpeed() { return speed; }
    void setSpeed(int m_speed);
protected:
    int health = 0;
    int speed = 0;
};

#endif // STARSHIP_H
