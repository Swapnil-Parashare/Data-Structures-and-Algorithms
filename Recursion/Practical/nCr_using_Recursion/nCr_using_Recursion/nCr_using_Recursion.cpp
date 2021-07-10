
#include <iostream>

using namespace std;

int input1(void);
int input2(void);
int fact_r(int n);
int simple_c(int n, int r);
int c(int n, int r);

int main()
{
    while (true)
    {
        cout << "Number of Combination possible (Using Simple Function) : " << simple_c(input1(), input2());
        cout << "Number of Combination possible (Using Recursive Function) : " << c(input1(), input2());
    }
}


int input1(void)
{
    cout << "Enter the Value of 'n' : ";
    int x;
    cin >> x;
    return x;
}

int input2(void)
{
    cout << "\n\nEnter the Value of 'r' : ";
    int x;
    cin >> x;
    return x;
}

int fact_r(int n)
{
    if (n == 0)
        return 1;
    else
        return fact_r(n - 1) * n;
}

// Simple Function

int simple_c(int n, int r)
{
    int t1, t2;
    t1 = fact_r(n);
    t2 = fact_r(r)* fact_r(n - r);
    return t1 / t2;
}

// Recursive Function

int c(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return c(n - 1, r - 1) + c(n - 1, r);

}

/**************************************************************************
* Recursive Function is more powerful than simple one for big calculations.
**************************************************************************/



