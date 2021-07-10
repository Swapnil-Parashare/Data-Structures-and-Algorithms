
#include <iostream>

using namespace std;


int input1(void);
int input2(void);
double FuncA(double x, double n);

int  main()
{
    cout<< "Answer : " << FuncA(input1(), input2());
}




// Functions Taking Input

int input1(void)
{
    cout << "Enter the Power of 'e' : ";
    int x;
    cin >> x;
    return x;

}

int input2(void)
{
    cout << "Enter the Precision : ";  // Precision is nothing but total number of terms of Taylor series(counting starts with 0)
    int x;
    cin >> x;
    return x;

}





// Taylor Series Using Recursion.

/****************************************************************
Here: - x = Power of e
        n = Total Number of Terms
****************************************************************/

double FuncA(double x, double n)
{
    static double p = 1;

    static double f = 1;

    static double r = 0;



    if (n == 0)
        return 1;
    else
    {
        r = FuncA(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}