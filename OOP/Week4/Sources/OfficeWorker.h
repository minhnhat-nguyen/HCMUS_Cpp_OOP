#pragma once
#include <iostream>

#include "Employee.h"

class OfficeWorker : public Employee {
   private:
    int workdays;
    double allowance;

   public:
    // do the same to 5 constructors above
    OfficeWorker();
    OfficeWorker(const OfficeWorker& officeWorker) = default;
    OfficeWorker(std::string name);
    OfficeWorker(std::string name, double baseSalary);
    OfficeWorker(std::string name, int startedYear, double baseSalary,
                 int workdays, double allowance);
    virtual ~OfficeWorker() = default;
    virtual double getSalary() const;
    int getWorkdays() const;
    double getAllowance() const;
    void setWorkdays(int workdays);
    void setAllowance(double allowance);
    friend std::istream& operator>>(std::istream& is,
                                    OfficeWorker& officeWorker);
    friend std::ostream& operator<<(std::ostream& os,
                                    const OfficeWorker& officeWorker);
};