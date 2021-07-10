
#include <iostream>

using namespace std;

struct Array
{
    int A[15];
    int size;
    int length;

};

int get(struct Array arr, int index);
void set(struct Array* arr, int index, int x);
int maximum(struct Array arr);
int minimum(struct Array arr);
int i_sum(struct Array arr);
int r_sum(struct Array arr, int last_i);
float avg(struct Array arr);
void reverse1(struct Array* arr);
void reverse2(struct Array* arr);
void insert_sort(struct Array* arr, int x);
int is_sort(struct Array arr);
void l_shift(struct Array* arr);



void display(struct Array arr);
void swap(int* x, int* y);

int main()
{
    struct Array A1 = { {1,3,5,7,13,15,17,19,23}, 15, 9 };
    reverse2(&A1);
    display(A1);
  
}


// Getter Function

int get(struct Array arr, int index)
{
    if (index >= 0 && index <= arr.length)
    {
        return arr.A[index];
    }
}


// Setter Function

void set(struct Array* arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}


// Finding Maximum

int maximum(struct Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}


// Finding Minimum

int minimum(struct Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// Finding Sum (Iterative)

int i_sum(struct Array arr)
{
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

// Finding Sum (Recursive)

int r_sum(struct Array arr, int last_i)
{
    if (last_i < 0)
        return 0;

    else
        return r_sum(arr, last_i - 1) + arr.A[last_i];
}

// Finding Average

float avg(struct Array arr)
{
    return (float)i_sum(arr) / arr.length;
}

// Reversing an Array(Method 1)

void reverse1(struct Array* arr)                                           // Auxillary Array is Required
{
    int i = 0;
    int j = 0;

    int* B = new int[arr->length];                                          // Auxillary Array is Created in Heap

    for (i = arr->length - 1, j = 0   ;   i >= 0   ;   i--, j++)        
    {
        B[j] = arr->A[i];
    }

    for (i = 0 ; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }

    delete[] B;

    B = NULL;
}

// Reversing an Array(Method 2)                                             // No Auxillary Array is Required

void reverse2(struct Array* arr)
{
    int i = 0;
    int j = 0;

    for (i = 0, j = arr->length - 1 ; i < j ; i++, j--)
    {
        swap(&arr->A[j], &arr->A[i]);
    }
}

// Inserting in a Sorted Array

void insert_sort(struct Array* arr, int x)
{
    if (arr->size == arr->length)
    {
        cout << "Insufficient Space " << endl;
        return ;
    }

    int i = arr->length - 1;

    while (arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

// Checking wether Array is Sorted or Not

int is_sort(struct Array arr)
{
    for (int i = 0; i < arr.length - 2; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;   // False
        }
    }
    return 1;          // True
}

// Shifting Negative Elements on Left Hand Side

void l_shift(struct Array* arr)
{
    int i = 0;
    int j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
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