#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL ;


// Display

void dispaly()
{
    struct Node* P = top;

    if (P == NULL)
    {
        cout << "\n\nStack is Empty" << endl;
    }

    else
    {
        while (P)
        {
            cout << P->data << " ";
            P = P->next;
        }
    }
}


// Push

void push(int x)
{
    struct Node* t = new struct Node;

    if (t == NULL)
    {
        cout << "\nStack Overflow" << endl;
        return;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

//Pop

int pop()
{
    int x = -1;
    struct Node* P = top;
    if (P == NULL)
    {
        cout << "\nStack Underflow" << endl;
        return x;
    }
    else
    {
        x = P->data;
        top = top->next;
        delete P;
        return x;
    }

}

// Peek

int peek(int pos)
{
    int x = -1;

    struct Node* P = top;

    for (int i = 0; P && i < pos - 1; i++)
    {
        P = P->next;
    }
    if (P == NULL)
    {
        cout << "\nInvalid Position" << endl;
    }
    else
    {
        x = P->data;
    }
    return x;

}

// Stack Top

int stackTop()
{
    int x = -1;

    Node* P = top;

    if (P == NULL)
    {
        cout << "\nStack is Empty" << endl;
    }
    else
    {
        x = P->data;
    }

    return x;
}

// Is Empty

int isEmpty()
{
    return top ? 0 : 1;
}

// Is Full

int isFull()
{
    Node* t = new Node;

    int x = t ? 0 : 1;

    delete t;

    return x;
}



int main()
{
  
    int choice;                                 // Here Object is not even created, everything depends on our top pointer.
    do
    {
        cout << "\nEnter Choice : ";
        cout << "\n1]Display \n2]Push \n3]Pop \n4]Peek \n5]Stack Top \n6]Is Empty \n7]Is Full";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\nStack : ";
            dispaly();
            cout << endl;
            break;
        }
        case 2:
        {
            int x;
            cout << "\nElement : ";
            cin >> x;
            push(x);
            break;
        }

        case 3:
        {
            cout << "\nDeleted Element : " << pop() << endl;
            break;
        }

        case 4:
        {
            int x;
            cout << "\nPosition : ";
            cin >> x;
            cout << "\nElement : " << peek(x) << endl;
            break;
        }

        case 5:
        {
            cout << "\nElement : " << stackTop() << endl;
            break;
        }

        case 6:
        {
            if (isEmpty())
            {
                cout << "\nStack is Empty" << endl;
            }
            else
            {
                cout << "\nStack is not Empty" << endl;
            }
            break;
        }

        case 7:
        {
            if (isFull())
            {
                cout << "\nStack is Full" << endl;
            }
            else
            {
                cout << "\nStack is not Full" << endl;
            }
            break;
        }
        
        }
    } while (choice > 0);

}
