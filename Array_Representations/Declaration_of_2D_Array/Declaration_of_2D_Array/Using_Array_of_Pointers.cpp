#include<iostream>

using namespace std;


// Method 2 :- Using Array of Pointers

void method2(void)
{

    int* A2[3];                           // A2 is Array of Pointers to Integer

    A2[0] = new int[4];                   // Each Pointer is Assigned with Heap Memory
    A2[1] = new int[4];
    A2[2] = new int[4];



    int x = 1;                           // Initialization and Accessing Elements is same as that of Normal Array.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            A2[i][j] = x;
            x++;
        }
    }

    cout << "\n2D-Array By Array Of Pointers :\n" << endl;

    for (int i = 0; i < 3; i++)           // Printing the Elements For Conformation
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A2[i][j] << " ";
        }
        cout << endl;
    }
}