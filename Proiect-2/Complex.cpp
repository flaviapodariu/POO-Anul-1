#include "Complex.h"
#include <iostream>
using namespace std;

Complex::Complex()
{
    this -> re = 0;
    this -> im = 0;
}

Complex::Complex(float real, float imaginar): re(real), im(imaginar){}

Complex::Complex(Complex &z)
{
    this -> re = z.re;
    this -> im = z.im;
}
float Complex::get_real()
{
    return this -> re;
}

float Complex::get_imaginar()
{
    return this -> im;
}

void Complex::set_real(float real)
{
    this -> re = real;
}

void Complex:: set_imaginar(float imaginar)
{
    this -> im = imaginar;
}

void Complex::citire(istream &in)
{
    cout << "Partea reala: ";
    in >> this -> re;   cout << "\n";

    cout << "Partea imaginara: ";
    in >> this -> im;   cout << "\n";

}
void Complex::afisare(ostream &out) const
{
    if(this -> re == 0 && this -> im != 0)
        out << this -> im<< "i";
    else
    if(this -> im == 0)
        out << 0;
    else
    if(this -> im == 0)
        out << this -> re;
    else

    if(this -> im > 0)
        out << re << " + "<< im<< "i";
    else
        out << re << im << "i";
}

istream& operator >>(istream &in, Complex &z)
{
    z.citire(in);
    return in;
}
ostream& operator <<(ostream &out, Complex &z)
{
    z.afisare(out);
    return out;
}
Complex& Complex::operator=(const Complex &z)
{
    this -> re = z.re;
    this -> im = z.im;
    return *this;
}

bool Complex::operator!=(const Complex &z) const{
    if(this-> re != z.re || this->im != z.im)
       return true;
    return false;
}

bool Complex::operator==(const Complex &z) const
{
    if(this -> re == z.re && this ->im == z.im)
        return true;
    return false;
}

Complex::~Complex()
{
    this -> re = 0;
    this -> im = 0;
}

Complex& operator*(Complex &z1, Complex&z2)
{
   Complex *rezultat = new Complex;
   rezultat->re = z1.re * z2.re  - z1.im * z2.im;
   rezultat->im = z1.re * z2.im + z1.im * z2.re;
   return *rezultat;
}

Complex& operator+(Complex &z1, Complex&z2)
{
    Complex *rezultat = new Complex;
    rezultat -> re = z1.re + z2.re;
    rezultat -> im = z1.im + z2.im;
    return *rezultat;
}

Complex& operator-(Complex &z1, Complex &z2)
{
    Complex* rezultat = new Complex;
    rezultat -> re = z1.re - z2.re;
    rezultat -> im = z1.im - z2.im;
    return*rezultat;
}


