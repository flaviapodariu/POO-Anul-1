#ifndef PROIECTUL_3_PESTI_H
#define PROIECTUL_3_PESTI_H
#include "Vertebrate.h"

class Pesti: public Vertebrate {
    double lungime;
    double masa;
    string tip_peste;
public:
    Pesti();
    Pesti(string, unsigned, int, double, double,string);
    Pesti(Pesti&);
    ~Pesti();
    double getLungime()const;
    double getMasa()const;
    string getTip()const;
    void setLungime(double);
    void setMasa(double);
    void setTip(string);
    friend istream &operator>>(istream&in, Pesti&);
    friend ostream &operator <<(ostream &out, Pesti&);
    void citire(istream &in);
    void afisare(ostream &out);
    Pesti& operator=(const Pesti&);

};

#endif //PROIECTUL_3_PESTI_H
