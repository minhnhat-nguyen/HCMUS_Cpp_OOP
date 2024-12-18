#pragma once
#include <iostream>
#include "Point.h"
#define tolerance 1e-13
class Rectangle {
   private:
    Point _tL, _tR, _bR, _bL;
    bool isSquare(const double a, const double b, const double c) const;
   public:
    Rectangle(Point tL = Point(0,0), Point tR = Point(0,0), Point bR = Point(0,0),
              Point bL = Point(0,0));
    bool isValid() const;
    double getArea() const;
    double getPerimeter() const;
    friend std::istream& operator>>(std::istream& is, Rectangle& R);
    friend std::ostream& operator<<(std::ostream& os, Rectangle& R);
};