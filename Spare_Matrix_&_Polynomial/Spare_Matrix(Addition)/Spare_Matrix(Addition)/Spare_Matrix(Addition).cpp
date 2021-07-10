
/**************************     Creation & Display      ********************************/

#include <iostream>

using namespace std;

struct Element
{
    int i;
    int j;
    int x;

};

struct Spare
{

    int m;
    int n;
    int num;
    struct Element* e;

};

    void initialize(struct Spare* A1);
    void dispaly(struct Spare A1);
    struct Spare* add(struct Spare* A1, struct Spare* A2);
    

    


int main()
{
    struct Spare A1;
    cout << "\nEnter Data for Spare Matrix 1" << endl;
    initialize(&A1);
    cout << "\nSparse Matrix 1 : \n" << endl;
    dispaly(A1);

    struct Spare A2;
    cout << "\nEnter Data for Spare Matrix 2" << endl;
    initialize(&A2);
    cout << "\nSparse Matrix 2 : \n" << endl;
    dispaly(A2);

    struct Spare* A3 = add(&A1, &A2);
    cout << "\n\n\nResultant Matrix : \n" << endl;
    dispaly(*A3);

    return 0;

    
    

}

// Initializer 

void initialize(struct Spare* A1)
{
    cout << "\nEnter Number of Rows of Spare Matrix : ";
    cin >> A1->m;

    cout << "\nEnter Number of Columns of Spare Matrix : ";
    cin >> A1->n;

    cout << "\nEnter Total Number of Non-Zero Elements : ";
    cin >> A1->num;

    A1->e = new struct Element[A1->num];

    cout << "\nNote : Data should be Entered in Sequence of Elements as they occured in Matrix" << endl;

    for (int i = 0; i < A1->num; i++)
    {
        cout << "\nEnter the Data of Element " << i + 1 << endl;
        cout << "\nRow : ";
        cin >> A1->e[i].i;
        cout << "\nColumn : ";
        cin >> A1->e[i].j;
        cout << "\nElement : ";
        cin >> A1->e[i].x;
    }

}

// Display

void dispaly(struct Spare A1)
{
    
    int i, j, k = 0;

    for (i = 1; i <= A1.m; i++)
    {
        cout << "\t";
        for (j = 1; j <= A1.n; j++)
        {
            if (i == A1.e[k].i && j == A1.e[k].j)
            {
                cout << A1.e[k].x << " ";
                k++;
            }
            else
            {
                cout << 0 << " ";

            }

        }
        cout << endl;
    }
}

// Addition

struct Spare* add(struct Spare* A1, struct Spare* A2)
{
    if (A1->m != A2->m || A1->n != A2->n)                                             // If any one of these Negative conditions is true then Break
    {
        cout << "Given Matrix Cannot be Added due to Different Dimensions" << endl;
        return NULL;
    }

    struct Spare* S;                                                                   // This is Pointer to our Resultant Spare Object
    S = new struct Spare[1];                                                           // Allocating Memory Dynamically
    S->m = A1->m;
    S->n = A1->n;
    S->e = new struct Element[A1->num + A2->num];                                         // Maximum Number of Non-Zero Elements in Resultant cannot exceed the sum non zero elements of Given Matrices
    

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < A1->num && j < A2->num)
    {
        if (A1->e[i].i < A2->e[i].i)
        {
            S->e[k++] = A1->e[i++]; 
        }

        else if (A2->e[i].i < A1->e[i].i)
        {
            S->e[k++] = A2->e[i++];
        }

        else
        {
            if (A1->e[i].j < A2->e[i].j)
            {
                S->e[k++] = A1->e[i++];
            }

            else if (A2->e[i].j < A1->e[i].j)
            {
                S->e[k++] = A2->e[j++];
            }

            else
            {
                S->e[k] = A1->e[i++];
                S->e[k++].x += A2->e[j++].x;

            }
        }
    }
    for (; i < A1->num; i++)  S->e[k++] = A1->e[i];                     // For Copying Remaining Elements when either i or j reaches end of the matrix
    for (; j < A2->num; j++)  S->e[k++] = A2->e[j];

    S->num = k;                                                           // Total Non-Zero Elements in Resultant Matrix

    return S;

}


