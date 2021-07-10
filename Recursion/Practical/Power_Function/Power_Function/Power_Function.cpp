
#include <iostream>

using namespace std;

int input1(void);
int input2(void);
int power(int m, int n);
int pow_loop(int m, int n);




int main()
{
    
    cout<< "Calculating Power by Recursion :" << power(input1(),input2()) << endl;
    cout <<"Calculating Power by Loop :" << pow_loop(input1(), input2()) << endl;

}



/*****************************************************************************************************
Here Sequence of Calling is :- 1]input2()
                               2]input1()
                               3]power()


If you want to call input1() first then,
                               1]Interchange these functions inside the power() calling and defination.
                               2]Interchange m <--> n inside whole Program.

******************************************************************************************************/












// Functions for taking inputs

int input1(void)
{
    cout << "Please Enter the Number You want to Raise : " << endl;
    int x;
    cin >> x;
    return x;     
}

int input2(void)
{
    cout << "\n\nPlease Enter the Power upto which you want to Raise : " << endl;
    int x;
    cin >> x;
    return x;
}





// Calculating Power Using Recursion

int power(int m, int n)                                             // These Functions are easy to write also theyare short and compact. 
{
    if (n == 0)
        return 1;
    else
        return power(m, n - 1)*m ;
}




// Calculating Power Using Loops

int pow_loop(int m, int n)
{
    int r = 1;
    if (n == 0)
        return 1;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            r *= m;
        }

        return r;

    }
        
}

