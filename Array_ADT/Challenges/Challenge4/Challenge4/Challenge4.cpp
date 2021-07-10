
#include <iostream>

using namespace std;

class Array
{
private:

    int* A;
    int size;
    int length;

public:

    Array();                     // Default Unparametreized Constructor

    ~Array()                      // Destructor
    {
        delete[]A;
    }

    void max_min();
    void display();
    

};


int main()
{
    Array A1;
    A1.display();
    A1.max_min();
}

 void Array::max_min()
{
    int max = A[0];
    int min = A[0];

    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        else if (A[i] > max)
        {
            max = A[i];
        }

    }
    cout << "\nMaximum Element From Given Array : " << max << endl;
    cout << "\nMinimum Element From Given Array : " << min << endl;
    
}






















/********************************************** Supportive Functions  *********************************************************/


Array::Array()
{
    cout << "\nPlease Enter the size of Your Array : ";
    cin >> size;

    A = new int[size];

    cout << "\nPlease Enter the Number of Elements You want Enter Now : ";
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        cout << "\nEnter Element No. " << i + 1 << " : ";
        cin >> A[i];
    }
}


void Array::display()
{
    if (length <= size && length > 0)

    {
        cout << "\nYour Array Elements are : ";

        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    else if (length > size)
        cout << "\nYour Length is Exceeding the sizes of Array." << endl;

    else
        cout << "\nAs Specified Length is '0' so there is nothing to display." << endl;
}
