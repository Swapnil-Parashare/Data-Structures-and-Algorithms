
#include <iostream>

using namespace std;

int main()
{
	int* p, * q;                                     // Declaring Pointers         

	p = new int[5];                                  // Initializing Pointer 'p'  with heap memory

	int x = 11;

	for (int i = 0; i < 5; i++)                      // Initializing our array in heap, pointed by Pointer 'p'
	{
		p[i] = x;
		x++;
	}

	for (int i = 0; i < 5; i++)                      // Printing out elements of heap array, pointed by 'p'
	{
		cout << p[i] << endl;
	}




	q = new int[10];                                 // Creating New array of required size i.e heap memory allocation to another pointer 'q'

	for (int i = 0; i < 5; i++)                      // Copying elements from p to q.
	{
		q[i] = p[i];
	}


	for (int i = 0; i < 5; i++)                      // Printing out elements of heap array pointed by 'q'
	{
		cout << q[i] << endl;
	}

	delete[]p;                                      // Heap Memory Pointed by 'p' is Deleted. Now 'p' is pointing to anything.(but not NULL)

	p = q;                                          // Now 'p' is pointing to same memory address were 'q' is pointing.

	q = NULL;                                       // Now 'q' is pointing to nothing.



	/**********************************************************************************************
	 There is Big Difference Between:- 1] Pointer Pointing to Anything ( Its very Dangerous)
		   							   2] Pointer Pointing to Nothing  ( Null Pointer , Its Safe)
	***********************************************************************************************/
 

}
