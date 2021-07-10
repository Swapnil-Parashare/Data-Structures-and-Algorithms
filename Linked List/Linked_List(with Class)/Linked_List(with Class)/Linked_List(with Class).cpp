#include <iostream>

using namespace std;

class Node
{
public:

    int data;
    Node* next;                    // Self-Referencing
};

class Linked_List
{
private:

    Node* first;


public:

    Linked_List()                   // Default Constructor
    {
        first = NULL;
    }

    Linked_List(int A[], int n);    // Parametrized Constructor  (Producing LL from given Array)
    ~Linked_List();                 // Destructor

    Node* get_first();


    void display_i();
    void display_r(Node* P);
    int count_i();
    int count_r(Node* P);
    int sum_i();
    int sum_r(Node* P);
    int max_i();
    int max_r(Node* P);
    int min_i();
    int min_r(Node* P);
    Node* search_i(int key);
    Node* search_r(Node* P, int key);
    Node* search_m(int key);
    void insert(int pos, int x);
    void append(int x);
    void insert_sort(int x);
    int Delete(int index);
    int is_sort();
    void r_duplicates();
    void reverse_1();
    void reverse_2();
    void reverse_3(Node* Q, Node* P);
    int is_loop();
    
};

Linked_List::Linked_List(int A[], int n)
{
    Node* last;
    Node* t;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

Linked_List::~Linked_List()
{
    Node* P = first;

    while (first)                     // Here P is Following first
    {
        first = first->next;
        delete P;
        P = first;

    }
}


Node* Linked_List::get_first()        // For Accessing "first pointer" which is our Private Data Member
{
    return first;
}


int main()
{
    int A[] = { 1,2,3,4,5,6,7,8,9,10 };
    Linked_List L1(A, 10);

    int choice;
    do
    {
        cout << "\nEnter Choice :";
        cout << "\n1]Display \n2]Count Nodes \n3]Calulate Sum \n4]Calculate Maximum \n5]Calculate Minimum";
        cout << "\n6]Search \n7]Insert \n8]Append \n9]Insert in Sorted Linked List \n10]Delete";
        cout << "\n11]Verify Sorted Linked List \n12]Remove Duplicates \n13]Reverse \n14]Check Presence of Loop";
        cout << "\n\nFor Exiting Enter -1 ";
        cout << "\n\nChoice : ";
        cin >> choice;



        switch (choice)
        {
        case 1:

        {
            int i = 0;
            cout << "\n1]Iterative \n2]Recursive \n\nChoice : ";
            cin >> i;

            if (i == 1)
            {
                L1.display_i();
            }

            else
            {
                Node* x = L1.get_first();
                cout << "\nLinked List : ";
                L1.display_r(x);
                cout << endl;
            }
            break;
        }


        case 2:

        {
            int i = 0;
            cout << "\n1]Iterative \n2]Recursive \n\nChoice : ";
            cin >> i;

            if (i == 1)
            {
                cout << "\nTotal Number of Nodes : " << L1.count_i() << endl;
            }

            else
            {
                Node* P = L1.get_first();
                cout << "\nTotal Number of Nodes : " << L1.count_r(P) << endl;
            }
            break;
        }

        case 3:

        {
            int i = 0;
            cout << "\n1]Iterative \n2]Recursive \n\nChoice : ";
            cin >> i;

            if (i == 1)
            {
                cout << "\nSum : " << L1.sum_i() << endl;
            }
            else
            {
                Node* P = L1.get_first();
                cout << "\nSum : " << L1.sum_r(P) << endl;
            }
            break;
        }

        case 4:

        {
            int i = 0;
            cout << "\n1]Iterative \n2]Recursive \n\nChoice : ";
            cin >> i;

            if (i == 1)
            {
                cout << "\nMaximum : " << L1.max_i() << endl;
            }
            else
            {
                Node* P = L1.get_first();
                cout << "\nMaximum : " << L1.max_r(P) << endl;
            }
            break;


        }

        case 5:

        {
            int i = 0;
            cout << "\n1]Iterative \n2]Recursive \n\nChoice : ";
            cin >> i;

            if (i == 1)
            {
                cout << "\nMinimum : " << L1.min_i() << endl;
            }
            else
            {
                Node* P = L1.get_first();
                cout << "\nMinimum : " << L1.min_r(P) << endl;
            }
            break;


        }

        case 6:

        {
            int i = 0;
            cout << "\n1]Iterative \n2]Recursive \n3]Search with \"Move to Head\" \n\nChoice : ";
            cin >> i;

            if (i == 1)
            {
                int x = 0;
                cout << "\nElement : ";
                cin >> x;

                Node* P = L1.search_i(x);

                if (P)cout << "\nElement " << P->data << " is present at Node " << P << endl;
                else cout << "\nSpecified Element Not Found" << endl;
            }
            else if (i == 2)
            {
                Node* s = L1.get_first();

                int x = 0;
                cout << "\nElement : ";
                cin >> x;

                Node* P = L1.search_r(s, x);
                if (P)cout << "\nElement " << P->data << " is present at Node " << P << endl;
                else cout << "\nSpecified Element Not Found" << endl;
            }
            else
            {
                int x = 0;
                cout << "\nElement : ";
                cin >> x;

                Node* P = L1.search_m(x);

                if (P)cout << "\nElement " << P->data << " is present at Node " << P << endl;
                else cout << "\nSpecified Element Not Found" << endl;
            }
            break;
        }

        case 7:

        {
            int x = 0;
            cout << "\nElement : ";
            cin >> x;

            int pos = 0;
            cout << "\nPosition : ";
            cin >> pos;

            L1.insert(pos, x);

            break;
        }
        case 8:

        {
            int x = 0;
            cout << "\nElement : ";
            cin >> x;

            L1.append(x);

            break;
        }

        case 9:

        {
            int x = 0;
            cout << "\nElement : ";
            cin >> x;

            L1.insert_sort(x);

            break;
        }

        case 10:

        {
            int x = 0;
            cout << "\nIndex : ";
            cin >> x;

            cout << "\nDeleted Element : " << L1.Delete(x) << endl;

            break;
        }

        case 11:

        {
            if (L1.is_sort())
            {
                cout << "\nLinked List is Sorted." << endl;
            }
            else
            {
                cout << "\nLinked List is not Sorted." << endl;
            }
            break;
        }

        case 12:
        {
            L1.r_duplicates();
            break;
        }

        case 13:
        {
            int i = 0;
            cout << "\n1]Reverse Elements \n2]Reverse Links  \n\nChoice : ";
            cin >> i;

            if (i == 1)
            {
                L1.reverse_1();
            }
            else
            {
                int x = 0;
                cout << "\n1]Using Sliding Pointers \n2]Using Recursion  \n\nChoice : ";
                cin >> x;
                if (x == 1)
                {
                    L1.reverse_2();
                }
                else
                {
                    Node* P = L1.get_first();
                    Node* Q = NULL;
                    L1.reverse_3(Q, P);
                }

            }
            break;
        }

        case 14:
        {
            int x = L1.is_loop();

            if (x)
            {
                cout << "\nLoop is Present in Linked List." << endl;
            }

            else
            {
                cout << "\nLinked List is Linear, Loop is Absent." << endl;
            }

        }

        
        }

    } while (choice > 0);

}



// Display (Iterative)

void Linked_List::display_i()
{
    Node* P = first;
    cout << "\nLinked List : ";
    while (P != NULL)
    {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

// Display (Recursive)

void Linked_List::display_r(Node* P)
{
    if (P)
    {
        cout << P->data << " ";
        display_r(P->next);
    }
}

// Counting Nodes (Iterative)

int Linked_List::count_i()
{
    int x = 0;
    Node* P = first;

    while (P)
    {
        x++;
        P = P->next;
    }
    return x;
}

// Counting Nodes (Recursive)

int Linked_List::count_r(Node* P)
{
    int count = 0;
    if (P == NULL)
        return 0;
    else
    {
        return count_r(P->next) + 1;
    }
}

// Sum (Iterative)

int Linked_List::sum_i()
{
    Node* P = first;
    int sum = 0;

    while (P)
    {
        sum += P->data;
        P = P->next;
    }
    return sum;

}

// Sum (Recursive)

int Linked_List::sum_r(Node* P)
{
    if (P == NULL)
        return 0;
    else
    {
        return sum_r(P->next) + P->data;
    }

}

// Maximum (Iterative)

int Linked_List::max_i()
{
    Node* P = first;
    int max = INT32_MIN;

    while (P)
    {
        if (P->data > max)
        {
            max = P->data;
        }
        P = P->next;
    }
    return max;

}

// Maximum (Recursive)

int Linked_List::max_r(Node* P)
{
    int x = 0;

    if (P == NULL)
        return INT32_MIN;                                            // i.e at last node Minimum integer is returned

    else
        x = max_r(P->next);                                           // Whatever the function returns stores in this x.

    return  x > P->data ? x : P->data;
}

// Minimum (Iterative)

int Linked_List::min_i()
{
    Node* P = first;
    int min = INT32_MAX;

    while (P)
    {
        if (P->data < min)
        {
            min = P->data;
        }
        P = P->next;
    }
    return min;

}

// Minimum (Recursive)

int Linked_List::min_r(Node* P)
{
    int x = 0;

    if (P == NULL)
        return INT32_MAX;                                            // i.e at last node Minimum integer is returned

    else
        x = max_r(P->next);

    return  x < P->data ? x : P->data;
}

// Searching (Iterative)

Node* Linked_List::search_i(int key)
{
    Node* P = first;

    while (P != NULL)
    {
        if (key == P->data)
            return P;

        P = P->next;
    }
    return NULL;
}

// Searching (Recursive)

Node* Linked_List::search_r(Node* P, int key)
{
    if (P == NULL)
    {
        return NULL;
    }

    else if (P->data == key)
    {
        return P;
    }

    return search_r(P->next, key);
}

// Searching (Move to Head)

Node* Linked_List::search_m(int key)
{
    Node* P = first;
    Node* Q = NULL;
    while (P != NULL)
    {
        if (key == P->data && Q == NULL)
        {
            return P;
        }

        else if (key == P->data && Q)
        {
            Q->next = P->next;                                 // It will crash if key is present at first position (as at first iteration Q is pointing to NULL)
            P->next = first;                                   // P and first both are pointing on 1st Node
            first = P;                                         // Only P is pointing on 1st node and first is pointing on P i.e P has became first node.
            return P;
        }

        Q = P;
        P = P->next;
    }
    return NULL;
}

// Inserting in a Linked List

void Linked_List::insert(int pos, int x)
{
    if (pos < 0 || pos > this->count_i())
    {
        cout << "\nInvalid Position" << endl;
        return;
    }

    Node* t = new Node;
    t->data = x;
    t->next = NULL;

    if (pos == 0)
    {
        t->next = first;
        first = t;
    }

    else if (pos > 0)
    {
        Node* P = first;

        for (int i = 0; i < pos - 1; i++)
        {
            P = P->next;
        }

        t->next = P->next;
        P->next = t;
    }

}

// Appending a Node in Linked List

void Linked_List::append(int x)
{
    Node* t = new Node;
    t->data = x;
    t->next = NULL;

    Node* P = first;

    for (int i = 0; i < this->count_i() - 1; i++)
    {
        P = P->next;
    }

    P->next = t;
    P = t;
}

// Inserting the Node in Sorted Linked List

void Linked_List::insert_sort(int x)
{
    Node* Q = NULL;
    Node* P = first;

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
        if (P == first)                            // i.e our pointer is stopped on first Node itself.
        {
            t->next = first;
            first = t;
        }
        else                                       // General Case
        {
            Q->next = t;
            t->next = P;
        }
    }
}

// Deleting Node From Linked List

int Linked_List::Delete(int index)
{
    int x = -1;
    Node* Q = NULL;
    Node* P = first;


    if (index <= 0 || index > this->count_i())
    {
        cout << "\nInvalid Index" << endl;
        return x;
    }

    if (index == 1)
    {
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

// Checking Whether Linked List is Sorted or Not.

int Linked_List::is_sort()
{
    Node* P = first;
    int x = INT_MIN;

    while (P)
    {
        if (x <= P->data)
        {
            x = P->data;
            P = P->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

// Removing Duplicates

void Linked_List::r_duplicates()
{
    Node* P = first;
    Node* Q = first->next;

    while (Q != NULL)               // Here P is Following Q.
    {
        if (P->data != Q->data)
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


// Reverse (By Reversing Elements) (Generally Not Practised)


void Linked_List::reverse_1()      // Requires an Auxillary Array
{
    int* A = new int[this->count_i()];
    Node* P = first;
    int i = 0;

    while (P != NULL)                         // Copying
    {
        A[i] = P->data;
        P = P->next;
        i++;
    }

    i--;
    P = first;

    while (P != NULL)                        // Reverse Copying
    {
        P->data = A[i];
        P = P->next;
        i--;
    }

}

// Reverse (By Reversing Links) (Generally Practised)

void Linked_List::reverse_2()        // Uses Sliding Pointers
{
    Node* P = first;
    Node* Q = NULL;
    Node* R = NULL;

    while (P != NULL)
    {
        R = Q;
        Q = P;
        P = P->next;
        Q->next = R;
    }
    first = Q;
}

// Reverse (By Reversing Links using Recursion)

void Linked_List::reverse_3(Node* Q, Node* P)
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

// Checking Presence of LOOP in LL.

int Linked_List::is_loop()
{
    Node* P;
    Node* Q;
    P = Q = first;

    do
    {
        P = P->next;
        Q = Q->next;
        if (Q) Q = Q->next;

    } while (Q && P != Q);

    return P == Q ? 1 : 0;
}                                                    /*******   121  ********/



