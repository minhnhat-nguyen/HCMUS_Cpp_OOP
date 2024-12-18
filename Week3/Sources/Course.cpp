#include "Course.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Student.h"

std::vector<Student> Course::getStudentsByRange(double lowerBound,
                                                double upperBound) const {
  std::vector<Student> result;
  for (Student s : _students)
    if (s.getGrade() >= lowerBound && s.getGrade() < upperBound)
      result.push_back(s);
  return result;
}

Course::Course() {}

Course::Course(std::string courseId, std::string name)
    : _courseId(courseId), _name(name) {}

Course::Course(std::string courseId, std::string name,
               std::vector<Student> students) {
  this->_courseId = courseId;
  this->_name = name;
  this->_students = students;
}

void Course::enroll(const Student &s) { _students.push_back(s); }

void Course::enroll(const std::vector<Student> &students) {
  _students.insert(_students.end(), students.begin(), students.end());
}

void Course::removeById(const std::string &id) {
  _students.erase(std::remove_if(_students.begin(), _students.end(),
                                 [id](Student s) { return s.getId() == id; }),
                  _students.end());
}

void Course::removeByIds(const std::vector<std::string> &ids) {
  for (std::string id : ids) removeById(id);
}

std::vector<Student> Course::getExcellentStudents() const {
  return getStudentsByRange(9);
}

std::vector<Student> Course::getGoodStudents() const {
  return getStudentsByRange(8, 9);
}

std::vector<Student> Course::getAverageStudents() const {
  return getStudentsByRange(5, 8);
}

std::vector<Student> Course::getWeakStudents() const {
  return getStudentsByRange(0, 5);
}

int Course::getPassedStudent() const {
  int ct = 0;
  for (Student s : _students)
    if (s.getGrade() >= 5) ++ct;
  return ct;
}

int Course::getFailedStudent() const {
  int ct = 0;
  for (Student s : _students)
    if (s.getGrade() < 5) ++ct;
  return ct;
}

void Course::sortByName_Asc() {
  std::sort(_students.begin(), _students.end(), [](Student s1, Student s2) {
    return s1.getFullname() < s2.getFullname();
  });
}

void Course::sortByName_Desc() {
  std::sort(_students.begin(), _students.end(), [](Student s1, Student s2) {
    return s1.getFullname() > s2.getFullname();
  });
}

void Course::sortByScore_Asc() {
  std::sort(_students.begin(), _students.end(), [](Student s1, Student s2) {
    return s1.getGrade() < s2.getGrade();
  });
}

void Course::sortByScore_Desc() {
  std::sort(_students.begin(), _students.end(), [](Student s1, Student s2) {
    return s1.getGrade() > s2.getGrade();
  });
}

Course::Iterator::Iterator(std::vector<Student>::iterator it) : _it(it) {}

Course::Iterator &Course::Iterator::operator++() {
  _it++;
  return *this;
}

Course::Iterator Course::Iterator::operator++(int) {
  Iterator result = *this;
  _it++;
  return result;
}

bool Course::Iterator::operator==(const Iterator &other) const {
  return _it == other._it;
}

bool Course::Iterator::operator!=(const Iterator &other) const {
  return _it != other._it;
}

Student &Course::Iterator::operator*() { return *_it; }
Course::Iterator Course::Iterator::operator+(int n) {
  return Iterator(_it + n);
}
Course::Iterator Course::begin() { return Iterator(_students.begin()); }
Course::Iterator Course::end() { return Iterator(_students.end()); }

void Course::save(std::string filename) {
  std::ofstream ofs(filename);
  ofs << _courseId << '|' << _name << '\n';
  for (Student s : _students)
    ofs << s.getId() << '|' << s.getGrade() << '|' << s.getFullname() << '\n';
  ofs.close();
}

int Course::size() const { return _students.size(); }
Student &Course::operator[](int index) {
  if (index < 0 || index >= _students.size())
    throw std::out_of_range("Index out of range!");
  return _students[index];
}

void Course::load(std::string filename) {
  std::ifstream ifs(filename);
  std::string line;
  std::getline(ifs, line);
  std::stringstream ss(line);
  std::getline(ss, _courseId, '|');
  std::getline(ss, _name, '|');
  while (std::getline(ifs, line)) {
    std::stringstream ss(line);
    std::string id, fullname;
    double grade;
    std::getline(ss, id, '|');
    ss >> grade;
    ss.ignore();
    std::getline(ss, fullname, '|');
    _students.push_back(Student(id, grade, fullname));
  }
}
