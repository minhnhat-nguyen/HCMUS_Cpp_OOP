#include <iostream>
#include <fstream>

bool strcmp(std::string str1, std::string str2) {
    if (str1.size() != str2.size())
        return 0;
    for (int i = 0; i < str1.size(); ++i)
        if (str1[i] != str2[i])
            return 0;
    return 1;
};
int main() {
    std::fstream input1("input1.4.1.txt");
    std::fstream input2("input1.4.2.txt");
    std::string str1, str2;
    int i = 1;
    while ((std::getline(input1, str1)) && i++) {
        std::getline(input2,str2);
        if (!strcmp(str1, str2)) {
            std::cout << i << "// " << str1 << '\n';
            std::cout << i << "\\\\ " << str2 << '\n';
        }
    }
}