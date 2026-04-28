#include <iostream>
using namespace std;
class test;
{
    int x=10;
    double y=10;
    Public:
    void sum(int z)
    {
        cout<<x+z;

    }
    //overloading types
    void add(double a)
    {
        cout<<y+a;

    }
    //NUMBER OF PARAMETER
    void add(int m ;int n)
    {
        cout<=x+m+n;
    }
};
int main()
{
    test obj;
    obj.add(50);
    obj.add(50.2);
    obi(10,20);
    return 0;
}
