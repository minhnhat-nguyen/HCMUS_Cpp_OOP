#pragma once
#define default_size 1000

class Stack {
   private:
    int* arr;
    int topIndex;
    int size;

   public:
    Stack(int n = default_size);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int n);
    void pop();
    int getTopValue();
};