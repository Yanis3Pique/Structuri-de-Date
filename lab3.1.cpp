#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int MAX_HEAP_SIZE = 100;

void buildMinHeap(int v[], int n);
void heapify(int v[], int n, int i);
void insert(int v[], int& n, int val);
int findMin(int v[], int n);
void displayHeap(int v[], int n);

int main() {
    int v[MAX_HEAP_SIZE], n = 0, x;
    buildMinHeap(v, n);
    int option = 0;
    do {
        cout << "\nPlease choose an option:\n";
        cout << "1. Insert a value\n";
        cout << "2. Find the minimal value\n";
        cout << "3. Display the heap\n";
        cout << "4. Exit\n";
        cin >> option;
        switch (option) {
            case 1: {
                int val;
                cout << "Enter a value to insert: ";
                cin >> val;
                insert(v, n, val);
                cout << "Value inserted.\n";
                break;
            }
            case 2: {
                int min_val = findMin(v, n);
                if (min_val != -1) {
                    cout << "Minimal value: " << min_val << "\n";
                } else {
                    cout << "Heap is empty.\n";
                }
                break;
            }
            case 3: {
                displayHeap(v, n);
                break;
            }
            case 4: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid option.\n";
            }
        }
    } while (option != 4);
    return 0;
}

void buildMinHeap(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
}

void heapify(int v[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && v[left] < v[smallest]) {
        smallest = left;
    }
    if (right < n && v[right] < v[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(v[i], v[smallest]);
        heapify(v, n, smallest);
    }
}

void insert(int v[], int& n, int val) {
    if (n == MAX_HEAP_SIZE) {
        cout << "Heap is full.\n";
        return;
    }
    v[n++] = val;
    int i = n - 1;
    while (i > 0 && v[(i - 1) / 2] > v[i]) {
        swap(v[i], v[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int findMin(int v[], int n) {
    if (n == 0) {
        return -1;
    }
    return v[0];
}

void displayHeap(int v[], int n) {
    cout << "Heap: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

