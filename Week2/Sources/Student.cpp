#include "Student.h"

#include <iostream>

Student::Student() {
    studentId = nullptr;
    gpa = 0;
    fullname = nullptr;
    address = nullptr;
}

Student::Student(const Student& other) {
    studentId = new char[strlen(other.studentId) + 1];
    strcpy(studentId, other.studentId);
    gpa = other.gpa;
    fullname = new char[strlen(other.fullname) + 1];
    strcpy(fullname, other.fullname);
    address = new char[strlen(other.address) + 1];
    strcpy(address, other.address);
}

Student::Student(const char* studentId, double gpa, const char* fullname,
                 const char* address) {
    this->studentId = new char[strlen(studentId) + 1];
    strcpy(this->studentId, studentId);
    this->gpa = gpa;
    this->fullname = new char[strlen(fullname) + 1];
    strcpy(this->fullname, fullname);
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

Student::~Student() {
    delete[] studentId;
    delete[] fullname;
    delete[] address;
    studentId = fullname = address = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student ID: " << student.studentId << '\n';
    os << "GPA: " << student.gpa << '\n';
    os << "Full name: " << student.fullname << '\n';
    os << "Address: " << student.address << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
    char temp[255];
    std::cout << "Enter student ID: ";
    is >> temp;
    student.studentId = new char[strlen(temp) + 1];
    strcpy(student.studentId, temp);
    std::cout << "Enter GPA: ";
    is >> student.gpa;
    std::cout << "Enter full name: ";
    is.ignore();
    is.getline(temp, 255);
    student.fullname = new char[strlen(temp) + 1];
    strcpy(student.fullname, temp);
    std::cout << "Enter address: ";
    is.getline(temp, 255);
    student.address = new char[strlen(temp) + 1];
    strcpy(student.address, temp);
    return is;
}