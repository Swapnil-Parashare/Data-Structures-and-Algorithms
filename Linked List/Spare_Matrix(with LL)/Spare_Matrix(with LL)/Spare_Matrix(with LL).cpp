#include <iostream>

using namespace std;

struct Node
{
	int column;
	int value;
	Node* next;
};
struct Node* first = NULL;

struct Linked_list
{
	Node* L;
};

struct Spare
{
	int m;
	int n;
	Linked_list* A;
};

// Initialize

void initialize(struct Spare* S1)
{
	cout << "Total Rows : ";
	cin >> S1->m;

	cout << "Total Columns : ";
	cin >> S1->n;

	int row = S1->m;

	S1->A = new Linked_list[row];                              // I think memory is not allocated properly.


	cout << "Enter Elements : " << endl;

	/*********************    Creation of LL	********************/

	int value;
	Node* last = NULL;
	Node* t = NULL;
	for (int i = 0; i < S1->m; i++)
	{
		for (int j = 0; j < S1->n; j++)
		{
			cin >> value;
			if (value)
			{
				if (i >= 0 && j == 0)
				{
					 S1->A[i].L = new Node;
					 first = S1->A[i].L;
					 first->column = j;
					 first->value = value;
					 first->next = NULL;
					 last = first;
				}
				else
				{
					t = new Node;
					t->column = j;
					t->value = value;
					t->next = NULL;

					last->next = t;
					last = t;
				}
	 
			}
		}
	}
}

// Display



int main()
{
	struct Spare S1;
	initialize(&S1);
}