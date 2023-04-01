#include <iostream>
#include <list>

using namespace std;

list<int> multiply(list<int> num, int digit) {
    list<int> result;

    int carry = 0;
    for (auto it = num.begin(); it != num.end(); ++it) {
        int product = (*it) * digit + carry;
        result.push_back(product % 10);
        carry = product / 10;
    }

    if (carry != 0) {
        result.push_back(carry);
    }

    return result;
}

int main()
{
    string input;
    cin >> input;

    list<int> num;
    for (int i = input.length() - 1; i >= 0; --i) {
        num.push_back(input[i] - '0');
    }

    int digit;
    cin >> digit;

    list<int> result = multiply(num, digit);
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        cout << (*it);
    }
    cout << endl;

    return 0;
}
