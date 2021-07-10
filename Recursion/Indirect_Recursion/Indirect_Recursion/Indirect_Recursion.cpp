/********************************************************************************************************
Trace the Tree of this Indirect Recursive Function, Find out the output and Sequence of Function Calling.
Tally all the things while Debugging.
********************************************************************************************************/


#include <iostream>

using namespace std;

void funcA(int n);
void funcB(int n);



void funcA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        funcB(n - 1);
    }
}

void funcB(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        funcA(n/2);
    }
}






int main()
{
    funcA(20);
}

