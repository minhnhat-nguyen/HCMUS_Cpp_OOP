#include <iostream>
#include "OfficeWorker.h"

OfficeWorker::OfficeWorker() : Employee(), workdays(0), allowance(0.0) {}
OfficeWorker::OfficeWorker(std::string name) : Employee(name), workdays(0), allowance(0.0) {}
OfficeWorker::OfficeWorker(std::string name, double baseSalary) : Employee(name, baseSalary), workdays(0), allowance(0.0) {}
OfficeWorker::OfficeWorker(std::string name, int startedYear, double baseSalary, int workdays, double allowance) : Employee(name, startedYear, baseSalary), workdays(workdays), allowance(allowance) {}
double OfficeWorker::getSalary() const { return baseSalary + workdays * 100000 + allowance; }
int OfficeWorker::getWorkdays() const { return workdays; }
double OfficeWorker::getAllowance() const { return allowance; }
void OfficeWorker::setWorkdays(int workdays) { this->workdays = workdays; }
void OfficeWorker::setAllowance(double allowance) { this->allowance = allowance; }
std::istream& operator>>(std::istream& is, OfficeWorker& officeWorker) {
    std::string name;
    int startedYear;
    double baseSalary;
    int workdays;
    double allowance;
    std::cout << "Enter name, started year, base salary, workdays, allowance: ";
    is >> name >> startedYear >> baseSalary >> workdays >> allowance;
    officeWorker.setName(name);
    officeWorker.setStartedYear(startedYear);
    officeWorker.setBaseSalary(baseSalary);
    officeWorker.setWorkdays(workdays);
    officeWorker.setAllowance(allowance);
    return is;
}  

std::ostream& operator<<(std::ostream& os, const OfficeWorker& officeWorker) {
    os << officeWorker.getName() << " " << officeWorker.getStartedYear() << " " << officeWorker.getBaseSalary() << " " << officeWorker.getWorkdays() << " " << officeWorker.getAllowance();
    return os;
}