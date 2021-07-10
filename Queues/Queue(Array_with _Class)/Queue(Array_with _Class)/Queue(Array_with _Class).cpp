#include <iostream>

using namespace std;

class Queue
{
private:

    int size;
    int front;
    int rear;
    int* Q;

public:

    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[10];
    }

    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }

    ~Queue()
    {
        delete[]Q;
    }

    void display();
    void enqueue(int x);
    int dequeue();
    int peek(int pos);
};


void Queue::display()
{
    if (front == rear)
    {
        cout << "\nStack is Empty" << endl;
    }
    else
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
    }
    cout << endl;

}
void Queue::enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << "\nQueue Overflow" << endl;
        return;
    }

    rear++;
    Q[rear] = x;
}

int Queue::dequeue()
{
    int x = -1;
    if (rear == front)
    {
        cout << "\nQueue Underflow" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

int Queue::peek(int pos)
{
    if (pos < 1 || pos > size || pos > rear + 1)
    {
        return -1;
    }
    return Q[front + pos];

}

int main()
{
    Queue q;                                      // Default Constructor "size = 10"
    int choice = 0;

    cout << "\nNote : Please Create Queue before performing any Operation" << endl;

    do
    {
        cout << "\nEnter Choice : ";
        cout << "\n1]Display \n2]Enqueue \n3]Dequeue \n4]Peek";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\nStack : ";
            q.display();
            break;
        }

        case 2:
        {
            int x;
            cout << "\nElement : ";
            cin >> x;
            q.enqueue(x);
            break;
        }

        case 3:
        {
            cout << "\nDeleted Element : " << q.dequeue();
            cout << endl;
            break;
        }

        case 4:
        {
            int x;
            cout << "\nEnter Position : ";
            cin >> x;

            cout << "\nElement : " << q.peek(x) << endl;
            break;
        }

        
        }
    } while (choice > 0);




}

