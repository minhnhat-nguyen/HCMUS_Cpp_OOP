#include "Queue.h"

#include <cstring>
#include <iostream>

Queue::Queue(int n) {
    arr = new int[n];
    frontIndex = rearIndex = 0;
    size = n;
}

Queue::~Queue() {
    delete[] arr;
    arr = nullptr;
    frontIndex = rearIndex = 0;
    size = 0;
}

bool Queue::isEmpty() { return (frontIndex == rearIndex); }

bool Queue::isFull() { return (rearIndex == size && frontIndex == 0); }

void Queue::enqueue(int n) {
    if (rearIndex == size) {
        if (frontIndex == 0) return;
        memmove(arr + frontIndex, arr, rearIndex - frontIndex);
        rearIndex = size - frontIndex;
        frontIndex = 0;
    }
    arr[rearIndex++] = n;
}

void Queue::dequeue() {
    if (!isEmpty()) ++frontIndex;
}

int Queue::getFrontValue() {
    if (!isEmpty()) return arr[frontIndex];
    return INT32_MIN;
}
