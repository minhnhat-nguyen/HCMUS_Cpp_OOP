#include <iostream>
#define default_size 10
class Stack {
   private:
    char* arr;
    int size;
    int stack_size;
    void extend() {
        char* temp = new char[this->size * 2];
        for (int i = 0; i < this->size; ++i) temp[i] = arr[i];
        delete[] arr;
        arr = temp;
        this->size *= 2;
    }

   public:
    Stack() {
        this->size = default_size;
        arr = new char[this->size];
        stack_size = 0;
    }

    ~Stack() { delete[] arr; }

    void push(char c) {
        if (stack_size == size - 1) extend();
        arr[stack_size++] = c;
    }

    bool empty() { return stack_size == 0; }

    void pop() {
        if (!empty()) --stack_size;
    }
    
    char top() {
        if (!empty()) return arr[stack_size - 1];
        return '\0';
    }

};

void test() {
    Stack s;
    char c;
    int n;
    std::cout << "Enter the number of characters: ";
    std::cin >> n;
    while (n--) {
        std::cout << "Enter a character: ";
        std::cin >> c;
        s.push(c);
    }
    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }
}

int main() { test();}