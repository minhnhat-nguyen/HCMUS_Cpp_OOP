#pragma once
#include <exception>
#include <fstream>

class TimeFormatException : public std::exception {
   public:
    const char* what() const throw();
};

class Time {
   private:
    int _hour;
    int _minute;
    int _second;

   public:
    Time();
    Time(int hour, int minute, int second);
    bool isValidTime();
    int getHour();
    int getMinute();
    int getSecond();
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};