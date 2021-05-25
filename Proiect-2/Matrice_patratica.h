#ifndef PROIECTUL_2_MATRICE_PATRATICA_H
#define PROIECTUL_2_MATRICE_PATRATICA_H
#include<iostream>
#include "Matrice.h"

class Matrice_patratica: public Matrice {
protected:
    int dim;
public:
    Matrice_patratica();
    Matrice_patratica(int);
    Matrice_patratica(Matrice_patratica&);
    virtual ~Matrice_patratica();
    int get_dimensiune() const;
    void set_dimensiune(int);
    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator >>(istream &in, Matrice_patratica &mp);
    friend ostream& operator <<(ostream &out, Matrice_patratica &mp);
    Matrice_patratica& operator=(const Matrice_patratica&);

    static Complex& calculeazaDeterminant(Matrice_patratica&, int);
    static void minor(Matrice_patratica&, Matrice_patratica&, int, int, int);
    bool esteDiagonala(Matrice_patratica&);
};

#endif //PROIECTUL_2_MATRICE_PATRATICA_H
