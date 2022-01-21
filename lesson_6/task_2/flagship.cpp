#include "flagship.h"

Flagship::Flagship()
{

}

int Flagship::getFleetSpeed()
{
    fleetSpeed = speed;
    if (cruisers.size() != 0) {
        for (int i = 0; i < int(cruisers.size()); i++) {
            if (cruisers[i].getSpeed() < fleetSpeed && cruisers[i].getSpeed() > 0) {
                fleetSpeed = cruisers[i].getSpeed();
            }
        }
    }
    return fleetSpeed;
}

void Flagship::addCruiser(Cruiser &m_cruiser)
{
    if (m_cruiser.getHealth() != 0) {
        cruisers.push_back(m_cruiser);
        m_cruiser.setHealth(0);
        m_cruiser.setSpeed(0);
        m_cruiser.setArmor(0);
        m_cruiser.fighters.clear();
    }
}


