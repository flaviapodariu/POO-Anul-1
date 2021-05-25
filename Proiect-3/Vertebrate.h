#ifndef PROIECTUL_3_VERTEBRATE_H
#define PROIECTUL_3_VERTEBRATE_H
#include "Animal.h"

using namespace std;

class Vertebrate: public Animal {
protected:
    int nrVertebre;
public:
    Vertebrate();
    Vertebrate(string, unsigned, int);
    Vertebrate(Vertebrate&);
    ~Vertebrate();
    int getVertebre();
    void setVertebre(int);
    friend istream &operator>>(istream&in, Vertebrate&);
    friend ostream &operator <<(ostream &out, Vertebrate&);
    void citire(istream &in);
    void afisare(ostream &out);
    Vertebrate& operator=(const Vertebrate&);
};

#endif //PROIECTUL_3_VERTEBRATE_H
