#ifndef PROIECTUL_3_ANIMAL_H
#define PROIECTUL_3_ANIMAL_H
#include <iostream>
using namespace std;

class Animal {
protected:
    string denumire;
    unsigned longevitate;
public:
    Animal();
    Animal(string, unsigned);
    Animal(Animal&);
    virtual ~Animal();
    string getDenumire();
    unsigned getLongevitate();
    void setDenumire(string);
    void setLongevitate(unsigned);
    friend istream &operator>>(istream&in, Animal&);
    friend ostream &operator <<(ostream &out, Animal&);
    virtual void citire(istream &in) = 0;
    virtual void afisare(ostream &out) = 0;
    Animal& operator=(const Animal&);

};



#endif //PROIECTUL_3_ANIMAL_H
