#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
      LinkedList() {
        head = NULL;
    }

    void insertNode(int value) {
        Node* node = new Node;
        node->data = value;
        node->next = NULL;

        if (value % 2 != 0) {
            node->next = head;
            head = node;
        } else {

        if (head == NULL) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
            temp = temp->next;
        }
            temp->next = node;
            }
        }
    }

    void displayList() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
        cout << endl;
    }

    void displayOddNodes() {
        Node* temp = head;
        int count = 0;
        cout << "Odd nodes: ";
        while (temp != NULL) {
    if (temp->data % 2 != 0) {
        cout << temp->data << " ";
        count++;
    }
            temp = temp->next;
        }
        cout << "\nCount of odd nodes: " << count << endl;
    }

    void displayEvenNodes() {
        Node* temp = head;
        int count = 0;
        cout << "Even nodes: ";
        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                cout << temp->data << " ";
                count++;
            }
            temp = temp->next;
        }
        cout << "\nCount of even nodes: " << count << endl;
    }
};

int main() {
    LinkedList list;

    list.insertNode(11);
    list.insertNode(6);
    list.insertNode(3);
    list.insertNode(14);
    list.insertNode(7);
    list.insertNode(10);

    list.displayList();
    list.displayOddNodes();
    list.displayEvenNodes();

    return 0;
}