#include "Employee.h"
#include <iostream>

Employee::Employee() : name("_default"), startedYear(0), baseSalary(0.0) {}
Employee::Employee(std::string name, std::string id, int startedYear, double baseSalary) : name(name), id(id), startedYear(startedYear), baseSalary(baseSalary) {}
double Employee::getSalary() const { return baseSalary;}
std::string Employee::getName() const { return name; }
int Employee::getStartedYear() const { return startedYear; }
void Employee::setName(std::string newName) { name = newName; }
void Employee::setStartedYear(int newStartedYear) { startedYear = newStartedYear; }
void Employee::setBaseSalary(double newBaseSalary) { baseSalary = newBaseSalary; }
std::string Employee::getId() const { return id; }
double Employee::getBaseSalary() const { return baseSalary; }
std::istream& operator>>(std::istream& is, Employee& employee) {
    employee.input(is);
    return is;
} 
std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    employee.output(os);
    return os;
}
void Employee::inputBirthday() {
    std::cout << "Enter birthday (dd/mm/yyyy): ";
    std::cin >> birthday;
}
Date Employee::getBirthday() const { return birthday; }