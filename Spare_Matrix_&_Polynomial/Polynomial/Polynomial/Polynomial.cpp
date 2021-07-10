
#include <iostream>

using namespace std;

struct element
{
	int coeff;
	int exp;
};

struct poly
{
	int n;
	struct element* t;
};

void initialize(struct poly* P1)
{
	cout << "\nEnter Total Number of Non-Zero Elements : ";
	cin >> P1->n;

	P1->t = new struct element[P1->n];

	for (int i = 0; i < P1->n; i++)
	{
		cout << "\nEnter Data of Element " << i + 1 << endl;
		cout << "\nCoefficient : ";
		cin >> P1->t[i].coeff;
		cout << "\nExponent : ";
		cin >> P1->t[i].exp;
	}

}

void display(struct poly P1)
{
	cout << "\n\n Polynomial : ";

	for (int i = 0; i < P1.n; i++)
	{		
		cout << P1.t[i].coeff << "x"<< P1.t[i].exp ;
		if(i!=(P1.n - 1))
			cout << " + ";

	}
	cout << endl;

}


struct poly* add(struct poly* P1, struct poly* P2)
{
	struct poly* P3;
	P3 = new struct poly[1];
	P3->t = new struct element[P1->n + P2->n];

	int i, j, k;
	i = j = k = 0;

	while (i < P1->n && j < P2->n)
	{
		if (P1->t[i].exp > P2->t[j].exp)
			P3->t[k++] = P1->t[i++];

		else if (P1->t[i].exp < P2->t[j].exp)
			P3->t[k++] = P2->t[j++];

		else
		{
			P3->t[k].exp = P1->t[i].exp;
			P3->t[k++].coeff = P1->t[i++].coeff + P2->t[j++].coeff;
		}
	}

	for(; i < P1->n ; i++) P3->t[k++] = P1->t[i];
	for(; j < P2->n ; j++) P3->t[k++] = P2->t[j];
	P3->n = k;

	return P3;
}

int main()
{
	struct poly* P1;
	P1 = new struct poly[1];
	cout << "\nEnter Data for Polynomial 1 : \n" << endl;
	initialize(P1);

	struct poly* P2;
	P2 = new struct poly[1];
	cout << "\n\n\nEnter Data for Polynomial 2 : \n" << endl;
	initialize(P2);

	struct poly* P3;
	P3 = new struct poly[1];

	P3 = add(P1, P2);

	display(*P1);
	display(*P2);
	display(*P3);

}
