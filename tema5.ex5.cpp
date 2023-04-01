#include <iostream>
#include <list>

using namespace std;

list<int> addLists(list<int> num1, list<int> num2) {
    list<int> result;
    int carry = 0;
    auto it1 = num1.begin(), it2 = num2.begin();

    while (it1 != num1.end() || it2 != num2.end()) {
        int sum = carry;
        if (it1 != num1.end()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.end()) {
            sum += *it2;
            ++it2;
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry > 0) {
        result.push_back(carry);
    }
    return result;
}

int main()
{
    list<int> num1 = {2, 4, 5};
    list<int> num2 = {4, 3};
    list<int> result = addLists(num1, num2);
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        cout << *it;
    }
    cout << endl;

    num1 = {9, 1};
    num2 = {1, 1};
    result = addLists(num1, num2);
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        cout << *it;
    }
    cout << endl;

    num1 = {9, 9, 9};
    num2 = {1};
    result = addLists(num1, num2);
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        cout << *it;
    }
    cout << endl;

    return 0;
}
