/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "main.cpp"
 * 20.06.2023
 */
#include <iostream>
#include "Miasto.h"
#include "Biblioteka.h"
#include "Czytelnik.h"
#include "Produkt.h"
#include "Ksiazka.h"
#include "Czasopismo.h"
using namespace std;

int main() {

    //Tworzę miasta, na których będę wykonywać testy.
    Miasto miasto1("Warszawa", "mazowieckie");
    Miasto miasto2("Wrocław", "dolnośląskie");
    Miasto miasto3("Opole", "opolskie");
    Miasto miasto4("Katowice", "śląslie");

    //Tworzę biblioteki, które dodam do miasta "Warszawa".
    Biblioteka bibliotekaWwa1("WarszawskaBiblioteka", "ul.Główna1",
                              567453128, 128);
    Biblioteka bibliotekaWwa2("Książeczka", "ul.Szeroka4",
                              900876543, 325);
    Biblioteka bibliotekaWwa3("Czytelniak", "ul.Kolista76",
                              433673502, 230);
    Biblioteka bibliotekaWwa4("BibliotekaUW", "ul.Uniwersytecka1",
                              625785124, 1000);
    Biblioteka bibliotekaWwa5("BibliotekaUW", "ul.Uniwersytecka90",
                              123531754, 500);

    //Dodaję utworzone biblioteki do miasta "Warszawa".
    cout << "Dodaję biblioteki do miasta Warszawa:" << endl;
    cout << miasto1.dodajBiblioteke(bibliotekaWwa1) << endl;
    cout << miasto1.dodajBiblioteke(bibliotekaWwa2) << endl;
    cout << miasto1.dodajBiblioteke(bibliotekaWwa3) << endl;
    cout << miasto1.dodajBiblioteke(bibliotekaWwa4) << endl;
    //Sprawdzam, czy program poprawnie się zachowa gdy spróbuję dodać
    //bibliotekę o tej samej nazwie.
    cout << miasto1.dodajBiblioteke(bibliotekaWwa5) << endl;
    cout << miasto1.usunBiblioteke("BibliotekaUW") << endl;
    cout << miasto1.dodajBiblioteke(bibliotekaWwa5) << endl;
    cout << endl;


    //Tworzę biblioteki, które dodam do miasta "Wrocław".
    Biblioteka bibliotekaWroc1("Biblioteczka", "ul.Biblioteczna1",
                              504367166, 324);
    Biblioteka bibliotekaWroc2("BibliotekaUWr", "ul.Mostowa34",
                               711267832, 2000);
    Biblioteka bibliotekaWroc3("KsiążkiUJadzi", "ul.Jagodna",
                               503225165, 20);

    //Dodaję utworzone biblioteki do miasta "Wrocław".
    cout << "Dodaję biblioteki do miasta Wrocław:" << endl;
    cout << miasto2.dodajBiblioteke(bibliotekaWroc1) << endl;
    cout << miasto2.dodajBiblioteke(bibliotekaWroc2) << endl;
    cout << miasto2.dodajBiblioteke(bibliotekaWroc3) << endl;
    cout << endl;

    //Tworzę bibliotekę, którą dodam do miasta "Opole".
    Biblioteka bibliotekaOp1("JedynaBibliotekaWOpolu", "ul.Opolska",
                             664672376, 600);

    //Dodaję utworzoną biblioteke do miasta "Opole".
    cout << "Dodaję bibliotekę do miasta Opole:" << endl;
    cout << miasto3.dodajBiblioteke(bibliotekaOp1) << endl;
    cout << endl;

    //Tworzę biblioteki, które dodam do miasta "Katowice".
    Biblioteka bibliotekaKat1("BibliotekaHutnicza", "ul.Huta1",
                               501456155, 3000);
    Biblioteka bibliotekaKat2("MalutkaBiblioteczka", "ul.Przyjazna8",
                              900874277, 5);
    Biblioteka bibliotekaKat3("BibliotekaGłówna", "ul.Główna5",
                              777325166, 1234);

    cout << "Dodaję biblioteki do miasta Katowice:" << endl;
    cout << miasto4.dodajBiblioteke(bibliotekaKat1) << endl;
    cout << miasto4.dodajBiblioteke(bibliotekaKat2) << endl;
    cout << miasto4.dodajBiblioteke(bibliotekaKat3) << endl;
    cout << endl;

    //Testuję funkcje klasy "Miasto".
    cout << "Miasto " + miasto1.get_nazwaMiasta() +
    " znajduje się w województwie o nazwie " + miasto1.get_wojewodztwo() << endl;
    cout << endl;


    //Testuję funkcje klasy "Biblioteka".
    cout << "Przed zmianą lokalizacji biblioteka " + bibliotekaWwa3.get_nazwaBiblioteki() +
    " znajdowała się na " + bibliotekaWwa3.get_adres() + " ,a jej magazyn mieścił "
    + to_string(bibliotekaWwa3.get_pojemnoscMagazynu())+ " produktów" << endl;
    //Biblioteka "Czytelniak" zmienia swoją lokalizację.
    bibliotekaWwa3.set_adres("ul.Krucza24");
    bibliotekaWwa3.set_pojemnoscMagazynu(345);
    cout << "Po zmianie lokalizacji biblioteka " + bibliotekaWwa3.get_nazwaBiblioteki() +
            " znajduje się na " + bibliotekaWwa3.get_adres() + " ,a jej magazyn mieści "
            + to_string(bibliotekaWwa3.get_pojemnoscMagazynu())+ " produktów" << endl;
    cout << endl;

    cout << "Biblioteka o nazwie " + bibliotekaKat2.get_nazwaBiblioteki() + " zmieniła nazwę. ";
    bibliotekaKat2.set_nazwaBiblioteki("MiniBiblioteczka");
    cout << "Od teraz będzie znana jako " + bibliotekaKat2.get_nazwaBiblioteki() << endl;
    cout << endl;

    bibliotekaOp1.set_numerKontaktowy(885471953);
    cout << "Biblioteka " + bibliotekaOp1.get_nazwaBiblioteki() +
    " zmieniła numer kontaktowy! Od teraz dzwońcie pod numer " + to_string(bibliotekaOp1.get_numerKontaktowy()) << endl;
    cout << endl;


    //Tworzę czytelników.
    ostatnieId = 0;
    Czytelnik czytelnik1("Kasia Kot");
    Czytelnik czytelnik2("Juliusz Konieczny");
    Czytelnik czytelnik3("Anna Strzała");
    Czytelnik czytelnik4("Marian Jaskier");
    Czytelnik czytelnik5("Wojciech Cień");
    Czytelnik czytelnik6("Krzysztof Frama");
    Czytelnik czytelnik7("Marcin Rytm");
    Czytelnik czytelnik8("Barbara Wróbel");
    Czytelnik czytelnik9("Maria Grudniowa");
    Czytelnik czytelnik10("Adam Hak");
    Czytelnik czytelnik11("Izabela Pawłowska");
    Czytelnik czytelnik12("Kacper Janusz");
    Czytelnik czytelnik13("Waleria Magiczna");

    //Testuję funkcje klasy "Czytelnik".
    cout << "Czytelnik o numerze id " + to_string(czytelnik10.get_idCzytelnika())
    + " nazywa się " + czytelnik10.get_imieNazwisko() << endl;
    cout << endl;


    //Tworzę książki.
    Ksiazka ksiazka1("Adam Bolesny", "Krzaki",
                     "Wydawnictwo Omega", 456, 2016);
    Ksiazka ksiazka2("Czesław Groźny", "Natarcie Smoka",
                     "Alfa Ksiązki", 145, 2012);
    Ksiazka ksiazka3("Natalnia Bema", "Lodziarnia",
                     "Wydawnictwo Pantofelek", 657, 2015);
    Ksiazka ksiazka4("Bartosz Sroka", "O wilku",
                     "Wydawnictwo Omega", 65, 2022);
    Ksiazka ksiazka5("Joanna Lilia", "Waleczny Miecz",
                     "Wydawnictwo Omega", 444, 2013);
    Ksiazka ksiazka6("Urszula Wojtkowiak", "Wakacje nad Odrą",
                     "Wydawnictwo Pantofelek", 1290, 2017);

    //Tworzę czasopisma.
    Czasopismo czasopismo1("Tymoteusz Sobota", "Niskie Obcasy",
                           "Wydawnictwo Czas", 20, 7);
    Czasopismo czasopismo2("Olga Fontanna", "Fit Life",
                           "Wydawnictwo Omega", 17, 30);
    Czasopismo czasopismo3("Nataniel Jutro", "Modnista",
                           "Wydawnictwo Czas", 50, 14);
    Czasopismo czasopismo4("Sylfia Kontroler", "Nowinki dla Graczy",
                           "Wydawnictwo Pantofelek",30 , 1);


    //Testuję funkcje klasy "Biblioteka"
    cout << bibliotekaWroc2.zalozKarteBiblioteczna(czytelnik1) << endl;
    cout << bibliotekaWroc2.zalozKarteBiblioteczna(czytelnik2) << endl;
    cout << bibliotekaWroc2.zalozKarteBiblioteczna(czytelnik3) << endl;
    cout << bibliotekaWroc2.zalozKarteBiblioteczna(czytelnik4) << endl;
    cout << bibliotekaWroc2.zalozKarteBiblioteczna(czytelnik4) << endl;
    cout << endl;

    cout << bibliotekaWroc2.dodajKsiazke(ksiazka1) << endl;
    cout << bibliotekaWroc2.dodajKsiazke(ksiazka2) << endl;
    cout << bibliotekaWroc2.dodajKsiazke(ksiazka3) << endl;
    cout << bibliotekaWroc2.dodajCzasopismo(czasopismo1) << endl;
    cout << bibliotekaWroc2.dodajCzasopismo(czasopismo2) << endl;

    cout << bibliotekaWroc2.wypozyczProdukt("Nowinki dla Graczy", 3) << endl;
    cout << bibliotekaWroc2.wypozyczProdukt("Krzaki", 3) << endl;
    cout << bibliotekaWroc2.wypozyczProdukt("Krzaki", 1) << endl;
    //W tym miejscu funkcja nie zwraca tego co powinna.
    //Niestety nie potafiłam naprawić błedu.
    cout << bibliotekaWroc2.zwrocProdukt("Krzaki", 1) << endl;
    //
    cout << bibliotekaWroc2.zwrocProdukt("Krzaki", 12) << endl;
    cout << bibliotekaWroc2.sprawdzStatusProduktu("Krzaki") << endl;
    cout << bibliotekaWroc2.zwrocProdukt("Krzaki", 1) << endl;
    cout << endl;

    cout << "Aktualny stan magazynu biblioteki " + bibliotekaKat2.get_nazwaBiblioteki()
    + " wynosi " + to_string(bibliotekaKat2.get_aktualnaLiczbaProduktow()) + " produktów" << endl;
    cout << bibliotekaKat2.dodajKsiazke(ksiazka1) << endl;
    cout << bibliotekaKat2.dodajKsiazke(ksiazka1) << endl;
    cout << bibliotekaKat2.dodajKsiazke(ksiazka1) << endl;
    cout << bibliotekaKat2.dodajKsiazke(ksiazka1) << endl;
    cout << bibliotekaKat2.dodajKsiazke(ksiazka1) << endl;
    cout << bibliotekaKat2.dodajKsiazke(ksiazka1) << endl;
    cout << "Aktualny stan magazynu biblioteki " + bibliotekaKat2.get_nazwaBiblioteki()
            + " wynosi " + to_string(bibliotekaKat2.get_aktualnaLiczbaProduktow()) + " produktów" << endl;
    cout << bibliotekaKat2.usunProdukt(4) << endl;
    cout << "Aktualny stan magazynu biblioteki " + bibliotekaKat2.get_nazwaBiblioteki()
            + " wynosi " + to_string(bibliotekaKat2.get_aktualnaLiczbaProduktow()) + " produkty" << endl;
    cout << "Magazyn biblioteki " + bibliotekaKat2.get_nazwaBiblioteki() + " mieści " +
    to_string(bibliotekaKat2.get_pojemnoscMagazynu()) + " produktów." << endl;
    cout << endl;

    //Testuję funkcje klas "Produkt", "Czasopismo" oraz "Książka".
    cout << "Książka " + ksiazka1.get_tytul() + " została wydana przez " +
    ksiazka1.get_wydawnictwo() + " w " + to_string(ksiazka1.get_rokWydania()) + " roku." << endl;
    cout << "Książka " + ksiazka2.get_tytul() + " została wydana przez " +
            ksiazka2.get_wydawnictwo() + " w " + to_string(ksiazka2.get_rokWydania()) + " roku." << endl;
    cout << "Czasopismo " + czasopismo1.get_tytul() + " liczy " + to_string(czasopismo1.get_liczbaStron()) +
            " stron i jest wydawane co " + to_string(czasopismo1.get_okresWydania()) + " dni." << endl;
    czasopismo1.set_okresWydania(18);
    cout << "Czasopismo " + czasopismo1.get_tytul() + " zmieniło okres wydania i od teraz jest wydawane co "
             + to_string(czasopismo1.get_okresWydania()) + " dni." << endl;
    cout << czasopismo3.zakonczWydawanie(czasopismo3) << endl;
    cout << czasopismo3.zakonczWydawanie(czasopismo3) << endl;
    cout << endl;

    return 0;
}
