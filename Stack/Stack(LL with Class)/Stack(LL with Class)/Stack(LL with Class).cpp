#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    void display();
    void push(int x);
    int pop();
    int peek(int pos);
    int stackTop();
    int isEmpty();
    int isFull();
};

void Stack::display()
{
    Node* P = top;

    if (P == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        while (P)
        {
            cout << P->data << " ";
            P = P->next;
        }
    }
    cout << endl;
}

void Stack::push(int x)
{
    Node* t = new Node;

    if (t == NULL)
    {
        cout << "\nStack Overflow" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    Node* P = top;

    if (P == NULL)
    {
        cout << "\nStack Underflow" << endl;
        return x;
    }
    else
    {
        top = top->next;
        x = P->data;
        delete P;
        return x;
    }
}

int Stack::peek(int pos)
{
    Node* P = top;
    int x = -1;
    for (int i = 0; P && i < pos - 1; i++)
    {
        P = P->next;
    }
    if (P == NULL)
    {
        cout << "\nInvalid Position" << endl;
        return x;
    }
    else
    {
        x = P->data;
        return x;
    }

}

int Stack::stackTop()
{
    if (top)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

int Stack::isEmpty()
{
    int x = top ? 0 : 1;
    return x;
}

int Stack::isFull()
{
    Node* t = new Node;

    int x = t ? 0 : 1;

    return x;
}








int main()
{
    class Stack st;
    int choice;

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
            st.display();
            break;
        }

        case 2:
        {
            int x;
            cout << "\nElement : ";
            cin >> x;
            st.push(x);
            break;
        }

        case 3:
        {
            cout << "\nDeleted Element : " << st.pop() << endl;
            break;
        }

        case 4:
        {
            int x;
            cout << "\nPosition : ";
            cin >> x;
            cout << "\nElement : " << st.peek(x) << endl;
            break;
        }

        case 5:
        {
            cout << "\nElement : " << st.stackTop() << endl;
            break;
        }

        case 6:
        {
            if (st.isEmpty())
            {
                cout << "\nStack is Empty" << endl;
            }
            else
            {
                cout << "\nStack is Not Empty" << endl;
            }
            break;

        }

        case 7:
        {
            if (st.isFull())
            {
                cout << "\nStack is Full" << endl;
            }
            else
            {
                cout << "\nStack is Not Full" << endl;
            }
            break;

        }
        }
    } while (choice > 0);
}

