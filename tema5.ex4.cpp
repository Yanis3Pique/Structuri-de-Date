#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

Node* interclasare(Node* l1, Node* l2) {
    Node* res = nullptr;
    Node* tail = nullptr;

    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->val < l2->val) {
        res = tail = l1;
        l1 = l1->next;
    } else {
        res = tail = l2;
        l2 = l2->next;
    }

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != nullptr) tail->next = l1;
    if (l2 != nullptr) tail->next = l2;

    return res;
}

void afisare_lista(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n, m;
    cout << "Dati lungimea primei liste: ";
    cin >> n;
    cout << "Dati lungimea celei de-a doua lista: ";
    cin >> m;

    Node* l1 = nullptr;
    Node* l2 = nullptr;

    cout << "Dati elementele listei 1: ";
    int x;
    cin >> x;
    l1 = new Node(x);
    Node* p = l1;
    for (int i = 1; i < n; i++) {
        cin >> x;
        p->next = new Node(x);
        p = p->next;
    }

    cout << "Dati elementele listei 2: ";
    cin >> x;
    l2 = new Node(x);
    p = l2;
    for (int i = 1; i < m; i++) {
        cin >> x;
        p->next = new Node(x);
        p = p->next;
    }

    Node* res = interclasare(l1, l2);

    afisare_lista(res);

    while (res != nullptr) {
        Node* tmp = res;
        res = res->next;
        delete tmp;
    }

    return 0;
}
