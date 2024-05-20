/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Produkt.hu"
 * 20.06.2023
 */
#pragma once

#include <string>

class Produkt {
private:
    std::string autor;
    std::string tytul;
    std::string wydawnictwo;
    int liczbaStron;
    int unikalnyNumer;
    bool dostepnoscProduktu;

public:
    //konstruktor
    Produkt(std::string autor_h, std::string tytul_h, std::string wydawnictwo_h, int liczbaStron_h);

    //getery
    std::string get_autor();
    std::string get_tytul();
    std::string get_wydawnictwo();
    int get_liczbaStron();
    int get_unikalnyNumer();
    bool get_dostepnoscProduktu();

    void set_UnikalnyNumer(int numer);
    void set_dostepnoscProduktu(bool zmiennaBoolowska);


    friend bool operator== (Produkt produkt1, Produkt produkt2);

};



