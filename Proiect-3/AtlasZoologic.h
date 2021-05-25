#ifndef PROIECTUL_3_ATLASZOOLOGIC_H
#define PROIECTUL_3_ATLASZOOLOGIC_H
#include "Pesti.h"
#include "Reptile.h"
#include "Vertebrate.h"
#include "Animal.h"
#include "Pasari.h"
#include <list>

template <class T> class AtlasZoologic
{
    static int nrFile;
    list <T> atlas;
public:
    AtlasZoologic();
    AtlasZoologic(AtlasZoologic&);
    ~AtlasZoologic();
    static int getNumarFile();
    int getSize();
    void setAtlasSize(int);
    AtlasZoologic& operator+=(T&);
    template<class U>
    friend ostream& operator <<(ostream &out, AtlasZoologic<U>&);
    AtlasZoologic& operator=(const AtlasZoologic<T>&);
    void afisare(ostream &out);

};
template<class T>
int AtlasZoologic<T>::nrFile;



template<class T>
AtlasZoologic<T>::AtlasZoologic()
{
    nrFile = 0;
    atlas.resize(0);

}

template<class T>
AtlasZoologic<T>::AtlasZoologic(AtlasZoologic<T> &altAtlas)
{
    atlas.resize();
    this -> atlas = altAtlas.atlas;

}

template<class T>
AtlasZoologic<T>::~AtlasZoologic()
{
    nrFile = 0;
    atlas.clear();
}

template<class T>
int AtlasZoologic<T>::getNumarFile() {
    return nrFile;
}

template <class T>
void AtlasZoologic<T>::setAtlasSize(int sz)
{
    atlas.resize(sz);
}

template<class T>
AtlasZoologic<T>& AtlasZoologic<T>::operator+=(T &ob)
{
    atlas.push_back(ob);
    nrFile++;
    return *this;
}

template<class U>
ostream &operator<<(ostream &out, AtlasZoologic<U>& animale)
{
    animale.afisare(out);
    return out;
}

template<class T>
void AtlasZoologic<T>::afisare(ostream &out)
{
   for(auto it: atlas)
     out << *it << "\n";
}

template<class T>
AtlasZoologic<T> &AtlasZoologic<T>::operator=(const AtlasZoologic<T>& altAtlas)
{
    this -> atlas.resize(altAtlas.atlas.size());
    nrFile = altAtlas.nrFile;
    this -> atlas = altAtlas.atlas;
    return *this;
}

template<class T>
int AtlasZoologic<T>::getSize() {
    return atlas.size();
}
// ----------------------------------Specializare Pesti----------------------------------------------


template <> class AtlasZoologic<Pesti*>
{
    static int pestiSpeciali;
    static int nrFile;
    list<Pesti*> atlasPesti;
public:
    AtlasZoologic();
    AtlasZoologic(AtlasZoologic&);
    ~AtlasZoologic();
    AtlasZoologic& operator+=(Pesti*&);
    friend ostream& operator <<(ostream &out, AtlasZoologic<Pesti*>&);
    AtlasZoologic& operator=(const AtlasZoologic<Pesti*>&);
    void afisare(ostream &out);
    static int getSpeciali();
    static int getFile();
};
AtlasZoologic<Pesti*>::AtlasZoologic()
{
  atlasPesti.resize(0);
}
AtlasZoologic<Pesti*>::AtlasZoologic(AtlasZoologic<Pesti*>& pe)
{
    atlasPesti.resize(pe.atlasPesti.size());
    atlasPesti = pe.atlasPesti;
}
AtlasZoologic<Pesti*>::~AtlasZoologic()
{
    atlasPesti.resize(0);
    pestiSpeciali = 0;
    nrFile = 0;
}
AtlasZoologic<Pesti*>& AtlasZoologic<Pesti*>::operator=(const AtlasZoologic<Pesti*>& p)
{
    atlasPesti.resize(p.atlasPesti.size());
    atlasPesti = p.atlasPesti;
    return *this;
}

AtlasZoologic<Pesti*>& AtlasZoologic<Pesti *>::operator+=(Pesti* &p)
{
    atlasPesti.push_back(*&p);
    nrFile++;
    if(p->getLungime() > 100 && p->getTip() == "rapitor")
        pestiSpeciali++;
    return *this;
}

ostream& operator<<(ostream& out, AtlasZoologic<Pesti*>& pe)
{
    pe.afisare(out);
    return out;
}
void AtlasZoologic<Pesti*>::afisare(ostream &out)
{
    for(auto it: atlasPesti)
        cout << *it<< "\n";


    if(pestiSpeciali == 1)
       cout << "In acest atlas se afla "<< pestiSpeciali<< " peste rapitor cu lungime mai mare de 1m"<< "\n";
    else
        cout << "In acest atlas se afla "<< pestiSpeciali<< " pesti rapitori cu lungime mai mare de 1m"<< "\n";
}

int AtlasZoologic<Pesti *>::getSpeciali()
{
    return pestiSpeciali;
}

int AtlasZoologic<Pesti *>::getFile()
{
    return nrFile;
}

int AtlasZoologic<Pesti*>:: pestiSpeciali;
int AtlasZoologic<Pesti*>:: nrFile;
#endif //PROIECTUL_3_ATLASZOOLOGIC_H

