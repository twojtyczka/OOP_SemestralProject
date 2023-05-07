#include "Paleciak.h"

Paleciak::Paleciak() {
    udzwig = 10;
}
Paleciak::Paleciak(int udzwig) : udzwig(udzwig) {

}
Paleciak::~Paleciak() {

}

int Paleciak::otrzymajudzwig() const {
    return udzwig;
}

void Paleciak::ustawudzwig(int udzwig) {
    udzwig = udzwig;
}
