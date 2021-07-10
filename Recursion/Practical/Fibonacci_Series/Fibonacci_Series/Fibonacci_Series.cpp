
#include <iostream>

using namespace std; 

int input(void);
int fib(int n);
int m_fib(int n);
int i_fib(int n);

int main()
{
    while (true)
    {
        cout << "Fibonaccic Term for given Number using Normal Recursion : " << fib(input());
        cout << "Fibonaccic Term for given Number using Memoization : " << m_fib(input());
        cout << "Fibonaccic Term for given Number using Iteration : " << i_fib(input());

    }
}

// Input Functions

int input(void)
{
    cout << "\nPlease Enter The Integer : ";
    int x;
    cin >> x;
    return x;
}


// Fibonacci Series Using Recursion

int fib(int n)
{
    if (n <= 1)
        return n;
    else
        return fib(n - 2) + fib(n - 1);

}


// Fibonacci Series Using Recursion and Memoization

int m_fib(int n)
{
    int array[10];                           // Our array is initialized with -1.
    for (int i = 0; i < 10; i++)
    {
        array[i] = -1;
    }

    if (n <= 1)
    {
        array[n] = n;
        return n;
    }

    else
    {
        if (array[n - 2] == -1)                                       // Checking wether the value is present in our array or not
        {
            array[n - 2] = fib(n - 2);                                // As the value is absent hence calling the Function and storing the value in array.
        }
                                                                      // Here function is called only when its value is absent in array(i.e functions are called only once)
        if (array[n - 1] == -1)
        {
            array[n - 1] = fib(n - 1);
        }

        array[n] = array[n - 2] + array[n - 1];

        return array[n - 2] + array[n - 1];
             
    }
}

// Fibonacci Series Using Iteration

int i_fib(int n)
{
    int t0 = 0;
    int t1 = 1;
    int s = 0;

    if (n <= 1)
        return n;
    else
        for (int i = 2; i <= n; i++)
        {
            s = t0 + t1;
            t0 = t1;
            t1 = s;
        }
    return s;
}

