#include "Point3D.h"
#include <cmath>

//Getters
double Point3D::getX() const { return x; }
double Point3D::getY() const { return y; }
double Point3D::getZ() const { return z; }

//Setters
void Point3D::setX(double x) { this->x = x; }
void Point3D::setY(double y) { this->y = y; }
void Point3D::setZ(double z) { this->z = z; }


Point3D& Point3D::addPoints(const Point3D &P) {
    x += P.x;
    y += P.y;
    z += P.z;
    return *this;
}

Point3D& Point3D::subtractPoints(const Point3D &P) {
    x -= P.x;
    y -= P.y;
    z -= P.z;
    return *this;
}

double Point3D::magnitude() {
    return std::sqrt(x*x + y*y + z*z);
}

