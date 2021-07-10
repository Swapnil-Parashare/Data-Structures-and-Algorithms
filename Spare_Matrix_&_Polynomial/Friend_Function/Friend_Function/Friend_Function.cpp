
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

    friend Box add(Box B1, Box B2);                                                       // Its not the member function of the class.
    
};

Box add(Box B1, Box B2)                                                                   // Our Friend Function.
{
    Box B3;
    B3.length = B1.length + B2.length;
    B3.breadth = B1.breadth + B2.breadth;
    B3.height = B1.height + B2.height;
    return B3;
}


int main()
{
    Box B1(1, 2, 3);
    Box B2(4, 5, 6);
    B1.display();
    B2.display();

    Box B3 = add(B1, B2);                                                              // It can be called without the help of any object. 
    B3.display();
    return 0;
}