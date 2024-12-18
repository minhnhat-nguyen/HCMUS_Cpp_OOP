#pragma once
#include <exception>
#include <fstream>

class DividedByZeroException : public std::exception {
public:
    const char* what() const throw();
};

class Fraction {
    private:
        int _num, _den;
    public:
        Fraction();
        void SetValue(int num, int den);
        int GetNumerator() const;
        int GetDenominator() const;
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};