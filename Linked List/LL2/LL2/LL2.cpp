#include <iostream>

using namespace std;

class Node
{
public:

    int data;
    Node* next;                    // Self-Referencing
};

class Linked_List
{
private:

    Node* first;


public:

    Linked_List()                   // Default Constructor
    {
        first = NULL;
    }

    Linked_List(int A[], int n);    // Parametrized Constructor  (Producing LL from given Array)
    ~Linked_List();                 // Destructor

    Node* get_first();


    void display_i();
    void concatenate(Node* Q);
    void merge(Node* Q);


};

Linked_List::Linked_List(int A[], int n)
{
    Node* last;
    Node* t;

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

    while (first)                     // Here P is Following first
    {
        first = first->next;
        delete P;
        P = first;

    }
}


Node* Linked_List::get_first()        // For Accessing "first pointer" which is our Private Data Member
{
    return first;
}


int main()
{
    int A[] = { 1,2,3 };
    Linked_List L1(A, 3);
    int B[] = { 4,5,6 };
    Linked_List L2(B, 3);

    int choice;
    do
    {
        cout << "\nEnter Choice :";
        cout << "\n1]Display \n2]Concatenate \n3]Merge";
        cout << "\n\nFor Exiting Enter -1 ";
        cout << "\n\nChoice : ";
        cin >> choice;



        switch (choice)
        {

        case 1:

        {
            L1.display_i();
            break;
        }

        case 2:

        {
            Node* Q = L2.get_first();

            L1.concatenate(Q);
            break;
        }

        case 3:

        {
            Node* Q = L2.get_first();

            L1.merge(Q);
            break;
        }



        }

    } while (choice > 0);

}



// Display (Iterative)

void Linked_List::display_i()
{
    Node* P = first;
    cout << "\nLinked List : ";
    while (P != NULL)
    {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

// Concatenate

void Linked_List::concatenate(Node* Q)
{
    Node* P = first;

    while (P->next != NULL)
    {
        P = P->next;
    }
    P->next = Q;
    Q = NULL;

}

// Merge

void Linked_List::merge(Node* Q)
{
    Node* P = first;
    Node* third = NULL;
    Node* last = NULL;

    if (P->data < Q->data)
    {
        third = P;
        last = P;
        P = P->next;
        last->next = NULL;
    }

    else if (P->data > Q->data)
    {
        third = Q;
        last = Q;
        Q = Q->next;
        last->next = NULL;
    }

    while (P != NULL && Q != NULL)
    {
        if (P->data < Q->data)
        {
            last->next = P;
            last = P;
            P = P->next;
            last->next = NULL;
        }

        else if (P->data > Q->data)
        {
            last->next = Q;
            last = Q;
            Q = Q->next;
            last->next = NULL;
        }
    }

    if (P) last->next = P;
    else last->next = Q;






}

