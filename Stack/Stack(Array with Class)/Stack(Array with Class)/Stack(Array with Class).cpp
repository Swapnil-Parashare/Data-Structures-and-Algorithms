

/******************************************************************************************************
    This is the code of Stack(with Array), using structure and functions i.e Functional Programing,
                Later converted into Class i.e Object Oriented Programing,
                And then Finally into Template Class i.e Polymorphism.
******************************************************************************************************/



#include <iostream>

using namespace std;

template <typename T>

class Stack
{
private:

    int size;
    int top;
    T* S;

public:

    Stack(int size)
    {
        this->size = size;
        this->S = new T[this->size];
        this->top = -1;
    }

    ~Stack()
    {
        delete[]S;
    }

    void push(T x);
    T pop();
    T peek(int pos);
    T stackTop();
    int isEmpty();
    int isFull();
    void display();

};





// Push

template<class T>

void Stack<T>::push(T x)                                               // Template Class's Function's syntax is little different.
{
    if (top == size - 1)
    {
        cout << "\nStack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        S[top] = x;
    }
}

// Pop
template<class T>

T Stack<T>::pop()
{
    T x = -1;
    if (top == -1)
    {
        cout << "\nStack Underflow" << endl;
    }
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

// Peek
template<class T>

T Stack<T>::peek(int pos)
{
    T x = -1;
    if (top - pos + 1 < 0 || pos <= 0)
    {
        cout << "\nInvalid Position" << endl;
    }
    else
    {
        x = S[top - pos + 1];
    }
    return x;
}

// Stack Top
template<class T>

T Stack<T>::stackTop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return S[top];
    }
}

// Checking Stack Empty

template<class T>

int Stack<T>::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

// Checking Stack Full

template<class T>

int Stack<T>::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

// Display

template<class T>

void Stack<T>::display()
{
    int P = top;

    if (P == -1)
    {
        cout << "\n\nStack is Empty" << endl;
    }
    else
    {
        while (P != -1)
        {
            cout << S[P] << " ";
            P--;
        }
    }
}

int main()
{
    int x = 0;
    cout << "\nEnter the Size of Stack : ";
    cin >> x;

    class Stack<int>st(x);


    int choice;
    do
    {
        cout << "\nEnter Choice : ";
        cout << "\n1]Push \n2]Pop \n3]Peek \n4]Is Empty \n5]Is Full \n6]Display";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int x = -1;                                                              // Change the Data type according to data type of Class.
            cout << "\nElement : ";
            cin >> x;
            st.push(x);
            break;
        }

        case 2:
        {
            cout << "\nDeleted Element : " << st.pop() << endl;;
            break;
        }

        case 3:
        {
            int x = -1;
            cout << "\nPosition : ";
            cin >> x;

            cout << "\nElement : " << st.peek(x) << endl;
            break;

        }

        case 4:
        {
            if (st.isEmpty())
            {
                cout << "\nStack is Empty" << endl;
            }
            else
            {
                cout << "\nStack is not Empty" << endl;
            }
            break;
        }

        case 5:
        {
            if (st.isFull())
            {
                cout << "\nStack is Full" << endl;
            }
            else
            {
                cout << "\nStack is not Full" << endl;
            }
            break;
        }

        case 6:
        {
            cout << endl;
            cout << "\nStack : ";
            st.display();
            cout << endl;
            break;
        }


        }
    } while (choice > 0);

}
