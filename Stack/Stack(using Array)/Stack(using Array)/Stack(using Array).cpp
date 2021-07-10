
#include <iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int* S;
};

struct Stack* Poly;                                                     // Global Pointer to our stack i.e (same as that of first)

// Initialize

void initialize(struct Stack* st)                                       // Does Required Memory Allocation only
{
    cout << "\nEnter Size of Stack : ";
    cin >> st->size;

    st->S = new int[st->size];

    st->top = -1;

}

// Push

void push(struct Stack* st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "\nStack Overflow" << endl;
        return;
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

// Pop

int pop(struct Stack* st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "\nStack Underflow" << endl;
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

// Peek

int peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0  || pos <= 0)
    {
        cout << "\nInvalid Position" << endl;
    }
    else
    {
        x = st.S[st.top - pos + 1];
    }
    return x;
}

// Stack Top

int stackTop(struct Stack st)
{
    if (st.top == -1)
    {
        return -1;
    }
    else
    {
        return st.S[st.top];
    }
}

// Checking Stack Empty

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

// Checking Stack Full

int isFull(struct Stack st)
{
    if (st.top == st.size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

// Display

void display(struct Stack st)
{
    
    if (st.top == -1)
    {
        cout << "\nStack is Empty" << endl;
    }
    else
    {
        while (st.top != -1)
        {
            cout << st.S[st.top] << " ";
            st.top--;
        }
    }
}


int main()
{
    struct Stack st;

    cout << "\n NOTE : Please Create the Stack Before Performing any Operation\n" << endl;
     
    int choice;
    do
    {
        cout << "\nEnter Choice : ";
        cout << "\n1]Create \n2]Push \n3]Pop \n4]Peek \n5]Is Empty \n6]Is Full \n7]Display";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            initialize(&st);
            break;
        }

        case 2:
        {
            int x = -1;
            cout << "\nElement : ";
            cin >> x;
            push(&st, x);
            break;
        }

        case 3:
        {
            pop(&st);
            break;
        }

        case 4:
        {
            int x = -1;
            cout << "\nPosition : ";
            cin >> x;

            cout << "\nElement : " << peek(st, x) << endl;
            break;

        }

        case 5:
        {
            if (isEmpty(st))
            { 
                cout << "\nStack is Empty" << endl;
            }
            else
            { 
                cout << "\nStack is not Empty" << endl;
            }
            break;
        }

        case 6:
        {
            if (isFull(st))
            {
                cout << "\nStack is Full" << endl;
            }
            else
            {
                cout << "\nStack is not Full" << endl;
            }
            break;
        }

        case 7:
        {
            cout << endl;
            display(st);
            cout << endl;
            break;
        }
        }
    } while (choice > 0);

}
