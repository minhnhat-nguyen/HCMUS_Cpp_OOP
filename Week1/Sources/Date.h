#pragma once
#include <iostream>

class Date {
private:
    unsigned int _day, _month;
    int _year;
    int getDaysOfMonth();
    bool isLeap();
    bool isValid();
public:
    Date(unsigned int day = 1,unsigned int month = 1, int year = 1);

    void increase1Day();
    void decrease1Day();
    void increaseNDays(const int n);
    void decreaseNDays(int n);
    int compare(const Date& other) const;

    friend std::istream& operator>>(std::istream& is, Date& d);
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
};