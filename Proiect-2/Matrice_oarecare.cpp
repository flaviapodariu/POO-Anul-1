#include "Matrice_oarecare.h"

Matrice_oarecare::Matrice_oarecare(): Matrice()
{
    this -> lin = 0;
    this -> col = 0;
}
Matrice_oarecare::Matrice_oarecare(int linii, int coloane): Matrice(linii,coloane)
{
    this -> lin = linii;
    this -> col = coloane;
}
Matrice_oarecare::Matrice_oarecare(Matrice_oarecare &mo): Matrice(mo)
{
    this->lin = mo.lin;
    this->col = mo.col;
    v = new Complex *[lin];
    for (int i = 0; i < lin; i++)
    {
        v[i] = new Complex[col];
        for (int j = 0; j < col; j++)
            v[i][j] = mo.v[i][j];
    }
}
Matrice_oarecare::~Matrice_oarecare()
{
    for(int i = 0; i < lin; i++)
        delete[] v[i];
    delete[] v;

    this -> lin = 0;
    this -> col = 0;
}
int Matrice_oarecare::get_linii() const
{
    return this -> lin;
}

int Matrice_oarecare::get_coloane() const
{
    return this -> col;
}

void Matrice_oarecare::set_linii(int nrLinii)
{
    this -> lin = nrLinii;
}

void Matrice_oarecare::set_coloane(int nrColoane)
{
    this -> col = nrColoane;
}

void Matrice_oarecare::citire(istream &in)
{
    cout << "Introduceti numarul de linii: ";
    in >> this -> lin;  cout << "\n";
    cout << "Introduceti numarul de coloane: ";
    in >> this -> col;  cout << "\n";

    v = new Complex*[lin];
    cout << "Introduceti "<< lin * col << " elemente: ";  cout << "\n";
    for (int i = 0; i < lin; i++)
    {   v[i] = new Complex[col];
        for (int j = 0; j < col; j++)
            in >> v[i][j];
    }
     cout << "\n";
}

void Matrice_oarecare::afisare(ostream &out)
{
    for(int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
            out << v[i][j]<< right << setw(7) ;
        out << "\n";
    }
}

istream& operator >>(istream &in, Matrice_oarecare &mo)
{
    mo.citire(in);
    return in;
}

ostream& operator <<(ostream &out, Matrice_oarecare &mo)
{
    mo.afisare(out);
    return out;
}

Matrice_oarecare& Matrice_oarecare::operator=(const Matrice_oarecare &mo)
{
    for (int i = 0; i < lin; i++)
        delete[] v[i];
    delete[] v;              // sterg ce am inainte de egal ca sa evit heap corruption

    this->lin = mo.lin;
    this->col = mo.col;
    v = new Complex *[lin];
    for (int i = 0; i < lin; i++)
        v[i] = new Complex[col];

    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            this->v[i][j] = mo.v[i][j];
    return *this;
}