#pragma once
#include <exception>
#include <string>

class IntegerFormatException : public std::exception {
public:
    const char* what() const throw();
};

int ParseInteger(std::string str);