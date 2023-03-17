#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
/// Linked List (Lista inlantuita)
using namespace std;

struct Nod {
    int data;
    Nod* next;
};

struct Nod* newNod(int data) {
   Nod* nod = new Nod;
   nod->data = data;
   nod->next = NULL;
   return nod;
};

void inserareNouNod(Nod** radacina, int data)
{
    Nod* nod = newNod(data);
    Nod* p;
    if(*radacina == NULL) { *radacina = nod; }
    else
    {
        p = *radacina;
        while(p->next != NULL) { p = p->next; }
        p->next = nod;
    }
}

void afisareLista(Nod* radacina)
{
    while(radacina != NULL)
    {
        cout << radacina->data << " -> ";
        radacina = radacina->next;
    }
    cout << "NULL" << endl;
}

Nod* creareLista(int v[], int n)
{
    Nod* radacina = NULL;
    for(int i=0;i<n;i++)
    {
        inserareNouNod(&radacina, v[i]);
    }
    return radacina;
}

void inserareDupa(Nod* nod_anterior, int data_noua)
{
    if (nod_anterior == NULL)
    {
        cout << "Nodul anterior dat nu poate fi NULL";
        return;
    }
    Nod* nod_nou = newNod(data_noua);
    nod_nou->data = data_noua;
    nod_nou->next = nod_anterior->next;
    nod_anterior->next = nod_nou;
}

Nod* stergePrimulElement(Nod* radacina)
{
    if (radacina == NULL) { return NULL; }
    Nod* urmator = radacina->next;
    delete radacina;
    return urmator;
}

void stergeUltimulElement(Nod* radacina)
{
    if (radacina == NULL || radacina->next == NULL)
    {
        delete radacina;
        return;
    }
    Nod* p = radacina;
    while (p->next->next != NULL) { p = p->next; }
    delete p->next;
    p->next = NULL;
}

void stergeElementDupaIndex(Nod** radacina, int index) {
    if (*radacina == NULL)
    {
        return;
    }
    if (index == 0)
    {
        Nod* temp = *radacina;
        *radacina = (*radacina)->next;
        delete temp;
        return;
    }
    Nod* current = *radacina;
    int i = 0;
    while (current != NULL && i < index - 1)
    {
        current = current->next;
        i++;
    }
    if (current == NULL || current->next == NULL)
    {
        return;
    }
    Nod* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void stergeElementDupaValoare(Nod** radacina, int data_de_sters)
{
    Nod* anterior = NULL;
    Nod* curent = *radacina;

    while (curent != NULL && curent->data != data_de_sters)
    {
        anterior = curent;
        curent = curent->next;
    }
    if (curent == NULL)
    {
        return;
    }
    if (anterior == NULL)
    {
        *radacina = curent->next;
    }
    else
    {
        anterior->next = curent->next;
    }
    delete curent;
}

int cautareValoare(Nod* radacina, int valoare_cautata) {
    int index = 0;
    while (radacina != NULL) {
        if (radacina->data == valoare_cautata) {
            return index;
        }
        radacina = radacina->next;
        index++;
    }
    return -1; /// valoarea cautata nu a fost gasita
}

int valoarePePozitie(Nod* radacina, int index)
{
    int pozitie = 0;
    while (radacina != NULL)
    {
        if (pozitie == index)
        {
            return radacina->data;
        }
        radacina = radacina->next;
        pozitie++;
    }
    /// Returnam valoare specialapentru cazul în care indexul nu a fost gasit
    return -1;
}

int main()
{
    cout << "LISTA COMENZILOR (Indexarea incepe de la 0!):" << endl;
    cout << "0 - Creare Lista" << endl;
    cout << "1 - Afisare Lista" << endl;
    cout << "2 - Adaugare element in Lista" << endl;
    cout << "3 - Stergerea primului element din Lista" << endl;
    cout << "4 - Stergerea ultimului element din Lista" << endl;
    cout << "5 - Inserarea unui element in Lista dupa index" << endl;
    cout << "6 - Stergerea unui element din Lista dupa index" << endl;
    cout << "7 - Stergerea unui element din Lista dupa valoare" << endl;
    cout << "8 - Cautarea unei valori in Lista si returnarea indexului" << endl;
    cout << "9 - Cautarea unui index in Lista si returnarea valorii de pe acea pozitie" << endl;
    cout << endl;

    ifstream f("input.in");
    int i, cmd_nr = 0, n, data_de_inserat, index;
    Nod* radacina;
    f >> n;
    int v[n];
    for(i=0;i<n;i++)
    {
        f >> v[i];
    }
    while(cmd_nr != -1)
    {
        cout << "Dati comanda: "; cin >> cmd_nr;
        if (cmd_nr == 0)
        {
            radacina = creareLista(v, n);
        }
        if (cmd_nr == 1)
        {
            afisareLista(radacina);
        }
        else if (cmd_nr == 2)
        {
            cout << "Dati o valoare de inserat in lista: ";
            cin >> data_de_inserat;
            inserareNouNod(&radacina, data_de_inserat);
        }
        else if (cmd_nr == 3)
        {
            radacina = stergePrimulElement(radacina);

        }
        else if (cmd_nr == 4)
        {
            stergeUltimulElement(radacina);
        }
        else if (cmd_nr == 5)
        {
            cout << "Dati un index dupa care sa se insereze nodul urmator: ";
            cin >> index;
            cout << "Dati o valoare de inserat in lista: ";
            cin >> data_de_inserat;
            Nod* nod_curent = radacina;
            while (nod_curent != NULL && nod_curent->data != index) { nod_curent = nod_curent->next; }
            if (nod_curent != NULL) { inserareDupa(nod_curent, data_de_inserat); }
        }
        else if (cmd_nr == 6)
        {
            cout << "Dati un index al carui element doriti sa fie sters: ";
            cin >> index;
            stergeElementDupaIndex(&radacina, index);
        }
        else if (cmd_nr == 7)
        {
            cout << "Dati o valoare de eliminat in lista: ";
            cin >> data_de_inserat; ///folosita aici ca data_de_sters
            stergeElementDupaValoare(&radacina, data_de_inserat);
        }
        else if (cmd_nr == 8)
        {
            cout << "Dati o valoare de cautat in lista: ";
            cin >> data_de_inserat; ///folosita aici ca data_de_cautat
            index = cautareValoare(radacina, data_de_inserat);
            if (index != -1)
            {
                cout << "Valoarea " << data_de_inserat << " se gaseste in lista la indexul " << index << endl;
            }
            else
            {
                cout << "Valoarea " << data_de_inserat << " nu a fost gasita in lista." << endl;
            }

        }
        else if (cmd_nr == 9)
        {
            cout << "Dati un index de cautat in lista: ";
            cin >> index;
            data_de_inserat = valoarePePozitie(radacina, index); ///folosita pentru a stoca valoarea de la indexul index
            if (data_de_inserat != -1)
            {
                cout << "Pe pozitia " << index << " se gaseste in lista valoarea " << data_de_inserat << endl;
            }
            else
            {
                cout << "Pe pozitia " << index << " nu a fost gasita nicio valoare in lista." << endl;
            }
        }
        else if (cmd_nr < 0 || cmd_nr > 9)
        {
            cout << "Mission aborted.";
            break;
        }
    }
}
