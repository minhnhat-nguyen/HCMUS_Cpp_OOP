#pragma once
#include <iostream>

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int day, int month, int year);
        Date(const Date& date);
        ~Date() = default;
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        friend std::istream& operator>>(std::istream& is, Date& date);
        friend std::ostream& operator<<(std::ostream& os, const Date& date);
};