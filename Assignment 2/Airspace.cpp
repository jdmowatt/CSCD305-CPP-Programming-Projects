#include "Airspace.h"

//Getters
double Airspace::getRadius() const { return radius; }
double Airspace::getHeight() const { return height; }
Point3D Airspace::getCenter() const { return center; }

//Setters
void Airspace::setRadius(double radius) { this->radius = radius; }
void Airspace::setHeight(double height) { this->height = height; }
void Airspace::setCenter(Point3D center) { this->center = center; }