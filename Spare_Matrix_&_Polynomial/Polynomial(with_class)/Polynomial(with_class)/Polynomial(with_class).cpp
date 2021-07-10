#include <iostream>

using namespace std;

class element
{
public :

    int coeff;
    int exp;
};

class poly
{
private:

    int n;
    class element* t;

public:

    poly(int n)
    {
        this->n = n;
        this->t = new class element[this->n];
    }

    ~poly()
    {
        delete[]t;
    }

    poly operator+(const poly& rhs);
	friend istream& operator>>(istream& is, poly& s);
	friend ostream& operator<<(ostream& os, poly& s);
};

poly poly::operator+(const poly& rhs)
{
	int i, j, k;
	i = j = k = 0;

    class poly* P3;
	P3 = new class poly(n + rhs.n);
	


	while (i < n && j < rhs.n)
	{
		if (t[i].exp   > rhs.t[j].exp)
			P3->t[k++] = t[i++];

		else if (t[i].exp < rhs.t[j].exp)
			P3->t[k++] = rhs.t[j++];

		else
		{
			P3->t[k].exp = t[i].exp;
			P3->t[k++].coeff = t[i++].coeff + rhs.t[j++].coeff;
		}
	}

	for (; i < n; i++) P3->t[k++] = t[i];
	for (; j < rhs.n; j++) P3->t[k++] = rhs.t[j];
	P3->n = k;

	return *P3;
}


istream& operator>>(istream& is, poly& s)
{
	for (int i = 0; i < s.n; i++)
	{
		cout << "\nEnter Data of Element " << i + 1 << endl;
		cout << "\nCoefficient : ";
		cin >> s.t[i].coeff;
		cout << "\nExponent : ";
		cin >> s.t[i].exp;
	}
	return is;
}

ostream& operator<<(ostream& os, poly& s)
{
	cout << "\n\n Polynomial : ";

	for (int i = 0; i < s.n; i++)
	{
		cout << s.t[i].coeff << "x" << s.t[i].exp;
		if (i != (s.n - 1))
			cout << " + ";

	}
	cout << endl;
	return os;
}







int main()
{
	cout << "\nEnter Data for Polynomial 1 : \n" << endl;
	cout << "\nEnter Total Number of Non-Zero Elements : ";
	int x;
	cin >> x;
	class poly* P1;
	P1 = new class poly(x);             // Here x is arugument to parametrized constructor , Dynamic memory is allocated for single object of class poly only.

	cin >> *P1;




	cout << "\nEnter Data for Polynomial 2 : \n" << endl;
	cout << "\nEnter Total Number of Non-Zero Elements : ";
	int y;
	cin >> y;
	class poly* P2;
	P2 = new class poly(y);			     // Here y is arugument to parametrized constructor, Dynamic memory is allocated for single object of class poly only.

	cin >> *P2;

	
	class poly P3 = *P1 + *P2 ;
	


	

	cout << *P1;
	cout << *P2; 
	cout << P3;


	// Note : 1]P1 and P2 are pointers to object , But argument should be passed by value, hence * is used.
	//        2]P3 is actually an Object, also "+" operator overloaded function returns an object, hence P3 is passed as it is.
}

 
