#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>

using std::string;

const string FILENAME = "student.data";

class Date {
   public:
    int date, month, year;
};

class Student {
   public:
    string id;
    string name;
    Date bday;
    bool status;  // 0 for undergrad, 1 for graduated

    Student(string i_id = "", string i_name = "", bool status = 0) {
        this->id = i_id;
        this->name = i_name;
        this->status = 0;
    }

    bool operator< (const Student rhs) const { return this->name < rhs.name; }
    bool operator<=(const Student rhs) const { return this->name <= rhs.name; }
    bool operator==(const Student rhs) const { return this->name == rhs.name; }
    bool operator> (const Student rhs) const { return this->name > rhs.name; }
    bool operator>=(const Student rhs) const { return this->name >= rhs.name; }

    void print() {
        std::cout << this->id << ' ' << this->name << ' ' << this->bday.date
                  << '/' << this->bday.month << '/' << this->bday.year << ' '
                  << (!this->status ? (string) "Undergraduate"
                                    : (string) "Graduated")
                  << '\n';
    }
};

class BST {
   private:
    class Node {
        friend BST;
        Student data;
        Node *left, *right;
        Node(Student i_data, Node* i_left = nullptr, Node* i_right = nullptr) {
            this->data  = i_data;
            this->left  = i_left;
            this->right = i_right;
        }
    };

    Node* head;

    void insert_helper(Node*& pos, Node* info) {
        if (!pos)
            pos = info;
        else {
            if (pos->data.id < info->data.id) insert_helper(pos->right, info);
            if (pos->data.id > info->data.id) insert_helper(pos->left, info);
        }
    }

    void deleteById_helper(Node*& pos, const string& id) {
        Node* tpos = pos;
        if (!pos) return;
        if (pos->data.id == id) {
            if (!pos->left && !pos->right) {
                delete pos;
                pos = nullptr;
                return;
            } else if (!tpos->left) {
                while (tpos->right) {
                    std::swap(tpos->data, tpos->right->data);
                    if (!tpos->right->right) {
                        delete tpos->right;
                        tpos->right = nullptr;
                        return;
                    }
                    tpos = tpos->right;
                }
            } else {
                while (tpos->left) {
                    std::swap(tpos->data, tpos->left->data);
                    if (!tpos->left->left) {
                        delete tpos->left;
                        tpos->left = nullptr;
                        return;
                    }
                    pos = pos->left;
                }
            }
        } else if (pos->data.id < id)
            deleteById_helper(pos->right, id);
        else if (pos->data.id > id)
            deleteById_helper(pos->left, id);
    }

    void lexicographicPrint_helper(Node* pos, std::set<Student>& s) {
        if (!pos) return;
        lexicographicPrint_helper(pos->left, s);
        s.insert(pos->data);
        lexicographicPrint_helper(pos->right, s);
    }

    Student* findById_helper(Node* pos, const string& id) {
        if (!pos) return nullptr;
        if (pos->data.id == id) return &pos->data;
        if (pos->data.id < id)  return findById_helper(pos->right, id);
        if (pos->data.id > id)  return findById_helper(pos->left, id);
        return nullptr;
    }

    void listGraduated_helper(Node* pos) {
        if (!pos) return;
        listGraduated_helper(pos->left);
        if (pos->data.status) pos->data.print();
        listGraduated_helper(pos->right);
    }

    void deleteGraduated_helper(Node*& pos) {
        while (pos && pos->data.status) {
            std::cout << pos->data.name << " has been deleted\n";
            deleteById_helper(head, pos->data.id);
        }
        if (!pos) return;
        deleteGraduated_helper(pos->left);
        deleteGraduated_helper(pos->right);
    }

   public:
    BST() { this->head = nullptr; }

    bool isEmpty() { return !this->head; }

    void insert(Student info) {
        Node* tmp = new Node(info);
        insert_helper(head, tmp);
    }

    void lexicographicPrint() {
        std::set<Student> s;
        lexicographicPrint_helper(head, s);
        for (Student i : s) i.print();
    }

    Student* findById(string id) {
        Student* tmp = findById_helper(head, id);
        if (!tmp) return nullptr;
        return tmp;
    }

    void deleteById(string id) { deleteById_helper(head, id); }

    void writeToFile(string filename) {
        std::fstream io_f(filename, std::ios::out | std::ios::trunc);
        std::set<Student> s;
        lexicographicPrint_helper(head, s);
        io_f << s.size() << '\n';
        for (Student i : s) {
            io_f << i.id << '\n'
                 << i.name << '\n'
                 << i.bday.date << '/' << i.bday.month << '/' << i.bday.year
                 << '\n'
                 << i.status << '\n';
        }
        io_f.close();
    }

    void listGraduated() { listGraduated_helper(head); }

    void deleteGraduated() { deleteGraduated_helper(head); }
};

Date parseDate(string date) {
    Date d;
    string token;
    std::istringstream ss(date);
    std::getline(ss, token, '/');
    d.date = std::stoi(token);
    std::getline(ss, token, '/');
    d.month = std::stoi(token);
    std::getline(ss, token, '/');
    d.year = std::stoi(token);
    return d;
}

BST readFile(string file_name) {
    BST bst;
    std::fstream io_f(file_name, std::ios::in);
    if (!io_f) return bst;
    Student s;
    int n;
    string bod;
    io_f >> n;
    while (n--) {
        io_f >> s.id >> s.name >> bod >> s.status;
        s.bday = parseDate(bod);
        bst.insert(s);
    }
    io_f.close();
    return bst;
}

Student inputStudent(bool type = 0) {
    Student s;
    string bod;
    if (!type) {
        std::cout << "Enter student id: ";
        std::cin >> s.id;
    }
    std::cout << "Enter student name: ";
    std::cin >> s.name;
    std::cout << "Enter student birthday (dd/mm/yyyy): ";
    std::cin >> bod;
    s.bday = parseDate(bod);
    std::cout << "Enter student status (0 for undergrad, 1 for graduated): ";
    std::cin >> s.status;
    return s;
}

BST bstInput() {
    BST bst;
    int n;
    std::cout << "Enter number of students: ";
    std::cin >> n;
    while (n--) {
        Student s = inputStudent();
        bst.insert(s);
    }
    bst.lexicographicPrint();
    return bst;
}

void addNewStudent(BST& bst) {
    Student s = inputStudent();
    bst.insert(s);
    std::cout << "Added successfully!\n";
}

void findById(BST& bst) {
    string id;
    std::cout << "Enter student id: ";
    std::cin >> id;
    Student* tmp = bst.findById(id);
    if (!tmp)
        std::cout << "Student not found!\n";
    else {
        std::cout << "==>  ";
        tmp->print();
    }
}

void updateById(BST& bst) {
    string id;
    std::cout << "Enter student id: ";
    std::cin >> id;
    Student* tmp = bst.findById(id);
    if (!tmp)
        std::cout << "Student not found!\n";
    else {
        string name = tmp->id;
        std::cout << "Enter new student info!\n";
        *tmp = inputStudent(1);
        tmp->id = id;
        std::cout << "Updated successfully!\n";
    }
}

void deleteById(BST& bst) {
    string id;
    std::cout << "Enter student id: ";
    std::cin >> id;
    bst.deleteById(id);
    std::cout << "Deleted successfully!\n";
}

void writeToFile(BST& bst) {
    bst.writeToFile(FILENAME);
    std::cout << "Saved successfully!\n";
}

void lexicographicPrint(BST& bst) {
    std::cout << "List of students in lexicographic order: \n"; 
    bst.lexicographicPrint(); 
}

void listGraduated(BST& bst) {
    std::cout << "List of graduated students: \n";
    bst.listGraduated(); 
}

void deleteGraduated(BST& bst) {
    bst.deleteGraduated();
    std::cout << "Deleted successfully!\n";
}

int main() {
    char c;
    BST bst = readFile(FILENAME);
    std::cout << "Loading data from file...\n"
              << (bst.isEmpty() ? (string) "No data found!"
                                : (string) "Data loaded!\n");
    int choice = 1;
    while (choice) {
        std::cout << "\n----------------------------------------\n"
                  << "[0] Exit\n"
                  << "[1] Add new student\n"
                  << "[2] Find student by id\n"
                  << "[3] Update student's info by id\n"
                  << "[4] List students in lexicographic order\n"
                  << "[5] List all gratuated students\n"
                  << "[6] Delete student's info by id\n"
                  << "[7] Delete all graduated students\n"
                  << "[8] Save data to file\n"
                  << "----------------------------------------\n"
                  << "\nEnter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 0:
                std::cout << "Program terminated!\n";
                break;
            case 1:
                addNewStudent(bst);
                break;
            case 2:
                findById(bst);
                break;
            case 3:
                updateById(bst);
                break;
            case 4:
                lexicographicPrint(bst);
                break;
            case 5:
                listGraduated(bst);
                break;
            case 6:
                deleteById(bst);
                break;
            case 7:
                deleteGraduated(bst);
                break;
            case 8:
                writeToFile(bst);
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    }
    return 0;
}