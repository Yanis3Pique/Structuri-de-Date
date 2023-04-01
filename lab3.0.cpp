#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream f("input.in");

void countSort(vector<int>& v) {
    int max_val = *max_element(v.begin(), v.end());
    int min_val = *min_element(v.begin(), v.end());
    int range = max_val - min_val + 1;
    vector<int> count(range);
    vector<int> output(v.size());
    for (int i = 0; i < v.size(); i++) {
        count[v[i] - min_val]++;
    }
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        output[count[v[i] - min_val] - 1] = v[i];
        count[v[i] - min_val]--;
    }
    for (int i = 0; i < v.size(); i++) {
        v[i] = output[i];
    }
}

int main() {
    int x, i = 0, v_size = 10001;
    int v[v_size + 1];
    while (f >> x) {
        v[i] = x;
        i++;
    }
    cout << "Vectorul nesortat este:" << endl;
    for (i = 0; i < v_size; i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;
    vector<int> v_vec(v, v + v_size);
    countSort(v_vec);
    cout << "Vectorul sortat este:" << endl;
    for (i = 0; i < v_size; i++) {
        cout << v_vec[i] << " ";
    }
    return 0;
}
