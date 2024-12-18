#pragma once
#include <string>

class Employee {
   protected:
    std::string name;
    int startedYear;
    double baseSalary;

   public:
    Employee();
    Employee(const Employee& employee) = default;
    Employee(std::string name);
    Employee(std::string name, double baseSalary);
    Employee(std::string name, int startedYear, double baseSalary);
    virtual ~Employee() = default;
    virtual double getSalary() const;
    std::string getName() const;
    int getStartedYear() const;
    void setName(std::string name);
    void setStartedYear(int startedYear);
    void setBaseSalary(double baseSalary);
    double getBaseSalary() const;
};