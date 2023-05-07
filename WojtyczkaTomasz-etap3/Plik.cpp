#include "Plik.h"
#include <string>

using namespace std;

//ciala funkcji

int Plik::readInt() {
    std::string line;
    if(czytaj == true)
        std::getline(file, line);
    else
        std::getline(std::cin, line);
    return atoi(line.c_str());
}
double Plik::readDouble() {
    std::string line;
    if(czytaj == true)
        std::getline(file, line);
    else
        std::getline(std::cin, line);
    return stod(line.c_str());
}
std::string Plik::readString() {
    std::string line;
    if(czytaj == true)
        std::getline(file, line);
    else
        std::getline(std::cin, line);
    return line;
}

