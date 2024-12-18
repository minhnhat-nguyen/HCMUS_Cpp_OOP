#pragma once
#include <string>
#include <iostream>
#include "Date.h"

class Employee {
   protected:
    std::string name;
    std::string id;
    int startedYear;
    double baseSalary;
    Date birthday;
    virtual void input(std::istream& is) = 0;
    virtual void output(std::ostream& os) const = 0;
    void inputBirthday();
   public:
    Employee();
    Employee(std::string name, std::string id, int startedYear, double baseSalary);
    virtual ~Employee() = default;
    virtual double getSalary() const;
    std::string getName() const;
    int getStartedYear() const;
    std::string getId() const;
    void setName(std::string name);
    void setStartedYear(int startedYear);
    void setBaseSalary(double baseSalary);
    Date getBirthday() const;
    double getBaseSalary() const;
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
    friend std::istream& operator>>(std::istream& is, Employee& employee);
};