#pragma once
#include <iostream>

class Student {
  private:
    float mathGrade, englishGrade, programmingGrade;
    public:
    Student(float mathGrade = 0, float englishGrade = 0, float programmingGrade = 0);
    float getAverage() const;
    bool isExellent() const;
    void setMathGrade(const float mathGrade);
    void setEnglishGrade(const float englishGrade);
    void setProgrammingGrade(const float programmingGrade);
    friend std::istream& operator>>(std::istream& is, Student& s);
    friend std::ostream& operator<<(std::ostream& os, const Student& s);  
};