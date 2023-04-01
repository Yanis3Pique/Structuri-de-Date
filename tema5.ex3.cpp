#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

/*
void insert(Node *&head, int x) {
    Node *node = new Node(x);
    node->next = head;
    head = node;
}

void reverseList(Node *&head) {
    Node *newHead = NULL;
    Node *current = head;

    while (current != NULL) {
        Node *next = current->next;
        current->next = newHead;
        newHead = current;
        current = next;
    }

    head = newHead;
}

void printList(Node *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);

    cout << "Lista initiala: ";
    printList(head);

    reverseList(head);

    cout << "Lista inversata: ";
    printList(head);

    return 0;
}
/// Codul acesta este cu lista auxiliara
*/

void insert(Node *&head, int x) {
    Node *node = new Node(x);
    node->next = head;
    head = node;
}

void reverseList(Node *&head) {
    Node *prev = NULL;
    Node *current = head;

    while (current != NULL) {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void printList(Node *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);

    cout << "Lista initiala: ";
    printList(head);

    reverseList(head);

    cout << "Lista inversata: ";
    printList(head);

    return 0;
}
/// Codul acesta este fara lista auxiliara
