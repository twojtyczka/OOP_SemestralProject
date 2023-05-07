#ifndef WOJTYCZKATOMASZ_ETAP3_PALECIAK_H
#define WOJTYCZKATOMASZ_ETAP3_PALECIAK_H

#include <iostream>
#include <string>
#include <vector>
#include "Produkt.h"
#include "Magazyn.h"

using namespace std;

//utworzenie klasy
class Paleciak {

    //atrybuty klasy
    std::vector<Produkt*> paleciak;
    int udzwig;

public:

    //metody klasy
    Paleciak();
    explicit Paleciak(int);
    ~Paleciak();

    int otrzymajudzwig() const;

    void ustawudzwig(int);
};

#endif //WOJTYCZKATOMASZ_ETAP3_PALECIAK_H
