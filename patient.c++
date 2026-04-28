#include <iostream>
using namespace std;

// Hospital Patient Queue System using Linked List
class PatientQueue
{
private:
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
    PatientQueue()
    {
        head = nullptr;
    }

    // Insert Emergency Patient (Beginning)
    void addEmg(int id)
    {
        Node* newNode = new Node{id, head};
        head = newNode;
        cout << "Emergency Patient Admitted: " << id << endl;
    }

    // Insert Regular Patient (End)
    void addReg(int id)
    {
        Node* newNode = new Node{id, nullptr};

        if (isEmpty())
        {
            head = newNode;
            cout << "Regular Patient Admitted: " << id << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        cout << "Regular Patient Admitted: " << id << endl;
    }

    // Delete First Patient
    void dischargeFirst()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Patient Discharged: " << temp->patientId << endl;
        delete temp;
    }

    // Search Patient
    void search(int id)
    {
        Node* temp = head;

        while (temp != nullptr)
        {
            if (temp->patientId == id)
            {
                cout << "Patient Found: " << id << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Patient Not Found" << endl;
    }

    // Update Patient ID at position
    void update(int pos, int newId)
    {
        Node* temp = head;

        for (int i = 0; i < pos && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        temp->patientId = newId;
        cout << "Patient Updated" << endl;
    }

    // Reverse Queue
    void reverse()
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
        cout << "Queue Reversed" << endl;
    }

    // Count Patients
    void count()
    {
        int c = 0;
        Node* temp = head;

        while (temp != nullptr)
        {
            c++;
            temp = temp->next;
        }

        cout << "Total Patients: " << c << endl;
    }

    // Display Queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node* temp = head;

        cout << "Patient Queue: ";

        while (temp != nullptr)
        {
            cout << temp->patientId << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    PatientQueue pq;

    pq.addReg(102);
    pq.addReg(103);
    pq.addEmg(101);

    pq.display();

    pq.search(102);

    pq.update(1, 200);

    pq.display();

    pq.count();

    pq.reverse();

    pq.display();

    pq.dischargeFirst();

    pq.display();

    return 0;
}