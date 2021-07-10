#include <iostream>

using namespace std;


class Node
{
public:

    Node* left_child;
    int data;
    Node* right_child;
};


class Queue                                           //Circular Queue using Array.
{
private:

    int size;
    int front;
    int rear;
    Node** Q;

public:

    Queue()
    {
        front = rear = 0;
        size = 10;
        Q = new Node*[size];
    }

    Queue(int size)
    {
        front = rear = 0;
        this->size = size;
        Q = new Node*[this->size];
    }

    ~Queue()
    {
        delete[]Q;
    }

    
    void enqueue(Node* x);
    Node* dequeue();
    int isEmpty();
};



void Queue::enqueue(Node* x)
{
    if ((rear + 1) % size == front)
    {
        cout << "\nQueue Overflow" << endl;
        return;
    }

    rear = (rear + 1) % size;
    Q[rear] = x;
}

Node* Queue::dequeue()
{
    Node* x = NULL;
    if (front == rear)
    {
        cout << "\nQueue Underflow" << endl;
    }
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

int Queue::isEmpty()
{
    return front == rear;
}


