
#include <iostream>

using namespace std;

struct Array* Merge(struct Array* arr1, struct Array* arr2);
struct Array* Union(struct Array* arr1, struct Array* arr2);
struct Array* Intersection(struct Array* arr1, struct Array* arr2);
struct Array* Difference(struct Array* arr1, struct Array* arr2);

void Initialize(struct Array* arr);
void display(struct Array arr);
void swap(int* x, int* y);

struct Array
{
    int* A;
    int size;
    int length;

};


int main()
{
    cout << "\n\t\t\t\t\tNote :- Please Enter Sorted Arrays" << endl;
    
    cout << "\nInitializing First Array : " << endl;
    struct Array A;
    Initialize(&A);
    display(A);

    cout << "\nInitializing Second Array : " << endl;
    struct Array B;
    Initialize(&B);
    display(B);
    

    int choice;
    do
    {
        cout << "\nPlease Enter Your Choice :" << endl;
        cout << "\n1]Merge \n2]Union \n3]Insection \n4]Difference ";
        cout << "\nFor Exiting Enter : -1" << endl;
        cout << "\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            struct Array* C;
            C = Merge(&A, &B);
            cout << "\nResultant Merged Array : " << endl;
            display(*C);
            break;

        case 2:

            struct Array* U;
            U = Union(&A, &B);
            cout << "\nResultant Union Array : " << endl;
            display(*U);
            break;
   

        case 3:

            struct Array* I;
            I = Intersection(&A, &B);
            cout << "\nResultant Intersection Array : " << endl;
            display(*I);
            break;           

        case 4:

            struct Array* D;
            D = Difference(&A, &B);
            cout << "\nResultant Difference Array : " << endl;
            display(*D);
            break;

        }


    } while (choice > 0);


}

                            /************************************    Merging            *******************************************/

struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;

    i = j = k = 0;

    struct Array* arr3 = new struct Array[sizeof(struct Array)];        // Memory is Assigned to our Dynamic Object(arr3).
    arr3->size = arr1->size + arr2->size;
    arr3->A = new int[arr3->size * sizeof(int)];                        // Memory is Assigned to Pointer inside our Dynamic Object.


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


                /************************************     Union           *******************************************/


struct Array* Union(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = new struct Array[sizeof(struct Array)];        // Memory is Assigned to our Dynamic Object(arr3).
    arr3->size = arr1->size + arr2->size;
    arr3->A = new int[arr3->size * sizeof(int)];                        // Memory is Assigned to Pointer inside our Dynamic Object.


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
        else                                               // Same as that of merge(only this condition is different)
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
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

    arr3->length = k;                                   // After copying last element 'k' is still incremented hence it is equal to length


    return arr3;                                         // It is Returning a struct Array pointer
}


                            /************************************     Intersection           *******************************************/


struct Array* Intersection(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = new struct Array[sizeof(struct Array)];        // Memory is Assigned to our Dynamic Object(arr3).
    arr3->size = arr1->size + arr2->size;
    arr3->A = new int[arr3->size * sizeof(int)];                        // Memory is Assigned to Pointer inside our Dynamic Object.


    int m = arr1->length;
    int n = arr2->length;

    while (i < m && j < n)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else                                               // Same as that of merge(only this condition is different)
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }


    }



    arr3->length = k;                                   // After copying last element 'k' is still incremented hence it is equal to length


    return arr3;                                         // It is Returning a struct Array pointer
}


                                /************************************      Difference        *******************************************/

struct Array* Difference(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = new struct Array[sizeof(struct Array)];        // Memory is Assigned to our Dynamic Object(arr3).
    arr3->size = arr1->size + arr2->size;
    arr3->A = new int[arr3->size * sizeof(int)];                        // Memory is Assigned to Pointer inside our Dynamic Object.



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
            j++;
        }
        else                                               // Same as that of merge(only this condition is different)
        {
            i++;
            j++;
        }


    }

    for (; i < m; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }



    arr3->length = k;                                   // After copying last element 'k' is still incremented hence it is equal to length


    return arr3;                                         // It is Returning a struct Array pointer
}











/**********************     Supportive Functions    ********************************/

// Initialize

void Initialize(struct Array* arr)
{
    cout << "\nPlease Enter the Size of Your Array : ";
    cin >> arr->size;

    arr->A = new int[arr->size * sizeof(int)];

    cout << "\nPlease Enter the Number of Elements You want Enter Now : ";
    cin >> arr->length;

    for (int i = 0; i < arr->length; i++)
    {
        cout << "\nEnter Element No. " << i + 1 << " : ";
        cin >> arr->A[i];
    }



}


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