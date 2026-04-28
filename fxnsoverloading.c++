#include <iostream>
using namespace std;

class test
{
    int x = 10;
    double y = 10;

public:
    void sum(int z)
    {
        cout << x + z << endl;
    }

    // overloading types
    void add(double a)
    {
        cout << y + a << endl;
    }

    // number of parameters
    void add(int m, int n)
    {
        cout << x + m + n << endl;
    }
};

int main()
{
    test obj;

    obj.sum(5);        // calls sum
    obj.add(50);       // calls double version (int converts to double)
    obj.add(50.2);     // calls double version
    obj.add(10, 20);   // calls int,int version

    return 0;
}
