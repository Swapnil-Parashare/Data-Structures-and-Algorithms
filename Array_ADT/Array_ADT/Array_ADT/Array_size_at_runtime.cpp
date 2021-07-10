
#include <iostream>

using namespace std;

int main()
{
	int size;
	cout << "Please Enter Your Array Size : " << endl;
	cin >> size;

	//int array[size];                  // Array in stack (Gives Error)

	int* ptr;

	ptr = new int[size];                // Array in Heap

	for (int i = 0; i < size; i++)
	{
		ptr[i] = i;
	}

	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << endl;
	}
}
