#include <iostream>

using namespace std;

/***************************************************************************************************************
 This is Template Class , we can use it for whatever type we want. Here we want 'Node**'   as addresses of
 "Node Pointers are to be stored.
 */

template <typename T>                   

class Stack                            // Stack using Array
{
private:

    int size;
    int top;
    T* S;                              // Here S is capable of pointing to "T". T may be int or int* or int** or int*** according to our need.

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
    int isEmpty();
    
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
    T x = NULL;
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

