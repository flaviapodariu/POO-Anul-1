#include "Nevertebrate.h"

Nevertebrate::Nevertebrate(): Animal() {}

Nevertebrate::Nevertebrate(Nevertebrate &n): Animal(n) {}
Nevertebrate::Nevertebrate(string denum, unsigned longev, int picioare) : Animal(denum, longev)
{
    this -> nrPicioare = picioare;
}

Nevertebrate::~Nevertebrate()
{
  this -> nrPicioare = 0;
}

istream &operator>>(istream &in, Nevertebrate &n)
{
    n.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Nevertebrate &n)
{
    n.afisare(out);
    return out;
}

void Nevertebrate::citire(istream &in)
{
    cout << "Introduceti denumirea nevertebratei: ";
    getline(in, this -> denumire);
    cout <<"\n";
    cout << "Introduceti longevitatea in ani a acestei nevertebrate: ";
    in >> this -> longevitate;
    cout << "\n";
    cout << "Introduceti numarul sau de picioare: ";
    in >> this ->nrPicioare;
    cout << "\n";
}

void Nevertebrate::afisare(ostream &out)
{
    Animal::afisare(out);
}

Nevertebrate &Nevertebrate::operator=(const Nevertebrate &n)
{
    this -> denumire = n.denumire;
    this -> longevitate = n.longevitate;
    this -> nrPicioare = n.nrPicioare;
    return *this;
}


