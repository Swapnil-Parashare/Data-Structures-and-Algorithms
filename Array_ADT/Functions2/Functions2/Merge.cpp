#include <iostream>

using namespace std;

struct Array
{
    int A[30];
    int size;
    int length;

};


// Note :- For Sorted Arrays Only

struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;

    i = j = k = 0;

    struct Array* arr3 = new struct Array[sizeof(struct Array)];        // 'arr3' is our Dynamic Object


    int m = arr1->length;
    int n = arr2->length;

    while (i < m && j < n)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else                                               // If elements are common still they are copied twice
        {
            arr3->A[k++] = arr1->A[i++];
            arr3->A[k++] = arr2->A[j++];

        }

    }

    for (; i < m; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for (; j < n; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;


    return arr3;                                         // It is Returning a struct Array pointer
}
