#include <iostream>
#include <stdlib.h>
#include "Animal.h"
#include "Vertebrate.h"
#include "Nevertebrate.h"
#include "Pesti.h"
#include "Pasari.h"
#include "Mamifere.h"
#include "Reptile.h"
#include "AtlasZoologic.h"
using namespace std;
void tip(Animal*& animale, int& pagina);

void menu_user() {
    cout << "\n Flavia Podariu, grupa 134, Tema 2 'Atlas Zoologic'";
    cout << "\n\t\t MENIU";
    cout << "\n------------------------------------------------------------------------------------------\n";
    cout << "1. Construiti o vertebrata" ; cout << "\n";
    cout << "2. Construiti o nevertebrata"; cout << "\n";
    cout << "3. Construiti o pasare"; cout << "\n";
    cout << "4. Construiti un peste"; cout << "\n";
    cout << "5. Upcasting Reptila -> Vertebrate "; cout << "\n";
    cout << "6. Dynamic cast Animal -> Reptila"; cout << "\n";
    cout << "7. Construiti un atlas zoologic cu N reptile"; cout << "\n";
    cout << "8. Construiti un atlas zoologic cu N pesti"; cout << "\n";
    cout << "9. Citire, memorare si afisare N obiecte"; cout << "\n";
    cout << "0. Iesire."; cout << "\n";
}

void menu()
{
    int option = 0;

    cout << " Alegeti una din urmatoarele actiuni: ";
    do {
       cin >> option;
       cin.get();

        if(option == 0)
            return;

        if(option == 1)
        {
          Vertebrate v;
          v.setDenumire("Cameleon");
          v.setLongevitate(8);
          cout << v;
        }
        else
        if(option == 2)
        {
            Nevertebrate n;
            cin >> n;
            cout << n;
        }
        else
        if(option == 3)
        {
            Pasari pas("Cioara", 12, 20, 30, true);
            cin >> pas;
            cout << pas;
        }
        else
        if(option == 4)
        {
            Pesti p1;
            cin >> p1;
            Pesti p2(p1);  // constructorul de copiere
            cout << p2;
        }
        else
        if(option == 5)
        {
            Vertebrate *vert = new Reptile("Sarpele din Clinceni", 5, 20, true);
            cout << *vert<< "\n";
        }
        else
        if(option == 6)
        {
            Mamifere mam("Vaca", 12, 100, 15.6, 1);
            Animal* a = dynamic_cast<Mamifere*>(&mam);
            cout << *a;
        }
        else
        if(option == 7)
        {
            int n;
            cout << "Cate reptile vom adauga in atlas? ";
            cin >> n;
            while(n < 0)
            {
                cout << "\n"<< "Introduceti un numar pozitiv!"<< "\n";
                cin >>n;
            }
            cin.get();
            AtlasZoologic<Reptile*> myAtlas;
            for(int i = 1; i <= n;i++)
            {
                Reptile* r = new Reptile;
                cin >> *r;
                myAtlas += r;
            }
            cout << myAtlas;
        }
        else
        if(option == 8)
        {
            int n;
            cout << "Cati pesti vom adauga in atlas? ";
            cin >> n;
            while(n < 0)
            {
                cout << "\n"<< "Introduceti un numar pozitiv!"<< "\n";
                cin >>n;
            }
            cin.get();
            AtlasZoologic<Pesti*> myAtlas;
            for(int i = 1; i <= n; i++)
            {
                Pesti *p = new Pesti;
                cin >> *p;
                myAtlas += p;
            }
            cout << myAtlas;
        }
        else
        if(option == 9)
        {
            Animal **animale;
            int i, n;
            cout << "Introduceti numarul de animale pe care le vom citi: ";
            cin >> n;
            cin.get();
            cout << "\n";
            animale = new Animal*[n];
            for(i = 1; i <= n; i++)
                tip(animale[i], i);

            for(i = 1; i <= n; i++)
            {
                cout << *animale[i];
                cout <<"      -"<< i <<"-"<<"\n\n";  // numarul paginii sub info afisate
            }

        }
        else
        if (option < 0 || option > 9)
           cout << "Optiune invalida. Incercati din nou!\n";

       cout << "Alegeti o alta actiune sau apasati 0: "; cout << "\n";
    } while (option);
}
void tip(Animal*& animale, int& pagina)
{
    string an;
    cout << "\n";
    cout << "Introduceti tipul de animal. Puteti alege intre: "<< "\n";
    cout << "-> nevertebrate"<<"\n";
    cout << "-> vertebrate"<<"\n";
    cout << "-> mamifere" <<"\n";
    cout << "-> pasari" <<"\n";
    cout << "-> pesti"<<"\n";
    cout << "-> reptile"<<"\n";
    getline(cin, an);
    try
    {
        if(an == "nevertebrate")
        {
            animale = new Nevertebrate;
            cin >> *animale;
        }
        else
        if(an == "vertebrate")
        {
            animale = new Vertebrate;
            cin >> *animale;
        }
        else
        if(an == "mamifere")
        {
            animale = new Mamifere;
            cin >> *animale;
        }
        else
        if(an == "pasari")
        {
            animale = new Pasari;
            cin >> *animale;
        }
        else
        if(an == "pesti")
        {
            animale = new Pesti;
            cin >> *animale;
        }
        else
        if(an == "reptile")
        {
            animale = new Reptile;
            cin >> *animale;
        }
        else
            throw 10;
    }
    catch(bad_alloc &var)
    {
        cout << "Allocation Failure"<< "\n";
        --pagina;
        exit(EXIT_FAILURE);
    }
    catch(int i)
    {
        cout << "Introduceti un tip de animal valid!"<< "\n";
        --pagina;
    }

}
int main() {
menu_user();
menu();
//cout << AtlasZoologic<Animal*>::getNumarFile();

    return 0;
}
