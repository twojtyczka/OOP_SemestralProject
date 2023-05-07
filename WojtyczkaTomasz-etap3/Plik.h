#ifndef WOJTYCZKATOMASZ_ETAP3_PLIK_H
#define WOJTYCZKATOMASZ_ETAP3_PLIK_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern bool czytaj;
extern std::ifstream file;

//utworzenie klasy
class Plik {

public:

    //metody klasy
    Plik() {

    };
    ~Plik() {

    };

    static int readInt();
    static double readDouble();
    static std::string readString();

};

#endif //WOJTYCZKATOMASZ_ETAP3_PLIK_H
