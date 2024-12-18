#pragma once
#include <iostream>

#include "Employee.h"

class Manager : public Employee {
   private:
    double positionAllowance;
    double bonus;

   public:
    Manager();
    Manager(const Manager& manager) = default;
    Manager(std::string name);
    Manager(std::string name, double baseSalary);
    Manager(std::string name, int startedYear, double baseSalary,
            double positionAllowance, double bonus);
    virtual ~Manager() = default;
    virtual double getSalary() const;
    double getPositionAllowance() const;
    double getBonus() const;
    void setPositionAllowance(double positionAllowance);
    void setBonus(double bonus);
    friend std::istream& operator>>(std::istream& is, Manager& manager);
    friend std::ostream& operator<<(std::ostream& os, const Manager& manager);
};