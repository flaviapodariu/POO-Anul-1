#ifndef PROIECTUL_3_REPTILE_H
#define PROIECTUL_3_REPTILE_H
#include "Vertebrate.h"

class Reptile: public Vertebrate {
    bool venin;
public:
    Reptile();
    Reptile(string, unsigned, int, bool);
    Reptile(Reptile&);
    ~Reptile();
    bool getVenin() const;
    void setVenin(bool);
    friend istream &operator>>(istream&in, Reptile&);
    friend ostream &operator <<(ostream &out, Reptile&);
    void citire(istream &in);
    void afisare(ostream &out);
    Reptile& operator=(const Reptile&);


};

#endif //PROIECTUL_3_REPTILE_H
