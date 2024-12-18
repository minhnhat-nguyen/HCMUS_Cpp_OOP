#include "Time.h"

const char* TimeFormatException::what() const throw() {
    return "Exception: Invalid time format";
}

Time::Time() : _hour(0), _minute(0), _second(0) {}

Time::Time(int hour, int minute, int second) : _hour(hour), _minute(minute), _second(second) {
    if (!isValidTime()) {
        throw TimeFormatException();
        _hour = _minute = _second = 0;
    }
}

bool Time::isValidTime() {
    return _hour >= 0 && _hour < 24 && _minute >= 0 && _minute < 60 && _second >= 0 && _second < 60;
}

int Time::getHour() {
    return _hour;
}

int Time::getMinute() {
    return _minute;
}

int Time::getSecond() {
    return _second;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t._hour << ":" << t._minute << ":" << t._second;
    return os;
}