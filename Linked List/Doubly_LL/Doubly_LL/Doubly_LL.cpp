
#include <iostream>

using namespace std;

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* first;

// Create

void create(int A[],int n)
{
    struct Node* last;                                  // For pointing last Node
    struct Node* t;                                     // For creating Nodes

    first = new struct Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;


    for (int i = 1; i < n; i++)
    {
        t = new struct Node;
        t->data = A[i];
        t->next = last->next;                             // i.e NULL
        t->prev = last;
        last->next = t;
        last = t;
    }

}


// Display

void dispaly(Node* P)
{
    while (P)
    {
        cout << P->data << " ";
        P = P->next;
    }
}

// Count

int count(Node* P)
{
    int i = 0;

    while (P)
    {
        i++;
        P = P->next;
    }
    return i;
}

// Insert

void insert(struct Node* P, int pos, int x)
{
    if (pos < 0 || pos > count(first))
    {
        cout << "\nInvalid Index" << endl;
        return;
    }

    struct Node* t = new struct Node;
    t->data = x;
    t->prev = NULL;
    t->next = NULL;


    if (pos == 0)
    {
        t->next = first;
        first->prev = t;
        t->prev = NULL;
        first = t;
    }

    else 
    {
        for (int i = 0; i < pos - 1; i++)
        {
            P = P->next;
        }

        t->next = P->next;
        P->next = t;
        t->prev = P;
        if(t->next) t->next->prev = t;
    }

}

// Delete

int Delete(struct Node* P, int index)
{   
    if (index <= 0 || index > count(first))
    {
        cout << "\nInvalid Index" << endl;
        return -1;
    }

    int x = 0;

    if (index == 1)
    {
        x = P->data;
        first = first->next;
        delete P;
        if(first) first->prev = NULL;
        return x;

    }

    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            P = P->next;
        }


        if (index != count(first))  P->next->prev = P->prev;                            // If last node is to be deleted
        P->prev->next = P->next;


        x = P->data;

        delete P;

        P = NULL;

        return x;
    }
  
}

// Reverse

void reverse(struct Node* P)
{
    struct Node* temp;

    while (P)
    {
        temp = P->next;
        P->next = P->prev;                             // Swapping is Done.       P->next and P->prev  links are swapped.
        P->prev = temp;

        P = P->prev;                                   // Hence for going to next Node ,instead of P = P->next we are doing P = P->prev.     So Now we are on next Node, were swapping is Not yet Done.

        if (P != NULL && P->next == NULL)              // Therefore here we are checking for usual P->next == NULL.
        {
            first = P;
        }
    }

}

int main()
{
    int A[] = { 1,2,3,4,5 };

    create(A, 5);
    int choice;

    do
    {
        cout << "\nEnter Choice : ";
        cout << "\n1]Display \n2]Count \n3]Insert \n4]Delete \n5]Reverse";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "\nDoubly Linked List : ";
                dispaly(first);
                cout << endl;
                break;
            }

            case 2:
            {
                cout << "\nNumber of Nodes : " << count(first) << endl;
                break;
            }

            case 3:
            {
                int x;
                int pos;
                cout << "\nElement : ";
                cin >> x;
                cout << "\nIndex : ";
                cin >> pos;

                insert(first, pos, x);
                break;
            }

            case 4:
            {
                int pos;
                cout << "\nIndex : ";
                cin >> pos;
                cout << "\nElement Deleted : " << Delete(first, pos) << endl;
                break;
            }

            case 5:
            {
                reverse(first);
                break;
            }
        }
    } while (choice > 0);
    
}
