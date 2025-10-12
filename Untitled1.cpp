#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtTarget(Node*& head, int d, int loc) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp->next != NULL && count < loc) {
        temp = temp->next;
        count++;
    }

    if (count == loc) {
        Node* node = new Node;
        node->data = d;
        node->next = temp->next;
        temp->next = node;
        cout << "Inserted " << d << " at location " << loc+1 << endl;
    } else {
        cout << "Node does not exist at given location!" << endl;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};

    cout << "Original list: ";
    printList(head);

    insertAtTarget(head, 40, 2);  

    cout << "Updated list: ";
    printList(head);

    return 0;
}