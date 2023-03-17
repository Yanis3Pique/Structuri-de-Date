///Pentru un polinom de grad n P(x) = Suma de la k=0 la n din (a indice k * x^k)
///unde a indice k reprezinta coeficientii polinomului, consideram urmatoarea reprezentare compusa din:
///• gradul maxim n
///• vectorul de coeficienti a0, a1, a2, ..., an

///Se citesc doua polinoame P si Q in reprezentarea de mai sus. Sa se calculeze polinomul produs P*Q si sa se afiseze.
///Input: n, n + 1 coeficienti (pentru P), m, m + 1 coeficienti (pentru Q).
///Output: coeficientii lui P*Q.

#include <iostream>
using namespace std;

const int MAXIM = 1005;

int main() {
    int n, m, i, j;
    int a[MAXIM], b[MAXIM], prod[MAXIM];

    /// Citim coeficientii primului polinom
    cout << "Introduceti gradul polinomului P: ";
    cin >> n;
    cout << "Introduceti coeficientii polinomului P (de la a0 la an): ";
    for (i=0;i<=n;i++)
    {
        cin >> a[i];
    }

    /// Citim coeficientii celui de-al doilea polinom
    cout << "Introduceti gradul polinomului Q: ";
    cin >> m;
    cout << "Introduceti coeficientii polinomului Q (de la b0 la bm): ";
    for (i=0;i<=m;i++)
    {
        cin >> b[i];
    }

    /// Initializam vectorul produs cu 0
    for (i=0;i<=n+m;i++)
    {
        prod[i] = 0;
    }

    /// Calculam coeficientii produsului
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=m;j++)
        {
            prod[i+j] += a[i] * b[j];
        }
    }

    /// Afisam coeficientii produsului
    cout << "Coeficientii produsului P*Q sunt: ";
    for (i=0;i<=n+m;i++)
    {
        cout << prod[i] << " ";
    }
    cout << endl;

    return 0;
}
