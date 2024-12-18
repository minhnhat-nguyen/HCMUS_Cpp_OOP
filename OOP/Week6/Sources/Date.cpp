#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}
Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year) {}
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date::setDay(int day) { this->day = day; }
void Date::setMonth(int month) { this->month = month; }
void Date::setYear(int year) { this->year = year; }

std::istream& operator>>(std::istream& is, Date& date) {
    int day;
    int month;
    int year;
    is >> day >> month >> year;
    date.day = day;
    date.month = month;
    date.year = year;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}