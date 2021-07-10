
#include <iostream>

using namespace std;

class Array
{
private:

    int* A;
    int n;

public:

    Array();

    ~Array()
    {
        delete[]A;
    }

    void set(int x, int y, int element);
    void get(int x, int y);
    void display();


};

int main()
{

    class Array A1;
    A1.display();

    int choice;
    do {
        cout << "\nEnter Your Choice : " << endl;
        cout << "\n1] Display \n2] Set an Element \n3] Get an Element \n4] Exit" << endl;
        cout << "\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            A1.display();
            break;

        case 2:
            int x, y, e;
            cout << "\nEnter the Indexes : " << endl;
            cout << "\n X : ";
            cin >> x;
            cout << "\n Y : ";
            cin >> y;


            cout << "\nEnter the Element : ";
            cin >> e;

            A1.set(x, y, e);
            break;

        case 3:

            int p, q;
            cout << "\nEnter the Indexes : " << endl;
            cout << "\n X : ";
            cin >> p;
            cout << "\n Y : ";
            cin >> q;
            A1.get(p, q);
            break;
        }
    } while (choice != 4);

}


Array::Array()
{
    cout << "\nEnter Number of Rows in your Diagonal Matrix : ";
    cin >> n;

    A = new int[n];                                                     // Our Dynamic 1D Array

    cout << "\nNote : Enter Diagonal Elements Only " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "\nElement at (" << i << "," << i << ") : ";
        cin >> A[i-1];
    }


}

void Array::set(int x, int y, int element)
{
    if (x == y)
    {
        A[x - 1] = element;
    }
}

void Array::get(int x, int y)
{
    if (x == y)
    {
        cout << "\nElement at (" << x << "," << x << ") : " << A[x - 1] << endl;
    }
    else
    {
        cout << "\nElement at (" << x << "," << y << ") : " << 0 << endl;
    }
        
}

void Array::display()
{
    cout << "\nDiagonal Matrix : " << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {          
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
                cout << 0 << " ";
            
        }
        cout << endl;
    }
}