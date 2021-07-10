#include <iostream>

using namespace std;


void insert(int A[], int n)                           // Here "n" is nothing but next free index.(At index 'n' insert respective element)
{
    int temp = A[n];
    int i = n;

    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }

    A[i] = temp;

}



void display(int A[])
{
    cout << "\nHeap : ";
    for (int i = 1; i <= 7; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Delete(int A[], int n)
{
    int i, j, x;

    i = 1;
    j = 2*i;

    x = A[1];
    A[1] = A[n];

    while (j < n - 1)
    {
        if (A[j + 1] > A[j])                                   // Compare Children, 'j' will point on the child which is greatest.
            j = j + 1;

        if (A[j] > A[i])
        {
            swap(A[i], A[j]);
            i = j;
            j = 2 * i;
        }

        else
            break;
    }

    A[n] = x;
}

int main()
{
    int A[] = { 0 , 10,20,30,25,5,40,35 };

    for (int i = 2; i <= 7; i++)
    {
        insert(A, i);
    }

    for (int i = 7; i >= 1; i--)
    {
        Delete(A, i);
    }

    display(A);
}
