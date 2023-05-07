#ifndef WOJTYCZKATOMASZ_ETAP3_WYJATEK_H
#define WOJTYCZKATOMASZ_ETAP3_WYJATEK_H

#include <string>

struct Wyjatek {
    std::string message;
    explicit Wyjatek(std::string msg) : message(std::move(msg)) {}
};

struct Zly_wybor : public Wyjatek {
    explicit Zly_wybor(std::string msg) : Wyjatek(std::move(msg)) {}
};

struct Zla_ilosc : public Wyjatek {
    explicit Zla_ilosc(std::string msg) : Wyjatek(std::move(msg)) {}
};
#endif //WOJTYCZKATOMASZ_ETAP3_WYJATEK_H
