#pragma once
#include <iostream>
#include <fstream>
#include "Employee.h"

class FactoryWorker : public Employee {
   private:
    int productCount;

   public:
    FactoryWorker();
    FactoryWorker(const FactoryWorker& factoryWorker) = default;
    FactoryWorker(std::string name);
    FactoryWorker(std::string name, double baseSalary);
    FactoryWorker(std::string name, int startedYear, double baseSalary,
                  int productCount);
    virtual ~FactoryWorker() = default;
    virtual double getSalary() const;

    int getProductCount() const;
    void setProductCount(int productCount);
    friend std::istream& operator>>(std::istream& is, FactoryWorker& factoryWorker);
    friend std::ostream& operator<<(std::ostream& os, const FactoryWorker& factoryWorker);
    
};