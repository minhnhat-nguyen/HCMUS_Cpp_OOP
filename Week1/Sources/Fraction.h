#pragma once
#include <iostream>

class Fraction {
   private:
    int _num, _den;
    int findGCD(int a, int b);

   public:
    Fraction(int num = 0, int den = 1);
    void simplify();
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    friend std::istream& operator>>(std::istream& in, Fraction& f);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    double toDouble() const;
    std::string toString() const;
};