#include <iostream>

#include "Queue.h"

using namespace std;

void BFS(int A[8][8], int start, int n)                               // start :- Its the starting node.     n :- Its the Dimension, if(7X7) then n = 7.
{
    int i = start;
                                                                      // Here we don't declare Queue, as 'front' and 'rear' are the global pointers in "Queue"
    int visited[8] = {0};



    cout << i << " ";
    visited[i] = 1;
    enqueue(i);

    int u, v;
    while (!isEmpty())
    {
        u = dequeue();

        for (v = 1; v <= n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                visited[v] = 1;
                enqueue(v);
            }
        }
    }

}

void DFS(int A[8][8], int start, int n)
{
    int u = start;
    int v;
    

    static int visited[8] = { 0 };                                                   // Its Static, Hence for every recursive call same array is used.

    if (visited[u] == 0)
    {
        cout << u << " ";
        visited[u] = 1;

        for (v = 1; v <= n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                DFS(A,v,n);
            }
        }
    }

    
}

int main()
{
    int A[8][8] = {
                   // 0 1 2 3 4 5 6 7  
               /*0*/ {0,0,0,0,0,0,0,0},
               /*1*/ {0,0,1,1,1,0,0,0},
               /*2*/ {0,1,0,1,0,0,0,0},
               /*3*/ {0,1,1,0,1,1,0,0},
               /*4*/ {0,0,0,1,0,1,0,0},
               /*5*/ {0,0,0,1,1,0,1,1},
               /*6*/ {0,0,0,0,0,0,0,0},
               /*7*/ {0,0,0,0,0,0,0,0}

                   };

    cout << "\n\tBFS : ";
    BFS(A, 4, 8);
    cout << endl;

    cout << "\n\tDFS : ";
    DFS(A, 4, 8);
    cout << endl;


}
