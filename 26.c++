#include <iostream>
using namespace std;

class Rectangle
{
    int length, breadth;

public:
    void getData()
    {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
    }

    int area()
    {
        return length * breadth;
    }
};

int main()
{
    Rectangle r;

    r.getData();  
    cout << "Area of Rectangle = " << r.area();

    return 0;
}