/******************************
Factorial of N Natural Numbers
******************************/

#include <iostream>

using namespace std;

int input(void);
int funA(int n);
int fact_loop(int n);




int main()
{
        cout << "Factorial Calculated By Using Recursion : " << funA(input()) << endl;
        cout << "Factorial Calculated By Using Loops : " << fact_loop(input()) << endl;   
}







// Taking Input

int input(void)
{
    cout << "\nPlease Enter the Natural Number of which Factorial is to be Calculated : " << endl;
    int x;
    cin >> x;
    return x;
}


// Factorial Using Recursion  

int funA(int n)
{
    if (n == 0)
        return 1;
    else
        return funA(n - 1) * n;
}


// Factorial Using Loop  

int fact_loop(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}