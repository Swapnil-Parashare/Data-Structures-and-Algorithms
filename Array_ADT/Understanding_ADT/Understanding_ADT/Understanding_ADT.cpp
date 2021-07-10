
#include <iostream>

using namespace std;

struct Array
{
    int* ptr;
    int size;
    int length;
};

void display(struct Array xyz);


int main()
{
    struct Array A1;                                           // Creating object of Structure

    cout << "Please Enter Size of Your Array : " << endl;
    cin >> A1.size;                                            // Initializing Size from user.

    A1.ptr = new int[A1.size];                                 // Initializing our Pointer with Memory Accordindly.

    A1.length = 0;                                             // Length is nothing but used size. It is initially inialized with 0.




    cout << "Please Enter Number of Elements of Array You Want to Initialized : " << endl;
    int n;
    cin >> n;



    cout << "Please Enter your Numbers" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> A1.ptr[i];
    }
    


    A1.length = n;


    display(A1);


}

void display(struct Array xyz)
{
    cout << "\n\tElements Of Your Array :-\n\t" ;
    for (int i = 0; i < xyz.length; i++)
    {
        cout << xyz.ptr[i] << " ";
    }
    cout << endl;
}