#include <fstream>
#include <iostream>
#include <list>
int main() {
    bool choice;
    int n;
    std::string str;
    std::cout << "Input the arguements: ";
    std::cin >> choice >> n >> str;
    std::fstream file(str, std::ios::in);
    if (choice) {
        std::list<std::string> list;
        while (n--) {
            std::getline(file, str);
            list.push_back(str);
        }
        while (std::getline(file, str)) {
            list.pop_front();
            list.push_back(str);
        }
        for (std::list<std::string>::iterator it = list.begin();
             it != list.end(); ++it)
            std::cout << *it << '\n';
    } else {
        while (n--) {
            std::getline(file, str);
            std::cout << str << '\n';
        }
    }
    file.close();
    return 0;
}