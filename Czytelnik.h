/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Czytelnik.h"
 * 20.06.2023
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Produkt.h"
#include "ZmienneGlobalne.h"

class Czytelnik {
private:
    std::string imieNazwisko;
    int idCzytelnika;
    std::vector<Produkt> wypozyczoneProduktyArchiwum;

public:
    Czytelnik(std::string imieNazwisko_h);

    //Przeniosłam tę zmienną z prywatnych do publicznych,
    //by móc z niej skorzystać w klasie "Biblioteka".
    std::vector<Produkt> wypozyczoneProdukty;

    std::string get_imieNazwisko();
    int get_idCzytelnika();

    void dodajDoWypozyczonychProduktow(Produkt produkt);
    std::string usunZWypozyczonychProduktow(Produkt produkt);

};



