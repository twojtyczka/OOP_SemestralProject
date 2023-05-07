#ifndef WOJTYCZKATOMASZ_ETAP3_PRODUKT_H
#define WOJTYCZKATOMASZ_ETAP3_PRODUKT_H

#include <iostream>
#include <string>

using namespace std;

//utworzenie klasy
class Produkt {

public:

    virtual int otrzymajID() const = 0;
    virtual string otrzymajnazwa() const = 0;
    virtual double otrzymajilosc() const = 0;
    virtual string otrzymajjednostka() const = 0;

    virtual void ustawilosc(double) = 0;
};

#endif //WOJTYCZKATOMASZ_ETAP3_PRODUKT_H
