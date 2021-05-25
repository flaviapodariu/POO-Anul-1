#include "Matrice.h"
int Matrice:: n;
Matrice::Matrice()
{
    v = nullptr;
    n++;
}

Matrice::Matrice(int lin, int col)
{
    v = new Complex*[lin];
    Complex val;     // se initializeaza cu 0 + 0*i = 0;
    for (int i = 0; i < lin; i++)
    {
        v[i] = new Complex[col];
        for(int j =0; j < col; j++)
            v[i][j] = val;
    }
    n++;

}

Matrice::Matrice(Matrice &matr){n++;}
Complex& Matrice::get_element(int i, int j)
{
    return v[i][j];
}

void Matrice::set_element(int i, int j)
{
    Complex val;
    cout << "Elementul de la linia "<<i<<" , coloana " <<j<<" este: ";
    cin >> val;
    v[i][j] = val;
}
Complex** Matrice::get_pointer()
{
    return v;
}

istream& operator>>(istream &in, Matrice &m)
{
    m.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Matrice &m)
{
    m.afisare(out);
    return out;
}

Matrice& Matrice::operator=(const Matrice &m)
{
    this -> v = m.v;
    return *this;
}

Matrice::~Matrice() {}

void Matrice::nrObiecte() {
 cout << n;
}
