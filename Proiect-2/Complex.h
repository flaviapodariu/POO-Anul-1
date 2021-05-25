#ifndef PROIECTUL_2_COMPLEX_H
#define PROIECTUL_2_COMPLEX_H

#include <iostream>

using namespace std;

class Complex {
    float re;
    float im;

public:
    Complex();
    Complex(float, float);
    Complex(Complex&);
    float get_real();
    float get_imaginar();
    void set_real(float);
    void set_imaginar(float);
    void citire(istream &in);
    void afisare(ostream &out) const;
    friend istream& operator>>(istream &in, Complex &z);
    friend ostream& operator<<(ostream &out, Complex &z);
    Complex& operator=(const Complex& z);
    bool operator !=(const Complex&) const;
    bool operator ==(const Complex&) const;
    friend Complex& operator*(Complex&, Complex&);
    friend Complex& operator+(Complex&, Complex&);
    friend Complex& operator-(Complex&, Complex&);

    ~Complex();
    friend class Matrice;

};

#endif //PROIECTUL_2_COMPLEX_H
