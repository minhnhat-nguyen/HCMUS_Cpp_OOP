#include "Rectangle.h"

#include <iostream>

#include "Point.h"

Rectangle::Rectangle(Point tL, Point tR, Point bR, Point bL) {
    this->_tL = tL;
    this->_tR = tR;
    this->_bR = bR;
    this->_bL = bL;
}

bool Rectangle::isSquare(const double a, const double b, const double c) const {
    return (a * a + b * b == c * c);
}

bool Rectangle::isValid() const {
    double d12 = getDistance(_tL, _tR);
    double d23 = getDistance(_tR, _bR);
    double d34 = getDistance(_bL, _bR);
    double d14 = getDistance(_bL, _tL);
    double d13 = getDistance(_tL, _bR);
    double d24 = getDistance(_tL, _bR);
    return (d12 == d34 && d23 == d14 && d13 == d24 &&
            (d12 * d12 + d23 * d23 - d13 * d13) < tolerance && this->getArea());
}

double Rectangle::getArea() const {
    return getDistance(_tL, _tR) * getDistance(_tL, _bL);
}

double Rectangle::getPerimeter() const {
    return 2 * (getDistance(_tL, _tR) + getDistance(_tL, _bL));
}

std::istream& operator>>(std::istream& is, Rectangle& R) {
    std::cout << "Enter the top-left point: ";
    is >> R._tL;
    std::cout << "Enter the top-right point: ";
    is >> R._tR;
    std::cout << "Enter the bottom-right point: ";
    is >> R._bR;
    std::cout << "Enter the bottom-left point: ";
    is >> R._bL;
    return is;
}


std::ostream& operator<<(std::ostream& os, Rectangle& R) {
    os << "Top-left point: " << R._tL << '\n';
    os << "Top-right point: " << R._tR << '\n';
    os << "Bottom-right point: " << R._bR << '\n';
    os << "Bottom-left point: " << R._bL << '\n';
    return os;
}
