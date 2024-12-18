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

    void print_helper(Member* pos, int depth = 0) {
        for (int i = 0; i < depth; ++i)
            std::cout << ((i == depth - 1) ? (string) "│" : (string) " ");
        std::cout << pos->name << '\n';
        for (Member* child: pos->children) 
            print_helper(child, depth + 1 + pos->name.length());
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

    void print() {
        print_helper(this->root);
    }
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
    tree.print();
    return 0;
}
