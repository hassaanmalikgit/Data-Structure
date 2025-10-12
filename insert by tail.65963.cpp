#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

class Linklist
{
public:

    void insertattail(int d)
    {
        Node* node = new Node;
        if(head == NULL)
        {
            node->data = d;
            node->next = NULL;
            head = node;
        }
        else
        {
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = node;
            node->next = NULL;
            node->data = d;
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
    Linklist ll;
    ll.insertattail(50);
    ll.insertattail(100);
    ll.insertattail(150);
    ll.insertattail(200);

    ll.display();

    return 0;
}