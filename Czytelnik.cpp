/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Czytelnik.cpp"
 * 20.06.2023
 */
#include "Czytelnik.h"

//Tworzę konstruktor.
Czytelnik::Czytelnik(std::string imieNazwisko_h) {
    imieNazwisko = imieNazwisko_h;
    idCzytelnika = ostatnieId + 1;
    //Zwiększam zmnienną "ostatnieId" o jeden,
    //by następny czytelnik miał inny numer.
    ostatnieId ++;
}

std::string Czytelnik::get_imieNazwisko() {
    return imieNazwisko;
}

int Czytelnik::get_idCzytelnika() {
    return idCzytelnika;
}


void Czytelnik::dodajDoWypozyczonychProduktow(Produkt produkt) {
    wypozyczoneProdukty.push_back(produkt);
}

//Tworzę funkcję, która usuwa produkt z listy aktualnie
//wypożyczonych produktów i dodaje go do archiwum wypożyczonych
//przez czytelnika produktów.
std::string Czytelnik::usunZWypozyczonychProduktow(Produkt produkt) {
    //Przechodzę pętlą po liście wypożyczonych produktów, aby znaleźć ten,
    //który chcę usunąć.
    for (auto it = wypozyczoneProdukty.begin();
    it != wypozyczoneProdukty.end(); it++) {
        //Gdy znajdę dany produkt, usuwam go z listy aktualnie
        //wypożyczonych produktów i dodaję do archiwum.
        if (*it == produkt) {
            wypozyczoneProduktyArchiwum.push_back(*it);
            wypozyczoneProdukty.erase(it);
            return "Książka została usunięta z listy wypożyczonych książek.";
        }
    }
    //Jeżeli nie znalazłam na tej liście danego produktu,
    //zwracam użytnikowi taką informację.
    return "Produkt nie został usunięty z wypożyczonych książek, "
           "ponieważ nie było go wśród nich.";
}





