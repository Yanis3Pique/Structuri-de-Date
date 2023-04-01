#include <iostream>
#include <fstream>
using namespace std;
ifstream f("input.in");

void merge(int array[], int const left, int const mid, int const right)
{
    int i, j;
	int const s1 = mid - left + 1;
	int const s2 = right - mid;
    int *stanga = new int[s1], *dreapta = new int[s2];
	for (i = 0; i < s1; i++)
		stanga[i] = array[left + i];
	for (j = 0; j < s2; j++)
		dreapta[j] = array[mid + 1 + j];
	int i_s1 = 0, i_s2 = 0;
	int i_final = left;
	while (i_s1 < s1 && i_s2 < s2) {
		if (stanga[i_s1] <= dreapta[i_s2])
        {
			array[i_final] = stanga[i_s1];
			i_s1++;
		}
		else
		{
			array[i_final] = dreapta[i_s2];
			i_s2++;
		}
		i_final++;
	}
	while (i_s1 < s1)
    {
		array[i_final] = stanga[i_s1];
		i_s1++;
		i_final++;
	}
	while (i_s2 < s2) {
		array[i_final] = dreapta[i_s2];
		i_s2++;
		i_final++;
	}
	delete[] stanga;
	delete[] dreapta;
}

void mergeSort(int v[], int const start, int const finish)
{
	if (start >= finish) return;
	int mid = start + (finish - start) / 2;
	mergeSort(v, start, mid);
	mergeSort(v, mid + 1, finish);
	merge(v, start, mid, finish);
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
	mergeSort(v, 0, v_size - 1);
	cout << "Vectorul sortat este:" << endl;
	for (i = 0; i < v_size; i++)
		cout << v[i] << " ";
	return 0;
}
