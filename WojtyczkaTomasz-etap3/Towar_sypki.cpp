#include "Towar_sypki.h"

using namespace std;

//ciala funkcji
Towar_sypki::Towar_sypki(int ID, string nazwa, double ilosc, string jednostka){
    noweID = ID;
    nowailosc = ilosc;
    nowanazwa = nazwa;
    nowajednostka = "kg";
}
Towar_sypki::~Towar_sypki() {

}

void Towar_sypki::ustawilosc(double x) {
    nowailosc = x;
}

int Towar_sypki::otrzymajID() const {
    return noweID;
}
string Towar_sypki::otrzymajnazwa() const {
    return nowanazwa;
}
double Towar_sypki::otrzymajilosc() const {
    return nowailosc;
}
string Towar_sypki::otrzymajjednostka() const {
    return nowajednostka;
}
