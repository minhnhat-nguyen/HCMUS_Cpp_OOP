#pragma once
#include <iostream>

#include "Employee.h"

class Manager : public Employee {
   private:
    double positionAllowance;
    double bonus;

   protected:
    void input(std::istream& is);
    void output(std::ostream& os) const;

   public:
    Manager();
    Manager(const Manager& manager) = default;
    Manager(std::string name, std::string id, int startedYear, double baseSalary,
            double positionAllowance, double bonus);
    virtual ~Manager() = default;
    virtual double getSalary() const;
    double getPositionAllowance() const;
    double getBonus() const;
    void setPositionAllowance(double positionAllowance);
    void setBonus(double bonus);
};