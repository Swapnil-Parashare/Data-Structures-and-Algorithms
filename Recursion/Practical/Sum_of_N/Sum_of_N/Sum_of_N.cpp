/***********************
Sum of N natural Numbers
***********************/

#include <iostream>

using namespace std;

int input(void);
int formula(int n);
int loop(int n);
int FuncA(int n);


int main()
{
    cout << "Sum of N Natural Numbers by Formula : " << formula(input()) << endl;
    cout << "Sum of N Natural Numbers by Loop : " << loop(input()) << endl;
    cout << "Sum of N Natural Numbers by Recursion : " << FuncA(input()) << endl;
}

/***************************************************************************************************
Function can be Directly passed as an Argument to Another function if "It is Returning something ".
***************************************************************************************************/
int input(void)
{
    cout << "\nPlease Enter the Natural Number till which Sum is to be Calculated : " << endl;
    int x;
    cin >> x;
    return x;
}


int formula(int n)
{
    return    n * (n + 1) / 2;
}

int loop(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }

    return sum;
}


// Recursion

/************************************************************************************
* 1] Recursive Functions are compact, short and easy to write.
  2] Recursion is most Convenient when you want to convert your Mathematical Solution in a Programatical form.
  3] Recursive Functions are Costly as they Consumes a lot of Memory.
  4] Recursive Functions can be converted into loops further.
* 
************************************************************************************/

int FuncA(int n)
{
    if (n == 0)
        return 0;
    else
        return FuncA(n - 1) + n;
}
