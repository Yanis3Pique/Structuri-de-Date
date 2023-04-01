#include <iostream>
#include <iomanip>

using namespace std;

/*
struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* lastNode = *head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void insertAverage(Node* prev, Node* current) {
    double average = (double)(prev->data + current->data) / 2.0;
    Node* newNode = new Node;
    newNode->data = average;
    newNode->next = current;
    prev->next = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertNode(&head, value);
    }

    Node* current = head;
    Node* nextNode = current->next;

    while (current->next != nullptr) {
        insertAverage(current, current->next);
        current = current->next->next;
    }


    printList(head);

    return 0;
}
/// Codul acesta a fost pentru numere intregi
*/

struct Node {
    double data;
    Node* next;
};

void insertNode(Node** head, double value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* lastNode = *head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void insertAverage(Node* prev, Node* current) {
    double average = (double)(prev->data + current->data) / 2.0;
    Node* newNode = new Node;
    newNode->data = average;
    newNode->next = current;
    prev->next = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        double value;
        cin >> value;
        insertNode(&head, value);
    }

    Node* current = head;
    Node* nextNode = current->next;

    while (current->next != nullptr) {
        insertAverage(current, current->next);
        current = current->next->next;
    }


    printList(head);

    return 0;
}
/// Codul acesta a fost pentru numere rationale
