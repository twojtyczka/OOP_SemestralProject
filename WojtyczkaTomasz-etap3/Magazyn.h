#ifndef WOJTYCZKATOMASZ_ETAP3_MAGAZYN_H
#define WOJTYCZKATOMASZ_ETAP3_MAGAZYN_H

//zastosowanie odpowiednich plikow naglowkowych
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Produkt.h"
#include "Towar.h"
#include "Towar_sypki.h"
#include "Towar_ciekly.h"
#include "Paleciak.h"
#include "Plik.h"
#include "mojvector.h"

using namespace std;

class Magazyn {

    Mojvector<Produkt*> mojvector;
    int vectorrozmiar;
    static int ID;
    int nowynumer;

public:

    //naglowki konstruktora i destruktora
    Magazyn();
    Magazyn(const Magazyn &m);
    Magazyn(int);
    ~Magazyn();

    Magazyn& operator=( const Magazyn& m );
    void wypelnijvector();
    void wypiszvector();
    void dodajsztuki();
    void odejmijsztuki();
    void edytujmagazyn();

    int otrzymajnumer() const;
    void ustawnumer(int);
};

#endif //WOJTYCZKATOMASZ_ETAP3_MAGAZYN_H
