#ifndef PROIECTUL_2_MATRICE_H
#define PROIECTUL_2_MATRICE_H
#include "Complex.h"
#include <iostream>
#include <iomanip>

class Matrice {
protected:
    Complex **v;
    static int n; //nr obiecte construite
public:
    Matrice();
    Matrice(int, int);
    Matrice(Matrice&);
    virtual ~Matrice() = 0;
    Complex** get_pointer();
    Complex& get_element(int, int);
    void set_element(int, int);
    virtual void citire(istream &in) = 0;
    virtual void afisare(ostream &out) = 0;
    friend istream& operator>>(istream &in, Matrice &m);
    friend ostream& operator<<(ostream &out, Matrice &m);
    Matrice& operator=(const Matrice&);
    static void nrObiecte();
};

#endif //PROIECTUL_2_MATRICE_H

