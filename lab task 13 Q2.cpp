#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int reg_no;
    string name;
    float cgpa;

public:
    void input() {
        cout << "Reg No: "; cin >> reg_no; cin.ignore();
        cout << "Name: "; getline(cin, name);
        cout << "CGPA: "; cin >> cgpa;
    }

    void output() {
        cout << reg_no << " " << name << " " << cgpa << endl;
    }

    int getKey() { return reg_no; }
};

class Node {
public:
    Student data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(Student s) { data = s; }
};

class BinaryTree {
public:
    Node* root = nullptr;

    Node* insert(Node* r, Student s) {
        if (!r) return new Node(s);
        if (s.getKey() < r->data.getKey()) r->left = insert(r->left, s);
        else r->right = insert(r->right, s);
        return r;
    }

    void preorder(Node* r) {
        if (!r) return;
        r->data.output();
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        r->data.output();
        inorder(r->right);
    }

    void postorder(Node* r) {
        if (!r) return;
        postorder(r->left);
        postorder(r->right);
        r->data.output();
    }

    Node* search(Node* r, int key) {
        if (!r || r->data.getKey() == key) return r;
        if (key < r->data.getKey()) return search(r->left, key);
        return search(r->right, key);
    }
};

int main() {
    BinaryTree bt;
    int choice;

    do {
        cout << "\n1.Insert 2.Pre 3.In 4.Post 5.Search 6.Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) { Student s; s.input(); bt.root = bt.insert(bt.root, s); }
        else if (choice == 2) bt.preorder(bt.root);
        else if (choice == 3) bt.inorder(bt.root);
        else if (choice == 4) bt.postorder(bt.root);
        else if (choice == 5) {
            int r; cout << "Reg No: "; cin >> r;
            Node* res = bt.search(bt.root, r);
            if (res) res->data.output(); else cout << "Not Found\n";
        }
    } while (choice != 6);
}