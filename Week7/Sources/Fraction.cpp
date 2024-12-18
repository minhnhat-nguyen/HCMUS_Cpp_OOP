#include "Fraction.h"
#include <iostream>

const char* DividedByZeroException::what() const throw() {
    return "Exception: Cannot divide by zero";
}


Fraction::Fraction() : _num(0), _den(1) {}
void Fraction::SetValue(int num, int den) {
    if (den == 0) {
        throw DividedByZeroException();
    }
    _num = num;
    _den = den;
}
int Fraction::GetNumerator() const {
    return _num;
}
int Fraction::GetDenominator() const {
    return _den;
}
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f._num << "/" << f._den;
    return os;
}
