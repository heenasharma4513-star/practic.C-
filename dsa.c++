#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> list1 = {1, 2, 3};
    list<int> list2 = {4, 5, 6}; 

    // Sort both lists (important)
    list1.sort();
    list2.sort();

    // Merge list2 into list1
    list1.merge(list2);

    // Display merged list
    cout << "Merged List: ";
    for (int x : list1) {
        cout << x << " ";
    }

    return 0;
}