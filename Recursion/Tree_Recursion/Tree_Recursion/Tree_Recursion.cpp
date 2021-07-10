/*****************************************************************************
Trace the whole Tree, Give Sequence for Function Calling and Guess the Output.
Tally the Whole Thing, While "Debugging".
*****************************************************************************/


#include <iostream>

using namespace std;

void func(int n)                              // Tree Recursive Fuction
{
	if (n > 0)
	{
		cout << n ;
		func(n - 1);
		func(n - 1);
	}
}

int main()
{
	int x;
	x = 3;
	func(x);
	return 0;
   
}

