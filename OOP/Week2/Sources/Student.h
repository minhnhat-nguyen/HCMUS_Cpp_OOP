#include <iostream>
#pragma once

class Student {
   private:
    char* studentId;
    double gpa;
    char* fullname;
    char* address;

   public:
    Student();
    Student(const Student& other);
    Student(const char* studentId, double gpa, const char* fullname,
            const char* address);
    ~Student();
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};
