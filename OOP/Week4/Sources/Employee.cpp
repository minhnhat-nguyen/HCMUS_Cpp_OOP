#include "Employee.h"
#include <iostream>

Employee::Employee() : name("_default"), startedYear(0), baseSalary(0.0) {}
Employee::Employee(std::string name) : name(name), startedYear(0), baseSalary(0.0) {}
Employee::Employee(std::string name, double baseSalary) : name(name), startedYear(0), baseSalary(baseSalary) {}
Employee::Employee(std::string name, int startedYear, double baseSalary) : name(name), startedYear(startedYear), baseSalary(baseSalary) {}
double Employee::getSalary() const { return baseSalary;}
std::string Employee::getName() const { return name; }
int Employee::getStartedYear() const { return startedYear; }
void Employee::setName(std::string newName) { name = newName; }
void Employee::setStartedYear(int newStartedYear) { startedYear = newStartedYear; }
void Employee::setBaseSalary(double newBaseSalary) { baseSalary = newBaseSalary; }
double Employee::getBaseSalary() const { return baseSalary; }