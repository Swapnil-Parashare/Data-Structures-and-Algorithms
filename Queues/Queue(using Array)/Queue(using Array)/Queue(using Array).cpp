#include <iostream>

using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int* Q;
};

// Create

void create(struct Queue* q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

// Display

void display(struct Queue q)
{
    if (q.front == q.rear)
    {
        cout << "\nStack is Empty" << endl;
    }
    else
    {
        for (int i = q.front + 1; i <= q.rear; i++)
        {
            cout << q.Q[i] << " ";
        }
    }
    cout << endl;
  
}


// Enqueue

void enqueue(struct Queue* q, int x)
{
    if (q->rear == q->size - 1)
    {
        cout << "\nStack Overflow" << endl;
    }

    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Dequeue

int dequeue(struct Queue* q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "\nStack Underflow" << endl;
    }

    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Count

int count(struct Queue q)
{
    int i = 0;
    while (q.front < q.rear)                            // It is count cuurent front so I am stopping it before rear
    {
        i++;
        q.front++;
    }
    return i;
}

// Space Left 

int space(struct Queue q)
{
    return q.size - count(q);
}

// Peek

int peek(struct Queue q, int pos)
{
    if (pos < 1 || pos > q.size || pos > q.rear + 1)
    {
        return -1;
    }
    return q.Q[q.front + pos];
}



int main()
{
    struct Queue q;
    int choice = 0;

    cout << "\nNote : Please Create Queue before performing any Operation" << endl;

    do
    {
        cout << "\nEnter Choice : ";
        cout << "\n1]Create \n2]Display \n3]Enqueue \n4]Dequeue \n5]Count \n6]Space Left \n7]Peek";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int size;
                cout << "\nEnter Size of Queue: ";
                cin >> size;
                create(&q, size);
                break;
            }

            case 2:
            {
                cout << "\nStack : ";
                display(q);
                break;
            }

            case 3:
            {
                int x;
                cout << "\nElement : ";
                cin >> x;
                enqueue(&q, x);
                break;
            }

            case 4:
            {
                cout << "\nDeleted Element : " << dequeue(&q);
                cout << endl;
                break;
            }

            case 5:
            {
                cout << "\nTotal Elements : " << count(q) << endl;
                break;
            }

            case 6:
            {
                cout << "\nSpace Left for " << space(q) << " Elements" << endl;
                break;
            }

            case 7:
            {
                int x;
                cout << "\nEnter Position : ";
                cin >> x;

                cout << "\nElement : " << peek(q, x) << endl;
            }
        }
    } while (choice > 0);


    
    
}
