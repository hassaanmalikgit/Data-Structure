#include <iostream>
using namespace std;

class Node {
public:
    float data;
    Node* prev;
    Node* next;

    Node(float val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(float val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        cout << "\nList: ";
        Node* t = head;
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }

    void deleteNode(float val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->data != val)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Value not found!\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Node deleted!\n";
    }

    void search(float val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        int pos = 1;
        Node* t = head;
        while (t != NULL) {
            if (t->data == val) {
                cout << "Found " << val << " at position " << pos << "\n";
                return;
            }
            t = t->next;
            pos++;
        }
        cout << "Value not found!\n";
    }
};

int main() {
    DoublyLinkedList list;
    int choice;
    float val;

    do {
        cout << "\n>> Doubly Linked List Menu <<\n";
        cout << "1. Insert Node\n";
        cout << "2. Display List\n";
        cout << "3. Delete Node\n";
        cout << "4. Search Value\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteNode(val);
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> val;
                list.search(val);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
