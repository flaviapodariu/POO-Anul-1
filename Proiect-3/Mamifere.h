#ifndef PROIECTUL_3_MAMIFERE_H
#define PROIECTUL_3_MAMIFERE_H
#include "Vertebrate.h"

class Mamifere: public Vertebrate {
    double viteza;
    int nrPui;
public:
    Mamifere();
    Mamifere(string, unsigned, int, double, int);
    Mamifere(Mamifere&);
    ~Mamifere();
    double getViteza() const;
    int getPui() const;
    void setPui(int);
    void setViteza(double);
    friend istream &operator>>(istream&in, Mamifere&);
    friend ostream &operator <<(ostream &out, Mamifere&);
    void citire(istream &in);
    void afisare(ostream &out);
    Mamifere& operator=(const Mamifere&);

};

#endif //PROIECTUL_3_MAMIFERE_H
