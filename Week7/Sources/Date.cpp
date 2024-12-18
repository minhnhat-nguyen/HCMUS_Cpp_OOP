#include "Date.h"

const char* DateFormatException::what() const throw() {
    return "Exception: Invalid date format";
}

Date::Date() : _day(0), _month(0), _year(0) {}

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {
    if (!isValidDate()) {
        throw DateFormatException();
        _day = _month = _year = 0;
    }
}

bool Date::isLeap() {
    return (_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0;
}

int Date::getDaysInMonth() {
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

bool Date::isValidDate() {
    return _day > 0 && _day <= getDaysInMonth() && _month > 0 && _month <= 12 && _year > 0;
}

int Date::getDay() {
    return _day;
}

int Date::getMonth() {
    return _month;
}

int Date::getYear() {
    return _year;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d._day << "/" << d._month << "/" << d._year;
    return os;
}
