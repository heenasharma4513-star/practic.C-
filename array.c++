#include <iostream>
using namespace std;

class inventory
{
    int size, capacity;
    int item[100];   // encapsulated primitive data

    bool isvalidindex(int index)
    {
        return index >= 0 && index < size;
    }

public:
    inventory(int cap = 100)
    {
        capacity = cap;
        size = 0;
    }

    // Insert at end
    void insert(int value)
    {
        if (size >= capacity)
        {
            cout << "Inventory Full\n";
            return;
        }
        item[size++] = value;
    }

    // Insert at specific index
    void insertat(int index, int value)
    {
        if (size >= capacity || index < 0 || index > size)
        {
            cout << "Invalid Position\n";
            return;
        }

        for (int i = size; i > index; i--)
        {
            item[i] = item[i - 1];
        }

        item[index] = value;
        size++;   // correct increment
    }

    // Update value
    void update(int index, int value)
    {
        if (!isvalidindex(index))
        {
            cout << "Invalid Index\n";
            return;
        }

        item[index] = value;
    }

    // Display inventory
    void display()
    {
        if (size == 0)
        {
            cout << "Inventory Empty\n";
            return;
        }

        cout << "Inventory Items: ";
        for (int i = 0; i < size; i++)
        {
            cout << item[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    inventory inv(10);

    inv.insert(100);
    inv.insert(200);
    inv.insert(300);

    inv.insertat(1, 150);   // insert at index 1
    inv.update(2, 250);     // update index 2

    inv.display();

    return 0;
}