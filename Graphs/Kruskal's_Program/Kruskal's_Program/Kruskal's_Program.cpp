#include <iostream>

#define I INT_MAX

using namespace std;



int edges[3][9] = {

                    { 1, 1 , 2 , 2, 3,  4, 4, 5, 5},
                    { 2, 6 , 3 , 7, 4,  5, 7, 6, 7},
                    {25, 5 ,12 ,10, 8, 16,14,20,18}
                
                  };

int set[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };

int included[9] = { 0 };

int t[2][6];


int find(int u)
{
    int x = u;
    int v = 0;

    while (set[x] > 0)
    {
        x = set[x];
    }

    while (u != x)                 // Code for Collapsing Find.
    {
        v = set[u];
        set[u] = x;
        u = v;
    }

    return x;
}

void union_(int A, int B)
{
    if (set[A] < set[B])
    {
        set[A] = set[A] + set[B];

        set[B] = A;
    }
    else
    {
        set[B] = set[A] + set[B];

        set[A] = B;
    }
}



int main()
{
    int i = 0, j, k, n = 7, e = 9, min = I, u, v;                             // n = Number of Vertices, e = Number of Edges.

    while (i < n - 1)
    {
        min = I;

        for (j = 0; j < e; j++)                                          // Finding the Minimum Edge also make sure that it is not included before.
        {
            if (included[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                k = j;
                u = edges[0][k];
                v = edges[1][k];
            }
        }

        if (find(u) != find(v))                                           // If their Ultimate Parents are not same.
        {
            t[0][i] = u;                                                  // Include it in our solution.
            t[1][i] = v;

            union_(find(u), find(v));                                     // Perform union operation on their ultimate parents and not on the actual vertices of Minimum Edge.

            i++;

        }

        included[k] = 1;                                                  // Record the processing in "included" array, irrespective of whether it is included in our solution or not.


    }

    // Printing Solution

    cout << "\nSpanning Tree : " << endl;

    for (i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }

}
