#include <iostream>
#include "Manager.h"

Manager::Manager() : Employee(), positionAllowance(1.0), bonus(0.0) {}
Manager::Manager(std::string name, std::string id, int startedYear, double baseSalary, double positionAllowance, double bonus) : Employee(name, id, startedYear, baseSalary), positionAllowance(positionAllowance), bonus(bonus) {}
double Manager::getSalary() const { return baseSalary * positionAllowance + bonus; }
double Manager::getPositionAllowance() const { return positionAllowance; }
double Manager::getBonus() const { return bonus; }
void Manager::setPositionAllowance(double positionAllowance) { this->positionAllowance = positionAllowance; }
void Manager::setBonus(double bonus) { this->bonus = bonus; }

void Manager::input(std::istream& is) {
    std::string name;
    std::string id;
    int startedYear;
    double baseSalary;
    double positionAllowance;
    double bonus;
    std::cout << "Enter name, id, started year, base salary, position allowance, bonus: ";
    is >> name >> id >> startedYear >> baseSalary >> positionAllowance >> bonus;
    this->name = name;
    this->id = id;
    this->startedYear = startedYear;
    this->baseSalary = baseSalary;
    this->positionAllowance = positionAllowance;
    this->bonus = bonus;
    inputBirthday();
}

void Manager::output(std::ostream& os) const {
    os << this->name << " " << this->id << " " << this->startedYear << " " << this->baseSalary << " " << this->positionAllowance << " " << this->bonus;
}