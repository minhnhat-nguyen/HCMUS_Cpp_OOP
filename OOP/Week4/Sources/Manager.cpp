#include <iostream>
#include "Manager.h"

Manager::Manager() : Employee(), positionAllowance(1.0), bonus(0.0) {}
Manager::Manager(std::string name) : Employee(name), positionAllowance(1.0), bonus(0.0) {}
Manager::Manager(std::string name, double baseSalary) : Employee(name, baseSalary), positionAllowance(1.0), bonus(0.0) {}
Manager::Manager(std::string name, int startedYear, double baseSalary, double positionAllowance, double bonus) : Employee(name, startedYear, baseSalary), positionAllowance(positionAllowance), bonus(bonus) {}
double Manager::getSalary() const { return baseSalary * positionAllowance + bonus; }
double Manager::getPositionAllowance() const { return positionAllowance; }
double Manager::getBonus() const { return bonus; }
void Manager::setPositionAllowance(double positionAllowance) { this->positionAllowance = positionAllowance; }
void Manager::setBonus(double bonus) { this->bonus = bonus; }
std::istream& operator>>(std::istream& is, Manager& manager) {
    std::string name;
    int startedYear;
    double baseSalary;
    double positionAllowance;
    double bonus;
    std::cout << "Enter name, started year, base salary, position allowance, bonus: ";
    is >> name >> startedYear >> baseSalary >> positionAllowance >> bonus;
    manager.setName(name);
    manager.setStartedYear(startedYear);
    manager.setBaseSalary(baseSalary);
    manager.setPositionAllowance(positionAllowance);
    manager.setBonus(bonus);
    return is;
}
std::ostream& operator<<(std::ostream& os, const Manager& manager) {
    os << manager.getName() << " " << manager.getStartedYear() << " " << manager.getBaseSalary() << " " << manager.getPositionAllowance() << " " << manager.getBonus();
    return os;
}