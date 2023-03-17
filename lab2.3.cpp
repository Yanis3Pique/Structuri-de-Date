///Sa se scrie un program pentru inserarea unui nou element t, dupa prima
///aparitie a unui element k dintr-un vector de n elemente citit in prealabil.
///Prin inserare intelegem ca vom atribui valoarea t in vector pe pozitia
///urmatoare elementului k, dupa ce elementele de dupa k au fost mutate
///o pozitie inspre dreapta. Bonus (+1p) pentru inserarea unui intreg
///vector de t elemente dupa prima aparitie a lui k.

///Input: n, n elemente in ordine arbitrara stocate intr-un vector,
///t valoarea de inserat in vector, k elementul dupa care dorim sa inseram
///[optional pt. bonus: cel de-al doilea vector].

///Output: vector cu elementele initial date, vector cu elementul t inserat
///dupa k (sau vector identic cu cel initial dat daca lipseste k, eventual cu un mesaj).

#include <iostream>
using namespace std;

int main()
{
    int n, k, t;
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> n;

    int v[n];

    cout << "Introduceti elementele vectorului: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Introduceti elementul k: ";
    cin >> k;

    int pozitie_k = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == k)
        {
            pozitie_k = i;
            break;
        }
    }

    if (pozitie_k == -1)
    {
        cout << "Elementul k nu a fost gasit in vector." << endl;
        cout << "Vectorul ramane neschimbat: ";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Introduceti elementul t: ";
        cin >> t;

        /// Inserare unui singur element
        for (int i = n; i > pozitie_k + 1; i--)
        {
            v[i] = v[i - 1];
        }
        v[pozitie_k + 1] = t;
        n++;

        cout << "Vectorul cu elementul t inserat dupa k este: ";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        /// Inserare un vector de elemente
        int numar_elemente_t = 0;
        cout << "Introduceti numarul de elemente pentru inserarea dupa k: ";
        cin >> numar_elemente_t;

        if (numar_elemente_t > 0)
        {
            int t_vector[numar_elemente_t];
            cout << "Introduceti elementele pentru inserarea dupa k: ";
            for (int i = 0; i < numar_elemente_t; i++)
            {
                cin >> t_vector[i];
            }

            int new_n = n + numar_elemente_t;
            int new_v[new_n + 1];

            /// Copiem elementele inainte de k
            for (int i = 0; i <= pozitie_k; i++)
            {
                new_v[i] = v[i];
            }

            /// Inseram elementele din t_vector
            for (int i = 0; i < numar_elemente_t; i++)
            {
                new_v[pozitie_k + i + 1] = t_vector[i];
            }

            /// Copiem elementele ramase dupa k
            for (int i = pozitie_k+1; i <= n; i++)
            {
                new_v[i + numar_elemente_t] = v[i];
            }

            cout << "Vectorul cu elementul t inserat dupa k: ";
            for (int i = 0; i < new_n; i++)
            {
                cout << new_v[i] << " ";
            }
            cout << endl;

        }
    }
}
