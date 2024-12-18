#pragma once
#define default_size 1000
#include <iostream>
#include <stdexcept>

template <class T>
class Stack {
   private:
    T* data;
    int topIndex;
    int capacity;

   public:
    Stack() {
        data = new T[default_size];
        capacity = default_size;
        topIndex = 0;
    }

    Stack(int n) {
        data = new T[n];
        capacity = n;
        topIndex = 0;
    }

    ~Stack() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        topIndex = 0;
    }

    void clear() { topIndex = 0; }

    class StackFullException : public std::exception {
       public:
        const char* what() const noexcept override { return "Stack is full"; }
    };

    class StackEmptyException : public std::exception {
       public:
        const char* what() const noexcept override { return "Stack is empty"; }
    };

    void push(const T& n) {
        if (isFull()) {
            throw StackFullException();
        }
        data[topIndex++] = n;
    }

    void pop() {
        if (isEmpty()) {
            throw StackEmptyException();
        }
        --topIndex;
    }

    T getTop() {
        if (isEmpty()) {
            throw StackEmptyException();
        }
        return data[topIndex - 1];
    }

    bool isFull() const { return topIndex == capacity; }
    bool isEmpty() const { return topIndex == 0; }
};
