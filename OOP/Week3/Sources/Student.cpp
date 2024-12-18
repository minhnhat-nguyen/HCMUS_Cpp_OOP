#include "Student.h"

#include <iostream>

Student::Student() : studentId(""), grade(0), fullname("") {}

Student::Student(std::string studentId, double grade, std::string fullname)
    : studentId(studentId), grade(grade), fullname(fullname) {}

void Student::setId(std::string studentId) { this->studentId = studentId; }
void Student::setGrade(double grade) { this->grade = grade; }
void Student::setFullname(std::string fullname) { this->fullname = fullname; }
std::string Student::getId() const { return studentId; }
double Student::getGrade() const { return grade; }
std::string Student::getFullname() const { return fullname; }

std::istream &operator>>(std::istream &is, Student &student) {
  std::cout << "Enter student's id: ";
  is >> student.studentId;
  std::cout << "Enter student's grade: ";
  is >> student.grade;
  std::cout << "Enter student's fullname: ";
  is >> student.fullname;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
  os << student.studentId << '\t';
  os << student.grade << '\t';
  os << student.fullname;
  return os;
}
