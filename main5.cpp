///Scrieti un algoritm pentru cautarea binara a unui element intr-un sir de n numere.
///Input: n, n elemente in ordine crescatoare stocate intr-un vector, k elementul cautat.
///Output: pozitia lui k in vector sau -1 in caz ca nu se gaseste.

#include <iostream>
using namespace std;
int main()
{
    int n, k, i , j, st, dr, poz, mij;
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

    st = 1;
    dr = n;
    while (st<=dr)
    {
        mij = (st + dr)/2;
        if (v[mij] >= k)
        {
            poz = mij;
            dr = mij-1;
        }
        else st = mij+1;
    }

    if (v[poz] == k) cout << "Pozitia elementului " << k << " in fisier este " << poz;
    else cout << "-1";
}
