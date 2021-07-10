#include <iostream>
#include <cmath>

using namespace std;

class Node                                                         // Only for Bin sort and Radix Sort
{
public:
    int data;
    Node* next;
};

class Array
{
private:

    int* A;
    int size;


public:

    Array(int x);
    ~Array();

    int* get_Array()
    {
        return A;
    }

    int get_size()
    {
        return size;
    }

    void initialize();
    void swap(int* x, int* y);
    void display();

    void Bubble_sort();
    void Insertion_sort();
    void Selection_sort();

    int Partition(int A[], int l, int h);                                  // Assistant Function Requires Arguments.
    void Quick_sort(int A[], int l, int h);                                // Recursive Function Requires Arguments.

    void Merge(int A[], int l, int mid, int h);                            // Assistant Function Requires Arguments.
    void i_Merge_sort();
    void r_Merge_sort(int A[], int l, int h);                              // Recursive Function Requires Arguments.

    int find_max();
    void Count_sort();

    void Bin_Insert(Node** Bin_ptr, int Index);                  // Here Index and Value are Same.
    int Delete(Node** Bin_ptr, int Index);
    void Bin_sort();

    int Count_Digit(int x);
    int getBinIndex(int x, int pass);
    void Radix_Insert(Node** Bin_ptr, int value, int Index);      // Here Index and Value are Different.
    void Radix_sort();

    void Shell_sort();
    


};



Array::Array(int x)                                                // It Allocates the Memory for our Dynamic Array but does not initialize it.
{
    size = x;
    A = new int[size];
}

Array::~Array()                                                    // It releases the allocated Dynamic Memory.
{
    delete[]A;
}


void Array::initialize()
{
    cout << "\nEnter the Elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
}

void Array::swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Array::display()
{
    cout << "\nArray : ";

    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}



void Array::Bubble_sort()
{
    int flag;
    int pass_count = 0;
    int comp_count = 0;
    int swap_count = 0;

    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;

        for (int j = 0; j < size - 1 - i; j++)
        {
            comp_count++;

            if (A[j] > A[j + 1])
            {
                swap_count++;

                swap(A + j, A + j + 1);

                flag = 1;
            }
        }

        pass_count++;

        if (flag == 0)
            break;
    }
    cout << "\n\t\t\t\tBubble Sort Analysis : " << endl;
    cout << "\n\tPasses      : " << pass_count << endl;
    cout << "\n\tComparision : " << comp_count << endl;
    cout << "\n\tSwapping    : " << swap_count << endl;
    cout << endl;

}

void Array::Insertion_sort()
{
    int pass_count = 0;
    int comp_count = 0;
    int swap_count = 0;

    for (int i = 1; i < size; i++)
    {
        int j, x;
        j = i - 1;
        x = A[i];

        while (j > -1 && A[j] > x)
        {
            swap_count++;
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;

        comp_count++;
        pass_count++;
    }

    cout << "\n\t\t\t\tInsertion Sort Analysis : " << endl;
    cout << "\n\tPasses      : " << pass_count << endl;
    cout << "\n\tComparision : " << comp_count << endl;
    cout << "\n\tSwapping    : " << swap_count << endl;
    cout << endl;
}

void Array::Selection_sort()
{
    int pass_count = 0;
    int comp_count = 0;
    int swap_count = 0;

    int i, j, k;

    for (i = 0; i < size - 1; i++)
    {
        for (j = k = i; j < size; j++)
        {
            comp_count++;

            if (A[j] < A[k])
            {
                k = j;
            }
        }
        swap(A + i, A + k);
        swap_count++;
        pass_count++;
    }

    cout << "\n\t\t\t\tSelection Sort Analysis : " << endl;
    cout << "\n\tPasses      : " << pass_count << endl;
    cout << "\n\tComparision : " << comp_count << endl;
    cout << "\n\tSwapping    : " << swap_count << endl;
    cout << endl;
}



int Array::Partition(int A[], int l, int h)
{
    int i = l;
    int j = h;
    int pivot = A[l];

    do
    {
        do { i++; } while (A[i] <= pivot);                                 // 'i' is finding the element greater than pivot ( Note : Here we are supposed to give continuation condition and not the condition when we have to stop. )

        do { j--; } while (A[j] > pivot);                                  // 'j' is finding the element which is less than or equal to pivot element.

        if (i < j)
        {
            swap(A + i, A + j);
        }


    } while (i < j);

    swap(A + l, A + j);

    return j;
}

void Array::Quick_sort(int A[], int l, int h)            // Note : In Quick Sort Algorithm the terminating "Infinity" plays a very important role.
{
    int j;

    if (l < h)                            // For Conforming, atleast two elements are present in Array.
    {
        j = Partition(A, l, h);
        Quick_sort(A, l, j);              // Left Side. (Note : 'j' is written instead of 'j+1'. Reason : Here the Sorted element acts as Infinity)
        Quick_sort(A, j + 1, h);          // Right Side.
    }
}



void Array::Merge(int A[], int l, int mid, int h)
{
    int i, j, k;

    i = l;
    j = mid + 1;
    k = l;

    int B[100];                                    // Auxillary Array.

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }

        else
        {
            B[k++] = A[j++];
        }
    }

    // Note : Either one the below two for-loops executes

    for (; i <= mid; i++)                               // If 'j' ends,  then copying remaining of 'i'.
    {
        B[k++] = A[i];
    }

    for (; j <= h; j++)                                 // If 'i' ends,  then copying remaining of 'j'.
    {
        B[k++] = A[j];
    }

    for (i = l; i <= h; i++)                            // Copying Elements Back from Auxillary Array "B" to Our Orignal Array "A".
    {
        A[i] = B[i];
    }
}

void Array::i_Merge_sort()
{
    int p, i, l, mid, h;

    int pass_count = 0;

    for (p = 2; p <= size; p = p * 2)
    {
        for (i = 0; i + p - 1 < size; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;

            Merge(A, l, mid, h);
            
        }

        pass_count++;
    }

    if (p / 2 < size)                                                   // If Number of Elements are odd, then one extra pass is required.
    {
        Merge(A, 0, (p / 2) - 1, size - 1);
        pass_count++;
    }

    cout << "\n\t\t\t\tIterative Merge Sort Analysis : " << endl;
    cout << "\n\tPasses : " << pass_count << endl; 
    cout << endl;

}

void Array::r_Merge_sort(int A[], int l, int h)
{
    int mid = 0;
    if (l < h)
    {
        mid = (l + h) / 2;

        r_Merge_sort(A, l, mid);                                              // For Left Side.
        r_Merge_sort(A, mid + 1, h);                                          // For Right Side.
        Merge(A, l, mid, h);
    }
}



int Array::find_max()
{
    int max = INT32_MIN;

    for (int i = 0; i < size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
}

void Array::Count_sort()
{
    int max, i, j;
    int* c;                                            // Our Count Array.

    max = find_max();                                  // One Member Function acn be called inside another Member Function without the help of Object.

    c = new int[max + 1];

    for (i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }

    for (i = 0; i < size; i++)
    {
        c[A[i]]++;
    }

    i = 0; j = 0;                                  // 'i' Traces Array "A" , 'j' Traces Array "c".

    while (j < max + 1)
    {
        if (c[j] > 0)
        {
            A[i++] = j;                            // Index of Count Array is copied as element in Array "A".
            c[j]--;

        }

        else
        {
            j++;
        }
    }

    cout << "\nNote : It is Index Based Sorting (Not Comparision Based), Hence No Comparisions, Swaps and Passes." << endl;
}



void Array::Bin_Insert(Node** Bin_ptr, int Index)            // Here we passes the Element of our Actual Array which becomes the Index of Bin Array.
{
    Node* temp;
    temp = new Node;
    temp->data = Index;  
    temp->next = NULL;

    if (Bin_ptr[Index] == NULL)
    {
        Bin_ptr[Index] = temp;
    }

    else
    {
        Node* P = Bin_ptr[Index];

        while (P->next != NULL)
        {
            P = P->next;
        }

        P->next = temp;
    }

}

int Array::Delete(Node** Bin_ptr, int Index)
{
    Node* P = Bin_ptr[Index];                               // Bin_ptr[Index] will always be Head Pointer.
    Bin_ptr[Index] = Bin_ptr[Index]->next;
    int x = P->data;
    delete P;
    return x;
}

void Array::Bin_sort()
{
    int max, i, j;

    Node** Bins;
        
    max = find_max();

    Bins = new Node * [max + 1];

    for (i = 0; i < max + 1; i++)                                             // Initializing all the Bins to NULL.
    {
        Bins[i] = NULL;
    }

    for (i = 0; i < size; i++)                                                // Initializing Bins Array According to our Requirement.
    {
        Bin_Insert(Bins, A[i]);                                                   // Here A[i] will be inserted in Bin Array at Index A[i].
    }

    i = 0; j = 0;

    while (i < max + 1)
    {
        while (Bins[i] != NULL)                                               // Deleting Elements from Bin Array and copying them back to our Actual Array Simultaneously.
        {
            A[j++] = Delete(Bins, i);
        }
        i++;
    }

    delete[] Bins;
    
}



int Array::Count_Digit(int x)
{
    int count = 0;

    while (x != 0)
    {
        x = x / 10;
        count++;
    }
    return count;
}

int Array::getBinIndex(int x, int pass)
{
    return (int)  (x / pow(10, pass)) % 10;
}

void Array::Radix_Insert(Node** Bin_ptr, int value, int Index)            // Here we passes the Element of our Actual Array which becomes the Index of Bin Array.
{
    Node* temp;
    temp = new Node;
    temp->data = value;                                                   // It is same as that of Bin_Insert only this statment is different.
    temp->next = NULL;

    if (Bin_ptr[Index] == NULL)
    {
        Bin_ptr[Index] = temp;
    }

    else
    {
        Node* P = Bin_ptr[Index];

        while (P->next != NULL)
        {
            P = P->next;
        }

        P->next = temp;
    }

}

void Array::Radix_sort()
{
    int max, i, j, npass;

    max = find_max();                                                     // To Find out Maximum Number 
    npass = Count_Digit(max);                                             // To Find out Number of Digits of Maximum Number.(As Passes = "Number of Maximum Digits" of a Number, present in given Array.)

    Node** Bins;

    Bins = new Node* [10];                                                // As we are sorting Integers i.e Decimal Numbers , Hence 10 Bins are Required.


    for (i = 0; i < 10 ; i++)                                             // Initializing all the Bins to NULL.
    {
        Bins[i] = NULL;
    }

    for (int pass = 0; pass < npass; pass++)
    {
        for (int i = 0; i < size; i++)                                    // Initializing Bin Array.(Note : Only this part is little different than Bin_sort())
        {
            int Bin_index = getBinIndex(A[i], pass);
            Radix_Insert(Bins, A[i], Bin_index);
        }

        // Deleting Process is also exact same as Bin_sort.

        i = 0; j = 0;

        while (i < 10)
        {
            while (Bins[i] != NULL)                                               // Deleting Elements from Bin Array and copying them back to our Actual Array Simultaneously.
            {
                A[j++] = Delete(Bins, i);
            }
            i++;
        }

        // After deleting we have to initialize all pointers to NULL, to make it ready for next pass.

        for (i = 0; i < 10; i++)                                             // Initializing all the Bins to NULL.
        {
            Bins[i] = NULL;
        }
    }

    delete[] Bins;           // Releasing the heap Memory.



}



void Array::Shell_sort()                                                            // Exact same as Insertion Sort with some modifications.
{
    int gap, i, j, x;

    for (gap = size / 2; gap >= 1; gap = gap / 2)
    {
        for (i = gap; i < size; i++)
        {
            j = i - gap;
            x = A[i];

            while (j > -1 && A[j] > x)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }

            A[j + gap] = x;

        }
    }
}


int main()
{
    int x;
    cout << "\nEnter the Size of Array : ";
    cin >> x;

    Array A1(x);

    int choice;


    do
    {
        cout << "\nEnter Choice : ";
        cout << "\n1]Initialize \n2]Display \n3]Bubble Sort \n4]Insertion Sort \n5]Selection Sort \n6]Quick Sort \n7]Merge Sort \n8]Count Sort \n9]Bin Sort \n10]Radix Sort \n11]Shell Sort";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            A1.initialize();
            break;
        }

        case 2:
        {
            A1.display();
            break;
        }

        case 3:
        {
            A1.Bubble_sort();
            break;
        }

        case 4:
        {
            A1.Insertion_sort();
            break;
        }

        case 5:
        {
            A1.Selection_sort();
            break;
        }

        case 6:
        {
            cout << "\nNote : For Quick sort, Infinity should be the Last Element of the Array which is to be Sorted" << endl;
            cout << "\n\tIf its not added, you may re-initialize it now." << endl;

            int* A;
            int size;

            A = A1.get_Array();
            size = A1.get_size();

            A1.Quick_sort(A, 0, size - 1);

            break;
        }
        case 7:
        {
            int x;
            cout << "\n1]Iterative \n2]Recursive";
            cout << "\n\nChoice : ";
            cin >> x;

            if (x == 1)
            {
                A1.i_Merge_sort();
            }

            else
            {
                int* A;
                int size;

                A = A1.get_Array();
                size = A1.get_size();

                A1.r_Merge_sort(A, 0, size - 1);
            }

            break;

        }

        case 8:
        {
            A1.Count_sort();
            break;
        }

        case 9:
        {
            A1.Bin_sort();
            break;
        }

        case 10:
        {
            A1.Radix_sort();
            break;
        }

        case 11:
        {
            A1.Shell_sort();
            break;
        }

        }

    } while (choice > 0);

}
