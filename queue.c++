#include <iostream>
#define MAX 5
using namespace std;

class Queue
{
    int arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if(rear == MAX-1)
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            if(front == -1)
                front = 0;   // first element

            rear++;
            arr[rear] = value;

            cout << value << " inserted\n";
        }
    }

    void dequeue()
    {
        if(front == -1 || front > rear)
        {
            cout << "Queue Underflow\n";
        }
        else
        {
            cout << arr[front] << " deleted\n";
            front++;

            // reset queue when empty
            if(front > rear)
            {
                front = rear = -1;
            }
        }
    }

    void display()
    {
        if(front == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Queue elements: ";
            for(int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}