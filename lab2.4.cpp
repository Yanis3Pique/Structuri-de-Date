///Fie un vector cu un numar impar de elemente cu proprietatea ca orice
///valoare are exact doua aparitii in vector cu exceptia unei singure valori.
///Identificati elementul care apare o singura data. Atentie: elementele
///duplicat nu sunt neaparat pe pozitii consecutive! Bonus (+1p) pentru
///un algoritm care are un timp mai bun de O(n^2)) operatii.
///Input: n impar, n elemente in ordine arbitrara cu proprietatea mentionata.
///Output: elementul care apare o singura data.

///Complexitatea - O(n)

#include <iostream>
using namespace std;

int main()
{
    int n, x, i, rez=0;
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> x;
        rez ^= x;
    }
    cout << "Elementul care apare o singura data este: " << rez;
    return 0;
}
