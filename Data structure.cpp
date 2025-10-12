#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;


class Linkedlist
{
public:
    void insertathead(int d)
    {
        Node* node = new Node;
        if (head == NULL)
        {
            node->data = d;
            node->next = NULL;
            head = node;
        }
        else
        {
            node->data = d;
            node->next = head;
            head = node;
        }
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data<<endl;
            temp = temp->next;
        }
    }
};


int main()
{
    Linkedlist ll;
    ll.insertathead(50);
    ll.insertathead(100);
    ll.insertathead(150);

    ll.display();

    return 0;
}