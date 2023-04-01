#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNodeSorted(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (*head == nullptr || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != nullptr && current->next->data <= value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
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
        insertNodeSorted(&head, value);
    }

    printList(head);

    return 0;
}
