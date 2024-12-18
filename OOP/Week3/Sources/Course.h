#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Student.h"

class Course {
 private:
  std::string _courseId;
  std::string _name;
  std::vector<Student> _students;
  std::vector<Student> getStudentsByRange(double lowerBound = 0,
                                          double upperBound = 10.01) const;

 public:
  Course();
  Course(std::string courseId, std::string name);
  Course(std::string courseId, std::string name, std::vector<Student> students);
  void enroll(const Student &s);
  void enroll(const std::vector<Student> &students);
  void removeById(const std::string &id);
  void removeByIds(const std::vector<std::string> &ids);
  std::vector<Student> getExcellentStudents() const;
  std::vector<Student> getGoodStudents() const;
  std::vector<Student> getAverageStudents() const;
  std::vector<Student> getWeakStudents() const;
  int getPassedStudent() const;
  int getFailedStudent() const;
  void sortByName_Desc();
  void sortByName_Asc();
  void sortByScore_Desc();
  void sortByScore_Asc();
  void save(std::string filename);
  void load(const std::string filename);
  class Iterator {
   private:
    std::vector<Student>::iterator _it;

   public:
    Iterator(std::vector<Student>::iterator it);
    Iterator &operator++();
    Iterator operator++(int);
    Iterator operator+(int n);
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    Student &operator*();
  };
  Iterator begin();
  Iterator end();
  int size() const;
  Student &operator[](int index);
};