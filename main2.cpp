///Sa se scrie un program pentru ordonarea crescatoare a unui sir de n
///numere folosind sortarea prin insertie (Insertion Sort).
///Input: n, n elemente in ordine arbitrara stocate intr-un vector.
///Output: vector continand elementele in ordine sortata.

#include <iostream>
using namespace std;
int main()
{
    int n, i , j, cheie, temp;
    cout << "n = ";
    cin >> n;
    int  v[n+1];
    cout << "Dati elementele vectorului: " << endl;
    for (i=0;i<n;i++)
    {
        cin >> v[i];
    }
    for (i=1;i<n;i++)
    {
        cheie = v[i];
        j = i-1;
        while(j>=0 && v[j]>cheie)
        {
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = cheie;
    }
    for (i=0;i<n;i++)
    {
        cout << v[i] << " ";
    }
}
