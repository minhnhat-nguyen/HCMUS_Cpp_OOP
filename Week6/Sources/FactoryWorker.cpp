#include "FactoryWorker.h"
#include <iostream>

FactoryWorker::FactoryWorker() : Employee(), productCount(0) {}
FactoryWorker::FactoryWorker(std::string name, std::string id, int startedYear, double baseSalary, int productCount) : Employee(name, id, startedYear, baseSalary), productCount(productCount) {}
double FactoryWorker::getSalary() const { return baseSalary + productCount * 2000; }
int FactoryWorker::getProductCount() const { return productCount; }
void FactoryWorker::setProductCount(int productCount) { this->productCount = productCount; }

void FactoryWorker::input(std::istream& is) {
    std::string name;
    std::string id;
    int startedYear;
    double baseSalary;
    int productCount;
    std::cout << "Enter name, id, started year, base salary, product count: ";
    is >> name >> id >> startedYear >> baseSalary >> productCount;
    this->name = name;
    this->id = id;
    this->startedYear = startedYear;
    this->baseSalary = baseSalary;
    this->productCount = productCount;
    inputBirthday();
}

void FactoryWorker::output(std::ostream& os) const {
    os << this->name << " " << this->id << " " << this->startedYear << " " << this->baseSalary << " " << this->productCount;
}