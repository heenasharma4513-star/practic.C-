#include <iostream>
using namespace std;

class patientqueue
{
    struct Node
    {
        int patientId;
        Node* next;
    };

    Node* head;

    bool isEmpty()
    {
        return head == nullptr;
    }

public:
    patientqueue()
    {
        head = nullptr;
    }

    // Emergency patient (insert at beginning)
    void addEmg(int id)
    {
        Node* newNode = new Node{id, head};
        head = newNode;
        cout << "Emergency patient added: " << id << endl;
    }

    // Regular patient (insert at end)
    void addReg(int id)
    {
        Node* newNode = new Node{id, nullptr};

        if (isEmpty())
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        cout << "Regular patient added: " << id << endl;
    }

    // Insert at position
    void insert(int id, int pos)
    {
        if (pos <= 0)
        {
            addEmg(id);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node{id, temp->next};
        temp->next = newNode;

        cout << "Patient admitted: " << id << endl;
    }

    // Remove first patient
    void dischargeFirst()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Patient discharged: " << temp->patientId << endl;
        delete temp;
    }

    // Reverse list
    void reverseList()
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Display queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Patient Queue: ";

        while (temp != nullptr)
        {
            cout << temp->patientId << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    patientqueue pq;

    pq.addReg(101);
    pq.addReg(102);
    pq.addEmg(201);
    pq.insert(150, 2);

    pq.display();

    pq.dischargeFirst();

    pq.display();

    pq.reverseList();

    cout << "After reversing: ";
    pq.display();

    return 0;
}