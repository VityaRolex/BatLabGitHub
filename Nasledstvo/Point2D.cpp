#include "Point2D.h"
#include <cmath>


Point2D::Point2D(double x, double y) : x(x), y(y) {}

Point2D::Point2D(const Point2D& other) : x(other.x), y(other.y) {}

Point2D::Point2D(Point2D&& other) noexcept : x(other.x), y(other.y) {
    other.x = 0;
    other.y = 0;
}

Point2D& Point2D::operator=(const Point2D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point2D& Point2D::operator=(Point2D&& other) noexcept {
    if (this != &other) {
        x = other.x;
        y = other.y;
        other.x = 0;
        other.y = 0;
    }
    return *this;
}

Point2D Point2D::operator+(const Point2D& other) const {
    return Point2D(x + other.x, y + other.y);
}

Point2D& Point2D::operator+=(const Point2D& other) {
    x += other.x;
    y += other.y;
    return *this;
}
Point2D Point2D::operator-(const Point2D& other) const {
    return Point2D(x - other.x, y - other.y);
}
Point2D& Point2D::operator-=(const Point2D& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
double Point2D::getX() const { return x; }
double Point2D::getY() const { return y; }

void Point2D::setX(double value) { x = value; }
void Point2D::setY(double value) { y = value; }

void Point2D::set(double newX, double newY) {
    x = newX;
    y = newY;
}
void Point2D::move(double dx, double dy) {
    x += dx;
    y += dy;
}
double Point2D::distanceTo(const Point2D& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
