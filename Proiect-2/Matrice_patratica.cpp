#include "Matrice_patratica.h"

Matrice_patratica::Matrice_patratica(): Matrice()
{
    this -> dim = 0;
}
Matrice_patratica::Matrice_patratica(int dimensiune): Matrice(dimensiune, dimensiune)
{
    this -> dim = dimensiune;
}
Matrice_patratica::Matrice_patratica(Matrice_patratica &mp): Matrice(mp)
{
    this -> dim = mp.dim;
    this -> v = new Complex*[dim];
    for(int i = 0 ; i < dim; i++)
    {
        v[i] = new Complex[dim];
        for(int j = 0; j < dim; j++)
            v[i][j] = mp.v[i][j];
    }
}
Matrice_patratica::~Matrice_patratica()
{
    for(int i = 0; i < dim; i++)
        delete[] v[i];
    delete[] v;

    this -> dim = 0;
}

int Matrice_patratica::get_dimensiune() const
{
    return this -> dim;
}

void Matrice_patratica::set_dimensiune(int dimensiune)
{
    this -> dim = dimensiune;
}

void Matrice_patratica:: citire(istream &in)
{
    cout << "Introduceti dimensiunea matricii: ";
    in >> this -> dim;

    v = new Complex*[dim];
    cout << "Introduceti " << dim * dim << " elemente: "; cout << "\n";

    for(int i = 0; i < dim; i++)
    {
        v[i] = new Complex[dim];
        for(int j = 0; j< dim; j++)
            in >> v[i][j];
    }

}

void Matrice_patratica::afisare(ostream &out)
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
            out << v[i][j] << right << setw(10);
        out << "\n";
    }
    out << "Determinantul matricei de mai sus este: "<< calculeazaDeterminant(*this, this -> dim);
    out << "\n";
}

istream& operator>>(istream &in, Matrice_patratica &mp)
{
    mp.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Matrice_patratica &mp)
{
    mp.afisare(out);
    return out;
}

Matrice_patratica& Matrice_patratica::operator=(const Matrice_patratica& mp)
{
    for(int i = 0; i < dim; i++)
        delete[] v[i];
    delete[] v;              // sterg ce am inainte de egal ca sa evit heap corruption

    this -> dim = mp.dim;
    v = new Complex*[dim];
    for(int i = 0; i < dim; i++)
        v[i] = new Complex[dim];

   for(int i = 0; i <dim; i++)
       for(int j = 0 ; j< dim; j++)
         this -> v[i][j] = mp.v[i][j];
   return *this;
}

bool Matrice_patratica::esteDiagonala(Matrice_patratica &mp)
{   Complex zero(0,0);

    for(int i = 0; i < mp.dim; i++)
        for(int j = 0; j <= i; j++)
            if(i != j && mp.v[i][j] != zero || i == j && mp.v[i][j] == zero )
                return false;
    return true;
}
Complex& Matrice_patratica::calculeazaDeterminant(Matrice_patratica &mp, int n)
{
    Complex *det = new Complex(0,0);                     // ?????????

    if(n == 2)
        return(mp.v[0][0] * mp.v[1][1]) - (mp.v[0][1] * mp.v[1][0]);

    Complex semn(1,0);
    Matrice_patratica temp(n-1);

    for(int i = 0; i < n; i++)
    {
        minor(mp, temp, 0, i, n);
        *det = *det + (semn * mp.v[0][i] * calculeazaDeterminant(temp, n - 1));
        semn.set_real(-semn.get_real());  // semn = -semn
    }

    return *det;
}

void Matrice_patratica::minor(Matrice_patratica &mp, Matrice_patratica &temp, int supl, int supc, int dimens)
{
   int i = 0;
   int j = 0;


   for(int lin = 0 ; lin < dimens; lin++)
   {
       for(int col = 0 ; col < dimens; col++)
       {
           if(lin == supl || col == supc)
              continue;
           else
           {
               temp.v[i][j++] = mp.v[lin][col];

               if(j == dimens-1)
               {
                   j = 0;
                   i++;
               }
           }
       }
   }
}


