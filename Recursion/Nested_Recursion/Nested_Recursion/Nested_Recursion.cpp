/********************************************************************************************************
Trace the Tree of this Nested Recursive Function, Find out the output and Sequence of Function Calling.
Tally all the things while Debugging.
********************************************************************************************************/


#include <iostream>

using namespace std;


int funA(int n)
{
    if (n > 100)
        return n - 10;
    else
        return funA(funA(n + 11));         // Nested Recursive Call
}


int main()
{
    
    cout << funA(51);
}

