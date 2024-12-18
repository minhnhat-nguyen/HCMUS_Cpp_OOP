#include "Fraction.h"

#include <iostream>
#include <string>

int Fraction::findGCD(int a, int b) {
  int smaller = (a < b) ? a : b;
  for (int i = smaller; i > 0; i--)
    if (a % i == 0 && b % i == 0) return i;
  return 1;
}

Fraction::Fraction(int num, int den) {
  if (den == 0) throw std::invalid_argument("Cannot divide by zero!");
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

Fraction Fraction::operator+(const Fraction &other) const {
  int num = _num * other._den + _den * other._num;
  int den = _den * other._den;
  Fraction result(num, den);
  result.simplify();
  return result;
}

Fraction Fraction::operator+(const int &num) const {
  Fraction result(num, 1);
  return *this + result;
}

Fraction Fraction::operator-(const Fraction &other) const {
  int num = _num * other._den - _den * other._num;
  int den = _den * other._den;
  Fraction result(num, den);
  result.simplify();
  return result;
}

Fraction Fraction::operator-(const int &num) const {
  Fraction result(num, 1);
  return *this - result;
}

Fraction Fraction::operator*(const Fraction &other) const {
  int num = _num * other._num;
  int den = _den * other._den;
  try {
    Fraction result(num, den);
    result.simplify();
    return result;
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << '\n';
    return Fraction(123, -1e5);
  }
}

Fraction Fraction::operator*(const int &num) const {
  Fraction result(num, 1);
  return *this * result;
}

Fraction Fraction::operator/(const Fraction &other) const {
  int num = _num * other._den;
  int den = _den * other._num;
  try {
    Fraction result(num, den);
    result.simplify();
    return result;
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << '\n';
    return Fraction(123, -1e5);
  }
}

Fraction &Fraction::operator=(const Fraction &other) {
  if (other == Fraction(123, -1e5)) return *this;
  _num = other._num;
  _den = other._den;
  return *this;
}

bool Fraction::operator==(const Fraction &other) const {
  return _num * other._den == _den * other._num;
}

bool Fraction::operator!=(const Fraction &other) const {
  return _num * other._den != _den * other._num;
}

bool Fraction::operator>=(const Fraction &other) const {
  return _num * other._den >= _den * other._num;
}

bool Fraction::operator>(const Fraction &other) const {
  return _num * other._den > _den * other._num;
}

bool Fraction::operator<=(const Fraction &other) const {
  return _num * other._den <= _den * other._num;
}

bool Fraction::operator<(const Fraction &other) const {
  return _num * other._den < _den * other._num;
}

Fraction &Fraction::operator+=(const Fraction &other) {
  *this = *this + other;
  return *this;
}

Fraction &Fraction::operator-=(const Fraction &other) {
  *this = *this - other;
  return *this;
}

Fraction &Fraction::operator*=(const Fraction &other) {
  *this = *this * other;
  return *this;
}

Fraction &Fraction::operator/=(const Fraction &other) {
  *this = *this / other;
  return *this;
}

Fraction::operator int() { return _num / _den; }
Fraction::operator float() { return (float)_num / (float)_den; }

Fraction Fraction::operator++(int) {
  Fraction result = *this;
  *this += 1;
  return result;
}

Fraction &Fraction::operator++() {
  *this += 1;
  return *this;
}

Fraction Fraction::operator--(int) {
  Fraction result = *this;
  *this -= 1;
  return result;
}

Fraction &Fraction::operator--() {
  *this -= 1;
  return *this;
}

double Fraction::toDouble() const { return (double)_num / (double)_den; }
std::istream &operator>>(std::istream &is, Fraction &f) {
  while (true) {
    try {
      long long num, den;
      std::cout << "Enter numerator: ";
      is >> num;
      std::cout << "Enter denominator: ";
      is >> den;
      f = Fraction(num, den);
      return is;
    } catch (const std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
    }
  }
}
std::ostream &operator<<(std::ostream &os, const Fraction &f) {
  if (f._num == 0) {
    os << 0;
    return os;
  }
  if (f._den == 1) {
    os << f._num;
    return os;
  }
  os << f._num << "/" << f._den;
  return os;
}

Fraction operator+(const int &num, const Fraction &f) {
  Fraction result(num, 1);
  return result + f;
}

Fraction operator-(const int &num, const Fraction &f) {
  Fraction result(num, 1);
  return result - f;
}

Fraction operator*(const int &num, const Fraction &f) {
  Fraction result(num, 1);
  return result * f;
}