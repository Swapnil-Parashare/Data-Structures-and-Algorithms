
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

// Note :- Row Major Formula is Used For Mapping
Array::Array()
{
    cout << "\nEnter Number of Rows in your Lower Triangular Matrix : ";
    cin >> n;

    A = new int[n*(n+1)/2];                                                     // Our Dynamic 1D Array

    cout << "\nEnter the Elements : " << endl;
    cout << endl;

    int i, j , x;
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            cin >> x;
            set(i, j, x);
        }
    }


}

void Array::set(int i, int j, int element)
{
    if (i >= j)
    {
        A[(i * (i - 1) / 2) + j - 1] = element;
    }
}

void Array::get(int i, int j)
{
    if (i >= j)
    {
        cout << "\nElement at (" << i << "," << j << ") : " << A[(i * (i - 1) / 2) + j - 1] << endl;
    }
    else
    {
        cout << "\nElement at (" << i << "," << j << ") : " << 0 << endl;
    }

}

void Array::display()
{
    cout << "\nLower Triangular Matrix : " << endl;
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "\t";
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << A[(i * (i - 1) / 2) + j - 1] << " ";
            }
            else
                cout << 0 << " ";

        }
        cout << endl;
    }
}