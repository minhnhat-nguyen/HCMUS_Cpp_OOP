#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
int main() {
    std::ifstream input("input1.1.txt");
    std::string word;
    std::string str;
    std::getline(input,str);
    int n = stoi(str);
    while (n--) {
        std::getline(input,str);
        std::stringstream sstr(str);
        std::map<std::string, int> words;
        int sentences = 0;
        std::cout << str << '\n';
        while (sstr >> word) {
            word[0] = tolower(word[0]);
            if (word[word.size() - 1] == '.' || word[word.size() - 1] == '!' || word[word.size() - 1] == '?' || word[word.size() - 1] == ';')
                sentences++;
            if (word[word.size() - 1]< 'a' || word[word.size() - 1] > 'z')
                word.pop_back();
            if (words.find(word) == words.end())
                words[word] = 1;
            else
                words[word]++;
        }
        std::cout << "\nNumber of distinct words: " << words.size() << '\n';
        std::cout << "Number of sentences: " << sentences << "\n\n";
    } 
    input.close();
}