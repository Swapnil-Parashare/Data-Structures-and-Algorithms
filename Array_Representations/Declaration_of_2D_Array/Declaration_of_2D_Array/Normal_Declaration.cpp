#include<iostream>

using namespace std;

// Method 1 :- Normal Declaration

void method1(void)
{


    int A1[3][4];                          // Just Declaration



    int B1[3][4] = {                       // Declaration and Initialization at same time
                    {1,2,3,4},
                    {5,6,7,8},
                    {9,8,0,1},
                   };


    int C1[3][4];


    int x = 1;                           // Initialization and Accessing Elements is same as that of Normal Array.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C1[i][j] = x;
            x++;
        }
    }


    cout << "\n2D-Array by Normal Declaration : \n" << endl;



    for (int i = 0; i < 3; i++)            // Printing the Elements For Conformation
    {
        for (int j = 0; j < 4; j++)
        {
            cout << C1[i][j] << " ";
        }
        cout << endl;
    }

}