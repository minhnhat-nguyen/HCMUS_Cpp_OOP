#pragma once
#include <iostream>

#include "Employee.h"

class OfficeWorker : public Employee {
   private:
    int workdays;
    double allowance;

   protected:
      void input(std::istream& is);
      void output(std::ostream& os) const;

   public:
    OfficeWorker();
    OfficeWorker(std::string name, std::string id, int startedYear, double baseSalary,
                 int workdays, double allowance);
    virtual ~OfficeWorker() = default;
    virtual double getSalary() const;
    int getWorkdays() const;
    double getAllowance() const;
    void setWorkdays(int workdays);
    void setAllowance(double allowance);
};