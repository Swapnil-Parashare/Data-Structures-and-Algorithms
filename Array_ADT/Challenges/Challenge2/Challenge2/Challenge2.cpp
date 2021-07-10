
                /*****************************************       Finding out the Duplicates     **********************************************/

#include <iostream>

using namespace std;

class Array
{
private:

    int* A;
    int size;
    int length;

public:

    Array();

    ~Array()                      // Destructor
    {
        delete[]A;
    }

    void func1();
    void func2();
    void func3();
    void display();
    int maximum();
    int minimum();

};

int main()
{
  
    Array A1;
    A1.display();
    int choice;
    do
    {
        cout << "\nPlease Enter Your Choice :" << endl;
        cout << "\n1] Finding Duplicates from Sorted/Unsorted Array(Using Hashing)" << endl;
        cout << "\n2] Finding Duplicates from Sorted/Unsorted Array(Without Hashing)" << endl;
        cout << "\n3] Finding Duplicates only for Sorted Array" << endl;
        cout << "\nFor Exiting Enter : -1" << endl;
        cout << "\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            A1.func1();
            break;


        case 2:

            A1.func2();
            break;

        case 3:

            A1.func3();
            break;
        }


    } while (choice > 0);


    
}


                    /****************************************  Finding Duplicates in Sorted/Unsorted Array  ********************************************/  

// A] Using Hashing 

void Array::func1()
{
    int l = minimum();
    int h = maximum();

    int siz = h + 1;          // This is the size of our Hash Array

    int* H;

    H = new int[siz];

    for (int i = 0; i < siz; i++)                         // For Initializing our Dynamic Array(Hash) to 0.
        H[i] = 0;

    for (int i = 0; i < length; i++)                      // For Tracing actual Array from User and accordingly incrementing Hash Array
        H[A[i]]++;

    for (int i = 0; i < siz; i++)                         // For Tracing Hash Array to find Duplicates
    {
        if (H[i] > 1)
        {
            cout << "\nElement " << i << " has occured " << H[i] << " times" << endl;
        }
    }


}


// B] Without Using Hashing

void Array::func2()
{
    for (int i = 0; i < length - 1; i++)
    {
        int count = 1;

        if (A[i] != -1)                                                    // For Keeping track of Previously traced elements
        {
            for (int j = i + 1; j < length; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;                                              // Once Element is Counted it should not be traced again by A[i]
                }
            }
            if (count > 1)
            {
                cout << "\nElement " << A[i] << " has occured " << count << " times" << endl;
            }
        }
    }
}



                    /****************************************  Finding Duplicates in Sorted/Unsorted Array  ********************************************/


// C] Only for Sorted Arrays(Without Hashing)

void Array::func3()
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == A[i + 1])
        {
            int j = i + 1;

            while (A[j] == A[i]) j++;

            cout << "\nElement " << A[i] << " has occured " << j-i << " times" << endl;
            i = j - 1;                                                                      // Ultimately i will be incremented to j at the starting of for loop.


        }
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


