#pragma once
#include <iostream>
#include <fstream>
#include "Employee.h"

class FactoryWorker : public Employee {
   private:
    int productCount;

   protected:
    void input(std::istream& is);
    void output(std::ostream& os) const;

   public:
    FactoryWorker();
    FactoryWorker(std::string name, std::string id, int startedYear, double baseSalary,
                  int productCount);
    virtual ~FactoryWorker() = default;
    virtual double getSalary() const;

    int getProductCount() const;
    void setProductCount(int productCount);
};