#include "Magazyn.h"
#include "Wyjatek.h"

using namespace std;

//konstruktor
Magazyn::Magazyn() {

    //podanie wartosci domyslnych
    vectorrozmiar = 0;
    nowynumer = 0;
}

//konstruktor kopiujący
Magazyn::Magazyn(const Magazyn &m) {
    this->nowynumer = m.nowynumer;
    this->vectorrozmiar = m.vectorrozmiar;
    this->mojvector = m.mojvector;
}

Magazyn::Magazyn(int numer) : nowynumer(numer) {

}

//destruktor
Magazyn::~Magazyn() {

}

//operator przypisania
Magazyn &Magazyn::operator=(const Magazyn &m) {
    this->nowynumer = m.otrzymajnumer();
    this->vectorrozmiar = m.vectorrozmiar;
    this->mojvector = m.mojvector;

    return *this;;
}

//wypelnianie vectora produktami lub dodawanie nowych (wprowadzanie nowych obiektow do vectora)
void Magazyn::wypelnijvector() {

    int decyzja = 0;
    int iloscproduktow = 0;
    double ilosc = 0;
    string nazwa;
    string jednostka;

    //sprawdzenie czy vector jest pusty
    if (mojvector.otrzymajRozmiar() == 0) {

        do {
            cout << "Wprowadz ilosc produktow jaka chcesz dodac: ";
            vectorrozmiar = Plik::readInt();
            //sprawdzenie czy uzytkownik wprowadzil liczbe wieksza od zera
            if (vectorrozmiar > 0)
                cout << endl;
            else
                throw Zla_ilosc("\nWprowadzono niepoprawna ilosc produktow (musi byc ona wieksza od zera).\n\n");
        } while (vectorrozmiar <= 0);

        //wprowadzanie nazw produktow
        for (int i = 0; i < vectorrozmiar; i++) {
            cout << "Wprowadz nazwe " << i + 1 << " produktu: ";
            nazwa = Plik::readString();

            do {

                cout <<
                     "\nJesli chcesz by dodany produkt byl towarem zwyklym- wybierz 1\n"
                     "Jesli chcesz by dodany produkt byl towarem sypkim- wybierz 2\n"
                     "Jesli chcesz by dodany produkt byl towarem cieklym- wybierz 3\n"
                     "\nWybierz czynnosc: ";

                decyzja = Plik::readInt();
                cout << endl;

                if (decyzja == 1) {
                    //tworzenie obiektu
                    Produkt *  nowyTowar = new Towar(ID, nazwa, ilosc, jednostka);
                    Magazyn::ID++;
                    //dodanie obiektu na koniec vectora
                    mojvector.push_back(nowyTowar);
                } else if (decyzja == 2) {
                    //tworzenie obiektu
                    Produkt * nowyTowar_sypki = new Towar_sypki(ID, nazwa, ilosc, jednostka);
                    Magazyn::ID++;
                    //dodanie obiektu na koniec vectora
                    mojvector.push_back(nowyTowar_sypki);
                } else if (decyzja == 3) {
                    //tworzenie obiektu
                    Produkt * nowyTowar_ciekly = new Towar_ciekly(ID, nazwa, ilosc, jednostka);
                    Magazyn::ID++;
                    //dodanie obiektu na koniec vectora
                    mojvector.push_back(nowyTowar_ciekly);
                } else
                    throw Zly_wybor("Wprowadz poprawna liczbe.\n");
            } while (decyzja != 1 && decyzja != 2 && decyzja != 3);

        }
        cout << endl;
    }
    else {


            cout << "\nWprowadz ilosc produktow jaka chcesz dodac: ";
            iloscproduktow = Plik::readInt();
            //sprawdzenie czy uzytkownik wprowadzil liczbe wieksza od zera
            if (iloscproduktow > 0)
                cout << endl;
            else
                throw Zla_ilosc("\nWprowadz poprawnie ilosc produktow jaka chcesz dodac (musi byc ona wieksza od zera).\n");

        //wprowadzanie nazw produktow
        for (int i = vectorrozmiar; i < (vectorrozmiar + iloscproduktow); i++) {

            cout << "Wprowadz nazwe " << i+1 << " produktu: ";
            nazwa = Plik::readString();

            do {

                cout <<
                     "\nJesli chcesz by dodany towar byl towarem zwyklym- wybierz 1\n"
                     "Jesli chcesz by dodany towar byl towarem sypkim- wybierz 2\n"
                     "Jesli chcesz by dodany towar byl towarem cieklym- wybierz 3\n"
                     "\nWybierz czynnosc: ";

                decyzja = Plik::readInt();

                if (decyzja == 1) {
                    //tworzenie obiektu
                    Produkt * nowyTowar = new Towar(ID, nazwa, ilosc, jednostka);
                    Magazyn::ID++;
                    //dodanie obiektu na koniec vectora
                    mojvector.push_back( nowyTowar);
                }
                else if (decyzja == 2) {
                    //tworzenie obiektu
                    Produkt * nowyTowar_sypki = new Towar_sypki(ID, nazwa, ilosc, jednostka);
                    Magazyn::ID++;
                    //dodanie obiektu na koniec vectora
                    mojvector.push_back(nowyTowar_sypki);
                }
                else if (decyzja == 3) {
                    //tworzenie obiektu
                    Produkt * nowyTowar_ciekly = new Towar_ciekly(ID, nazwa, ilosc, jednostka);
                    Magazyn::ID++;
                    //dodanie obiektu na koniec vectora
                    mojvector.push_back(nowyTowar_ciekly);
                }
                else
                    throw Zly_wybor ("Wprowadzono niepoprawna liczbe.\n");

            } while (decyzja != 1 && decyzja != 2 && decyzja != 3);
        }
        vectorrozmiar = mojvector.otrzymajRozmiar();
        cout << endl;
    }
}

//wypisywanie vectora w interfejsie uzytkownika
void Magazyn::wypiszvector() {

    cout << "\n";
    for (int i = 0; i < mojvector.otrzymajRozmiar(); i++) {
        cout << "ID: "<< mojvector[i]->otrzymajID() << "\t";
        cout << "Nazwa: "<< mojvector[i]->otrzymajnazwa() << "\t";
        cout << "Ilosc: "<< mojvector[i]->otrzymajilosc() <<" ";
        cout << mojvector[i]->otrzymajjednostka() <<"\t\n";
    }
}

//dodawanie ilosci w obiektach
void Magazyn::dodajsztuki() {

    int cyfra = 0;
    double ilosc = 0;
    int i = 0;

    //sprawdzenie czy rozmiar vectora jest wiekszy od 1, by w przypadku istnienia jednego obiektu program mogl pominac polecenie zwiazane z podaniem ID
    if (vectorrozmiar > 1) {
        cout << "\nWprowadz ID produktu, w ktorym chcesz dodac ilosc: ";
        cyfra = Plik::readInt();

        do {
            if (mojvector[i]->otrzymajID() != cyfra)
                i++;
        } while (mojvector[i]->otrzymajID() != cyfra && i < vectorrozmiar);

        if (mojvector[i]->otrzymajID() != cyfra)
            throw Zly_wybor ("\nNie ma produktu o takim ID.\n");
    }
    else
        cyfra = mojvector[i]->otrzymajID();

    //spytanie uzytkownika o ilosc, ktora chce dodac
    do {
        cout << "\nIle chcesz dodac ilosci do produktu o numerze ID = " << cyfra << ": ";
        ilosc = Plik::readDouble();
        //zabezpieczenie programu przed wpisaniem przez uzytkownika wartosci mniejszej od jeden
        if (ilosc < 1)
            throw Zly_wybor("\nMusisz podac liczbe wieksza od zera.\n");
    } while (ilosc < 1);

    //jesli uzytkownik poda niecalkowita liczbe wieksza od zera przy dodawaniu ilosci towaru "zwyklego", czyli niesypkiego i niecieklego
    // to jest zwracana najwieksza liczba calkowita, ktora jest mniejsza lub rowna podanemu argumentowi
    if (mojvector[i]->otrzymajjednostka() == "szt")
    {
        ilosc = floor(ilosc);
    }

    //dodanie ilosci
    mojvector[i]->ustawilosc(mojvector[i]->otrzymajilosc() + ilosc);
}

void Magazyn::odejmijsztuki() {

    int cyfra = 0;
    double ilosc = 0;
    int i = 0;

    //sprawdzenie czy rozmiar vectora jest wiekszy od 1, by w przypadku istnienia jednego obiektu program mogl pominac polecenie zwiazane z podaniem ID
    if (vectorrozmiar > 1) {
        cout << "\nWprowadz ID produktu, w ktorym chcesz dodac ilosc: ";
        cyfra = Plik::readInt();

        do {
            if (mojvector[i]->otrzymajID() != cyfra)
                i++;
        } while (mojvector[i]->otrzymajID() != cyfra && i < vectorrozmiar);

        if (mojvector[i]->otrzymajID() != cyfra)
            throw Zly_wybor ("\nNie ma produktu o takim ID.\n");
    }
    else
        cyfra = mojvector[i]->otrzymajID();

    //zabezpieczenie programu poprzez odebranie mozliwosci uzytkownikowi odjecia ilosci w produktach, w ktorych aktualnie znajduje sie zerowa ilosc
    if (mojvector[i]->otrzymajilosc() == 0)
        throw Zla_ilosc("\nNie mozna odjac ilosci produktu, poniewaz jest aktualnie zerowa ilosc danego produktu.\nNajpierw musisz dodac ilosc.\n");

    else {

        //poinformowanie uzytkownika, ze nie moze odjac ilosci mniejszej lub rownej 0
        do {
            cout << "\nJaka ilosc chcesz odjac w produkcie o numerze ID = " << cyfra << ": ";
            ilosc = Plik::readDouble();

            if (ilosc <= 0)
                throw Zly_wybor("\nPodana ilosc musi byc wieksza od zera.\n");
        }
        while (ilosc <= 0);

        if (mojvector[i]->otrzymajilosc() - ilosc < 0) {

            //poinformowanie o niemozliwosci odjecia wiekszej ilosci produktu od jej aktualnego stanu
            do {
                cout << "\nNie mozna odjac takej ilosci, poniewaz aktualna ilosc danego produktu jest mniejsza od wybranej liczby.\nWprowadz rowna badz mniejsza liczbe od aktualnej ilosci produktu.\n";
                cout << "\nPodaj nowa ilosc, jaka chcesz odjac: ";
                ilosc = Plik::readDouble();

                //jednoczesne zabezpieczenie przed podaniem wartosci mniejszych lub rownych zero
                if (ilosc <= 0) {

                    do {
                        cout << "\nPodana ilosc musi byc wieksza od zera.\n";
                        cout << "\nPodaj nowa ilosc, jaka chcesz odjac: ";
                        ilosc = Plik::readDouble();
                    } while (ilosc <= 0);
                }
            } while (mojvector[i]->otrzymajilosc() - ilosc < 0);

            //jesli uzytkownik poda niecalkowita liczbe przy odejmowaniu ilosci towaru "zwyklego", czyli niesypkiego i niecieklego to jest zwracana najwieksza liczba calkowita, ktora jest mniejsza lub rowna podanemu argumentowi
            if (mojvector[i]->otrzymajjednostka() == "szt")
            {
                ilosc = floor(ilosc);
            }

            //odjecie ilosci produktu
            mojvector[i]->ustawilosc(mojvector[i]->otrzymajilosc() - ilosc);
        }
        else {

            if (mojvector[i]->otrzymajjednostka() == "szt")
            {
                ilosc = floor(ilosc);
            }

            mojvector[i]->ustawilosc(mojvector[i]->otrzymajilosc() - ilosc);
        }
    }
}

void Magazyn::edytujmagazyn() {

    if (mojvector.otrzymajRozmiar() == 0) {
        try {
            cout << "\n";
            wypelnijvector();
            wypiszvector();
        }
        catch(Zla_ilosc & wyjatek) {
            cout << "\nZlapano wyjatek" << wyjatek.message;
        }
        catch(Zly_wybor & wyjatek) {
            cout << "\nZlapano wyjatek: " <<wyjatek.message;
        }
    }

    int wybor;
    do {
        cout <<
             "\nDodaj okreslona ilosc produktu (przyjecie)- wybierz 1\n"
             "Usun okreslona ilosc produktu (odbior)- wybierz 2\n"
             "Dodaj nowy produkt- wybierz 3\n"
             "Jesli chcesz wyjsc do menu glownego (wstecz)- wybierz 0\n"
             "\nWybierz czynnosc: ";
        wybor = Plik::readInt();

//wybor czynnosci (dodanie ilosci produktu, odjecie ilosci produktu, dodanie nowego produktu, przerwanie dzialania programu)
        try {
            switch (wybor) {
                case 0:
                    break;
                case 1:
                    wypiszvector();
                    dodajsztuki();
                    wypiszvector();
                    break;
                case 2:
                    wypiszvector();
                    odejmijsztuki();
                    wypiszvector();
                    break;
                case 3:
                    wypiszvector();
                    wypelnijvector();
                    wypiszvector();
                    break;
                default:
                    cout << "\nNiepoprawny wybor- wybierz jeszcze raz." << endl;
            }
        }
        catch(Zla_ilosc & wyjatek) {
            cout << "\nZlapano wyjatek: " << wyjatek.message << endl;
        }
        catch(Zly_wybor & wyjatek) {
            cout << "\nZlapano wyjatek: " << wyjatek.message << endl;
        }
    } while (wybor != 0);
}

int Magazyn::otrzymajnumer() const {
    return nowynumer;
}

void Magazyn::ustawnumer(int numer) {
    nowynumer = numer;
}