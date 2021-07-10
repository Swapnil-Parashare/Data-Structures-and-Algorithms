
#include <iostream>

using namespace std;

int input1(void);
int input2(void);
double e(double x, double n);
double i_e(double x, double n);



int main()
{
    cout << "Answer using Recursion : " << e(input1(), input2());
    cout << "Answer using Iteration : " << i_e(input1(), input2());
}

int input1(void)
{
    cout << "Please Enter the Power of 'e' : ";
    int x;
    cin >> x;
    return x;
}

int input2(void)
{
    cout << "\nPlease Enter the Precision : ";
    int x;
    cin >> x;
    return x;
}


// Recursive Function for Taylor Series With Horner's Rule

double e(double x, double n)
{
    static double s = 1;

    if (n == 0)
        return s;
    else
    {
        s = 1 + (x/n)*s ;
        return e(x, n - 1);
    }


}


// Iterative Function For Taylor Series With Horner's Rule

double i_e(double x, double n)
{
    double s = 1;
    while(n > 0)
    {
        s = 1 + (x / n) * s;   
        n--;
    }
    return s;

}


