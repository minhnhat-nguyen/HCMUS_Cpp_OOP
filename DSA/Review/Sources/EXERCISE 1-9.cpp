#include <fstream>
#include <iostream>

class Student {
    class Date {
       public:
        unsigned short date, month, year;
        Date(unsigned short date = 1, unsigned short month = 1, unsigned short year = 1) {
            this->date = date;
            this->month = month;
            this->year = year;
        }
    };

   public:
    char name[30];
    Date dateOfBirth;
    char address[50];
    char _class[10];
    char ID[9];
    Student() { dateOfBirth = Date(); }
    void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Date of birth: " << dateOfBirth.date << "/"
                  << dateOfBirth.month << "/" << dateOfBirth.year << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Class: " << _class << std::endl;
        std::cout << "ID: " << ID << std::endl;
    }
};

Student* input(int& n) {
    std::cout << "Enter number of students: ";
    std::cin >> n;
    Student* students = new Student[n];
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter student " << i + 1 << "th information:\n";
        std::cout << "Name: ";
        std::cin.ignore(32767,'\n');
        std::cin.getline(students[i].name, 30);
        std::cout << "Date of birth: ";
        std::cin >> students[i].dateOfBirth.date >>
            students[i].dateOfBirth.month >> students[i].dateOfBirth.year;
        std::cin.ignore(32767,'\n');
        std::cout << "Address: ";
        std::cin.getline(students[i].address, 50);
        std::cout << "Class: ";
        std::cin.getline(students[i]._class, 10);
        std::cout << "ID: ";
        std::cin >> students[i].ID;
    }
    return students;
}

void writeToFile(Student* students, int n) {
    std::fstream file("output1.9.bin", std::ios::binary | std::ios::out);
    file.seekp(0, std::ios::beg);
    file.write((char*)&n, sizeof(int));
    file.write((char*)students, sizeof(Student) * n);
    file.close();
}

int main() {
    int n;
    Student* students = input(n);
    writeToFile(students, n);
    return 0;
}