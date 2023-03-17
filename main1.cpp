///Sa se scrie un program pentru ordonarea crescatoare a unui sir de n
///numere folosind metoda Bubble Sort.
///Input: n, n elemente in ordine arbitrara stocate intr-un vector.
///Output: vector continand elementele in ordine sortata.

#include <iostream>
using namespace std;
int main()
{
    int n, i , j, temp;
    cout << "n = ";
    cin >> n;
    int  v[n+1];
    cout << "Dati elementele vectorului: " << endl;
    for (i=1;i<=n;i++)
    {
        cin >> v[i];
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n-i;j++)
        {
            if (v[j]>v[j+1])
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        cout << v[i] << " ";
    }
}
