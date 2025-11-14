#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D {
private:
    double x;
    double y;

public:
    virtual void foo(){};
    Point2D(double x = 0, double y = 0);
    Point2D(const Point2D& other);
    Point2D(Point2D&& other) noexcept;
    Point2D& operator=(const Point2D& other);
    Point2D& operator=(Point2D&& other) noexcept;
    Point2D operator+(const Point2D& other) const;
    Point2D& operator+=(const Point2D& other);
    Point2D operator-(const Point2D& other) const;
    Point2D& operator-=(const Point2D& other);
    double getX() const;
    double getY() const;
    void setX(double value);
    void setY(double value);
    void set(double newX, double newY);
    void move(double dx, double dy);
    double distanceTo(const Point2D& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Point2D& p);
};

#endif
