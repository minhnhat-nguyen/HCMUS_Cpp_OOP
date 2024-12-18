#include <iostream>

#include "Employee.h"
#include "FactoryWorker.h"
#include "Manager.h"
#include "OfficeWorker.h"
#include "Company.h"
int main() {
    Employee emp1;
    emp1.setName("Lý Minh");
    emp1.setStartedYear(2015);
    emp1.setBaseSalary(55000.0);

    std::cout << "Tên nhân viên: " << emp1.getName() << '\n';
    std::cout << "Năm bắt đầu làm việc: " << emp1.getStartedYear() << '\n';
    std::cout << "Lương cơ bản: " << emp1.getBaseSalary() << '\n';

    Employee emp2;
    Employee emp3("Vương Phương");
    Employee emp4("Trương Vĩ", 78000.0);
    Employee emp5("Lưu Mẫn", 2018, 63000.0);
    OfficeWorker off1;
    OfficeWorker off2("Triệu Kiệt");
    OfficeWorker off3("Trần Tú", 85000.0);
    OfficeWorker off4("Châu Vũ", 2015, 72000.0, 270, 1100.0);
    OfficeWorker off5("Chu Cương", 2019, 72000.0, 270, 1100.0);
    FactoryWorker fac1;
    FactoryWorker fac2("Dương Vĩ");
    FactoryWorker fac3("Từ Lệ", 92000.0);
    FactoryWorker fac4("Tôn Minh", 2020, 86000.0, 550);
    Manager man1;
    Manager man2("Chu Cương");
    Manager man3("Lý Đan", 105000.0);
    Manager man4("Hà Hiểu", 2016, 94000.0, 1.7, 6000.0);
    Company company;
    company.addEmployee(&off1);
    company.addEmployee(&off2); 
    company.addEmployee(&off3);
    company.addEmployee(&off4);
    company.addEmployee(&off5);
    company.addEmployee(&fac1);
    company.addEmployee(&fac2);
    company.addEmployee(&fac3);
    company.addEmployee(&fac4);
    company.addEmployee(&man1);
    company.addEmployee(&man2);
    company.addEmployee(&man3);
    company.addEmployee(&man4);
    std::cout << "Danh sách nhân viên: \n";
    company.Output();
    std::cout << "Tổng lương của công ty: " << company.getSalary() << '\n';
    std::string EmployeeToFind = "Chu Cương";
    std::cout << "Nhân viên có tên " << EmployeeToFind << " là: \n";
    std::vector<Employee*> matchedEmployee =company.findEmployee(EmployeeToFind);
    for (Employee* em : matchedEmployee) {
        if (dynamic_cast<OfficeWorker*>(em))
            std::cout << "OfficeWorker: " << *dynamic_cast<OfficeWorker*>(em) << '\n';
        else if (dynamic_cast<FactoryWorker*>(em))
            std::cout << "FactoryWorker: " << *dynamic_cast<FactoryWorker*>(em) << '\n';
        else if (dynamic_cast<Manager*>(em))
            std::cout << "Manager: " << *dynamic_cast<Manager*>(em) << '\n';
    }
    return 0;
}