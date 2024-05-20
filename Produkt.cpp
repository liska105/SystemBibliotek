/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Produkt.cpp"
 * 20.06.2023
 */
#include "Produkt.h"

//konstruktor
Produkt::Produkt(std::string autor_h, std::string tytul_h, std::string wydawnictwo_h, int liczbaStron_h) {
    autor = autor_h;
    tytul = tytul_h;
    wydawnictwo = wydawnictwo_h;
    liczbaStron = liczbaStron_h;
    //Ustawiam unikalny numer produktu na 0,
    //ponieważ każda biblioteka ma swoją
    //numerację i dopiero przy dodaniu produktu do danej
    //biblioteki zyska on swój unikalny numer.
    unikalnyNumer = 0;
    dostepnoscProduktu = true;
}

//getery

std::string Produkt::get_autor() {
    return autor;
}

std::string Produkt::get_tytul() {
    return tytul;
}

std::string Produkt::get_wydawnictwo() {
    return wydawnictwo;
}

int Produkt::get_liczbaStron() {
    return liczbaStron;
}

int Produkt::get_unikalnyNumer() {
    return unikalnyNumer;
}

bool Produkt::get_dostepnoscProduktu() {
    return dostepnoscProduktu;
}

//

void Produkt::set_UnikalnyNumer(int numer) {
    unikalnyNumer = numer;
}

void Produkt::set_dostepnoscProduktu(bool zmiennaBoolowska) {
    dostepnoscProduktu = zmiennaBoolowska;
}

//Definiuję operator, aby móc porównać dwa produkty
//w 35 wierszu w pliku "Czytelnik.cpp".
bool operator== (Produkt produkt1, Produkt produkt2){
    return (produkt1.get_autor() == produkt2.get_autor()) &&
           (produkt1.get_tytul() == produkt2.get_tytul()) &&
           (produkt1.get_wydawnictwo() == produkt2.get_wydawnictwo()) &&
           (produkt1.get_liczbaStron() == produkt2.get_liczbaStron()) &&
           (produkt1.get_unikalnyNumer() == produkt2.get_unikalnyNumer()) ;
}







