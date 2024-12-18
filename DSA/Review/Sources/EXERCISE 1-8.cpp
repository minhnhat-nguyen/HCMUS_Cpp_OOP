#include <fstream>
#include <iostream>

template <typename T>
class List {
   private:
    struct Node {
        T data;
        Node* next;
        Node(T c, Node* next = nullptr) {
            this->data = c;
            this->next = next;
        }
    };;
    Node* head;
    Node* tail;

    void recursive_delete(Node* node) {
        if (!node) return;
        if (node->next) recursive_delete(node->next);
        delete node;
    }

   public:
    List() { this->head = this->tail = nullptr; }

    ~List() { recursive_delete(this->head); }

    bool empty() { return this->head == nullptr; }

    void push_back(T data) {
        Node* node = new Node(data);
        if (this->empty())
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    void push_front(T data) {
        Node* node = new Node(data);
        if (this->empty())
            head = tail = node;
        else {
            node->next = head;
            head = node;
        }
    }

    void pop_back() {
        if (this->empty()) return;
        if (head == tail) {
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != this->tail) temp = temp->next;
        delete this->tail;
        this->tail = temp;
        this->tail->next = nullptr;
    }

    void pop_front() {
        if (this->empty()) return;
        Node* temp = this->head->next;
        delete this->head;
        this->head = temp;
    }

    T front() { return this->head->data; }

    T back() { return this->tail->data; }
};

bool is_palindrome(std::string str) {
    List<char> list;
    for (char c : str) {
        char ch = tolower(c);
        if (ch >= 'a' && ch <= 'z') list.push_back(ch);
    }
    while (!list.empty()) {
        if (list.back() != list.front()) return 0;
        list.pop_back();
        list.pop_front();
    }
    return 1;
}

int main() {
    std::fstream file("input1.8.1.txt", std::ios::in);
    std::string str;
    while (std::getline(file, str)) {
        std::cout << '"' << str << "\" is "
                  << (is_palindrome(str) ? "" : "not ") << "a palindrome string"
                  << '\n';
    }
}