#ifndef WOJTYCZKATOMASZ_ETAP3_SIEC_MAGAZYNOW_H
#define WOJTYCZKATOMASZ_ETAP3_SIEC_MAGAZYNOW_H

#include <iostream>
#include <vector>
#include "Magazyn.h"
#include "Plik.h"

using namespace std;

class Siec_magazynow: public Magazyn {

    Magazyn x;
    std::vector<Magazyn> magazyny;
    int numer;
    int iloscmagazynow;
    int iloscdodanychmagazynow;

public:

    //naglowki konstruktora i destruktora
    Siec_magazynow();
    Siec_magazynow(int);
    ~Siec_magazynow();

    int otrzymajnumer() const;
    void ustawnumer(int);

    void dodajmagazyn();
    void wypiszmagazyny();
    void wybormagazynu();

};

#endif //WOJTYCZKATOMASZ_ETAP3_SIEC_MAGAZYNOW_H
