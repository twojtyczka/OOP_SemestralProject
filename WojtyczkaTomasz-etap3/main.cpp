#include <iostream>
#include <fstream>
#include "Wyjatek.h"
#include "Siec_magazynow.h"
#include "Plik.h"

using namespace std;

std::ifstream file;
bool czytaj = false;

int Magazyn::ID = 0;

int main(int argc, char * argv[]) {

    if (argc > 1) {
        file.open(argv[1]);
        if (file.is_open()) {
            czytaj = true;
            cout <<"Plik jest otwarty.\n";
        }
    }

    //utworzenie obiektu (reprezentanta klasy Siec_magazynow)
    Siec_magazynow m1;

    //wywolanie funkcji, ktore sa skladowymi klasy
    m1.dodajmagazyn();
    m1.wypiszmagazyny();

    int wybor = 0;
    do {
        cout <<
             "\nMENU GLOWNE:"
             "\nDodaj okreslona ilosc magazynow- wybierz 1\n"
             "Edytuj magazyny- wybierz 2\n"
             "Jesli chcesz zakonczyc dzialanie programu- wybierz 0\n"
             "\nWybierz czynnosc: ";
        wybor = Plik::readInt();

        //wybor czynnosci (dodanie magazynow, edytowanie zawartosci magazynow, zakonczenie dzialania programu)

        try {
            switch (wybor) {
                case 0:
                    break;
                case 1:
                    m1.dodajmagazyn();
                    m1.wypiszmagazyny();
                    break;
                case 2:
                    m1.wypiszmagazyny();
                    m1.wybormagazynu();
                    break;
                default:
                    cout << "Wystapila pomylka, wybierz czynnosc jeszcze raz\n";
                    break;
            }
        }
        catch(Zly_wybor & wyjatek) {
            cout << "\nWyjatek zostal zlapany " << wyjatek.message << endl;
        }
        catch(Zla_ilosc & wyjatek) {
            cout << "\nWyjatek zostal zlapany " << wyjatek.message << endl;
        }
    } while (wybor != 0);

    if(czytaj == true)
        file.close();
    return 0;
}
