/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Ksiazka.cpp"
 * 20.06.2023
 */
#include "Ksiazka.h"

Ksiazka::Ksiazka(std::string autor_h, std::string tytul_h,
                 std::string wydawnictwo_h, int liczbaStron_h, int rokWydania_h)
: Produkt(autor_h, tytul_h,  wydawnictwo_h, liczbaStron_h) {
    rokWydania = rokWydania_h;
}

int Ksiazka::get_rokWydania() {
    return rokWydania;
}

