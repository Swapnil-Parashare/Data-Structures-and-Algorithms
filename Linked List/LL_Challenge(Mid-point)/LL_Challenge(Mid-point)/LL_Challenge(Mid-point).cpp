#include <iostream>
#include <cmath>

using namespace std;

class Node
{
public:

    int data;
    Node* next;
};

class Linked_List
{
private: 

    Node* first;

public:

    Linked_List()
    {
        first = NULL;
    }

    Linked_List(int A[], int n);

    ~Linked_List();

    Node* get_first();

    Node* mid_point1();
    Node* mid_point2();
    Node* mid_point3();
    void dispaly();
           

};

Linked_List::Linked_List(int A[], int n)
{
    Node* last;                                      // For Pointing Last Node
    Node* t;                                         // For creating Nodes.

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

Linked_List::~Linked_List()
{

    Node* P = first;

    while(first)
    {
        first = first->next;
        delete P;
        P = first;
    }
}

Node* Linked_List::get_first()
{
    return first;
}

void Linked_List::dispaly()
{
    cout << "Linked List : ";
    Node* P = first;
    while (P)
    {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

int main()
{
    int A[] = { 1,2,3,4,5,6,7,8,9,10};
    Linked_List L1(A,9);
     
    int choice;
    do
    {
        cout << "\nEnter Choice" << endl;
        cout << "\nFinding Midpoint of Linked_List." << endl;
        cout << "\n1]Tracing Two Times \n2]Tracing Single Time \n3]Using Stack";
        cout << "\n\nChoice:";
        cin >> choice;
        cout << endl;
        L1.dispaly();


        switch (choice)
        {
        case 1:
        {
            
            Node* P = NULL;
            P = L1.mid_point1();
            cout << "\nThe Middle Node is " << P << endl;
            cout << "\nData : " << P->data << endl;
            break;
        }

        case 2:
        {
            Node* P = NULL;
            P = L1.mid_point2();
            cout << "\nThe Middle Node is " << P << endl;
            cout << "\nData : " << P->data << endl;
            break;
        }

        case 3:
        {
            cout << "\nFuntionality Under Development" << endl;
            break;
        }

        }

    } while (choice > 0);

}

// Midpoint (Tracing Two Times)

Node* Linked_List::mid_point1()
{
    int count = 0;
    int mid = 0;
    Node* P = first;

    while (P)
    {
        count++;
        P = P->next;
    }

    mid = (int)ceil(count / 2);

    P = first;

    for (int i = 0; i < mid; i++)
    {
        P = P->next;
    }

    return P;   
}

// Midpoint (Tracing Single Time)

Node* Linked_List::mid_point2()
{
    Node* P = first;
    Node* Q = first;

    while (Q->next)                            // I want Q to stop on last Node itself.
    {
        P = P->next;
        Q = Q->next;
        if (Q->next) Q = Q->next;
    }
    return P;
}
