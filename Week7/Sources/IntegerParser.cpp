#include "IntegerParser.h"

const char* IntegerFormatException::what() const throw() {
    return "Exception: Cannot convert string to integer";
}

int ParseInteger(std::string _str) {
    int result = 0;
    int sign = 1;
    int i = 0;
    if (_str.length() == 0) throw IntegerFormatException();
    if (_str[0] == '-') {
        sign = -1;
        i = 1;
    }
    if (_str[0] == '+')
        i = 1;

    if (i==1 && _str.length() == 1) throw IntegerFormatException();

    for (; i < _str.length(); i++) {
        if (_str[i] < '0' || _str[i] > '9') 
            throw IntegerFormatException();
        result = result * 10 + (_str[i] - '0');
    }
    return result * sign;
}