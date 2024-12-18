#include "Array.h"

const char* IndexOutOfRangeException::what() const throw() {
    return "Exception: Index out of range";
}


Array::Array(int size) : _size(size) {
    _data = new int[size];
}


Array::Array(const Array& a) : _size(a._size) {
    _data = new int[_size];
    for (int i = 0; i < _size; i++) {
        _data[i] = a._data[i];
    }
}

Array& Array::operator=(const Array& a) {
    if (this != &a) {
        delete[] _data;
        _size = a._size;
        _data = new int[_size];
        for (int i = 0; i < _size; i++) {
            _data[i] = a._data[i];
        }
    }
    return *this;
}

Array::~Array() {
    delete[] _data;
}


int& Array::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw IndexOutOfRangeException();
    }
    return _data[index];
}


const int& Array::operator[](int index) const {
    if (index < 0 || index >= _size) {
        throw IndexOutOfRangeException();
    }
    return _data[index];
}


int Array::Size() const {
    return _size;
}


int& Array::GetValueAt(int index) {
    if (index < 0 || index >= _size) {
        throw IndexOutOfRangeException();
    }
    return _data[index];
}


const int& Array::GetValueAt(int index) const {
    if (index < 0 || index >= _size) {
        throw IndexOutOfRangeException();
    }
    return _data[index];
}