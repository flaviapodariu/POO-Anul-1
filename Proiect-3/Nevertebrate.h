#ifndef PROIECTUL_3_NEVERTEBRATE_H
#define PROIECTUL_3_NEVERTEBRATE_H
#include "Animal.h"

class Nevertebrate: public Animal {
    int nrPicioare;
public:
    Nevertebrate();
    Nevertebrate(string, unsigned, int);
    Nevertebrate(Nevertebrate&);
    ~Nevertebrate();
    friend istream &operator>>(istream&in, Nevertebrate&);
    friend ostream &operator <<(ostream &out, Nevertebrate&);
    void citire(istream &in);
    void afisare(ostream &out);
    Nevertebrate& operator=(const Nevertebrate&);


};

#endif //PROIECTUL_3_NEVERTEBRATE_H
