/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Czasopismo.h"
 * 20.06.2023
 */
#pragma once
#include "Produkt.h"
#include <iostream>

//Tworzę klasę "Czasopismo", która dziedziczy po klasie "Produkt".
class Czasopismo : public Produkt {
private:
    //Deklaruję zmienne.
    int okresWydania_wDniach;
    bool czyJestWydawane;

public:
    Czasopismo(std::string autor_h, std::string tytul_h,
               std::string wydawnictwo_h, int liczbaStron_h, int okresWydania_wDniach_h);

    int get_okresWydania();
    void set_okresWydania(int nowyOkres);
    bool czyJestJeszczeWydawane();
    std::string zakonczWydawanie(Czasopismo czasopismo);
};


