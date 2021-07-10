#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue

void enqueue(int x)
{
    struct Node* t = new Node[1];

    if (t == NULL)
    {
        cout << "\nQueue is Full" << endl;
    }
    else
    {
        t->data = x;
        t->next = NULL;

        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

// Dequeue

int dequeue()
{
    int x = -1;
    if (front == NULL)
    {
        cout << "\nQueue Underflow" << endl;
    }
    else
    {
        struct Node* P = front;
        front = front->next;
        x = P->data;
        delete P;
    }
    return x;
}

// Display

void display()
{
    Node* P = front;
    if (P == NULL)
    {
        cout << "\n\nQueue is Empty" << endl;
        return;
    }

    while (P)
    {
        cout << P->data << " ";
        P = P-> next;
    }
    cout << endl;
}

int main()
{                                                          // Here Even the Object is not created.

    int choice;
    do
    {
        cout << "\nEnter Choice : " << endl;
        cout << "\n1]Display \n2]Enqueue \n3]Dequeue";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\nQueue : ";
            display();
            break;
        }
        case 2:
        {
            int x;
            cout << "\nElement : ";
            cin >> x;
            enqueue(x);
            break;
        }
        case 3:
        {
            cout << "\nDeleted Element : " << dequeue();
            cout << endl;
            break;
        }
        }

    } while (choice > 0);

}
