/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Biblioteka.hs"
 * 20.06.2023
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Produkt.h"
#include "Czytelnik.h"
#include "Ksiazka.h"
#include "Czasopismo.h"

class Biblioteka {
private:
    //Deklaruje zmienne.
    std::string nazwaBiblioteki;
    std::string adres;
    int numerKontaktowy;
    int pojemnoscMagazynu;
    int aktualnaLiczbaProduktow;
    std::vector<Produkt> produkty;
    std::vector<Produkt> aktualnieWypozyczone;
    std::vector<Czytelnik> czytelnicy;
    int ostatniUnikalnyNumer;

public:
    //Deklaruję konstruktor.
    Biblioteka(std::string nazwaBiblioteki_h, std::string adres_h, int numerKontaktowy_h, int pojemnoscMagazynu_h);

    //Deklaruję funkcje "get".
    std::string get_nazwaBiblioteki();
    std::string get_adres();
    int get_numerKontaktowy();
    int get_pojemnoscMagazynu();
    int get_aktualnaLiczbaProduktow();

    //Deklaruję funkcje "set".
    void set_nazwaBiblioteki(std::string nowaNazwa);
    void set_adres(std::string nowyAdres);
    void set_numerKontaktowy(int nowyNumer);
    void set_pojemnoscMagazynu (int nowaPojemnosc);

    //Deklaruję pozostałe funkcje.
    std::string dodajKsiazke(Ksiazka nowaKsiazka);
    std::string dodajCzasopismo(Czasopismo noweCzasopismo);
    std::string usunProdukt(int unikalnyNumer);
    std::string zalozKarteBiblioteczna(Czytelnik nowyCzytelnik);
    std::string wypozyczProdukt(std::string tytul, int idCzytelnika);
    std::string zwrocProdukt(std::string tytul, int idCzytelnika);
    std::string sprawdzStatusProduktu(std::string tytul);
};



