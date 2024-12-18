#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::string;

class Member {
    friend class FamilyTree;
    string name;
    std::vector<Member*> children;
    Member(string i_name) { name = i_name; }
};

class FamilyTree {
   private:
    Member* root;
    std::unordered_map<string, Member*> members;

    void preOrder_helper(Member* pos) {
        if (!pos) return;
        std::cout << pos->name << ' ';
        if (pos->children.size() > 0) preOrder_helper(pos->children[0]);
        if (pos->children.size() > 1) preOrder_helper(pos->children[1]);
    }

    void inOrder_helper(Member* pos) {
        if (!pos) return;
        if (pos->children.size() > 0) inOrder_helper(pos->children[0]);
        std::cout << pos->name << ' ';
        if (pos->children.size() > 1) inOrder_helper(pos->children[1]);
    }

    void postOrder_helper(Member* pos) {
        if (!pos) return;
        if (pos->children.size() > 0) postOrder_helper(pos->children[0]);
        if (pos->children.size() > 1) postOrder_helper(pos->children[1]);
        std::cout << pos->name << ' ';
    }

   public:
    FamilyTree() { this->root = 0; }

    bool isEmpty() { return (this->root == nullptr); }

    void insert(string child, string parent) {
        if (this->members.find(parent) == this->members.end()) {
            this->members[parent] = new Member(parent);
            this->root = this->members[parent];
        }
        Member* tmpChild = new Member(child);
        this->members[child] = tmpChild;
        this->members[parent]->children.push_back(tmpChild);
    }

    void preOrder() { preOrder_helper(this->root); }

    void inOrder() { inOrder_helper(this->root); }

    void postOrder() { postOrder_helper(this->root); }
};

FamilyTree readFile() {
    char c;
    FamilyTree tree;
    int n;
    string parent, child = "";
    std::fstream iof("input.txt");
    iof >> n;
    while (n--) {
        iof >> c >> parent >> c;
        while (true) {
            iof >> c;
            if (c == ')') {
                tree.insert(child, parent);
                break;
            }
            if (isupper(c)) {
                if (child.length() != 0) tree.insert(child, parent);
                child = "";
            }
            child += c;
        }
        child = "";
        iof.ignore(32767, '\n');
    }
    return tree;
}

int main() {
    FamilyTree tree = readFile();
    tree.preOrder();
    std::cout << '\n';
    tree.inOrder();
    std::cout << '\n';
    tree.postOrder();
    return 0;
}
