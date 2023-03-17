///Sa se scrie un program pentru ordonarea descrescatoare a unui sir de
///n numere folosind sortarea prin selectie (Selection Sort).
///Input: n, n elemente in ordine arbitrara stocate intr-un vector.
///Output: vector continand elementele in ordine sortata.

#include <iostream>
using namespace std;
int main()
{
    int n, i , j, minim, temp;
    cout << "n = ";
    cin >> n;
    int  v[n+1];
    cout << "Dati elementele vectorului: " << endl;
    for (i=0;i<n;i++)
    {
        cin >> v[i];
    }
    for (i=0;i<n-1;i++)
    {
        minim = i;
        for (j=i+1;j<n;j++)
        {
          if (v[j] < v[minim]) minim = j;
        }
        if (minim!=i)
        {
            temp = v[minim];
            v[minim] = v[i];
            v[i] = temp;
        }
    }
    for (i=0;i<n;i++)
    {
        cout << v[i] << " ";
    }
}
