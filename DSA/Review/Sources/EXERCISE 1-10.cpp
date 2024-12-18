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
        std::cout << "\tName: " << name << std::endl;
        std::cout << "\tDate of birth: " << dateOfBirth.date << "/"
                  << dateOfBirth.month << "/" << dateOfBirth.year << std::endl;
        std::cout << "\tAddress: " << address << std::endl;
        std::cout << "\tClass: " << _class << std::endl;
        std::cout << "\tID: " << ID << std::endl;
    }
};

Student* read_file(int& n) {
    std::fstream file("output1.9.bin", std::ios::binary | std::ios::in);
    file.read((char*)&n, sizeof(int));
    Student* students = new Student[n];
    file.read((char*)students, sizeof(Student)*n);
    file.close();
    return students;
}

int main() {
    int n;
    Student* students = read_file(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Student " << i + 1 << "th information:\n";
        students[i].print();
    }
    delete[] students;
    return 0;
}