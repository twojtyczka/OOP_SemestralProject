#include "Towar.h"

using namespace std;

//ciala funkcji
Towar::Towar(int ID, string nazwa, int ilosc, string jednostka) {
    noweID = ID;
    nowailosc = ilosc;
    nowajednostka = "szt";
    nowanazwa = nazwa;
}
Towar::~Towar() {

}

void Towar::ustawilosc(double x) {
    nowailosc = x;
}

int Towar::otrzymajID() const {
    return noweID;
}
string Towar::otrzymajnazwa() const {
    return nowanazwa;
}
double Towar::otrzymajilosc() const {
    return nowailosc;
}
string Towar::otrzymajjednostka() const {
    return nowajednostka;
}
