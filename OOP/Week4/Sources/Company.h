#pragma once
#include <vector>

#include "Employee.h"
#include "FactoryWorker.h"
#include "Manager.h"
#include "OfficeWorker.h"

class Company {
   private:
    std::string companyName;
    std::vector<Manager> _managers;
    std::vector<FactoryWorker> _ftrWorkers;
    std::vector<OfficeWorker> _ofceWorkers;

   public:
    Company();
    Company(std::string companyName);
    void addEmployee(Employee* employee);
    void Input();
    void Output();
    double getSalary();
    std::vector<Employee*> findEmployee(std::string name);
};