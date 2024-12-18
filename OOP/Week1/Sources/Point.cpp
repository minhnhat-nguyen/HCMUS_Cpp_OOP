#include "Point.h"

#include <math.h>

#include <iostream>

Point::Point(double x, double y) {
    this->_x = x;
    this->_y = y;
}

double Point::getX() const { return this->_x; }

double Point::getY() const { return this->_y; }

bool Point::operator==(const Point& other) const {
    return this->_x == other._x && this->_y == other._y;
}

double Point::distanceTo(const Point& other) const {
    double dx = this->_x - other._x;
    double dy = this->_y - other._y;
    return sqrt(dx * dx + dy * dy);
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p._x >> p._y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p._x << "," << p._y << ')';
    return os;
}

double getDistance(const Point& a, const Point& b) {
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    return sqrt(dx * dx + dy * dy);
}