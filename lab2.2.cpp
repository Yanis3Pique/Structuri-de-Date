///Sa se scrie un program pentru stergerea primei aparitii a unei valori k
///citite de la tastatura dintr-un vector de n elemente citit in prealabil.
///Prin stergere intelegem mutarea elementelor de dupa pozitia elementului sters cate o pozitie spre
///stanga si micsorarea lui n. Bonus (+1p) pentru eliminarea tuturor aparitiilor.
///Input: n, n elemente in ordine arbitrara stocate intr-un vector, k valoarea a carei prima aparitie trebuie eliminata.
///Output: vector cu elementele initial date, vector cu elementul k eliminat
///(sau vector identic cu cel initial dat daca lipseste k, eventual cu un mesaj).

#include <iostream>
using namespace std;

int main()
{
    int n, copie_n, k;
    cout << "n = ";
    cin >> n;
    copie_n = n;
    int v[n], copie_v[n];
    cout << "Dati elementele vectorului: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        copie_v[i] = v[i];
    }
    cout << "k = ";
    cin >> k;

    int i = 0;
    while (i < n)
    {
        if (v[i] == k)
        {
            for (int j = i; j < n - 1; j++)
            {
                v[j] = v[j + 1];
            }
            n--;
        }
        else
        {
            i++;
        }
    }

    if (n == 0)
    {
        cout << "Vectorul initial nu contine niciun element." << endl;
    }
    else if (n == 1)
    {
        cout << "Vectorul initial contine doar elementul " << v[0] << "." << endl;
    }
    else
    {
        cout << "Vectorul initial: ";
        for (int i = 0; i < copie_n; i++)
        {
            cout << copie_v[i] << " ";
        }
        cout << endl << "Vectorul actualizat: ";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
    }
}
