/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Ksiazka.h"
 * 20.06.2023
 */
#pragma once
#include "Produkt.h"

//Tworzę klasę "Książka", która dziedziczy po klasie "Produkt".
class Ksiazka : public Produkt {
private:
    int rokWydania;

public:
    Ksiazka(std::string autor_h, std::string tytul_h,
            std::string wydawnictwo_h, int liczbaStron_h, int rokWydania_h);

    int get_rokWydania();
};


