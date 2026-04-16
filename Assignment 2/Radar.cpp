#include "Radar.h"
#include <iostream>

void Radar::checkViolation(Airspace &s) {
    //Check Horizontal Distance
    double dx = position.getX() - s.center.getX();
    double dz = position.getZ() - s.center.getZ();
    double distSq = (dx * dx) + (dz * dz);
    double radiusSq = s.radius * s.radius;

    //Check Vertical Distance
    double bottom = s.center.getY() - (s.height / 2.0);
    double top = s.center.getY() + (s.height / 2.0);


    //Check if position is within the Radius and below the height
    if (distSq <= radiusSq && position.getY() >= bottom && position.getY() <= top) {
        std::cout << "Airspace violation happened!" << std::endl;
    } else {
        std::cout << "No airspace violation has happened!" << std::endl;
    }
}