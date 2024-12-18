#include "Fraction.h"
#include <string>
#include <iostream>

int Fraction::findGCD(int a, int b) {
    int smaller = (a < b) ? a : b;
    for (int i = smaller; i > 0; i--)
        if (a % i == 0 && b % i == 0) return i;
    return 1;
}

Fraction::Fraction(int num, int den) {
    if (den == 0) throw std::invalid_argument("Denominator cannot be 0");
    _num = num;
    _den = den;
}

void Fraction::simplify() {
    int gcd = findGCD(abs(_num), abs(_den));
    if (_den < 0) {
        _den *= -1;
        _num *= -1;
    }
    _num /= gcd;
    _den /= gcd;
}

Fraction Fraction::operator+(const Fraction& other) const {
    int num = _num * other._den + _den * other._num;
    int den = _den * other._den;
    Fraction result(num, den);
    result.simplify();
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = _num * other._den - _den * other._num;
    int den = _den * other._den;
    Fraction result(num, den);
    result.simplify();
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = _num * other._num;
    int den = _den * other._den;
    Fraction result(num, den);
    result.simplify();
    return result;
}

Fraction Fraction::operator/(const Fraction& other) const {
    int num = _num * other._den;
    int den = _den * other._num;
    Fraction result(num, den);
    result.simplify();
    return result;
}

std::string Fraction::toString() const {
    return std::to_string(_num) + "/" + std::to_string(_den);
}

double Fraction::toDouble() const { return (double)_num / (double)_den; }

std::istream& operator>>(std::istream& is, Fraction& f) {
    while (true) {
        try {
            long long num, den;
            std::cout << "Enter numerator: ";
            is >> num;
            std::cout << "Enter denominator: ";
            is >> den;
            f = Fraction(num, den);
            return is;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }
}
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.toString();
    return os;
}