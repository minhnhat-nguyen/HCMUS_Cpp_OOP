#include <iostream>
#include "OfficeWorker.h"

OfficeWorker::OfficeWorker() : Employee(), workdays(0), allowance(0.0) {}
OfficeWorker::OfficeWorker(std::string name, std::string id, int startedYear, double baseSalary, int workdays, double allowance) : Employee(name, id, startedYear, baseSalary), workdays(workdays), allowance(allowance) {}
double OfficeWorker::getSalary() const { return baseSalary + workdays * 100000.0 + allowance; }
int OfficeWorker::getWorkdays() const { return workdays; }
double OfficeWorker::getAllowance() const { return allowance; }
void OfficeWorker::setWorkdays(int workdays) { this->workdays = workdays; }
void OfficeWorker::setAllowance(double allowance) { this->allowance = allowance; }
void OfficeWorker::input(std::istream& is) {
    std::string name;
    std::string id;
    int startedYear;
    double baseSalary;
    int workdays;
    double allowance;
    std::cout << "Enter name, id, started year, base salary, workdays, allowance: ";
    is >> name >> id >> startedYear >> baseSalary >> workdays >> allowance;
    this->name = name;
    this->id = id;
    this->startedYear = startedYear;
    this->baseSalary = baseSalary;
    this->workdays = workdays;
    this->allowance = allowance;
    inputBirthday();
}
void OfficeWorker::output(std::ostream& os) const {
    os << this->name << " " << this->id << " " << this->startedYear << " " << this->baseSalary << " " << this->workdays << " " << this->allowance;
}