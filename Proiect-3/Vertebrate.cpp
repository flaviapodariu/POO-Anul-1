#include "Vertebrate.h"

Vertebrate::Vertebrate(): Animal()
{
    this -> nrVertebre = 0;
}
Vertebrate::Vertebrate(string nume, unsigned longev, int nrV): Animal(nume, longev)
{
    this -> nrVertebre = nrV;
}
Vertebrate::Vertebrate(Vertebrate &vert): Animal(vert)
{
    this -> nrVertebre = vert.nrVertebre;
}

Vertebrate::~Vertebrate()
{
    this -> nrVertebre = 0;
}

void Vertebrate::citire(istream &in)
{
    cout << "Introduceti denumirea vertebratei: ";
    getline(in,this -> denumire);
    cout <<"\n";
    cout << "Introduceti longevitatea in ani a acestei vertebrate: ";
    in >> this -> longevitate;
    cout << "\n";
    cout << "Introduceti numarul sau de vertebre: ";
    in >> this -> nrVertebre;
    cout << "\n";
    in.get();
}

void Vertebrate::afisare(ostream &out)
{
   Animal::afisare(out);
   out << "Numar de vertebre: "<< this -> nrVertebre;
   out << "\n";
}

istream &operator>>(istream &in, Vertebrate &vert)
{
    vert.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Vertebrate &vert)
{
    vert.afisare(out);
    return out;
}

Vertebrate &Vertebrate::operator=(const Vertebrate &vert)
{
    this -> denumire = vert.denumire;
    this -> longevitate = vert.longevitate;
    this -> nrVertebre = vert.nrVertebre;
    return *this;
}

int Vertebrate::getVertebre()
{
   return this -> nrVertebre;
}

void Vertebrate::setVertebre(int x)
{
    this -> nrVertebre = x;
}


