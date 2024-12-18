#pragma once
#include <iostream>

class Fraction {
 private:
  int _num, _den;
  int findGCD(int a, int b);

 public:
  Fraction(int num = 0, int den = 1);
  void simplify();
  Fraction operator+(const Fraction &other) const;
  Fraction operator+(const int &num) const;
  Fraction operator-(const Fraction &other) const;
  Fraction operator-(const int &num) const;
  Fraction operator*(const Fraction &other) const;
  Fraction operator*(const int &num) const;
  Fraction operator/(const Fraction &other) const;
  Fraction &operator=(const Fraction &other);
  bool operator==(const Fraction &other) const;
  bool operator!=(const Fraction &other) const;
  bool operator>=(const Fraction &other) const;
  bool operator>(const Fraction &other) const;
  bool operator<=(const Fraction &other) const;
  bool operator<(const Fraction &other) const;
  Fraction &operator+=(const Fraction &other);
  Fraction &operator-=(const Fraction &other);
  Fraction &operator*=(const Fraction &other);
  Fraction &operator/=(const Fraction &other);
  operator int();
  operator float();
  Fraction operator++(int);
  Fraction &operator++();
  Fraction operator--(int);
  Fraction &operator--();
  friend std::istream &operator>>(std::istream &in, Fraction &f);
  friend std::ostream &operator<<(std::ostream &out, const Fraction &f);
  double toDouble() const;
  friend Fraction operator+(const int &num, const Fraction &f);
  friend Fraction operator-(const int &num, const Fraction &f);
  friend Fraction operator*(const int &num, const Fraction &f);
};
