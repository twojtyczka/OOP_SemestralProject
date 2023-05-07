#include "Towar_ciekly.h"

using namespace std;

//ciala funkcji
Towar_ciekly::Towar_ciekly(int ID, string nazwa, double ilosc, string jednostka) {
    noweID = ID;
    nowailosc = ilosc;
    nowanazwa = nazwa;
    nowajednostka = "l";
}
Towar_ciekly::~Towar_ciekly() {

}

void Towar_ciekly::ustawilosc(double x){
    nowailosc = x;
}

int Towar_ciekly::otrzymajID() const {
    return noweID;
}
string Towar_ciekly::otrzymajnazwa() const {
    return nowanazwa;
}
double Towar_ciekly::otrzymajilosc() const {
    return nowailosc;
}
string Towar_ciekly::otrzymajjednostka() const {
    return nowajednostka;
}
