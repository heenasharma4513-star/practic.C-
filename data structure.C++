
 #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertBefore(Node*& head, int x, int y) {
    if (head == NULL) return;

    if (head->data == x) {
        Node* newNode = new Node(y);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* p = head;

    while (p->next != NULL && p->next->data != x) {
        p = p->next;
    }

    if (p->next == NULL) return;

    Node* newNode = new Node(y);
    newNode->next = p->next;
    p->next = newNode;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(25);
    head->next->next = new Node(30);
    head->next->next->next = new Node(11);

    display(head);

    insertBefore(head, 25, 101);

    display(head);

    return 0;
}