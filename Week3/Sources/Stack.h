#pragma once
#define default_size 1000
#include <iostream>

template <class T>
class Stack {
 private:
  T *data;
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
  bool isFull() { return topIndex == capacity; }
  bool isEmpty() { return topIndex == 0; }

  void push(const T &n) {
    if (!isFull()) data[topIndex++] = n;
  }

  T pop() {
    if (!isEmpty()) return data[--topIndex];
    return INT32_MAX;
  }

  T getTop() {
    if (!isEmpty()) return data[topIndex - 1];
    return INT32_MAX;
  }
};