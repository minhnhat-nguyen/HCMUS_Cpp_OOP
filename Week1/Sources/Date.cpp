#include "Date.h"

#include <iomanip>
#include <iostream>
#include <math.h>
bool Date::isLeap() {
    return (abs(_year) % 4 == 0 && abs(_year) % 100 != 0) || abs(_year) % 400 == 0;
}

bool Date::isValid() {
    if (_year < 1) return false;
    if (_month < 1 || _month > 12) return false;
    if (_day < 1 || _day > getDaysOfMonth()) return false;
    return true;
}

int Date::getDaysOfMonth() {
    switch (_month) {
        case 2:
            return isLeap() ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

Date::Date(unsigned int day, unsigned int month, int year) {
    _day = day;
    _month = month;
    _year = year;
    if (!isValid()) throw std::invalid_argument("The date is invalid");
}

void Date::increase1Day() {
    ++_day;
    if (_day > getDaysOfMonth()) {
        _day = 1;
        ++_month;
        if (_month > 12) {
            _month = 1;
            ++_year;
        }
    }
}

void Date::decrease1Day() {
    --_day;
    if (_day == 0) {
        --_month;
        if (_month == 0) {
            _month = 12;
            --_year;
        }
        _day = getDaysOfMonth();
    }
}

void Date::increaseNDays(const int n) {
    for (int i = 0; i < n; i++) increase1Day();
}

void Date::decreaseNDays(int n) {
    for (int i = 0; i < n; i++) {
        decrease1Day();
    }
}

int Date::compare(const Date& other) const {
    if (_year < other._year)
        return -1;
    else if (_year > other._year)
        return 1;
    else {
        if (_month < other._month)
            return -1;
        else if (_month > other._month)
            return 1;
        else {
            if (_day < other._day)
                return -1;
            else if (_day > other._day)
                return 1;
            else
                return 0;
        }
    }
}

std::istream& operator>>(std::istream& is, Date& d) {
    int day, month, year;
    while (true) {
        try {
            is >> day >> month >> year;
            d = Date(day, month, year);
            return is;
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << '\n';
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Date& dt) {
    os << std::setfill('0') << std::setw(2) << dt._day << '/'
       << std::setfill('0') << std::setw(2) << dt._month << '/'
       << std::setfill('0') << std::setw(4) << dt._year;
    return os;
}