///Sa se scrie un program pentru gasirea maximului si minimului dintr-un vector de n elemente folosind mai putin de 2n
///comparatii intre elemente (omitem aici numararea comparatiilor pentru contoarele necesare iterarii:
///de exemplu i < n dintr-un for).
///Input: n, n elemente in ordine arbitrara stocate intr-un vector.
///Output: valoarea minima si cea maxima.

#include <iostream>
using namespace std;

/// Functie pentru a gasi minimul si maximul dintr-un vector
/// Incepe de la pozitia start si se termina la pozitia end (inclusiv)
///Returneaza un obiect de tip struct MinMax, care contine minimul si maximul gasite
struct MinMax {
    int min;
    int max;
};

MinMax gasesteMinMax(int v[], int start, int end)
{
    MinMax mm, mmLeft, mmRight;
    int mid;

    /// Cazul de baza, daca vectorul are doar un element
    if (start == end)
    {
        mm.min = v[start];
        mm.max = v[start];
        return mm;
    }

    /// Cazul in care vectorul are doua elemente
    if (end == start + 1)
    {
        if (v[start] < v[end])
        {
            mm.min = v[start];
            mm.max = v[end];
        }
        else
        {
            mm.min = v[end];
            mm.max = v[start];
        }
        return mm;
    }

    /// Cazul general pentru vectori cu cel putin 3 elemente
    mid = (start + end) / 2;
    mmLeft = gasesteMinMax(v, start, mid);
    mmRight = gasesteMinMax(v, mid + 1, end);

    /// Combinam minimul si maximul gasit in cele doua jumatati
    if (mmLeft.min < mmRight.min)
    {
        mm.min = mmLeft.min;
    }
    else
    {
        mm.min = mmRight.min;
    }
    if (mmLeft.max > mmRight.max)
    {
        mm.max = mmLeft.max;
    }
    else
    {
        mm.max = mmRight.max;
    }

    return mm;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int v[n];

    cout << "Dati elementele vectorului: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    MinMax mm = gasesteMinMax(v, 0, n - 1);

    cout << "Valoarea minima este " << mm.min << endl;
    cout << "Valoarea maxima este " << mm.max << endl;

    return 0;
}
