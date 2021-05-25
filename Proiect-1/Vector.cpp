/*
 * Supraincarcarea pe operatorul >> nu am mai exemplificat-o in meniu pentru ca
 * am initializat deja vectorul prin cei 2 constructori.
 *
 * Supraincarcarea pe operatorul << nu am exemplificat-o in mod explicit in meniu
 * pt ca oricum am folosit-o la fiecare optiune din meniu pt a demonstra
 * corectitudinea solutiilor.
 *
 * Am implementat clasa maxim pentru a returna 2 valori prin metoda findMax().
 *
 * In cazul in care valoarea maxima apare de mai multe ori in vector,
 * indexul considerat corespunde primei aparitii ale maximului.
 *
 * Pentru ultimele optiunea 3 si ultimele 3 functii am copiat initializarea de la optiunea 1.
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
#define MIN -99999
void menu_user();
void menu();
class maxim;

class Vector{
    int size;
    int *arr;

public:
    Vector();
    Vector(int val, int vectSize);
    Vector(Vector &aux);
    ~Vector();
    int get_vect(int index);
    int get_size();
    void set_vect(int index, int val);
    void set_size(int newSize);

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream &in, Vector& v);
    friend ostream& operator<<(ostream &out, Vector& v);

    Vector& operator=(const Vector &aux);

    int sumaElem();
    void actualizare(int val, int lungime);
    void sortat();
    void citireAfisare();
    maxim findMax();

};

class maxim
{   friend Vector;
    int index;
    int valoareMax;
public:
    maxim()
    {
        this -> index = 0;
        this -> valoareMax = MIN;
    }
    ~maxim()
    {
        this -> index = 0;
        this -> valoareMax =0;
    }
    int get_index()
    {
        return this->index;
    }
    int get_valoareMax()
    {
        return this -> valoareMax;
    }

    void set_index(int newIndex)
    {
        this -> index = newIndex;
    }
    void set_valoareMax(int newMax)
    {
        this ->valoareMax = newMax;
    }

};
//---------------------------------------------------------------------------------------------------------------------------------------------------

Vector :: Vector()
{
    this -> size = 0;
    this -> arr = new int[this -> size];
    for(int i = 0 ; i < this -> size ; i++)
        arr[i] = 0;

}

Vector :: Vector(int val, int vectSize)
{   this -> size = vectSize;
    this -> arr = new int[vectSize];
    for (int i = 0; i < vectSize; i++)
         arr[i] = val;
}

Vector :: Vector(Vector &aux)
{
    this -> size = aux.size;
    this -> arr = new int[this -> size];
    for(int i = 0; i < this -> size ; i++)
        arr[i] = aux.arr[i];
}

Vector :: ~Vector()
{
    this ->size = 0;
    delete [] arr;
}
int Vector::get_vect(int index)
{
    return arr[index];
}

int Vector::get_size()
{
    return this -> size;
}
void Vector::set_size(int newSize)
{
    this -> size = newSize;
}

void Vector::set_vect(int index, int val)
{
    this -> arr[index] = val;
}
void Vector::citire(istream &in)
{
    cout << "Introduceti dimensiunea vectorului";
    in >> this -> size;
    cout << "\n";
    cout << "Introduceti elementele vectorului";
    cout << "\n";
    for(int i = 0; i < this->size; i++)
        in >> arr[i];
}
void Vector::afisare(ostream &out)
{
    out << "Vectorul contine urmatoarele elemente:\n";
    for (int i = 0; i < size; i++)
       out << arr[i]<< " ";
}

ostream& operator<<(ostream &out, Vector& v)
{
    v.afisare(out);
    return out;
}

istream& operator>>(istream &in, Vector& v)
{
    v.citire(in);
    return in;
}

Vector& Vector:: operator=(const Vector &v)
{
    delete[] this->arr;
   this->size = v.size;
   this -> arr = new int[this->size];
   for(int i = 0 ; i < this->size; i++)
      arr[i] = v.arr[i];
}

int Vector::sumaElem() {
    int s = 0;
    for(int i = 0; i < this ->size; i++)
        s += this -> arr[i];
    return s;
}
void Vector::actualizare(int val, int lungime)
{
    this -> size = lungime;
    delete [] arr;
    this -> arr = new int[lungime];
    for(int i = 0; i < lungime; i++)
       this -> arr[i] = val;
}

void Vector::sortat()
{
    sort(arr+0, arr + this -> size);
}

maxim Vector::findMax()
{
    maxim rezultat;
    for(int i = 0; i < this -> size; i++)
        if(arr[i] > rezultat.get_valoareMax())
        {
            rezultat.set_valoareMax(arr[i]);
            rezultat.set_index(i);
        }
    return rezultat;
}

void Vector::citireAfisare()
{   int dimens, val;
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> dimens;  cout << "\n";
    this->size = dimens;

    cout << "Introduceti "<< dimens << " elemente:";
    for(int i = 0; i < dimens; i++)
    {
        cin >> val;
        this -> arr[i] = val;
    }
    for(int i = 0; i < dimens; i++)
      cout << arr[i]<< " ";
}
//------------------------------------------------------------ MAIN -----------------------------------------------------------------------------------

int main() {
    menu_user();
    menu();
    return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void menu_user() {
    cout << "\n Flavia Podariu, grupa 134, Tema 3 'Vector'";
    cout << "\n\t\t MENIU";
    cout << "\n------------------------------------------------------------------------------------------\n";
    cout << "1.Initializeaza vectorul si seteaza manual valorile."; cout << "\n";
    cout << "2.Initializeaza un vector constant."; cout << "\n";
    cout << "3.Copiati vectorul curent catre un alt vector."; cout << "\n";
    cout << "4.Actualizati dimensiunea vectorului.(se reinitializeaza un vector constant!)"; cout << "\n";
    cout << "5.Calculati suma tuturor elementelor vectorului."; cout << "\n";
    cout << "6.Gasiti maximul si pozitia lui."; cout << "\n";
    cout << "7.Sortati crescator vectorul."; cout << "\n";
    cout << "0.Iesire."; cout << "\n";
}

void menu()
{
int option = 0;

cout << "Alegeti una din urmatoarele actiuni: ";
do {
cin >> option;
        if(option == 0)
            return;
        if (option == 1)
        {   int dimens;
            Vector myVect;
            cout << "Introduceti dimensiunea vectorului: ";
            cin >> dimens;
            cout << "\n";
            myVect.set_size(dimens);
            cout << "Introduceti "<< dimens << " valori: ";
            for(int i = 0; i < dimens ; i++)
            {
                int val;
                cin >> val;
                myVect.set_vect(i, val);
            }
            cout << "\n";
            cout << myVect;
            cout << "\n";
        }
        else
        if (option == 2)
        {
            int dimens, val;
            cout << "Introduceti dimensiunea vectorului: ";
            cin >> dimens;
            cout << "\n";
            cout << "Introduceti valoarea corespunzatoare elementelor vectorului: ";
            cin >> val;  cout << "\n";

            Vector myVect(val, dimens);
            cout << myVect;
            cout << "\n";

        }
        else
        if (option == 3)
        {    int dimens;
            Vector myVect;
            cout << "Introduceti dimensiunea vectorului: ";
            cin >> dimens;
            cout << "\n";
            myVect.set_size(dimens);
            cout << "Introduceti "<< dimens << " valori: ";
            for(int i = 0; i < dimens ; i++)
            {
                int val;
                cin >> val;
                myVect.set_vect(i, val);
            }
            Vector aux = myVect;
            cout << "Vectorul initial este:"; cout << "\n";
            for(int i = 0; i < myVect.get_size(); i ++)
                cout << myVect.get_vect(i)<< " ";
            cout << "\n";
            cout << "Vectorul nou, copiat este:"; cout << "\n";
            for(int i = 0; i < aux.get_size(); i ++)
                cout << aux.get_vect(i)<< " ";
            cout << "\n";
        }
        else
        if(option == 4)
        {   Vector myVect(5, 5);
            int dimens, val;
            cout << "Introduceti dimensiunea vectorului: ";
            cin >> dimens;
            cout << "\n";
            cout << "Introduceti valoarea corespunzatoare elementelor vectorului: ";
            cin >> val;
            cout << "\n";
            myVect.actualizare(val, dimens);
            cout << myVect;
            cout << "\n";
        }
        else
        if(option == 5)
        {   int dimens;
            Vector myVect;
            cout << "Introduceti dimensiunea vectorului: ";
            cin >> dimens;
            cout << "\n";
            myVect.set_size(dimens);
            cout << "Introduceti "<< dimens << " valori: ";
            for(int i = 0; i < dimens ; i++)
            {
                int val;
                cin >> val;
                myVect.set_vect(i, val);
            }
            int suma = myVect.sumaElem();
            cout << suma;
            cout << "\n";
        }
        else
        if(option == 6)
        {
            int dimens;
            Vector myVect;
            cout << "Introduceti dimensiunea vectorului: ";
            cin >> dimens;
            cout << "\n";
            myVect.set_size(dimens);
            cout << "Introduceti "<< dimens << " valori: ";     //am copiat initializarea de la optiunea 1
            for(int i = 0; i < dimens ; i++)
            {
                int val;
                cin >> val;
                myVect.set_vect(i, val);
            }

            maxim rezultat = myVect.findMax();
            cout << "Maximul este "<< rezultat.get_valoareMax()<< " si s-a gasit la indexul "<< rezultat.get_index();
            cout << "\n";
        }
        else
        if(option == 7)
        {
            int dimens;
            Vector myVect;
            cout << "Introduceti dimensiunea vectorului: ";
            cin >> dimens;
            cout << "\n";
            myVect.set_size(dimens);
            cout << "Introduceti "<< dimens << " valori: ";     //am copiat initializarea de la optiunea 1
            for(int i = 0; i < dimens ; i++)
            {
                int val;
                cin >> val;
                myVect.set_vect(i, val);
            }
            myVect.sortat();
            cout << myVect;
            cout << "\n";
        }


if (option < 0 || option > 7)
cout << "Optiune invalida. Incercati din nou!\n";
cout << "Alegeti o alta actiune sau apasati 0: "; cout << "\n";
} while (option);
}
