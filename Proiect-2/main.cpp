#include <iostream>
#include "Complex.h"
#include "Matrice.h"
#include "Matrice_oarecare.h"
#include "Matrice_patratica.h"
#include "Matrice_triunghiulara.h"
using namespace std;

void menu_user() {
    cout << "\n Flavia Podariu, grupa 134, Tema 10 'Matrice complexa'";
    cout << "\n\t\t MENIU";
    cout << "\n------------------------------------------------------------------------------------------\n";
    cout << "1. Construiti o matrice patratica" ; cout << "\n";
    cout << "2. Construiti o matrice oarecare"; cout << "\n";
    cout << "3. Construiti o matrice triunghilaura"; cout << "\n";
    cout << "4. Calculati determinantul unei matrice patratice"; cout << "\n";
    cout << "5. Verificati daca o matrice triunghiulara este diagonala"; cout << "\n";
    cout << "6. Upcasting Matrice -> Matrice patratica"; cout << "\n";
    cout << "7. Upcasting Matrice patratica -> Matrice triunghiulara"; cout << "\n";
    cout << "8. Downcasting Matrice triunghiulara -> Matrice patratica"; cout << "\n";
    cout << "0. Iesire."; cout << "\n";
}

void menu()
{
    int option = 0;

    cout << " Alegeti una din urmatoarele actiuni: ";
    do {
        cin >> option;

        if(option == 0)
            return;

        if(option == 1)
        {
            Matrice_patratica mp;
            cin >> mp;
            cout << "Matricea construita de dvs. este: "; cout << "\n";
            cout << mp;
        }
        else
        if(option == 2)
        {
            Matrice_oarecare mo;
            cin >> mo;
            cout << "Matricea construita de dvs. este: "; cout << "\n";
            cout << mo;
        }
        else
        if(option == 3)
        {
          Matrice_patratica mp;
          cin >> mp;
          cout << Matrice_patratica::calculeazaDeterminant(mp, mp.get_dimensiune());
          cout << "\n";

        }
        else
        if(option == 4)
        {
            Matrice_patratica mp;   // apelez constructorul parametrizat
            cin >> mp;
            Matrice_patratica mp2(mp);  //apelez constructorul de copiere
            cout << mp;
            if(mp2.esteDiagonala(mp2))
             cout << "Matricea triunghiulara introdusa de dvs. este diagonala!";
            else cout << "Matricea triunghiulara introdusa de dvs. nu este diagonala!";
            cout << "\n";
        }
        else
        if(option == 5)
        {
            Matrice_triunghiulara mt;
            cin >> mt;
            Matrice_triunghiulara mt2(mt);
            cout << mt2;

        }
        else
        if(option == 6)
        {
            Matrice *matr = new Matrice_patratica;
            cin >> *matr;
            cout << *matr;

        }
        else
        if(option == 7)
        {
            Matrice_patratica *ptr = new Matrice_triunghiulara;
            cin >> *ptr;
            cout << *ptr;
        }
        else
        if(option == 8)
        {
            Matrice_triunghiulara *ptr1 = (Matrice_triunghiulara*) new Matrice_patratica;
            cin >> *ptr1;
            cout << *ptr1;
        }
        else
        if (option < 0 || option > 8)
            cout << "Optiune invalida. Incercati din nou!\n";

        cout << "Alegeti o alta actiune sau apasati 0: "; cout << "\n";
    } while (option);
}

void tip_obiect(Matrice *&obiect, int &nr_ordine)
{
    string fel;
    cout << "\n";
    cout << "Introduceti felul matricei numarul "<<nr_ordine+1<<": ";
    cin >> fel;
    try {
        if(fel == "patratica")
        {
            obiect = new Matrice_patratica;
            cin >> *obiect;
        }
        else
        if(fel == "oarecare")
        {
            obiect = new Matrice_oarecare;
            cin >> *obiect;
        }
        else
        if(fel == "triunghiulara")
        {
            obiect = new Matrice_triunghiulara;
            cin >> *obiect;
        }
        else throw 5;
    }
    catch(int error){
        cout << "Acel tip de matrice nu exista! Incercati oarecare, patratica sau triunghiulara.\n";
        nr_ordine--;
    }

}

void citireMemorareAfisare()
{
    Matrice **obiecte;
    int nrObiecte;
    cout << "Introduceti numarul de obiecte citite: ";
    cin >> nrObiecte;
    cout << "\n";
    obiecte = new Matrice*[nrObiecte];

    for(int i = 0 ; i < nrObiecte; i++)
        tip_obiect(obiecte[i], i);
    for(int i = 0; i < nrObiecte; i++)
    {
        cout << "\n"<< *obiecte[i];
        cout << "-------------------------------\n";
    }
}


int main() {

//    citireMemorareAfisare();
      // Testarea metodei statice de numarare obiecte construite
//    Matrice_triunghiulara m1;
//    Matrice_oarecare m2;
//    Matrice::nrObiecte();

    menu_user();
    menu();

    return 0;
}
