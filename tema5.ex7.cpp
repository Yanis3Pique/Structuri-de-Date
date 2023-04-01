#include <iostream>
#include <list>
using namespace std;

list<int> multiply(list<int> num1, list<int> num2) {
    list<int> result(num1.size() + num2.size(), 0);
    list<int>::iterator it1 = num1.begin(), it2 = num2.begin(), res_it = result.begin();

    for (int i = 0; it2 != num2.end(); ++it2, ++i) {
        int carry = 0;
        list<int>::iterator temp_res_it = res_it;

        for (it1 = num1.begin(); it1 != num1.end(); ++it1, ++temp_res_it) {
            int prod = (*it1) * (*it2) + carry + (*temp_res_it);
            carry = prod / 10;
            *temp_res_it = prod % 10;
        }

        if (carry > 0) {
            *temp_res_it += carry;
        }

        ++res_it;
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    result.reverse();
    return result;
}

int main() {
    string str_num1, str_num2;
    cout << "Enter two positive integers: ";
    cin >> str_num1 >> str_num2;

    list<int> num1, num2;
    for (char c : str_num1) {
        num1.push_front(c - '0');
    }
    for (char c : str_num2) {
        num2.push_front(c - '0');
    }

    list<int> result = multiply(num1, num2);
    cout << "Product: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
