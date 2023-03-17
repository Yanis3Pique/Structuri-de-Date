///Pentru un polinom de grad n P(x) = Suma de la k=0 la n din (a indice k * x^k)
///unde a indice k reprezinta coeficientii polinomului, consideram urmatoarea reprezentare compusa din:
///• gradul maxim n
///• vectorul de coeficient, i a0, a1, a2, ..., an

///Se citeste un polinom P in reprezentarea de mai sus si o valoaret. Sa se evalueze P(t) si sa se afiseze.
///Input: n, n+1 coeficienti, valoarea t.
///Output: P(t).

#include <iostream>
using namespace std;

int main()
{
    int n, t, i;
    cout << "Introduceti gradul polinomului: ";
    cin >> n;
    if(n==0)
    {
        cout << "Introduceti coeficientii polinomului: ";
        cin >> i;
        cout << "Introduceti valoarea t pentru evaluarea polinomului: ";
        cin >> t;
        cout << "Valoarea polinomului evaluat la t = " << t << " este " << i << endl;
    }
    else
    {
        int a[n+1];
        cout << "Introduceti coeficientii polinomului de la gradul " << n << " la gradul 0: ";
        for (i=n;i>=0;i--)
        {
            cin >> a[i];
        }

        cout << "Introduceti valoarea t pentru evaluarea polinomului: ";
        cin >> t;

        int rez = a[n];
        for (i=n-1;i>=0;i--)
        {
            rez = a[i] + t*rez;
        }

        cout << "Valoarea polinomului evaluat la t = " << t << " este " << rez << endl;
    }

    return 0;
}

