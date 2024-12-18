#include "FactoryWorker.h"
#include <iostream>

FactoryWorker::FactoryWorker() : Employee(), productCount(0) {}
FactoryWorker::FactoryWorker(std::string name) : Employee(name), productCount(0) {}
FactoryWorker::FactoryWorker(std::string name, double baseSalary) : Employee(name, baseSalary), productCount(0) {}
FactoryWorker::FactoryWorker(std::string name, int startedYear, double baseSalary, int productCount) : Employee(name, startedYear, baseSalary), productCount(productCount) {}
double FactoryWorker::getSalary() const { return baseSalary + productCount * 2000; }
int FactoryWorker::getProductCount() const { return productCount; }
void FactoryWorker::setProductCount(int productCount) { this->productCount = productCount; }
std::istream& operator>>(std::istream& is, FactoryWorker& factoryWorker) {
    std::string name;
    int startedYear;
    double baseSalary;
    int productCount;
    std::cout << "Enter name, started year, base salary, product count: ";
    is >> name >> startedYear >> baseSalary >> productCount;
    factoryWorker.setName(name);
    factoryWorker.setStartedYear(startedYear);
    factoryWorker.setBaseSalary(baseSalary);
    factoryWorker.setProductCount(productCount);
    return is;
}
std::ostream& operator<<(std::ostream& os, const FactoryWorker& factoryWorker) {
    os << factoryWorker.getName() << " " << factoryWorker.getStartedYear() << " " << factoryWorker.getBaseSalary() << " " << factoryWorker.getProductCount();
    return os;
}