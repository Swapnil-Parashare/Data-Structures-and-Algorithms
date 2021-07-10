
#include <iostream>

using namespace std;

void swap(int* x, int* y);
void display(struct Array arr);

int linear_search(struct Array arr, int key);
int transposition(struct Array* arr, int key);
int move_to_front(struct Array* arr, int key);
int Binary_search(struct Array arr, int key);
int R_Binar_Search(struct Array arr, int l, int h, int key);

struct Array
{
    int A[10];
    int size;
    int length;
};

int main()
{
    struct Array A1 = { {1,2,3,4,5,6,7,8,9,0}, 10, 10 }; 

    display(A1);
    cout << Binary_search(A1, 1) << endl;                            // Binary Search Functions are checked First as they require Sorted Array.
    cout << R_Binar_Search(A1,0,9,8) << endl;

    cout << linear_search(A1, 8) << endl;
    cout << transposition(&A1, 1) << endl;               
    cout << move_to_front(&A1, 6) << endl;
    display(A1);
    
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void display(struct Array arr)
{
    cout << "\nCurrent Condition :\t" ;
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
    cout << endl;
}


                                                    /*****************************************
                                                                LINEAR SEARCHING
                                                    *****************************************/

                                                    
// Simple Linear Search

int linear_search(struct Array arr, int key)                    // Pass by Value is sufficient for just searching
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}


// Linear Search with "Transposition"

int transposition(struct Array* arr, int key)                 // Pass by Address is Required as we have to swap the elements
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i] && i != 0)                       // i != 0 is for avoiding invalid -1 index
        {
            swap(arr->A[i], arr->A[i - 1]);
            return i - 1;
        }

        else if (key == arr->A[i] && i == 0)
            return 0;
    }
    return -1;
}


// Linear Search with "Move to front"

int move_to_front(struct Array* arr, int key)                 // Pass by Address is Required as we have to swap the elements
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(arr->A[i], arr->A[0]);
            return 0;
        }
    }
    return -1;
}



                                                    /*****************************************
                                                                BINARY SEARCHING
                                                    *****************************************/

/*
           Note :- It doesn't work if Array is not Sorted.
*/

// Iterative Binary Search

int Binary_search(struct Array arr, int key)
{
    int l, h, mid;

    l = 0;
    h = arr.length - 1;

        while (l <= h)
        {
            mid = (l + h) / 2;

            if (key == arr.A[mid])
                return mid;

            else if (key < arr.A[mid])
                h = mid - 1;

            else
                l = mid + 1;

        }
        return -1;
}


// Recursive Binary Search


/*
           Note :- Here l,h should be present as our function parametres, we can't initialize it inside our Function as above.
                   As the function is going to call itself with modified values. 
*/


int R_Binar_Search(struct Array arr,int l,int h, int key)
{

    
    if (l <= h)
    {
        int mid = (l + h) / 2;

        if (key == arr.A[mid])
            return mid;

        else if (key < arr.A[mid])
            return R_Binar_Search(arr, l, mid - 1, key);

        else
            return R_Binar_Search(arr, mid + 1, h, key);

    }

    else
        return -1;
}