#include "Reptile.h"
#include<limits>
Reptile::Reptile(): Vertebrate()
{
    this -> venin = false;
}

Reptile::Reptile(string denum, unsigned longev, int nrV, bool venin): Vertebrate(denum, longev, nrV)
{
    this -> venin = venin;
}

Reptile::Reptile(Reptile &r) : Vertebrate(r)
{
    this ->venin = r.venin;
}

Reptile::~Reptile()
{
    this -> venin = false;
}
void Reptile::citire(istream &in)
{
    cout << "Introduceti denumirea reptilei: ";
    getline(in, this -> denumire);
    cout << "\n";
    cout << "Introduceti longevitatea in ani a acestei reptile: ";
    in >> this -> longevitate;
    cout << "\n";
    cout << "Este aceasta reptila veninoasa? (0 = nu / 1 = da): ";
    while(!(in >> this ->venin))
    {
        cout << "Introduceti o valoare valida!"<< "\n";
        cout << "Pentru NU, apasati 0, pentru DA, apasati 1"<< "\n";
        in.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";
    in.get();
}
void Reptile::afisare(ostream &out)
{
    Vertebrate::afisare(out);
    if(this -> venin)
       out << "Aceasta reptila este extrem de veninoasa!";
    else
       out << "Aceasta reptila nu este veninoasa!";
    out << "\n";
}

istream &operator>>(istream &in, Reptile &r)
{
    r.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Reptile &r)
{
    r.afisare(out);
    return out;
}

Reptile &Reptile::operator=(const Reptile &r)
{
    this -> denumire = r.denumire;
    this -> longevitate = r.longevitate;
    this -> venin = r.venin;
    return *this;
}

bool Reptile::getVenin() const
{
    return this -> venin;
}

void Reptile::setVenin(bool venom)
{
    this -> venin = venom;
}
