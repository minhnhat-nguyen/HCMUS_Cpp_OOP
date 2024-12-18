#pragma once
#include <iostream>
#include <iterator>
#include <vector>

class Student {
 private:
  std::string studentId;
  double grade;
  std::string fullname;

 public:
  Student();
  Student(std::string studentId, double grade, std::string fullname);
  void setId(std::string studentId);
  void setGrade(double grade);
  void setFullname(std::string fullname);
  std::string getId() const;
  double getGrade() const;
  std::string getFullname() const;
  friend std::istream &operator>>(std::istream &is, Student &student);
  friend std::ostream &operator<<(std::ostream &os, const Student &student);
};