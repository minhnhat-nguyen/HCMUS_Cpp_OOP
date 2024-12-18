#pragma once
#define default_size 1000
#include <stdexcept>

template <class T>
class Queue {
   private:
    T* arr;
    int frontIndex, rearIndex;
    int size;

   public:
    Queue(int n = default_size) {
        arr = new T[n];
        size = n;
        frontIndex = rearIndex = -1;
    }

    ~Queue() {
        delete[] arr;
        arr = nullptr;
        size = 0;
        frontIndex = rearIndex = -1;
    }

    bool isEmpty() const { return frontIndex == -1; }

    bool isFull() const { return (rearIndex + 1) % size == frontIndex; }

    class QueueEmptyException : public std::exception {
       public:
        const char* what() const noexcept override { return "Queue is empty"; }
    };

    class QueueFullException : public std::exception {
       public:
        const char* what() const noexcept override { return "Queue is full"; }
    };

    void enqueue(const T& n) {
        if (isFull()) {
            throw QueueFullException();
        }

        if (isEmpty()) {
            frontIndex = 0;
        }

        rearIndex = (rearIndex + 1) % size;
        arr[rearIndex] = n;
    }

    void dequeue() {
        if (isEmpty()) {
            throw QueueEmptyException();
        }

        if (frontIndex == rearIndex) {
            frontIndex = rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % size;
        }
    }

    T getFront() const {
        if (isEmpty()) {
            throw QueueEmptyException();
        }
        return arr[frontIndex];
    }
};
