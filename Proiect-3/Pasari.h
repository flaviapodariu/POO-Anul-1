#ifndef PROIECTUL_3_PASARI_H
#define PROIECTUL_3_PASARI_H
#include "Vertebrate.h"

class Pasari:public Vertebrate {
    double anvergura_aripi;
    bool zboara;
public:
    Pasari();
    Pasari(string ,unsigned,int, double, bool);
    Pasari(Pasari&);
    ~Pasari();
    double getAripi() const;
    bool getZbor() const;
    void setAripi(double);
    void setZbor(bool);
    friend istream &operator>>(istream&in, Pasari&);
    friend ostream &operator <<(ostream &out, Pasari&);
    void citire(istream &in);
    void afisare(ostream &out);
    Pasari& operator=(const Pasari&);

};

#endif //PROIECTUL_3_PASARI_H
