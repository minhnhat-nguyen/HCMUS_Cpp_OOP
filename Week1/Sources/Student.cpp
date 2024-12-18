#include "Student.h"

#include <iostream>

Student::Student(float mathGrade, float englishGrade, float programmingGrade) {
    this->mathGrade = mathGrade;
    this->englishGrade = englishGrade;
    this->programmingGrade = programmingGrade;
    if (mathGrade < 0 || mathGrade > 10 || englishGrade < 0 || englishGrade > 10 || programmingGrade < 0 || programmingGrade > 10)
        throw std::invalid_argument("Invalid grade");
}

float Student::getAverage() const {
    return (mathGrade + englishGrade + programmingGrade) / 3;
}

bool Student::isExellent() const {
    return (mathGrade >= 6.5 && englishGrade >= 6.5 && programmingGrade >= 6.5 && getAverage() >= 8);
}

void Student::setMathGrade(const float mathGrade) {
    this->mathGrade = mathGrade;
}

void Student::setEnglishGrade(const float englishGrade) {
    this->englishGrade = englishGrade;
}

void Student::setProgrammingGrade(const float programmingGrade) {
    this->programmingGrade = programmingGrade;
}

std::istream& operator>>(std::istream& is, Student& s) {
    float mathGrade, englishGrade, programmingGrade;
    while (true) {
        try {
            std::cout << "Enter math grade: ";
            is >> mathGrade;
            std::cout << "Enter english grade: ";
            is >> englishGrade;
            std::cout << "Enter programming grade: ";
            is >> programmingGrade;
            s = Student(mathGrade, englishGrade, programmingGrade);
            return is;
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << '\n';
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Math grade: " << s.mathGrade << '\n';
    os << "English grade: " << s.englishGrade << '\n';
    os << "Programming grade: " << s.programmingGrade << '\n';
    return os;
}






