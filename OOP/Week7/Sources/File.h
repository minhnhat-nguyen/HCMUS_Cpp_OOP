#pragma once
#include <exception>
#include <string>
#include <fstream>

class FileNotFoundException : public std::exception {
    public:
        const char* what() const throw();
};

class File {
    private: 
        std::fstream _file;
        std::string _filepath;
    public:
        bool isOpen();
        void open(std::string path);
        void close();
        void write(std::string str);
        bool getline(std::string& str);
        void ignore();
};