#pragma once
#include <vector>

#include "Employee.h"
#include "FactoryWorker.h"
#include "Manager.h"
#include "OfficeWorker.h"

class Company {
   private:
    std::string companyName;
    std::vector<std::unique_ptr<Employee>> _employee;

   public:
    Company();
    Company(std::string companyName);
    void input();
    void output();
    double getSalary();
    Employee* getHighest();
    int getFactoryWorker();
    int getOfficeWorker();
    double getAverageSalary();
    void listEmployeeWithSalaryBelow(double n);
    void findEmployeeById(std::string id);
    void findEmployeeByName(std::string name);
    void findEmployeeBornInMonth(int n);
};