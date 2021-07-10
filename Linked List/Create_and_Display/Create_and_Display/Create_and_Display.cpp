
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* first = NULL;
struct Node* second = NULL;
struct Node* third = NULL;



// Creation of Linked List

void create(int A[], int n)
{
    struct Node* t;
    struct Node* last;

    first = new struct Node[1];         // Space is allocated for our first node.
    first->data = A[0];                 // Data is assigne dto our First Node.
    first->next = NULL;                 // Self Refertial Pointer of our First Node is assinged to Null.

    last = first;                       // Now 'last' and 'first' both Pointers are pointing to our first node.

    for (int i = 1; i < n; i++)         // For loop is Starting from 1, because our first node is already assigned.
    {
        t = new struct Node[1];
        t->data = A[i];
        t->next = NULL;

        last->next = t;                  // Last Node is Pointing on t.

        last = t;                        // ??

    }
}


void create2(int A[], int n)
{
    struct Node* t;
    struct Node* last;

    second = new struct Node[1];         // Space is allocated for our first node.
    second->data = A[0];                 // Data is assigne dto our First Node.
    second->next = NULL;                 // Self Refertial Pointer of our First Node is assinged to Null.

    last = second;                       // Now 'last' and 'first' both Pointers are pointing to our first node.

    for (int i = 1; i < n; i++)         // For loop is Starting from 1, because our first node is already assigned.
    {
        t = new struct Node[1];
        t->data = A[i];
        t->next = NULL;

        last->next = t;                  // Last Node is Pointing on t.

        last = t;                        // ??

    }
}

// Display (Iterative)

void display_i(struct Node* p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;

    }
}

// Display (Recursive)

void display_r(struct Node* p)
{
    if(p != NULL)
    {
        cout << p->data << " ";
        display_r(p->next);
        
    }
}

// Counting Nodes (Iterative)

int count_i(struct Node* P)
{
    int count = 0;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}

// Counting Nodes (Recursive)

int count_r(struct Node* P)
{
    int count = 0;
    if (P == NULL)
        return 0;
    else
        return count_i(P->next) + 1;
            
}

// Sum (Iterative)

int sum_i(struct Node* P)
{
    int sum = 0;
    while (P != NULL)
    {
        sum = sum + P->data;
        P = P->next;
    }
    return sum;
}

// Sum (Recursive)

int sum_r(struct Node* P)
{
    int count = 0;
    if (P == NULL)
        return 0;
    else
        return sum_r(P->next) + P->data;

}

// Maximum (Iterative)

int max_i(struct Node* P)
{
    int max = INT32_MIN;

    while (P)
    {
        if (P->data > max)
            max = P->data;
        P = P->next;
    }
    return max;
}

// Maximum (Recursive)


int max_r(struct Node* P)
{
    int x = 0;

    if (P == NULL)
        return INT32_MIN;                                            // i.e at last node Minimum integer is returned

    else
        x = max_r(P->next);

    return  x > P->data ? x : P->data;
}

// Searching (Iterative)

struct Node* search_i(struct Node* P, int key)
{
    while (P != NULL)
    {
        if (key == P->data)
            return P;
     
        P = P->next;
    }
    return NULL;
}

// Searching (Recursive)

struct Node* search_r(struct Node* P, int key)
{
    if (P == NULL)
        return NULL;

    else if (key == P->data)
    {
        return P;
    }

    else
        return search_r(P->next, key);
}

// Searching (Iterative "Move to head")

struct Node* search_m(struct Node* P, int key)
{
    struct Node* Q  = NULL ;
    
    while (P != NULL)
    {


        if (key == P->data)

        {
            Q->next = P->next;           // It will crash if key is present at first position (as at first iteration Q is pointing to NULL)
            P->next = first;             // P and first both are pointing on 1st Node
            first = P;                   // Only P is pointing on 1st node and first is pointing on P i.e P has became first node.


            return P;
        }

        Q = P;
        P = P->next;
    }
    return NULL;
}

// Inserting in a Linked List

void insert(struct Node* P, int pos, int x)
{
    if (pos < 0 || pos > count_i(P))
    {
        cout << "\nInvalid Position" << endl;
        return;
    }

    struct Node* t;
    t = new struct Node[1];
    t->data = x;

    if (pos == 0)
    {
        t->next = first;
        first = t;
    }

    else if (pos > 0)
    {
        for (int i = 0; i < pos - 1 && P; i++)
        {
            P = P->next;
        }

        t->next = P->next;
        P->next = t;
    }
}

// Inserting at Last in Linked List

void insert_last(struct Node* P, int x)
{
    Node* t = new Node;
    t->data = x;
    t->next = NULL;

    Node* last = first;

    if (P == NULL)
    {
        first = last = t;
       
    }
    else
    {
        for (int i = 0; i < count_i(P) - 1; i++)                             // This for loop makes sure that last pointer ia actually pointing on last node.
        {
            last = last->next;
        }

        last->next = t;
        last = t;                                                            // Now last is pointing on newly created Node which is inserted at last.
    }

}

// Inserting in a Sorted Linked List

void insert_sort(struct Node* P, int x)
{
    Node* Q = NULL;

    Node* t = new Node;
    t->data = x;
    t->next = NULL;

    if (P == NULL)                                  // i.e if LINKED LIST IS NOT INITIALLY PRESENT
    {
        first = t;
    }

    else
    {
        while (P && P->data < x)
        {
            Q = P;
            P = P->next;
        }

        if (P == first)                             // i.e our pointer is stopped on first Node itself.
        {
            t->next = first;
            first = t;
        }

        else
        {
            t->next = Q->next;
            Q->next = t;
        }

    }

}

// Deleting Node From Linked List

int Delete(struct Node* P, int index)
{
    struct Node* Q = NULL;

    int x = -1;

    if (index <= 0 || index > count_i(P))
        return -1;

    if (index == 1)
    {
        P = first;
        first = first->next;
        x = P->data;
        delete P;
        return x;
    }

    else
    {
        for (int i = 0; i < index - 1 && P; i++)
        {
            Q = P;
            P = P->next;
        }

        Q->next = P->next;
        x = P->data;
        delete P;
        return x;
    }


}


// Checking Whether Linked List is Sorted or Not

int is_sort(struct Node* P)
{
    int x = INT_MIN;

    while (P != NULL)
    {
        if (P->data < x)
            return 0;
        x = P->data;
        P = P->next;
    }
    return 1;
}

// Removing Duplicates

void remove_duplicate(struct Node* P)
{
    struct Node* Q = first->next;           // Here P is following Q

    while (Q != NULL)
    {
        if(P->data != Q->data)
        {
            P = Q;
            Q = Q->next;
        }

        else
        {
            P->next = Q->next;
            delete Q;
            Q = P->next;
        }
    }


}


// Reverse (By Reversing Elements)

void reverse_1(struct Node* P)
{
    int* A = new int[count_i(P)];
    int i = 0;

    while (P != NULL)
    {
        A[i] = P->data;
        P = P->next;
        i++;
    }

    i--;
    P = first;

    while (P != NULL)
    {
        P->data = A[i];
        P = P->next;
        i--;
    }


}

// Reverse (By Reversing Links)

void reverse_2(struct Node* P)
{
    struct Node* Q = NULL;
    struct Node* R = NULL;

    while (P != NULL)
    {
        R = Q;
        Q = P;
        P = P->next;
        Q->next = R;
    }
    first = Q;

}

// Reverse (By Using Recursion)

void reverse_3(struct Node* Q, struct Node* P)
{
     
    if (P != NULL)
    {
        reverse_3(P, P->next);
        P->next = Q;
    }
    else
    {
        first = Q;
    }

}

// Concatenation

void concatenate(struct Node* P, struct Node* Q)
{
    third = P;

    while (P->next != NULL)
    {
        P = P->next; 
    }
    P->next = Q;
    Q = NULL;
    P = NULL;
}

// Merging Linked List

void merge(struct Node* P, struct Node* Q)
{
    struct Node* last;
    if (P->data < Q->data)
    {
        third = last = P;
        P = P->next;
        last->next = NULL;
    }
    else
    {
        third = last = Q;
        Q = Q->next;
        last->next = NULL;
    }

    while(P != NULL && Q != NULL)
    { 
        if (P->data < Q->data)
        {
            last->next = P;
            last = P;
            P = P->next;
            last->next = NULL;
        }
        else
        {
            last->next = Q;
            last = Q;
            Q = Q->next;
            last->next = NULL;
        }
    }

    if (P) last->next = P;
    else last->next = Q;
}

// Checking LOOP in LL

int is_loop(struct Node* f)
{
    struct Node* p = first;
    struct Node* q = first;

    do
    {
        p = p->next;
        q = q->next;
        if (q) q = q->next;

    } while (p && q && p != q);

    if (p == q) return 1;
    else return 0;
}

int main()
{
    
    
 
    int A[] = {3,5,7,10,11,21,51};

    create(A, 7);
    insert_sort(first, 60);
    display_i(first);


    

    return 0;
}

























void data_main()
{

    /*
        cout << endl;
        display_r(first);

        cout << "\nTotal Nodes: " << count_i(first) << endl;
        cout << "Total Nodes: " << count_r(first) << endl;
        cout << "Sum : " << sum_i(first) << endl;
        cout << "Sum : " << sum_r(first) << endl;

        cout << "Maximum : " << max_i(first) << endl;
        cout << "Maximum : " << max_r(first) << endl;

        struct Node* x = NULL;

        x = search_m(first, 5);

        if (x != NULL)cout << "\nKey " << x->data << " is present at Node " << x << endl;
        else cout << "\nSpecified Key Not Found" << endl;

        display_i(first);

     */
     /*
         insert(first, 7, 121);
         cout << "\n\n" << endl;
         display_i(first);



         insert_last(first, 121);                                                   // Its working even if LL is initially created.
         cout << endl;
         display_i(first);


         */
         /*
             insert_sort(first, 1);                                                   // Its working even if LL is initially created.

             cout << endl;
             display_i(first);
         */

         /*
             cout <<"\n\nDeleted Element : " << Delete(first, 8) << endl;
             cout << endl;
             display_i(first);
         */

         /*
             if (is_sort(first)) cout << "\nSorted" << endl;
             else cout << "\nNot Sorted" << endl;
           */

           /*
               remove_duplicate(first);
               cout << endl;
               display_i(first);

           */
           /*
               reverse_1(first);
               cout << endl;
               display_i(first);
           */

           /*
               reverse_2(first);
               cout << endl;
               display_i(first);

           */


           /*
               reverse_3(NULL, first);
               cout << endl;
               display_i(first);
           */


    /*int B[] = {1,2,3,4,5,6,7};

    create2(B, 7);
    cout << "\nSecond Linked List : " << endl;
    display_i(second);*/

    /*concatenate(first, second);
    cout << "\nConcatenated Linked List : " << endl;
    display_i(third);*/

    /*merge(first, second);
    cout << "\nMerged Linked List : " << endl;
    display_i(third);*/

    // Creating Loop in our LL
/*
    struct Node* t1;
    struct Node* t2;

    t1 = first->next->next->next;                      // Now on 10
    t2 = first->next->next->next->next->next->next;    //  on last
    t2->next = t1;

    cout << "\n\n"<<is_loop(first);
*/
}



