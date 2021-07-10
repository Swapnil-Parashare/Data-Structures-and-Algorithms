#include <iostream>

using namespace std;

class Element
{
public:

	int i;
	int j;
	int x;
};

class Sparse
{
private:

	int m;
	int n;
	int num;
	Element* ele;

public:

	Sparse(int m, int n, int num)                                  // It is Parametrized constructor.
	{															   // It initializes our Class Data members with the arguments given to it.
		this->m = m;											   // It only allocates the Dynamic memory to our class data member(i.e Pointer) and does not initializes it.
		this->n = n;                                               // Unlikely to our Structural "Initializer" concept.
		this->num = num;
		ele = new Element[this->num];
	}

	~Sparse()
	{
		delete[] ele;
	}

	Sparse operator+(Sparse& s);

	friend istream& operator>>(istream& is, Sparse& s);
	friend ostream& operator<<(ostream& os, Sparse& s);


};

Sparse Sparse::operator+(Sparse& s)                                 // It Returns "Spare" Object, 'Spare::' is just Scope Resolution, Function name is 'operator+'.
{																	// Parametre is 'Spare &s', it means "Spare Object" but pass by reference.
	int i, j, k;                                                    // It is not pass by value(Spare s) or pass by address(Spare *s), its pass by reference(Spare &s).


	if (m != s.m || n != s.n)                                       // Just check for false conditions
		return Sparse(0, 0, 0);


	Sparse* sum = new Sparse(m, n, num + s.num);

	i = j = k = 0;
	while (i < num && j < s.num)
	{
		if (ele[i].i < s.ele[j].i)
			sum->ele[k++] = ele[i++];
		else if (ele[i].i > s.ele[j].i)
			sum->ele[k++] = s.ele[j++];
		else
		{
			if (ele[i].j < s.ele[j].j)
				sum->ele[k++] = ele[i++];
			else if (ele[i].j > s.ele[j].j)
				sum->ele[k++] = s.ele[j++];
			else
			{
				sum->ele[k] = ele[i];
				sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
			}
		}
	}

	for (; i < num; i++)sum->ele[k++] = ele[i];
	for (; j < s.num; j++)sum->ele[k++] = s.ele[j];

	sum->num = k;

	return *sum;

}
istream& operator>>(istream& is, Sparse& s)
{
	cout << "\nEnter Non-Zero Elements : " << endl;
	for (int i = 0; i < s.num; i++)
	{
		cout << "\nRow     : ";
		is >> s.ele[i].i;
		cout << "\nColumn  : ";
		is >> s.ele[i].j;
		cout << "\nElement : ";
		is >> s.ele[i].x;
	}
	return is;
}
ostream& operator<<(ostream& os, Sparse& s)
{
	int k = 0;
	for (int i = 1; i <= s.m; i++)
	{
		for (int j = 1; j <= s.n; j++)
		{
			if (s.ele[k].i == i && s.ele[k].j == j)
				os << s.ele[k++].x << " ";
			else
				os << "0 ";
		}
		cout << endl;
	}
	return os;
}

int main()
{	
	cout << "\nEnter Data of Matrix 1 : " << endl;
	int i, j, k;
	cout << "\nTotal Rows     : ";
	cin >> i;
	cout << "\nTotal Columns  : ";
	cin >> j;
	cout << "\nTotal Nonzero-Elements : ";
	cin >> k;
	Sparse s1(i, j, k);
	cin >> s1;
	
	cout << "\n\n\nEnter Data of Matrix 2 : " << endl;
	cout << "\nTotal Rows     : ";
	cin >> i;
	cout << "\nTotal Columns  : ";
	cin >> j;
	cout << "\nTotal Nonzero-Elements : ";
	cin >> k;
	Sparse s2(i, j, k);
	cin >> s2;
	
	Sparse sum = s1 + s2;

	cout << "\nFirst Matrix : \n" << endl << s1;
	cout << "\nSecond Matrix : \n" << endl << s2;
	cout << "\nSum Matrix : \n" << endl << sum;

	return 0;
}