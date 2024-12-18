#include "Stack.h"

#include <iostream>

Stack::Stack(int n) {
    arr = new int[n];
    size = n;
    topIndex = 0;
}

Stack::~Stack() {
    delete[] arr;
    arr = nullptr;
    size = 0;
    topIndex = 0;
}

bool Stack::isEmpty() { return (topIndex == 0); }

bool Stack::isFull() { return (topIndex == size); }

void Stack::push(int n) {
    if (!isFull()) arr[topIndex++] = n;
}

void Stack::pop() {
    if (!isEmpty()) --topIndex;
}

int Stack::getTopValue() {
    if (!isEmpty()) return arr[topIndex - 1];
    return INT32_MIN;
}