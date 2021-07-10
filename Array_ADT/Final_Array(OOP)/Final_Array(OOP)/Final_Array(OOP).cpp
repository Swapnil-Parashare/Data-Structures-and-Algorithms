
#include <iostream>


using namespace std;




class Array
{
private:

    int* A;
    int siz;
    int length;
    
public :
    
    Array()                         // Constructor(without parametre), It is Default Constructor,it will get called automatically when the object is created, and will initialize all the three atrtributes.             
    {
        siz = 10;
        length = 0;
        A = new int[siz];
    }

    Array(int sz)                   // Constructor(with parametre)
    {
        siz = sz;
        length = 0;
        A = new int[sz];
    }

    ~Array()                        // Destructor
    {
        delete[]A;
    }

    void initialize();
    void display();
    void append( int x);
    void insert(int index, int x);
    void Delete( int index);
    int index(void);
    int number(void);

  

};

void Array::initialize()
{
    cout << "\nPlease Enter the sizs of Your Array : ";
    cin >> siz;

    A = new int[siz ];

    cout << "\nPlease Enter the Number of Elements You want Enter Now : ";
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        cout << "\nEnter Element No. " << i + 1 << " : ";
        cin >> A[i];
    }
}

int main()
{
    Array A;                            // Normal Object of Class 'Array'
    Array* a1;                          // Pointer to the Object of Class 'Array'.
   
    a1 = &A;                            // Pointer is Assigned with the Memory of Existing Object.

/*
    cout << "Enter Size :" << endl;
    int sz;
    cin >> sz;
    a1 = new Array[sz];                 // Pointer is assigned with the Dynamic Memory for 'sz' number of objects i.e Array of Objects of Class 'Array'.
*/

    int choice;
    do
    {
        cout << "\nPlease Enter Your Choice :" << endl;
        cout << "\n0] Initialize \n1]Display \n2]Append \n3]Insert \n4]Delete" ;
        cout << "\nFor Exiting Enter : -1" << endl;
        cout << "\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 0:

            a1->initialize();                 // It is Initializing the Object Pointed By 'a1'.
            break;

        case 1:

            a1->display();
            break;

        case 2:

            a1->append(a1->number());
            break;

        case 3:

            a1->insert(a1->index(), a1->number());
            break;

        case 4:

            a1->Delete( a1->index());
            break;

        
        }


    } while (choice >= 0);

}




// Display Operation

void Array::display()
{
    if (length <= siz && length > 0)

    {
        cout << "\nYour Array Elements are : ";

        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    else if (length > siz)
        cout << "\nYour Length is Exceeding the sizs of Array." << endl;

    else
        cout << "\nAs Specified Length is '0' so there is nothing to display." << endl;
}




// Append Operation

void Array::append( int x)
{
    A[length] = x;
    length++;

}



// Insertion Operation

void Array::insert( int index, int x)
{
    if (index <= length && index >= 0)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }

        A[index] = x;

        length++;
    }

    else if (index > length)
        cout << "\nYour Index is Exceeding the existing length of array." << endl;

    else
        cout << "\nIndex should be a Positive Integer." << endl;

}


// Delete Operation

void Array::Delete( int index)
{
    if (index < length && index >= 0)
    {
        int x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        cout << "\nElement Deleted is : " << x << endl;
    }
    else if (index < 0)
        cout << "\nIndex should be a Positive Integer" << endl;
    else
        cout << "\nIndex is Exceeding the Specified Length " << endl;
}


int Array::index(void)
{
    int x;
    cout << "\nEnter the Index : ";
    cin >> x;
    return x;
}

int Array::number(void)
{
    int y;
    cout << "\nEnter the Number : ";
    cin >> y;
    return y;
}




















/*
// Finding Sum (Recursive)

int Array::r_sum( int last_i)
{
    if (last_i < 0)
        return 0;

    else
        return r_sum( last_i - 1) + arr.A[last_i];
}
*/


// Initializing Array
/*
void Initialize(struct Array* arr)
{
    cout << "\nPlease Enter the sizs of Your Array : ";
    cin >> arr->sizs;

    arr->A = new int[arr->sizs * sizsof(int)];

    cout << "\nPlease Enter the Number of Elements You want Enter Now : ";
    cin >> arr->length;

    for (int i = 0; i < arr->length; i++)
    {
        cout << "\nEnter Element No. " << i + 1 << " : ";
        cin >> arr->A[i];
    }



}




*/