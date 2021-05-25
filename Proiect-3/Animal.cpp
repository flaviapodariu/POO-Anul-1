#include "Animal.h"


Animal::Animal()
{
    this -> denumire = "";
    this ->longevitate = 0;
}

Animal::Animal(string nume, unsigned longevitate)
{
    this -> denumire = nume;
    this -> longevitate = longevitate;
}

Animal::Animal(Animal &a)
{
    this ->denumire =  a.denumire;
    this -> longevitate = a.longevitate;
}

Animal::~Animal()
{
    this -> denumire = "";
    this -> longevitate = 0;
}
string Animal::getDenumire()
{
    return this -> denumire;
}

unsigned Animal::getLongevitate()
{
    return this -> longevitate;
}

void Animal::setDenumire(string nume)
{
    this -> denumire = nume;
}

void Animal::setLongevitate(unsigned longev)
{
    this ->longevitate = longev;
}

void Animal::citire(istream &in)
{
    cout << "Introduceti denumirea animalului: ";
    getline(in, this -> denumire);
    cout <<"\n";
    cout << "Introduceti longevitatea in ani a acestui animal: ";
    in >> this -> longevitate;
    cout << "\n";

}

void Animal::afisare(ostream &out)
{
    out << "Denumire: "<< this -> denumire <<"\n";
    out << "Longevitate: "<< this -> longevitate << " ani";
    out << "\n";
}

istream &operator>>(istream &in, Animal &a)
{
    a.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Animal &a)
{
    a.afisare(out);
    return out;
}

Animal &Animal::operator=(const Animal &a)
{
    this -> longevitate =  a.longevitate;
    this -> denumire = a.denumire;
    return *this;
}
