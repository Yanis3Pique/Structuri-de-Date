#include <iostream>
#include <fstream>
using namespace std;
ifstream f("input.in");

int partitie(int v[], int start, int finish)
{
	int pivot = v[start];
	int counter = 0;
	for (int i = start + 1; i <= finish; i++) {
		if (v[i] <= pivot)
			counter++;
	}
	int i_pivot = start + counter;
	swap(v[i_pivot], v[start]);
	int i = start, j = finish;
	while (i < i_pivot && j > i_pivot) {
		while (v[i] <= pivot) {
			i++;
		}
		while (v[j] > pivot) {
			j--;
		}
		if (i < i_pivot && j > i_pivot) {
			swap(v[i++], v[j--]);
		}
	}
	return i_pivot;
}

void quickSort(int v[], int start, int finish)
{
	if (start >= finish) return;
	int p = partitie(v, start, finish);
	quickSort(v, start, p - 1);
	quickSort(v, p + 1, finish);
}

int main()
{
    ///int v[] = {5, 4, 3, 2, 10, 8, 9, 6, 7, 1, 3, 5}, x, i = 0;
	int v[10001], x, i = 0;
	///int v_size = sizeof(v) / sizeof(v[0]);
	int v_size = 10001;
	while (f >> x)
    {
        v[i] = x;
        i++;
    }
	cout << "Vectorul nesortat este:" << endl;
	for (i = 0; i < v_size; i++)
		cout << v[i] << " ";
    cout << endl << endl;
	quickSort(v, 0, v_size - 1);
	cout << "Vectorul sortat este:" << endl;
	for (i = 0; i < v_size; i++)
		cout << v[i] << " ";
	return 0;
}
