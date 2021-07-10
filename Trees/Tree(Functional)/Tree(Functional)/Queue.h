#include <iostream>

using namespace std;

struct Node                         // It is used for creating "tree" using "Linked-Representation"
{
    struct Node* left_child;
    int data;
    struct Node* right_child;
};

struct Queue                       // This Queue is created using "Array".( Also this Queue is Circular Queue )
{
    int size;                      // Here Queue is used to store the addresses of our "Tree's Nodes" and not integers.
    int front;                     // Hence Array type present in our Queue must be Node*.
    int rear;
    Node** Q;                       // "Q" is Nothing but the Dynamic Array which stores Node's Addresses same as that of "int*".                     
};

// Create

void create(struct Queue* q, int size)
{
    q->size = size;
    q->front = q->rear = 0;                  // Circular Queue
    q->Q = new Node*[q->size];               // Memory Allocated is of type Node*. It means we can store Addresses of Variables of type Node*.
}



// Enqueue

void enqueue(struct Queue* q, Node* x)           // We are Enqueuing our Node Pointers (Node*)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "\nStack Overflow" << endl;
    }

    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

// Dequeue

Node* dequeue(struct Queue* q)                    // We are Dequeuing our Node Pointers (Node*)
{
    Node* x = NULL;
    if (q->front == q->rear)
    {
        cout << "\nStack Underflow" << endl;
    }

    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];                                     // Space were front is pointing is always empty.

    }
    return x;
}


// Is Empty

int isEmpty(struct Queue q)
{
    if (q.front == q.rear)
        return 1;
    else
        return 0;
}




            /****************************** Not Required ***********************************/


// Display

void display(struct Queue q)
{
    if (q.front == q.rear)
    {
        cout << "\nStack is Empty" << endl;
    }
    else
    {
        for (int i = q.front + 1 ; i <= q.rear ;  (i + 1) % q.size)
        {
            cout << q.Q[i] << " ";
        }
    }
    cout << endl;

}


// Count

int count(struct Queue q)
{
    int i = 0;
    while (q.front < q.rear)                            // It counts current front(which is empty) so I am stopping it before rear
    {
        i++;
        q.front = (q.front + 1)%q.size;
    }
    return i;
}

// Space Left 

int space(struct Queue q)
{
    return q.size - count(q) - 1;                      // -1 due to circular behaviourial property
}



