#include<iostream>

using namespace std;

// Method 3 :- Using Double Pointer

void method3(void)
{

    int** A3;

    A3 = new int* [3];

    A3[0] = new int[4];
    A3[1] = new int[4];
    A3[2] = new int[4];

    int y = 1;                           // Initialization and Accessing Elements is same as that of Normal Array.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            A3[i][j] = y;
            y++;
        }
    }

    cout << "\n2D-Array By Double Pointer :\n" << endl;

    for (int i = 0; i < 3; i++)         // Printing the Elements For Conformation
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A3[i][j] << " ";
        }
        cout << endl;
    }
}