#pragma once
#include <exception>

class IndexOutOfRangeException : public std::exception {
public:
    const char* what() const throw();
};

class Array {
private:
    int* _data;
    int _size;
public:
    Array(int size);
    Array(const Array& a);
    Array& operator=(const Array& a);
    ~Array();
    int& operator[](int index);
    const int& operator[](int index) const;
    int Size() const;
    int& GetValueAt(int index);
    const int& GetValueAt(int index) const;
};