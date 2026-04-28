#include <iostream>
using namespace std;

int main()
{
    int i, j, n = 5, num;

    for(i = 0; i < n; i++)
    {
        num = 1;
        for(j = 0; j <= i; j++)
        {
            cout << num;
            num = num * (i - j) / (j + 1);
        }
        cout << endl;
    }

    return 0;
}