#ifndef WOJTYCZKATOMASZ_ETAP3_TOWAR_H
#define WOJTYCZKATOMASZ_ETAP3_TOWAR_H

#include <iostream>
#include <string>
#include "Produkt.h"

using namespace std;

//utworzenie klasy
class Towar :public Produkt {
    int noweID;
    string nowanazwa;
    double nowailosc;
    string nowajednostka;
public:

    //metody klasy
    Towar();
    Towar(int, string, int, string);
    ~Towar();


    int otrzymajID() const override;
    string otrzymajnazwa() const override;
    double otrzymajilosc() const override;
    string otrzymajjednostka() const override;
    void ustawilosc(double);

};

#endif //WOJTYCZKATOMASZ_ETAP3_TOWAR_H
