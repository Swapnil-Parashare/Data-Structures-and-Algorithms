
#include <iostream>

using namespace std;

void display(struct Array arr);
void append(struct Array* arr, int x);
void insert(struct Array* arr, int index, int x);
void Delete(struct Array* arr, int index);



struct Array
{
    int A[10];                     // Array is in Stack with size 10(cannot be changed).
    int size;                      // Here it will be same as that of array is declared, through out the program.
    int length;                    // Used size.
};



int main()
{
    struct Array A1 = { {1,2,3,4,5,21,51}, 10, 7 };
    display(A1);
    append(&A1, 121);                                              // Now Length has been incremented to 8
    display(A1);
    insert(&A1, 3, 151);                                           // Now Length has been incremented to 9
    display(A1);
    Delete(&A1, 0);                                                // Now Length is Decremented to 8
    display(A1);
   
}


// Display Operation

void display(struct Array arr)
{
    if (arr.length <= arr.size && arr.length > 0)

    {
        cout << "\nYour Array Elements are : ";

        for (int i = 0; i < arr.length; i++)
        {
            cout << arr.A[i] << " ";
        }
        cout << endl;
    }

    else if (arr.length > arr.size)
        cout << "\nYour Length is Exceeding the size of Array." << endl;

    else
        cout << "\nAs Specified Length is '0' so there is nothing to display." << endl;
}




// Append Operation

void append(struct Array* arr, int x)
{
    arr->A[arr->length] = x;
    arr->length++;
        
}



// Insertion Operation

void insert(struct Array* arr, int index, int x)
{
    if (index <= arr->length && index > 0)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = x;

        arr->length++;
    }

    else if (index > arr->length)
        cout << "\nYour Index is Exceeding the existing length of array." << endl;

    else
        cout << "\nIndex should be a Positive Integer." << endl;

}


// Delete Operation

void Delete(struct Array* arr, int index)
{
    if ( index < arr->length && index >= 0)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        cout << "\nElement Deleted is : " << x << endl;
    }
    else if (index < 0)
        cout << "\nIndex should be a Positive Integer" << endl;
    else
        cout << "\nIndex is Exceeding the Specified Length " << endl;
}


