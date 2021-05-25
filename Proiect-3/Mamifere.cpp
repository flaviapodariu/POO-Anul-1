//
// Created by Flavia on 25-Apr-21.
//

#include "Mamifere.h"

Mamifere::Mamifere(): Vertebrate()
{
    this -> viteza = 0;
    this -> nrPui = 0;

}

Mamifere::Mamifere(string denum, unsigned longev, int nrV, double v, int pui): Vertebrate(denum, longev, nrV)
{
    this -> viteza = v;
    this -> nrPui = pui;
}

Mamifere::Mamifere(Mamifere &m): Vertebrate(m)
{
    this -> viteza = m.viteza;
    this -> nrPui = m.nrPui;
}
Mamifere::~Mamifere()
{
    this -> viteza = 0;
    this -> nrPui = 0;
}

double Mamifere::getViteza() const
{
    return this ->viteza;
}

int Mamifere::getPui() const
{
    return this -> nrPui;
}

void Mamifere::setPui(int pui)
{
    this->nrPui = pui;
}

void Mamifere::setViteza(double v)
{
    this ->viteza = v;
}

istream &operator>>(istream &in, Mamifere &m)
{
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Mamifere &m)
{
    m.afisare(out);
    return out;
}

void Mamifere::citire(istream &in)
{
    Vertebrate::citire(in);
    cout << "Aceasta vertebrata este un mamifer! Introduceti viteza maxima a acestuia in km/h : ";
    in >> this -> viteza;
    cout << "\n";
    cout << "Introduceti numarul maxim de pui la o nastere: ";
    in >> this -> nrPui;
    cout << "\n";
    in.get();
}

void Mamifere::afisare(ostream &out)
{
    Vertebrate::afisare(out);
    cout << "Viteza: "<< this -> viteza<< " km/h";
    cout << "\n";
    cout << "Numar pui / nastere: "<< this -> nrPui<< " pui";
    cout << "\n";
}

Mamifere &Mamifere::operator=(const Mamifere &m)
{
    this -> denumire = m.denumire;
    this -> longevitate = m.longevitate;
    this -> viteza = m.viteza;
    this -> nrPui = m.nrPui;
    return *this;
}
