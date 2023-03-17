///Pentru un polinom de grad n P(x) = Suma de la k=0 la n din (a indice k * x^k)
///unde a indice k reprezinta coeficientii polinomului, consideram urmatoarea reprezentare compusa din:
///• gradul maxim n
///• vectorul de coeficienti a0, a1, a2, ..., an

///Se citesc doua polinoame P si Q in reprezentarea de mai sus. Sa se calculeze polinomul suma P + Q si sa se afiseze.
///Input: n, n + 1 coeficienti (pentru P), m, m + 1 coeficienti (pentru Q).
///Output: coeficientii lui P + Q.

#include <iostream>
using namespace std;

int main()
{
    int n, m, t, i, k;
    cout << "Introduceti gradul polinomului P: ";
    cin >> n;

    int P[n+1];
    cout << "Introduceti coeficientii polinomului P de la gradul " << n << " la gradul 0 " << ": ";
    for (i=n;i>=0;i--)
    {
        cin >> P[i];
    }

    cout << "Introduceti gradul polinomului Q: ";
    cin >> m;

    int Q[m+1];
    cout << "Introduceti coeficientii polinomului Q de la gradul " << m << " la gradul 0 " << ": ";
    for (i=m;i>=0;i--)
    {
        cin >> Q[i];
    }

    ///Aici puteam sa salvez suma coeficientilor celor doua polinoame, insa m-am gandit ca irosesc memorie.
    cout << "Coeficientii, in ordinea a0, a1, ... sunt: ";
    if (n > m)
    {
        for (i=0;i<=m;i++)
        {
            cout << P[i] + Q[i] << " ";
        }
        for (i=m+1;i<=n;i++)
        {
            cout << P[i] << " ";
        }
    }
    else
    {
        for (i=0;i<=m;i++)
        {
            cout << P[i] + Q[i] << " ";
        }
        for (i=m+1;i<=n;i++)
        {
            cout << Q[i] << " ";
        }
    }
}
