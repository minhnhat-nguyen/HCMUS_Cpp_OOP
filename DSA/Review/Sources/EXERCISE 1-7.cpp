#include <iostream>

class Queue {
   private:
    int _size;
    int maxSize;
    char* arr = nullptr;

   public:
    Queue() {
        this->_size = 0;
        this->maxSize = 0;
        arr = nullptr;
    }

    bool empty() { return this->_size == 0; }

    void push(char c) {
        if (this->_size == this->maxSize) {
            this->maxSize = 2 * (1 + this->maxSize);
            char* temp = new char[this->maxSize];
            for (int i = 0; i < _size; ++i) temp[i] = this->arr[i];
            // std::memcpy(temp, arr, _size * sizeof(int));
            delete[] arr;
            this->arr = temp;
        }
        this->arr[this->_size++] = c;
    }

    char front() { return this->arr[0]; }

    void pop() {
        if (this->empty())
            return;
        else {
            // memmove(arr, arr + 1, (--_size) * sizeof(int));
            for (int i = 1; i < this->_size; ++i)
                this->arr[i - 1] = this->arr[i];
            --this->_size;
        }
    }
};

void test() {
    Queue q;
    char c;
    int n;
    std::cout << "Enter the number of characters: ";
    std::cin >> n;
    while (n--) {
        std::cout << "Enter a character: ";
        std::cin >> c;
        q.push(c);
    }
    while (!q.empty()) {
        std::cout << q.front() << ' ';
        q.pop();
    }
}

int main() {
    test();
}