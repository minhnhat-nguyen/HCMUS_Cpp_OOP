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

    bool isSameDepth_helper(Node* curr, int& depth, int level) {
        if (!curr) return 1;
        if (!curr->_left && !curr->_right) {
            if (depth == -1) depth = level;
            return depth == level;
        }
        return isSameDepth_helper(curr->_left, depth, level + 1) &&
               isSameDepth_helper(curr->_right, depth, level + 1);
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

    bool isSameDepth() {
        int depth = -1;
        return isSameDepth_helper(this->root, depth, 0);
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
        if (tree.isAVL())
            std::cout << "The tree leaves " << (tree.isSameDepth() ? "are" : "aren't") << " in the same depth" << '\n';
    }
    return 0;
}