#include <algorithm>
#include <cmath>
#include <iostream>

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

    bool find_path(Node* curr, int val, std::vector<int>& path) {
        if (!curr) return 0;
        path.push_back(curr->_val);
        if (curr->_val == val)
            return 1;
        else if (curr->_val < val)
            return find_path(curr->_right, val, path);
        return find_path(curr->_left, val, path);
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

    int findLeastCommonAnceastor(int nodeA, int nodeB) {
        std::vector<int> pathA, pathB;
        if (!find_path(this->root, nodeA, pathA) ||
            !find_path(this->root, nodeB, pathB))
            return -1;
        int i = 0;
        while (i < pathA.size() && i < pathB.size() && pathA[i] == pathB[i])
            i++;
        return pathA[i - 1];
    }
};

int main() {
    std::vector<int> vt = {4, 2, 1, 3, 7, 5, 6, 9, 8, 10};
    Tree tree;
    tree.insert(vt);
    if (tree.isAVL())
        std::cout << tree.findLeastCommonAnceastor(6, 10);
    return 0;
}