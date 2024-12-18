#include "Company.h"

Company::Company() {
    companyName = "_default";
}

Company::Company(std::string companyName) : companyName(companyName) {}

void Company::addEmployee(Employee* employee) {
    if (dynamic_cast<Manager*>(employee))
        _managers.push_back(*dynamic_cast<Manager*>(employee));
    else if (dynamic_cast<FactoryWorker*>(employee))
        _ftrWorkers.push_back(*dynamic_cast<FactoryWorker*>(employee));
    else if (dynamic_cast<OfficeWorker*>(employee))
        _ofceWorkers.push_back(*dynamic_cast<OfficeWorker*>(employee));
}

void Company::Input() {
    int n;
    OfficeWorker ofceWorker;
    std::cout << "Enter number of office workers: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> ofceWorker;
        _ofceWorkers.push_back(ofceWorker);
    }
    FactoryWorker ftrWorker;
    std::cout << "Enter number of factory workers: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> ftrWorker;
        _ftrWorkers.push_back(ftrWorker);
    }
    Manager manager;
    std::cout << "Enter number of managers: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> manager;
        _managers.push_back(manager);
    }
}

void Company::Output() {
    std::cout << "Office workers: " << '\n';
    for (OfficeWorker ofceWorker : _ofceWorkers)
        std::cout << ofceWorker << '\n';
    std::cout << "Factory workers: " << '\n';
    for (FactoryWorker ftrWorker : _ftrWorkers) std::cout << ftrWorker << '\n';
    std::cout << "Managers: " << '\n';
    for (Manager manager : _managers) std::cout << manager << '\n';
}

double Company::getSalary() {
    double totalSalary = 0;
    for (OfficeWorker ofceWorker : _ofceWorkers)
        totalSalary += ofceWorker.getSalary();
    for (FactoryWorker ftrWorker : _ftrWorkers)
        totalSalary += ftrWorker.getSalary();
    for (Manager manager : _managers) totalSalary += manager.getSalary();
    return totalSalary;
}

std::vector<Employee*> Company::findEmployee(std::string name) {
    std::vector<Employee*> result;
    for (OfficeWorker& ofceWorker : _ofceWorkers)
        if (ofceWorker.getName() == name) result.push_back(&ofceWorker);
    for (FactoryWorker& ftrWorker : _ftrWorkers)
        if (ftrWorker.getName() == name) result.push_back(&ftrWorker);
    for (Manager& manager : _managers)
        if (manager.getName() == name) result.push_back(&manager);
    return result;
}
