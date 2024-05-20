/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Czasopismo.cpp"
 * 20.06.2023
 */
#include "Czasopismo.h"

//Tworzę konstruktor.
Czasopismo::Czasopismo(std::string autor_h, std::string tytul_h,
                       std::string wydawnictwo_h, int liczbaStron_h, int okresWydania_wDniach_h)
        : Produkt(autor_h, tytul_h, wydawnictwo_h, liczbaStron_h) {
    okresWydania_wDniach = okresWydania_wDniach_h;
    //Ustawaim wartość zmiennej, która mówi, czy czasopismo jest aktualnie wydawane, na prawdę.
    czyJestWydawane = true;
}

int Czasopismo::get_okresWydania() {
    return okresWydania_wDniach;
}

void Czasopismo::set_okresWydania(int nowyOkres) {
    okresWydania_wDniach = nowyOkres;
}

bool Czasopismo::czyJestJeszczeWydawane() {
    return czyJestWydawane;
}

std::string Czasopismo::zakonczWydawanie(Czasopismo czasopismo) {
    //Sprawdzam, czy podane na wejściu czasopismo jest jeszcze wydawane.
    if (czasopismo.czyJestJeszczeWydawane()) {
        //Jeśli tak, to zmieniam wartość "czyJestWydawane" na fałsz.
        czyJestWydawane = false;
        return "Zakończono wydawanie czasppisma " + czasopismo.get_tytul() + ".";
    }
    //W przeciwnym wypadku:
    return "Nie da się zakończyć wydawania czasopisma " + czasopismo.get_tytul() + "." +
                     " Dane czasopismo już wcześniej przestało być wydawane.";

}
