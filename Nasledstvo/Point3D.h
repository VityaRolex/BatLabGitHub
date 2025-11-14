#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

class Point3D : public Point2D {
private:
    double z;

public:
    Point3D(double x = 0, double y = 0, double z = 0);
    Point3D(const Point3D& other);
    Point3D(Point3D&& other) noexcept;
    Point3D& operator=(const Point3D& other);
    Point3D& operator=(Point3D&& other) noexcept;
    Point3D operator+(const Point3D& other) const;
    Point3D& operator+=(const Point3D& other);
    Point3D operator-(const Point3D& other) const;
    Point3D& operator-=(const Point3D& other);
    double getZ() const;
    void setZ(double value);
    void set(double newX, double newY, double newZ);
    void move(double dx, double dy, double dz);
    double distanceTo(const Point3D& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Point3D& p);
};

#endif
