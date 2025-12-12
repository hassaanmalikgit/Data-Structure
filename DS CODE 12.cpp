#include <iostream>
#include <string>
#include <iomanip> // for formatting large values
using namespace std;

class Account {
public:
    int id;
    string name;
    double balance;
    Account() {
        id = 0;
        name = "";
        balance = 0;
    }

    Account(int i, string n, double b) {
        id = i;
        name = n;
        balance = b;
    }

    void display() {
        cout << "ID: " << id << " | Name: " << name
             << " | Balance: " << fixed << setprecision(2) << balance << endl;
    }
};

struct StackNode {
    string action;
    StackNode* next;
};

class TransactionStack {
private:
    StackNode* top;

public:
    TransactionStack() { top = NULL; }

    void push(string a) {
        StackNode* n = new StackNode();
        n->action = a;
        n->next = top;
        top = n;
    }

    void show() {
        StackNode* temp = top;
        cout << "\n--- Transaction History ---\n";
        while (temp != NULL) {
            cout << temp->action << endl;
            temp = temp->next;
        }
    }
};

struct Node {
    Account data;
    Node* next;
};
struct DNode {
    Account data;
    DNode* next;
    DNode* prev;
};
struct BSTNode {
    Account data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insertBST(BSTNode* root, Account a) {
    if (root == NULL) {
        BSTNode* n = new BSTNode();
        n->data = a;
        n->left = n->right = NULL;
        return n;
    }
    if (a.id < root->data.id) root->left = insertBST(root->left, a);
    else root->right = insertBST(root->right, a);
    return root;
}

Account* searchBST(BSTNode* root, int id) {
    if (root == NULL) return NULL;
    if (root->data.id == id) return &root->data;
    if (id < root->data.id) return searchBST(root->left, id);
    else return searchBST(root->right, id);
}

void bubbleSort(Account arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Account temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

Node* head = NULL;
DNode* dhead = NULL;
BSTNode* bstRoot = NULL;
TransactionStack stack;
Account arr[100];
int arrCount = 0;

void createAccount() {
    int id;
    string name;
    double bal = 0;

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Balance: ";
    cin >> bal;

    Account a(id, name, bal);
    arr[arrCount++] = a;

    Node* n = new Node();
    n->data = a;
    n->next = head;
    head = n;

    DNode* dn = new DNode();
    dn->data = a;
    dn->next = dhead;
    dn->prev = NULL;
    if (dhead != NULL) dhead->prev = dn;
    dhead = dn;

    bstRoot = insertBST(bstRoot, a);

    cout << "Account Created Successfully!\n";
}

void deposit() {
    int id;
    double amt;
    cout << "Enter ID: ";
    cin >> id;

    Account* a = searchBST(bstRoot, id);
    if (a == NULL) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter Amount: ";
    cin >> amt;

    a->balance += amt; // update first

    // update array
    for (int i = 0; i < arrCount; i++) {
        if (arr[i].id == id) {
            arr[i].balance = a->balance;
            break;
        }
    }

    // update singly linked list
    Node* t = head;
    while (t != NULL) {
        if (t->data.id == id) {
            t->data.balance = a->balance;
            break;
        }
        t = t->next;
    }

    // update doubly linked list
    DNode* d = dhead;
    while (d != NULL) {
        if (d->data.id == id) {
            d->data.balance = a->balance;
            break;
        }
        d = d->next;
    }

    stack.push("Deposited " + to_string(amt) + " into ID " + to_string(id));
    cout << "Deposit Successful. New Balance: " << a->balance << endl;
}

void withdraw() {
    int id;
    double amt;
    cout << "Enter ID: ";
    cin >> id;

    Account* a = searchBST(bstRoot, id);
    if (a == NULL) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter Amount: ";
    cin >> amt;

    if (amt > a->balance) {
        cout << "Insufficient Funds.\n";
        return;
    }

    a->balance -= amt; // update first

    // update array
    for (int i = 0; i < arrCount; i++) {
        if (arr[i].id == id) {
            arr[i].balance = a->balance;
            break;
        }
    }

    // update singly linked list
    Node* t = head;
    while (t != NULL) {
        if (t->data.id == id) {
            t->data.balance = a->balance;
            break;
        }
        t = t->next;
    }

    // update doubly linked list
    DNode* d = dhead;
    while (d != NULL) {
        if (d->data.id == id) {
            d->data.balance = a->balance;
            break;
        }
        d = d->next;
    }

    stack.push("Withdrew " + to_string(amt) + " from ID " + to_string(id));
    cout << "Withdrawal Successful. New Balance: " << a->balance << endl;
}

void displayAccounts() {
    if (dhead == NULL) {
        cout << "There is no account.\n";
        return;
    }
    cout << "\n--- Accounts (Doubly Linked List Forward Traversal) ---\n";
    DNode* temp = dhead;
    while (temp != NULL) {
        temp->data.display();
        temp = temp->next;
    }
}

void sortAccounts() {
    bubbleSort(arr, arrCount);
    cout << "Accounts Sorted by ID.\n";
}

void menu() {
    int choice;
    while (true) {
        cout << "\n--- Banking System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Accounts\n";
        cout << "5. Sort Accounts by ID\n";
        cout << "6. Show Transactions\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayAccounts(); break;
            case 5: sortAccounts(); break;
            case 6: stack.show(); break;
            case 7: return;
            default: cout << "Invalid Choice.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}