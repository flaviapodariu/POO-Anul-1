#ifndef PROIECTUL_2_MATRICE_OARECARE_H
#define PROIECTUL_2_MATRICE_OARECARE_H
#include "Matrice.h"
#include <iostream>

class Matrice_oarecare: public Matrice {
  int col;
  int lin;
public:
    Matrice_oarecare();
    Matrice_oarecare(int, int);
    Matrice_oarecare(Matrice_oarecare&);
    ~Matrice_oarecare();
    int get_linii() const;
    int get_coloane() const;
    void set_linii(int);
    void set_coloane(int);
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator >>(istream &in, Matrice_oarecare &mo);
    friend ostream& operator <<(ostream &out, Matrice_oarecare &mo);
    Matrice_oarecare& operator=(const Matrice_oarecare&);

};

#endif //PROIECTUL_2_MATRICE_OARECARE_H
