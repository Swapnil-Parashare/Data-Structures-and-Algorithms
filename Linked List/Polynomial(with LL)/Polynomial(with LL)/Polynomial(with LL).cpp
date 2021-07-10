
#include <iostream>

using namespace std;

struct Node
{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* Poly;                            // Global First Pointer


// Create

void create()                                 // Concentrate on this Function
{
    struct Node* t;
    struct Node* last = NULL;

    int num;

    cout << "Enter Total Number of Terms : ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        t = new Node;
        cout << "\nEnter Coefficient and Exponent of Term " << i + 1 << endl;
        cin >> t->coeff >> t->exp ;
        t->next = NULL;


        if (Poly == NULL)
        {
            Poly = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }

    }
}

// Display

void display()
{
    cout << endl;

    Node* q = Poly;

    while (q)
    {
        cout << q->coeff << "x" << q->exp;
        if (q->next) cout << " + ";
        q = q->next;
    }
}

// Evaluate

int evaluate(int x)
{
    int sum = 0;
    Node* q = Poly;

    while (q)
    {
        sum += q->coeff * pow(x, q->exp);
        q = q->next;
    }
    return sum;

}


int main()
{
    create();
    display();
    cout << "\nFinal Value : " << evaluate(2) << endl;
}
