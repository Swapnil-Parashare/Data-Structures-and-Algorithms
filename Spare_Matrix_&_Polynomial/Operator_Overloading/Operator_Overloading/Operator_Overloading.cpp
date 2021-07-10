
#include <iostream>

using namespace std;

class Box
{
private: 

    int length;
    int breadth;
    int height;

public:

    Box(int length, int breadth, int height)
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    Box()
    {
        length = 0;
        breadth = 0;
        height = 0;
    }

    int volume(void)
    {
        return length * breadth * height;
    }

    void display()
    {
        cout << "\nLength  : " << length << endl;
        cout << "Breadth : " << breadth << endl;
        cout << "Height  : " << height << endl;
        cout << "Volume of Box : " << volume() << endl;
    }

    Box operator+(const Box& rhs)
    {
        Box B3;
        B3.length = length + rhs.length;
        B3.breadth = breadth + rhs.breadth;
        B3.height = height + rhs.height;
        return B3;
    }
};


int main()
{
    Box B1(1,2,3);
    Box B2(4,5,6);
    B1.display();
    B2.display();

    Box B3 = B1 + B2;
    B3.display();
}
