#include <iostream>

#include "Employee.h"
#include "FactoryWorker.h"
#include "Manager.h"
#include "OfficeWorker.h"
#include "Company.h"
int main() {
    Company company("Ginger Inc");
    int n;
    std::cout << "Enter number of employees: ";
    std::cin >> n;
    while (n--) company.input();
    std::cout << "Listing the employees of :\n";
    company.output();
    std::cout << "Total salary: " << company.getSalary() << '\n';
    {
        Employee* highest = company.getHighest();
        if (highest)
            std::cout << "Highest salary: " << *highest << '\n';
        else
            std::cout << "No employee!\n";
    }
    std::cout << "Number of factory workers: " << company.getFactoryWorker() << '\n';
    std::cout << "Number of office workers: " << company.getOfficeWorker() << '\n';
    std::cout << "Average salary: " << company.getAverageSalary() << '\n';
    std::cout << "Employees with salary below 3.000.000" << ":\n";
    company.listEmployeeWithSalaryBelow(3000000);
    std::string id;
    std::cout << "Enter id to find: ";
    std::cin >> id;
    company.findEmployeeById(id);
    std::string name;
    std::cout << "Enter name to find: ";
    std::cin >> name;
    company.findEmployeeByName(name);
    std::cout << "Employee was borned in month May:\n ";
    company.findEmployeeBornInMonth(5);
}