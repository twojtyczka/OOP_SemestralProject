#include "Siec_magazynow.h"
#include "Magazyn.h"
#include "Wyjatek.h"

using namespace std;

Siec_magazynow::Siec_magazynow() {
    numer = 0;
}
Siec_magazynow::Siec_magazynow(int numer) : numer(numer) {

}
Siec_magazynow::~Siec_magazynow() {

}

int Siec_magazynow::otrzymajnumer() const {
    return numer;
}

void Siec_magazynow::ustawnumer(int nr) {
    numer = nr;
}

void Siec_magazynow::dodajmagazyn() {

    //sprawdzenie czy vector jest pusty
    if (magazyny.empty()) {

        do {
            cout << "\nWprowadz ilosc magazynow jaka chcesz dodac: ";
            iloscmagazynow = Plik::readInt();
            //sprawdzenie czy uzytkownik wprowadzil liczbe wieksza od zera
            if (iloscmagazynow <= 0)
                cout << "\nWprowadz poprawnie ilosc magazynow jaka chcesz dodac (musi byc ona wieksza od zera).\n";
        }
        while (iloscmagazynow <= 0);

        //wprowadzanie nazw magazynow
        for (int i = 0; i < iloscmagazynow; i++) {
            numer = i+1;

            //tworzenie obiektu
            Magazyn nowyMagazyn(numer);
            //dodanie obiektu na koniec vectora
            magazyny.push_back(nowyMagazyn);

        }
    }
    else {

        do {
            cout << "\nWprowadz ilosc magazynow jaka chcesz dodac: ";
            iloscdodanychmagazynow = Plik::readInt();
            //sprawdzenie czy uzytkownik wprowadzil liczbe wieksza od zera
            if (iloscdodanychmagazynow <= 0)
                throw Zla_ilosc("\nWprowadzono niepoprawna ilosc magazynow (musi byc ona wieksza od zera).\n");
        } while (iloscdodanychmagazynow <= 0);

        //wprowadzanie nazw produktow
        for (int i = iloscmagazynow; i < (iloscmagazynow + iloscdodanychmagazynow); i++) {
            numer = i+1;

            //tworzenie obiektu
            Magazyn nowyMagazyn(numer);
            //dodanie obiektu na koniec vectora
            magazyny.push_back(nowyMagazyn);
        }
        iloscmagazynow = magazyny.size();
    }
}

void Siec_magazynow::wypiszmagazyny() {

    cout << "\n";
    for (int i = 0; i < magazyny.size(); i++) {
        cout << "Magazyn numer: " << magazyny[i].otrzymajnumer() << "\t";
        cout << endl;
    }
}

void Siec_magazynow::wybormagazynu() {

    if (iloscmagazynow > 1) {
        cout << "\nWprowadz numer magazynu, ktory chcesz edytowac: ";
        numer = Plik::readInt();

        //zabezpieczenie programu przed podaniem nieistniejacych wartosci numeru
        if (numer > iloscmagazynow || numer < 1) {
            throw Zly_wybor("\nMagazyn o takim numerze nie istnieje.\n");
        }
    }
    else
        numer = 1;

    magazyny[numer-1].otrzymajnumer();
    cout << "\nWybrales magazyn numer " << otrzymajnumer() << ".\n";
    magazyny[numer-1].edytujmagazyn();
}
