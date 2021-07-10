                            
                        /***********************        Finding Pair of Elements with Given Sum     ***************************/   

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

    void func1(int k);
    void func2(int k);
    void func3(int k);
    void display();
    int minimum();
    int maximum();
    

};


int main()
{
    Array A1;
    A1.display();
    int choice;

    cout << "\nPlease Enter the Sum of which Pairs are to be found : ";
    int k;
    cin >> k;

    do
    {
        cout << "\nPlease Enter Your Choice :" << endl;
        cout << "\n1] Finding Pair Using Hashing" << endl;
        cout << "\n2] Finding Pair Without Hashing" << endl;
        cout << "\n3] Finding Pair Without Hashing(only Sorted Array)" << endl;
        cout << "\nFor Exiting Enter : -1" << endl;
        cout << "\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            A1.func1(k);
            break;


        case 2:

            A1.func2(k);
            break;

        case 3:

            A1.func3(k);
            break;


        }


    } while (choice > 0);



}

                                           /************************    Sorted / Unsorted  Arrays      ***************************/

// A] Without Hashing

void Array::func1(int k)
{
    
    for (int i = 0; i < length -1 ; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (A[i] + A[j] == k)
            {
                cout << "\n" << A[i] << " + " << A[j] <<" = " << k << endl;
            }
        }
    }
}

// B] Using Hashing

void Array::func2(int k)
{
    int h = maximum();

    int siz = h + 1;                                      // This is the size of our Hash Array

    int* H;

    H = new int[siz];

    for (int i = 0; i < siz; i++)                         // For Initializing our Dynamic Array(Hash) to 0.
        H[i] = 0;

    for (int i = 0; i < length; i++)                         // This is for Tracing User's Array and making changes accordingly in our Hash Array 
    {
        if (H[(k - A[i])] != 0)
        {
            cout << "\n" << A[i] << " + " << k - A[i] << " = " << k << endl;    // Index of Hash Array represents the Element of Users Array
        }       
        H[A[i]]++;
                                                                                // Marking the Presence of Current Element in Hash Array
    }

}


                                /************************************** Only For Sorted Arrays***********************************************/

// Without Hashing

void Array::func3(int k)
{
    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        if (A[i] + A[j] == k)
        {
            cout << "\n" << A[i] << " + " << A[j] << " = " << k << endl;
            i++;
            j--;
        }
        else if (A[i] + A[j] < k)
        {
            i++;
        }
        else
            j--;
    }

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

// Finding Maximum

int Array::maximum()
{
    int max = A[0];

    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

// Finding Minimum

int Array::minimum()
{
    int min = A[0];

    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

