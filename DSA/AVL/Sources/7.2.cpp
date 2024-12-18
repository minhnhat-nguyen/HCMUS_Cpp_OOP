#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

class Tree {
   private:
    class Node {
        friend Tree;
        int _val;
        Node *_left, *_right;
        Node(int val, Node* left = nullptr, Node* right = nullptr) {
            this->_val = val;
            this->_left = left;
            this->_right = right;
        }
    };
    Node* root;

    void insert_helper(int val, Node*& curr) {
        if (!curr) curr = new Node(val);
        if (curr->_val < val) insert_helper(val, curr->_right);
        if (curr->_val > val) insert_helper(val, curr->_left);
    }

    void preorder_helper(Node* curr) {
        if (!curr) return;
        std::cout << curr->_val << ' ';
        preorder_helper(curr->_left);
        preorder_helper(curr->_right);
    }

    int isAVL_helper(Node* curr, bool& flag) {
        if (flag || !curr) return 0;
        int left = isAVL_helper(curr->_left, flag);
        int right = isAVL_helper(curr->_right, flag);
        if (std::abs(left - right) > 1) flag = 1;
        if (curr == this->root) return !flag;
        return std::max(left, right) + 1;
    }

    void delete_helper(Node* curr) {
        if (!curr) return;
        delete_helper(curr->_left);
        delete_helper(curr->_right);
        delete curr;
    }

   public:
    Tree() { this->root = nullptr; };

    ~Tree() { delete_helper(this->root); }

    void insert(std::vector<int> vt) {
        for (int val : vt) insert_helper(val, root);
    }

    void preOrder() { preorder_helper(this->root); }

    bool isAVL() {
        bool crashie = 0;
        return isAVL_helper(this->root, crashie);
    }
};

int main() {
    // Write a program to determine if given binary trees are AVL Tree. Suppose
    // that trees only store integer number type.Your program read trees in
    // input.txt and output yes/no AVL Tree.In input.txt, first row is number
    // of tree.Next rows are trees with each tree will be on a line and in
    // pre-order.Each integer value is separated by a space
    std::fstream fin("input.txt");
    std::string line;
    int n, tmp;
    fin >> n;
    fin.ignore();
    while (n--) {
        Tree tree;
        std::vector<int> vt;
        std::getline(fin, line);
        std::stringstream ss(line);
        while (ss >> tmp) vt.push_back(tmp);
        tree.insert(vt);
        std::cout << (tree.isAVL() ? "yes" : "no") << '\n';
    }
    return 0;
}