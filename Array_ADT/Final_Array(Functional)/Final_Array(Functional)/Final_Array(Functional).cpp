
#include <iostream>


using namespace std;

void Initialize(struct Array* arr);
void display(struct Array arr);
void swap(int* x, int* y);
void append(struct Array* arr, int x);
void insert(struct Array* arr, int index, int x);
void Delete(struct Array* arr, int index);

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
void resize(struct Array* arr);
int index(void);
int number(void);



struct Array
{
    int* A ;                       
    int size;                     
    int length;
};

int main()
{
    struct Array a1;

    Initialize(&a1);
    int choice;
    do
    {          
        cout << "\nPlease Enter Your Choice :" << endl;
        cout << "\n1]Display \n2]Append \n3]Insert \n4]Delete \n5]Get \n6]Set \n7]Maximum \n8]Minimum \n9]Iterative Sum \n10]Recursive Sum \n11]Average \n12]Reverse(Method 1) \n13]Reverse(Method2) \n14]Conforming Sorted Array \n15]Inserting in Sorted Array \n16]Seprating Positive & Negative Elements " ;
        cout << "\nFor Exiting Enter : -1" << endl;
        cout << "\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            display(a1);
            break;

        case 2:

            append(&a1, number());
            break;

        case 3:
            
            insert(&a1, index(), number());
            break;

        case 4:

            Delete(&a1, index());
            break;

        case 5:
            
            cout <<"\nElement : "<< get(a1, index()) << endl ;
            break;

        case 6:
            
            set(&a1, index(), number());
            break;

        case 7:

            cout << "\nMaximum Number : " << maximum(a1) << endl;
            break;

        case 8:

            cout << "\nMinimum Number : " << minimum(a1) << endl;
            break;

        case 9:

            cout << "\nSum By Iteration : " << i_sum(a1) << endl;
            break;

        case 10:

            cout << "\nSum By Recursion : " << r_sum(a1, a1.length - 1) << endl;
            break;

        case 11:

            cout << "\nAverage : " <<avg(a1) << endl;
            break;
        
        case 12:

            reverse1(&a1);
            break;

        case 13:

            reverse2(&a1);
            break;

        case 14:

            cout << "\nResult : " << is_sort(a1) << endl;
            break;

        case 15:

            insert_sort(&a1, number());
            break;

        case 16:

            l_shift(&a1);
            break;

        }


    } while (choice > 0);

}

// Initializing Array

void Initialize(struct Array* arr)
{ 
    cout << "\nPlease Enter the Size of Your Array : " ;
    cin >> arr->size;

    arr->A = new int[arr->size * sizeof(int)];

    cout << "\nPlease Enter the Number of Elements You want Enter Now : " ;
    cin >> arr->length;

    for (int i = 0; i < arr->length; i++)
    {
        cout << "\nEnter Element No. " << i + 1 << " : ";
        cin >> arr->A[i];
    }



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

// Swapping

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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
    if (index <= arr->length && index >= 0)
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
    if (index < arr->length && index >= 0)
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

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }

    for (i = 0; i < arr->length; i++)
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

    for (i = 0 ,j = arr->length - 1 ; i < j ; i++, j--)
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
        return;
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
    for (int i = 0; i < arr.length - 1; i++)
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

void resize(struct Array* arr)
{
    int size;
    cout << "Please Enter New Size : ";
    cin >> size;

    arr->size = size;
    arr->A = new int[arr->size * sizeof(int)];

}

int index(void)
{
    int x;
    cout << "\nEnter the Index : ";
    cin >> x;
    return x;
}

int number(void)
{
    int y;
    cout << "\nEnter the Number : ";
    cin >> y;
    return y;
}


