
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



class HashTable
{
private:

    int* A;
    int size;

public:

    HashTable(int x)
    {
        size = x;
        A = new int[size];
    }

    ~HashTable()
    {
        delete []A;
    }

    void initialize();

    int hash(int key);
    int probe(int key);
    void Insert(int key);
    int Search(int key);



};

void HashTable::initialize()
{
    for (int i = 0; i < size; i++)
    {
        A[i] = 0;
    }
}

int HashTable::hash(int key)
{
    return key % size;
}

int HashTable::probe(int key)                                                                 // It gives us next available "Free Space".
{
    int Index = hash(key);

    int i = 0;
    

    while (A[  (Index + i) % size     ] != 0)
    {
        i++;
    }

    return (Index + i) % size;
}

void HashTable::Insert(int key)
{
    int Index = hash(key);

    if (A[Index] != 0)
    {
        Index = probe(key);
    }

    A[Index] = key;


}

int HashTable::Search(int key)
{
    int Index = hash(key);

    int i = 0;

    while (A[(Index + i) % size] != key)                          // For Linear Searching Downwards.
    {
        i++;

        if (A[(Index + i) % size] == 0)                           // If we Encounter Empty Space then Element is Absent.
        {
            return -1;
        }

    }

    return (Index + i) % size;
}

int main()
{
    int x;
    cout << "\nEnter Number of Keys : ";
    cin >> x;

    Array A1(x); 

    HashTable H1(2*x);                                                      // Hash Table should always be "Half Filled" to maintain "Loading Factor (Elements/size) " 0.5   .

    H1.initialize();                                                        // It Initializes our Hash Table to 0.
   

    int choice;

    do
    {
        cout << "\nEnter Choice : " << endl;
        cout << "\n1]Enter Keys \n2]Insert in Hash Table \n3]Search " << endl;
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


            int y;

            y = H1.Search(x);

            if (y != -1)
            {
                cout << "\nKey " << x <<  " is found at index " << y <<endl;
            }

            else
            {
                cout << "\nKey "<< x << " is Absent" << endl;
            }

            break;
        }

        



        }

    } while (choice > 0);
}


