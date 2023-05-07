#ifndef WOJTYCZKATOMASZ_ETAP3_MOJVECTOR_H
#define WOJTYCZKATOMASZ_ETAP3_MOJVECTOR_H

#include <vector>

template<typename T>
class Mojvector {
    int rozmiar;
    std::vector<Produkt *> vect;
public:
    void push_back(Produkt* element) {
        vect.push_back(element);
        rozmiar++;
    };

    Produkt * & operator[](int i){
        return vect[i];
    }

    int otrzymajRozmiar() const {
        return rozmiar;
    }
    Mojvector() {
        rozmiar = 0;
    };
    ~Mojvector() {

    };
};


#endif //WOJTYCZKATOMASZ_ETAP3_MOJVECTOR_H
