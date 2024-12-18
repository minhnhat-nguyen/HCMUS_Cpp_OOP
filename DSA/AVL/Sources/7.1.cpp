#include <algorithm>
#include <iostream>
#include <vector>

class AVLTree {
   public:
    AVLTree() { root = nullptr; }

    void insert(int key) { root = insert(root, key); }

    void preOrderTraversal() { preOrder(root); }

    void inOrderTravelsal() { inOrder(root); }

    void postOrderTraversal() { postOrder(root); }

    void deleteNode(int key) { root = deleteNode(root, key); }

    int getHeight() { return root->height; }

    bool isExist(int key) { return search(root, key); }

   private:
    class Node {
       public:
        int key;
        Node *left;
        Node *right;
        int height;
        Node(int key) {
            this->key = key;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    Node *root;
    int height(Node *N) {
        if (N == nullptr) return 0;
        return N->height;
    }

    Node *newNode(int key) {
        Node *node = new Node(key);
        return node;
    }

    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;
        return y;
    }

    int getBalance(Node *N) {
        if (N == nullptr) return 0;
        return height(N->left) - height(N->right);
    }

    Node *insert(Node *node, int key) {
        if (node == nullptr) return newNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key) return rightRotate(node);

        if (balance < -1 && key > node->right->key) return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Node *root) {
        if (!root) return;
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node *root) {
        if (!root) return;
        inOrder(root->left);
        std::cout << root->key << " ";
        inOrder(root->right);
    }

    void postOrder(Node *root) {
        if (!root) return;
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->key << " ";
    }

    Node *findMin(Node *node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node *deleteNode(Node *node, int key) {
        if (node == nullptr) return node;

        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node *temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else
                    *node = *temp;
                delete temp;
            } else {
                Node *temp = findMin(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        if (node == nullptr) return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    bool search(Node *node, int key) {
        if (node == nullptr) return 0;
        if (key < node->key)
            return search(node->left, key);
        else if (key > node->key)
            return search(node->right, key);
        else
            return 1;
    }
};

int main() {
    AVLTree tree;
    std::vector<int> vt = {1, 2, 3, 4, 5, 6, 7};
    for (int i : vt) tree.insert(i);
    std::cout << "Pre-order traversal: ";
    tree.preOrderTraversal();
    std::cout << '\n';
    std::cout << "In-order traversal: ";
    tree.inOrderTravelsal();
    std::cout << '\n';
    std::cout << "Post-order traversal: ";
    tree.postOrderTraversal();
    std::cout << '\n';
    tree.deleteNode(3);
    std::cout << "In-order traversal after deleting 3: ";
    tree.inOrderTravelsal();
    std::cout << '\n';
    std::cout << "Height of tree: " << tree.getHeight() << '\n';
    std::cout << "Is 10 in the tree? " << tree.isExist(10) << '\n';
    return 0;
}
