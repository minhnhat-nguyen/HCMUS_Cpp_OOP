#include <iostream>
#include "Company.h"

Company::Company() { companyName = "_default"; }

Company::Company(std::string companyName) : companyName(companyName) {}

void Company::input() {
    char type;
    std::cout << "Enter type of employee (o: OfficeWorker, f: FactoryWorker, m: Manager): ";
    std::cin >> type;
    Employee* employee;
    switch (type) {
        case 'o': {
            employee = new OfficeWorker();
            break;
        }
        case 'f': {
            employee = new FactoryWorker();
            break;
        }
        case 'm': {
            employee = new Manager();
            break;
        }
        default:
            std::cout << "Invalid type!\n";
            return;
    }
    std::cin >> *employee;
    _employee.push_back(std::unique_ptr<Employee>(employee));
}

void Company::output() {
    for (std::unique_ptr<Employee>& em : _employee)
        std::cout << *em << ' ' << em->getSalary() << '\n';
}

double Company::getSalary() {
    double sum = 0;
    for (std::unique_ptr<Employee>& em : _employee)
        sum += em->getSalary();
    return sum;
}

Employee* Company::getHighest() {
    if (_employee.empty()) return nullptr;
    Employee* highest = _employee[0].get();
    for (std::unique_ptr<Employee>& em : _employee)
        if (em->getSalary() > highest->getSalary())
            highest = em.get();
    return highest;
}

int Company::getFactoryWorker() {
    int count = 0;
    for (std::unique_ptr<Employee>& em : _employee)
        if (dynamic_cast<FactoryWorker*>(em.get()))
            count++;
    return count;
}

int Company::getOfficeWorker() {
    int count = 0;
    for (std::unique_ptr<Employee>& em : _employee)
        if (dynamic_cast<OfficeWorker*>(em.get()))
            count++;
    return count;
}

double Company::getAverageSalary() {
    if (_employee.empty()) return 0;
    return getSalary() / _employee.size();
}

void Company::listEmployeeWithSalaryBelow(double n) {
    for (std::unique_ptr<Employee>& em : _employee)
        if (em->getSalary() < n)
            std::cout << *em << '\n';
}

void Company::findEmployeeById(std::string id) {
    for (std::unique_ptr<Employee>& em : _employee)
        if (em->getId() == id)
            std::cout << *em << '\n';
    std::cout << "Not found!\n";
}

void Company::findEmployeeByName(std::string name) {
    for (std::unique_ptr<Employee>& em : _employee) 
        if (em->getName() == name)
            std::cout << *em << '\n';

}

void Company::findEmployeeBornInMonth(int n) {
    for (std::unique_ptr<Employee>& em : _employee)
        if (em->getBirthday().getMonth() == n)
            std::cout << *em << '\n';
}