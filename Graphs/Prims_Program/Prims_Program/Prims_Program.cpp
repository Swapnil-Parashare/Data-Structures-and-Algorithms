#include <iostream>

#define I INT_MAX

using namespace std;

int cost[8][8] = {                                                      // This is the Global Cost Adjacency Matrix of the Graph for which Spanning Tree is to be generated.

                      // 0 1 2 3 4 5 6 7  
                  /*0*/ {I,I,I,I,I,I,I,I},
                  /*1*/ {I,I,25,I,I,I,5,I},
                  /*2*/ {I,25,I,12,I,I,I,10},
                  /*3*/ {I,I,12,I,8,I,I,I},
                  /*4*/ {I,I,I,8,I,16,I,14},
                  /*5*/ {I,I,I,I,16,I,20,18},
                  /*6*/ {I,5,I,I,I,20,I,I},
                  /*7*/ {I,I,10,I,14,18,I,I}

                  };

int near[8] = { I,I,I,I,I,I,I,I };

int t[2][6];


int main()
{
    int i, j, k = 0, u, v, n = 7, min = I;                      // n = number of vertex

    // Initial 4 Steps.


    for (i = 1; i <= n; i++)                                    // 1]Finding Minimum Edge, by tracing Upper Triangular part of "cost".
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i; v = j;
            }
        }
    }

    t[0][0] = u; t[1][0] = v;                                    // 2]Including Minimum Edge in "t" array.

    near[u] = near[v] = 0;                                       // 3]Marking Respective indexes as 0, as the vertices are included in our "t" array.

    for (i = 1; i <= n; i++)                                     // 4]Complete Updation of "near" array.
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
    }


    // Repeating Steps

    for (i = 1; i < n-1 ; i++)                                 
    {
        min = I;                                                    // Min value is modefied above, hence re-initialize it. 

        for (j = 1; j <= n; j++)                                    // 1]Finding Minimum Edge from "near". 
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }

        t[0][i] = k ; t[1][i] = near[k];                            // 2]Including Minimum Edge in "t" array.

        near[k] = 0;                                                // 3] Marking the Index w.r.t newly included vertex as 0.

        for (j = 1; j <= n; j++)                                    // 4]Complete Updation of "near" array.
        {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
            {
                near[j] = k;
            }
        }
    }

    // Printing Spanning Tree.

    cout << " Spanning Tree : " << endl;
     
    for (i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }


}
