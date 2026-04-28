#include <iostream>
using namespace std;
int main() {
    int arr[5] = {3,7,2,9,1}, max = arr[0];
    for(int i = 1; i < 5; i++)
        if(arr[i] > max)
            max = arr[i];
    cout << "Max = " << max;
    return 0;
}
