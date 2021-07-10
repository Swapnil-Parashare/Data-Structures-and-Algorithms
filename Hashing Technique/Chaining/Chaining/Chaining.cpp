#include <iostream>

using namespace std;

class Array                                                                         // For Keys on which Hashing is to be performed.
{
private:

    int* keys;
    int size;

public:

    Array(int x)
    {
        size = x;                                                                
        keys = new int[x];
    }

    ~Array()
    {
        delete[]keys;
    }

    void initialize()
    {
        cout << "\nKeys : ";

        for (int i = 0; i < size; i++)
        {
            cin >> keys[i];
        }
    }

    int get_size()
    {
        return size;
    }

    int* get_keys()
    {
        return keys;
    }
};



class Node                                                                           // For Forming Chains i.e Linked List.
{
public:

    int data;
    Node* next;
};




class HashTable
{
private:

    Node** HT;                          // This is our "Main" Double Pointer to Nodes.

public:

    HashTable();                       // Default Constructor
    ~HashTable();                      // Destructor

    Node** get_HT()                    // Getter
    {
        return HT;
    }

    int hash(int key);                 // Hash Function for calculating index.
    void Insert(int key);              // Nodes should be inserted in Chains(i.e LL) in Sorted order so that searching is easy.
    int Search(int key);
    int Delete(int key);




};

HashTable::HashTable()
{
    HT = new Node * [10];
    for (int i = 0; i < 10; i++)
        HT[i] = NULL;
}

HashTable::~HashTable()
{
    for (int i = 0; i < 10; i++)                  // For Deleting Nodes, present in each and every chain.
    {
        Node* P = HT[i];

        while (HT[i])
        {
            HT[i] = HT[i]->next;
            delete P;
            P = HT[i];
        }
    }


    delete[]HT;                                 // For deleting all the Node Pointers.

                                                // When we use delete, the memory pointed by that pointer is deleted.
}

int HashTable::hash(int key)
{
    return key % 10;                            // Calculating Index, on the basis of last digit.   
}

void HashTable::Insert(int key)
{
    int Index = hash(key);

    Node* t = new Node;
    t->data = key;
    t->next = NULL;

    if (HT[Index] == NULL)
    {
        HT[Index] = t;
    }

    else
    {
        Node* P = HT[Index];
        Node* Q = HT[Index];

        while (P && P->data < key)
        {
            Q = P;
            P = P->next;
        }

        if (Q = HT[Index])             // Q stop on 1st position itself
        {
            t->next = HT[Index];
            HT[Index] = t;
        }

        else
        {
            t->next = P;
            Q->next = t;
        }
    }
}

int HashTable::Delete(int key)                                         // Work Under Progress.
{
    int Index = hash(key);
    int x;

    Node* P = HT[Index];
    Node* Q = HT[Index];

    while (P && P->data < key)
    {
        Q = P;
        P = P->next;
    }
    if (P->data = key && HT[Index] == P)
    {
        x = P->data;
        HT[Index] = HT[Index]->next;
        delete P;
        return x;
    }
    else if (P->data = key)
    {
        x = P->data;
        Q->next = P->next;
        delete P;
        return x;
    }
    else
    {
        return -1;
    }


}

int HashTable::Search(int key)
{
    int Index = hash(key);

    Node* P = HT[Index];

    while (P)
    {
        if (P->data = key)
        {
            return P->data;
        }
        else if (P->data > key)                                      // As Nodes are Inserted in sorted Order.
            return -1;

        P = P->next;
    }

    return -1;

}


int main()
{
    int x;
    cout << "\nEnter Number of Keys : ";
    cin >> x;

    Array A1(x);

    HashTable H1;

    int choice;

    do
    {
        cout << "\nEnter Choice : " << endl;
        cout << "\n1]Enter Keys \n2]Insert in Hash Table \n3]Search \n4]Delete" << endl;
        cout << "\nChoice : ";
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
            int* A = A1.get_keys();

            for (int i = 0; i < A1.get_size(); i++)
            {
                H1.Insert(A[i]);
            }

            cout << "\nKeys Successfully Inserted In Hash Table." << endl;

            break;
        }

        case 3:
        {
            int x;
            cout << "\nKey : ";
            cin >> x;

            x = H1.Search(x);

            if (x != -1)
            {
                cout << "\nKey " << x << " found" << endl;
            }

            else
            {
                cout << "\nSpecified Key is Absent" << endl;
            }

            break;
        }

        case 4:
        {
            int x;
            cout << "\nKey : ";
            cin >> x;
            x = H1.Delete(x);

            break;

        }



        }

    } while (choice > 0);
}
