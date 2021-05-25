#include "Pasari.h"
#include<limits>
Pasari::Pasari(): Vertebrate()
{
    this -> anvergura_aripi = 0;
    this -> zboara = true;

}

Pasari::Pasari(string denum, unsigned longev, int nrV, double anvg, bool zbor): Vertebrate(denum, longev, nrV)
{
    this -> anvergura_aripi = anvg;
    this ->zboara = zbor;
}

Pasari::Pasari(Pasari &p): Vertebrate(p)
{
    this ->anvergura_aripi = p.anvergura_aripi;
    this -> zboara = p.zboara;
}

Pasari::~Pasari()
{
    this -> anvergura_aripi = 0;
    this -> zboara = true;

}

istream &operator>>(istream &in, Pasari &p)
{
    p.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Pasari &p)
{
    p.afisare(out);
    return out;
}

void Pasari::citire(istream &in)
{
    Vertebrate::citire(in);
    cout << "Aceasta vertebrata este o pasare! Introduceti anvergura aripilor acesteia in centimetri: ";
    in >> this ->anvergura_aripi;
    cout << "\n";
    cout << "Poate aceasta pasare sa zboare? (0 = nu / 1 = da) : ";
    while(!(in >> this ->zboara))
    {
        cout << "Introduceti o valoare valida!"<< "\n";
        cout << "Pentru NU, apasati 0, pentru DA, apasati 1"<< "\n";
        in.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n";

}

void Pasari::afisare(ostream &out)
{
    Vertebrate::afisare(out);
    out << "Anvergura aripi: "<< this -> anvergura_aripi<< "cm" << "\n";
    if(this -> zboara)
       out << "Aceasta pasare poate zbura.";
    else
       out << "Aceasta pasare nu poate zbura.";
    out << "\n";

}

Pasari &Pasari::operator=(const Pasari &p)
{
    this -> denumire = p.denumire;
    this -> longevitate = p.longevitate;
    this ->anvergura_aripi = p.anvergura_aripi;
    this -> zboara = p.zboara;
    return *this;
}

double Pasari::getAripi() const
{
    return this ->anvergura_aripi;
}

bool Pasari::getZbor() const
{
    return this -> zboara;
}

void Pasari::setAripi(double aripi)
{
    this ->anvergura_aripi = aripi;
}

void Pasari::setZbor(bool zbor)
{
    this -> zboara = zbor;
}
