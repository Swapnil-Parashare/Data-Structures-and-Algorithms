#include <iostream>

using namespace std;



// Function overloading 

int add(int x, int y)
{
    return x + y;
}

float add(float x, float y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}
 

// NOTE :- Instead of Overloading Function for number of times we can write a single "Function Template"


// Function Template

template <typename T>

T add(T x, T y)
{
    return (x + y);
}


int main()
{
    double x, y;
    cout << "\nEnter two numbers to be added: ";
    cin >> x >> y;
    cout << "\nAddition : " << add<double>(x, y) << endl;
}

