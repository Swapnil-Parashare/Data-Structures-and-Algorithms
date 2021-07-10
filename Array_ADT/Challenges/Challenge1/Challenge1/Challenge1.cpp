                                                   
                      /***************************   Finding Missing Missing Elements in Array   ********************************/

#include <iostream>

using namespace std;

class Array
{

    private:

        int* A;
        int size;
        int length;

    public:

        Array();                      // Default Constructor
         
        ~Array()                      // Destructor
        {
            delete[]A;
        }

       
        void display();
        int func1();
        int func2();
        void func3();
        void func4();
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
        cout << "\n1] Finding Single Missing Element in Sorted Array Starting from 1." << endl;
        cout << "\n2] Finding Single Missing Element in Sorted Array Not Starting from 1." << endl;
        cout << "\n3] Finding Multiple Missing Element in Sorted Array Not Starting from 1." << endl;
        cout << "\n4] Finding Multiple Missing Element in Unsorted Array Not Starting from 1." << endl;
        cout << "\nFor Exiting Enter : -1" << endl;
        cout << "\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nThe Single Missing Element is : " << A1.func1() << endl;
            break;

        case 2:
            cout << "\nThe Single Missing Element is : " << A1.func2() << endl; 
            break;

        case 3:
            cout << "\nThe Multiple Missing Elements are : " ;
            A1.func3();
            break;

        case 4:
            cout << "\nThe Multiple Missing Elements are : ";
            A1.func4();
            break;

        }


    } while (choice > 0);
}


                                /*************************  Sorted Array Starting from 1 ****************************************/


//  A] Using 'Sum' Relation (Single Element)

int Array::func1()
{
    int sum;
    int n = A[length - 1];
    sum = n*(n + 1) / 2;                  // Expected Sum when no element is Missing.

    int s = 0;
    for (int i = 0; i < length; i++)
    {
        s += A[i];                        // Actual Existing Sum.
    }

    return sum - s;

}
            
                               /*************************  Sorted Array Not Starting from 1 ****************************************/

//  B] Using 'Index' Relation (Single Element)

int Array::func2()
{
    int diff = A[0] - 0;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            return i + diff;
        }
    }
}


                              /*************************  Sorted Array Not Starting from 1 ****************************************/


//  C] Using 'Index' Relation ["Modified"] (Multiple Element)

void Array::func3()
{
    int diff = A[0] - 0;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            while(diff < A[i]-i)
            {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
    cout << endl;
}

                               /*************************  Unsorted Array Not Starting from 1 ****************************************/

//  D] Using Hashing  (Multiple Element)

void Array::func4()
{
    int l = minimum();
    int h = maximum();                                      
    int siz = h + 1;                //(This is the size of our hash array) As we want last index equal to maximum element of users array [Here size itself is length]

    int* H = new int[siz];

    for (int i = 0; i < siz ; i++)                         // For Initializing our Dynamic Array(Hash) to 0.
        H[i] = 0;


    for (int i = 0; i < length; i++)                       // For Tracing actual Array from User and according incrementing Hash Array
        H[A[i]]++;


    for (int i = l ; i < siz; i++)                          
    {
        if(H[i] == 0)
        {
            cout << i  << " ";
        }
    }

    cout << endl;
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
        if ( A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

