                            
                                    /**************************     Creation & Display      ********************************/    

#include <iostream>

using namespace std;

struct Element
{
    int i;
    int j;
    int x;

};


class Spare
{
private:

    int m;
    int n;
    int num;
    struct Element* e;

public:

    Spare();
    void dispaly();
    ~Spare()
    {
        delete[]e;
    }
};

int main()
{
    class Spare A1;
    A1.dispaly();
}

// Constructor 

Spare::Spare()
{
    cout << "\nEnter Number of Rows of Spare Matrix : ";
    cin >> m;

    cout << "\nEnter Number of Columns of Spare Matrix : ";
    cin >> n;

    cout << "\nEnter Total Number of Non-Zero Elements : ";
    cin >> num;

    e = new struct Element[num];

    cout << "\nNote : Data should be Entered in Sequence of Elements as they occured in Matrix" << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter the Data of Element " << i + 1 << endl;
        cout << "\nRow : ";
        cin >> e[i].i;
        cout << "\nColumn : ";
        cin >> e[i].j;
        cout << "\nElement : ";
        cin >> e[i].x;
    }

}

// Display

void Spare::dispaly()
{
    cout << "\nSparse Matrix : \n" << endl;

    int i, j, k = 0;

    for ( i = 1 ; i <= m ;i++)
    {
        cout << "\t";
        for ( j = 1 ; j <= n ;j++)
        {
            if (i == e[k].i && j == e[k].j)
            {
                cout << e[k].x << " ";
                k++;
            }
            else
            {
                cout << 0 << " ";

            }

        }
        cout << endl;
    }
}


