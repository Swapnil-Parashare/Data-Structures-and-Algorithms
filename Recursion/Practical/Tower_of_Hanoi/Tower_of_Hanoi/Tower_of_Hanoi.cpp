
#include <iostream>

using namespace std;

void TOH(int n, int A, int B, int C);
int input(void);


int main()
{
    TOH(input(),1,2,3) ;
}

int input(void)
{
    cout << "\nPlease Enter the Number of Disc : ";
    int x;
    cin >> x;
    return x;

}

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "(" << A << "," << C << ")" << endl;
        TOH(n - 1, B, A, C);
    }
}