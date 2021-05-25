#include "Matrice_triunghiulara.h"

Matrice_triunghiulara::Matrice_triunghiulara(): Matrice_patratica(){}
Matrice_triunghiulara::Matrice_triunghiulara(int dimensiune): Matrice_patratica(dimensiune)
{   this -> determinant = Complex(1,1);
    Complex defaultValue(1,0);
    for(int i = 0 ; i < dim; i++)
        v[i][i] = defaultValue;      // restul elementelor sunt initializate cu 0+0i din constructorul Matrice(int, int)
}

Matrice_triunghiulara::Matrice_triunghiulara(Matrice_triunghiulara &mt): Matrice_patratica(mt)
{
    this ->determinant = produsDiagonala(mt);
}

Matrice_triunghiulara::~Matrice_triunghiulara()
{
    this -> determinant = Complex(0,0);
}

void Matrice_triunghiulara::set_determinant(Complex &det) {
    this -> determinant = det;
}

Complex &Matrice_triunghiulara::get_determinant() {

    return this -> determinant;
}

void Matrice_triunghiulara:: citire(istream &in)
{
    cout << "Introduceti dimensiunea matricii: ";
    in >> this -> dim;

    v = new Complex*[dim];
    cout << "Introduceti " << dim << " elemente (cele de pe diagonala principala): "; cout << "\n";

    for(int i = 0; i < dim; i++)
    {
        v[i] = new Complex[dim];
        for(int j = 0; j< dim; j++)
            if(i == j)
             in >> v[i][j];
            else v[i][j] = Complex(0,0);
    }

}

void Matrice_triunghiulara::afisare(ostream &out)
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
            out << v[i][j] << right << setw(10);
        out << "\n";
    }
    out << "Determinantul matricei de mai sus este: "<< produsDiagonala(*this);
    out << "\n";
}
istream &operator>>(istream &in, Matrice_triunghiulara &mt)
{
    mt.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Matrice_triunghiulara &mt)
{
    mt.afisare(out);
    return out;
}

Matrice_triunghiulara& Matrice_triunghiulara::operator=(const Matrice_triunghiulara& mt)
{
    for(int i = 0; i < dim; i++)
        delete[] v[i];
    delete[] v;

    this -> dim = mt.dim;
    this -> determinant = mt.determinant;

    v = new Complex*[dim];
    for(int i = 0; i < dim; i++)
        v[i] = new Complex[dim];

    for(int i = 0; i < dim; i++)
        for(int j = 0 ; j< dim; j++)
            this -> v[i][j] = mt.v[i][j];
    return *this;
}

Complex & Matrice_triunghiulara::produsDiagonala(Matrice_triunghiulara &mt)
{
    Complex *produs = new Complex(1,0);
    for(int i = 0 ; i < mt.dim; i++)
        *produs = *produs * mt.v[i][i];
    return *produs;
}