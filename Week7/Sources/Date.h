#pragma once
#include <exception>
#include <fstream>

class DateFormatException : public std::exception {
public:
    const char* what() const throw();
};

class Date {
private:
    int _day;
    int _month;
    int _year;
    int getDaysInMonth();
    bool isLeap();
public:
    Date();
    Date(int day, int month, int year);
    bool isValidDate();
    int getDay();
    int getMonth();
    int getYear();
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
};