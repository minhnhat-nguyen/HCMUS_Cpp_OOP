#pragma once
#include <iostream>

class Point {
    private:
        double _x, _y;
    public:
        Point(double x = 0, double y = 0);
        double getX() const;
        double getY() const;
        double distanceTo(const Point& other) const;
        bool operator==(const Point& other) const;
        friend std::istream& operator>>(std::istream& is, Point& p);
        friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

double getDistance(const Point& a, const Point& b);



