///Scrieti algoritmul pentru cautarea secventiala a unui element intr-un s, ir de n numere.
///Input: n, n elemente in ordine arbitrara stocate intr-un vector, k elementul cautat.
///Output: pozitia lui k in vector sau -1 in caz ca nu se gaseste.

#include <iostream>
using namespace std;
int main()
{
    int n, k, i , j, poz = -1;
    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;
    int  v[n+1];
    cout << "Dati elementele vectorului: " << endl;
    for (i=1;i<=n;i++)
    {
        cin >> v[i];
    }

    for(i=1;i<=n;i++)
    {
        if(v[i] == k) poz = i;
    }

    if (poz == -1)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << "Pozitia elementului " << k << " in fisier este " << poz << endl;
    }
}
