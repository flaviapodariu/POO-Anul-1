#include "Pesti.h"

Pesti::Pesti(): Vertebrate()
{
    this -> lungime = 0;
    this -> masa = 0;
    this -> tip_peste = "";

}

Pesti::Pesti(string denum, unsigned longev, int nrV, double lung, double kg, string tip): Vertebrate(denum, longev, nrV)
{
    this -> lungime = lung;
    this -> masa = kg;
    this ->tip_peste = tip;
}

Pesti::Pesti(Pesti &p): Vertebrate(p)
{
    this -> lungime = p.lungime;
    this -> masa = p.masa;
    this -> tip_peste = p.tip_peste;
}

Pesti::~Pesti()
{
    this -> lungime = 0;
    this -> masa = 0;
    this -> tip_peste = "";
}

double Pesti::getLungime() const
{
    return this -> lungime;
}

double Pesti::getMasa() const
{
    return this -> masa;
}

string Pesti::getTip() const
{
    return this ->tip_peste;
}

void Pesti::setLungime(double l)
{
    this -> lungime = l;
}

void Pesti::setMasa(double m)
{
    this -> masa = m;
}

void Pesti::setTip(string tip)
{
    this -> tip_peste = tip;
}
istream &operator>>(istream &in, Pesti &p)
{
    p.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Pesti &p)
{
    p.afisare(out);
    return out;
}

void Pesti::citire(istream &in)
{
    Vertebrate::citire(in);
    cout << "Aceasta vertebrata este un peste! Introduceti lungimea sa in centimetri: ";
    in >> this -> lungime;
    cout << "\n";
    cout << "Introduceti masa pestelui in kg: ";
    in >> this -> masa;
    cout << "\n";
    cout << "Introdceti tipul pestelui (pasnic/rapitor): ";
     while(this ->tip_peste != "pasnic" && this ->tip_peste != "rapitor")
     {
         in >> this ->tip_peste;
         cout << "\n";
         if(this -> tip_peste != "pasnic" && this ->tip_peste != "rapitor")
         {
             cout << "Tipul introdus este invalid. Incercati 'pasnic' sau 'rapitor'!\n";
             cout << "Introdceti tipul pestelui (pasnic/rapitor): ";
         }

     }
     in.get();
}

void Pesti::afisare(ostream &out)
{
    Vertebrate::afisare(out);
    out << "Lungime: " << this ->lungime << " cm"<< "\n";
    out << "Masa: " << this -> masa << " kg"<< "\n";
    out << "Tip peste: " << this ->tip_peste << "\n";

}

Pesti &Pesti::operator=(const Pesti &p)
{
    this -> denumire = p.denumire;
    this -> longevitate = p.longevitate;
    this -> lungime = p.lungime;
    this -> masa  =p.masa;
    this -> tip_peste = p.tip_peste;
    return *this;
}


