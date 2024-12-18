#pragma once
#define default_size 1000

class Queue {
   private:
    int* arr;
    int frontIndex, rearIndex;
    int size;

   public:
    Queue(int n = default_size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int n);
    void dequeue();
    int getFrontValue();
};