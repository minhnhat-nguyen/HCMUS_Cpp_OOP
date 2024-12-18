#include "File.h"
#include <iostream>


const char* FileNotFoundException::what() const throw() {
    return "Exception: File does not exist!";
}

bool File::isOpen() {
    return _file.is_open();
}

void File::open(std::string path) {
    _filepath = path;
    _file.open(path, std::ios::in | std::ios::out);
    if (!_file.is_open()) {
        throw FileNotFoundException();
    }
}

void File::close() {
    _file.close();
}

void File::write(std::string str) {
    _file << str;
}

bool File::getline(std::string& str) {
    if (std::getline(_file, str))
        return true;
    return false;
}

void File::ignore() {
    _file.ignore();
}