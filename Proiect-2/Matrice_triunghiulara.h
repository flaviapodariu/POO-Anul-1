#ifndef PROIECTUL_2_MATRICE_TRIUNGHIULARA_H
#define PROIECTUL_2_MATRICE_TRIUNGHIULARA_H
#include "Matrice_patratica.h"
using namespace std;

class Matrice_triunghiulara: public Matrice_patratica{
 Complex determinant;
public:
    Matrice_triunghiulara();
    Matrice_triunghiulara(int);
    Matrice_triunghiulara(Matrice_triunghiulara&);
    ~Matrice_triunghiulara();
    Complex& get_determinant();
    void set_determinant(Complex&);
    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator >>(istream &in, Matrice_triunghiulara &mp);
    friend ostream& operator <<(ostream &out, Matrice_triunghiulara &mp);
    Matrice_triunghiulara& operator=(const Matrice_triunghiulara&);
    Complex& produsDiagonala(Matrice_triunghiulara&);

};

#endif //PROIECTUL_2_MATRICE_TRIUNGHIULARA_H
