#include <iostream>

using namespace std;


/*

// Normal Class 

class Weight
{
private: 
    int Kg;

public:

    void set_data(int x)
    {
        Kg = x;
    }

    int get_data()
    {
        return Kg;
    }
};


*/

// Template Class

template <typename T>

class Weight
{
private:
    T Kg;

public:

    void set_data(T x)
    {
        Kg = x;
    }

    T get_data()
    {
        return Kg;
    }
};



int main()
{
     Weight <double> W1;

    double x;
    cout << "\nEnter Weight : ";
    cin >> x;

    W1.set_data(x);

    cout << "\nWeight : " << W1.get_data() << endl;
}
