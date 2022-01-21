#include "cruiser.h"

Cruiser::Cruiser()
{

}

void Cruiser::addFighter(Fighter &m_fighter)
{
    //cout << "[WARN] Adding a fighter. Stats: health:" << m_fighter.getHealth() << "|power: " << m_fighter.getPower()
    //     << "|speed: " << m_fighter.getSpeed() << endl;
    if (slots > 0 && m_fighter.getHealth() > 0) {
        fighters.push_back(m_fighter);
        //cout << fighters[capacity-slots].getHealth() << endl;
        m_fighter.setHealth(0);
        m_fighter.setPower(0);
        m_fighter.setSpeed(0);
        slots--;
    }
    else {
        //cout << "slots: " << slots << "|m_fighter.getHealth(): " << m_fighter.getHealth() << endl;
        cout << "[ERROR] Can't add the fighter. " << endl;
    }
}

int Cruiser::getTotalPower()
{
    int totalPower = 0;
    for (int i = 0; i < capacity-slots; i++) {
        totalPower += fighters[i].getPower();
    }
    return totalPower;
}

int Cruiser::getSpeed()
{
    int cruiserSpeed = speed;
    for (int i = 0; i < int(fighters.size()) && fighters[i].getSpeed() > 0; i++) {
        if (fighters[i].getSpeed() < cruiserSpeed) {
            cruiserSpeed = fighters[i].getSpeed();
        }
    }
    return cruiserSpeed;
}

void Cruiser::setCapacity(int m_capacity)
{
    if (slots == capacity) {
        capacity = m_capacity;
        slots = capacity;
        fighters.clear();
    }
    else {
        cout << endl << "[ERROR] Can't change the capacity: the cruiser is not empty. " << endl;
    }
}




