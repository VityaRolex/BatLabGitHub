#include "Point3D.h"
#include <cmath>


Point3D::Point3D(double x, double y, double z)
    : Point2D(x, y), z(z) {}

Point3D::Point3D(const Point3D& other)
    : Point2D(other), z(other.z) {}

Point3D::Point3D(Point3D&& other) noexcept
    : Point2D(std::move(other)), z(other.z)
{
    other.z = 0;
}
Point3D& Point3D::operator=(const Point3D& other) {
    if (this != &other) {
        Point2D::operator=(other);
        z = other.z;
    }
    return *this;
}

Point3D& Point3D::operator=(Point3D&& other) noexcept {
    if (this != &other) {
        Point2D::operator=(std::move(other));
        z = other.z;
        other.z = 0;
    }
    return *this;
}

Point3D Point3D::operator+(const Point3D& other) const {
    return Point3D(getX() + other.getX(),
                   getY() + other.getY(),
                   z + other.z);
}

Point3D& Point3D::operator+=(const Point3D& other) {
    setX(getX() + other.getX());
    setY(getY() + other.getY());
    z += other.z;
    return *this;
}

Point3D Point3D::operator-(const Point3D& other) const {
    return Point3D(getX() - other.getX(),
                   getY() - other.getY(),
                   z - other.z);
}

Point3D& Point3D::operator-=(const Point3D& other) {
    (Point2D)(*this) -= (Point2D&)other;
    z -= other.z;
    return *this;
}

double Point3D::getZ() const { return z; }

void Point3D::setZ(double value) { z = value; }

void Point3D::set(double newX, double newY, double newZ) {
    Point2D::set(newX, newY);
    z = newZ;
}

void Point3D::move(double dx, double dy, double dz) {
    Point2D::move(dx, dy);
    z += dz;
}

double Point3D::distanceTo(const Point3D& other) const {
    double dx = getX() - other.getX();
    double dy = getY() - other.getY();
    double dz = z - other.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

std::ostream& operator<<(std::ostream& os, const Point3D& p) {
    os << (Point2D&)p << '\b' << ',' << p.getZ() << ')';
    return os;
}
