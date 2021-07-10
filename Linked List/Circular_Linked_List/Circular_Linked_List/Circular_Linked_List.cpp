#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;												// Global Head Node.
void create(int A[], int n);
void display_i(struct Node* P);
void display_r(struct Node* P);
int count(struct Node* P);
void insert(struct Node* h, int pos, int x);
int Delete(struct Node* P, int index);



int main()
{
	int A[] = { 1,2,3,4,5 };
	create(A, 5);
	
	display_r(head);
	cout << endl;

	Delete(head, 3);
	display_r(head);

}

//Create

void create(int A[], int n)
{
	struct Node* t;												// This is for Node creation (Hence Requires memory allocation)
	struct Node* last;											// This is just for pointing last Node. (Doesn't requires memory allocation)

	head = new struct Node;
	head->data = A[0];
	head->next = head;
	last = head;

	for (int i = 1; i < n; i++)
	{
		t = new struct Node;
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;

	}


}

// Display

void display_i(struct Node* P)                       // This Function strictly needs head node only, if other is given then head would never be printed.
{
	cout << "\nCircular Linked List : ";
	do 
	{
		cout << P->data << " ";
		P = P->next;

	} while (P != head);
	cout << endl;
}

void display_r(struct Node* P)
{
	static int flag = 0;

	if (P != head || flag == 0)
	{
		flag = 1;
		cout << P->data << " ";
		display_r(P->next);
	}
	flag = 0;
}

// Insert

void insert(struct Node* h, int pos, int x)
{
	struct Node* t = new struct Node;
	t->data = x;

	if (pos < 0 || pos > count(h)) cout << "\nInvalid Position" << endl;

	if (pos == 0)                                               // i.e Inserting Before Head Node.
	{
		if (head == NULL)                                       // i.e Circular Linked List is Empty.
		{
			head = t;
			head->next = head;
		}
		else
		{
			
			while (h->next != head)						         // For Reaching last Element
			{
				h = h->next;
			}
			h->next = t;                                         // Now Last Node is pointing on (newly created) Node before head.
			t->next = head;
			head = t;                                             // Our "head" is modified with newly inserted Node (it is optional)  "NOTE:- HEAD IS MODIFIED"
		}
	}

	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			h = h->next;
		}
		t->next = h->next;
		h->next = t;
	}
}

// Delete

int Delete(struct Node* P, int index)
{
	int x = 0;

	if (index <= 0 || index > count(head))
	{
		cout << "Invalid Index" << endl;
		return -1;
	}

	if (index == 1)
	{
		x = head->data;
		while (P->next != head)
		{
			P = P->next;
		}
		if (P == head)         // i.e head is the only Node,            P will stop on first Node itself
		{			
			delete head;
			head = NULL;
			return x;
		}
		else                       
		{
			P->next = head->next;
			delete head;
			head = P->next;
			return x;
		}
	}

	else
	{
		for (int i = 0; i < index - 2; i++)
		{
			P = P->next;
		}
		struct Node* Q = P->next;
		P->next = Q->next;
		x = Q->data;
		delete Q;
		Q = NULL;
		return x;

	}
}

// Count

int count(struct Node* P)
{
	int i = 0;

	do
	{
		i++;
		P = P->next;

	} while (P != head);
	return i;
}


void data()
{
	/*display_i(P);
	cout << "\nCircular Linked List : ";
	display_r(P);*/

	/*
	insert(head, 0, 121);									    // Insert Modifies head.
	display_r(head);											// Here I can't use 'P' , as "head" is Modified and 'P' contains address of old 'head'.
	*/


}