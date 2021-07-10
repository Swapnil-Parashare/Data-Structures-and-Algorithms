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
        front = rear = 0;
        size = 10;
        Q = new int[size];
    }

    Queue(int size)
    {
        front = rear = 0;
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
        int i = front + 1;
        do                                                                  
        {
            cout << Q[i] << " ";
            i = (i + 1) % size;

        } while (i != (rear + 1) % size);
    }
    cout << endl;

}
void Queue::enqueue(int x)
{
    if ((rear + 1) % size == front)
    {
        cout << "\nQueue Overflow" << endl;
        return;
    }

    rear = (rear + 1) % size;
    Q[rear] = x;
}

int Queue::dequeue()
{
    int x = -1;
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

int Queue::peek(int pos)
{
    if (pos < 1 || pos > size-1 || pos > rear + 1)
    {
        return -1;
    }
    return Q[front + pos];

}

int main()
{
    int size;
    cout << "\nEnter Size of Queue : ";
    cin >> size;

    Queue q(size);                                  
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

