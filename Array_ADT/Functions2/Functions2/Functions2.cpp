
#include <iostream>

using namespace std;

struct Array* Merge(struct Array* arr1, struct Array* arr2);
struct Array* Union(struct Array* arr1, struct Array* arr2);
struct Array* Intersection(struct Array* arr1, struct Array* arr2);
struct Array* Difference(struct Array* arr1, struct Array* arr2);




void display(struct Array arr);
void swap(int* x, int* y);

struct Array
{
    int A[30];
    int size;
    int length;

};


int main()
{
    // Note :- For Sorted Arrays Only

    struct Array A = { {1,2,3,}, 30, 3 };     // Take care that length should be exactly equal to total no of elements
    struct Array B = { {2,3,4}, 30, 3 };


    struct Array* C;
    C = Difference(&A, &B);
    display(*C);
    
}



















/**********************     Supportive Functions    ********************************/



// Display 

void display(struct Array arr)
{
    cout << "\nCurrent Situation :\t";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}



// Swapping

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}