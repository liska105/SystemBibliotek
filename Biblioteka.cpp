/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Biblioteka.cpp"
 * 20.06.2023
 */
#include "Biblioteka.h"

//Tworzę konstruktor.
Biblioteka::Biblioteka(std::string nazwaBiblioteki_h, std::string adres_h,
                       int numerKontaktowy_h, int pojemnoscMagazynu_h) {
    nazwaBiblioteki = nazwaBiblioteki_h;
    adres = adres_h;
    numerKontaktowy = numerKontaktowy_h;
    pojemnoscMagazynu = pojemnoscMagazynu_h;
    aktualnaLiczbaProduktow = 0;
    //Każda biblioteka ma swoją numerację dla produktów.
    //Przy tworzeniu biblikoteki ustawiam ostatni unikalny numer na 0.
    //Gdy dodaję do biblioteki nowy produkt, ustawiam jego unikalny numer
    //na o jeden większy od poprzedniego dodanego produktu.
    ostatniUnikalnyNumer = 0;
}

//Implementuję funkcje "get".
std::string Biblioteka::get_nazwaBiblioteki() {
    return nazwaBiblioteki;
}

std::string Biblioteka::get_adres() {
    return adres;
}

int Biblioteka::get_numerKontaktowy() {
    return numerKontaktowy;
}

int Biblioteka::get_pojemnoscMagazynu() {
    return pojemnoscMagazynu;
}

int Biblioteka::get_aktualnaLiczbaProduktow() {
    return aktualnaLiczbaProduktow;
}


//Implementuję funkcje "set".
void Biblioteka::set_nazwaBiblioteki(std::string nowaNazwa) {
    nazwaBiblioteki = nowaNazwa;
}

void Biblioteka::set_numerKontaktowy(int nowyNumer) {
    numerKontaktowy = nowyNumer;
}

void Biblioteka::set_adres(std::string nowyAdres) {
    adres = nowyAdres;
}

void Biblioteka::set_pojemnoscMagazynu(int nowaPojemnosc) {
    pojemnoscMagazynu = nowaPojemnosc;
}


//Implementuję pozostałe funkcje.

//Tworzę funkcję służącą do dodawania kiążek do biblioteki.
std::string Biblioteka::dodajKsiazke(Ksiazka nowaKsiazka) {
    //Sprawdzam, czy jest w magazynie miejsce na dodanie produktu.
    if (aktualnaLiczbaProduktow < pojemnoscMagazynu) {
        //Jeżeli tak, to nadaje książce, którą dodaje do biblioteki, unikatowy numer
        //i zwiększam wartość zmiennej "ostatniUnikalnyNumer" o jeden.
        //Nastepnie dodaje tę kiążke do listy produktów.
        nowaKsiazka.set_UnikalnyNumer(ostatniUnikalnyNumer + 1);
        ostatniUnikalnyNumer++;
        produkty.push_back(nowaKsiazka);
        aktualnaLiczbaProduktow ++;
        return "Książka " + nowaKsiazka.get_tytul() + " została dodana do biblioteki.";
    }
    return "Nie można dodać produktu, magazyn jest pełny" ;
}

//Tworzę funkcję służącą do dodawania czasopism do biblioteki.
std::string Biblioteka::dodajCzasopismo(Czasopismo noweCzasopismo) {
    //Sprawdzam, czy jest w magazynie miejsce na dodanie produktu.
    if (aktualnaLiczbaProduktow < pojemnoscMagazynu) {
        //Jeżeli tak, to nadaje czasopiśmie, które dodaje do biblioteki, unikatowy numer
        //i zwiększam wartość zmiennej "ostatniUnikalnyNumer" o jeden.
        //Nastepnie dodaje to czasopismo do listy produktów.
        noweCzasopismo.set_UnikalnyNumer(ostatniUnikalnyNumer + 1);
        ostatniUnikalnyNumer++;
        produkty.push_back(noweCzasopismo);
        aktualnaLiczbaProduktow++;
        return "Czasopismo " + noweCzasopismo.get_tytul() + " zostało dodane do biblioteki.";
    }
    return "Nie można dodać produktu, magazyn jest pełny" ;

}

//Tworzę funkcję służącą do usuwania produktów z biblioteki.
std::string Biblioteka::usunProdukt(int unikalnyNumer) {
    //Przechodzę pętlą po liście produktów dostępnych w bibliotece.
    for (auto it = produkty.begin(); it != produkty.end(); it++) {
        //Gdy natrafię na produkt, który chcę usunąć,
        //usuwam go z listy produktów i zmniejszam liczbę
        //produktów w magazynie o jeden.
        if (it->get_unikalnyNumer() == unikalnyNumer) {
            produkty.erase(it);
            aktualnaLiczbaProduktow --;
            return "Produkt został usunięty.";
        }
    }
    //Jeżeli nie natrafię na ten produkt, to informuję o tym użytkownika.
    return "W magazynie nie ma produktu, który chcesz usunąć, więc nie został usunięty.";
}

//Tworzę funkcje słóżącą do dodawania czytelników do biblioteki.
std::string Biblioteka::zalozKarteBiblioteczna(Czytelnik nowyCzytelnik) {
    //Przechodzę pętlą po liście czytelników zapisanych do danej biblioteki.
    for (auto it = czytelnicy.begin(); it != czytelnicy.end(); it++) {
        //Jeżeli czytelnik, którego chcę zapisać do biblioteki jest już
        //do niej zapisany, informuję o tym użytkownika i nie zapisuję
        //czytelnika do biblioteki.
        if (it->get_idCzytelnika() == nowyCzytelnik.get_idCzytelnika()) {
            return "Czytelnik o numerze id " + std::to_string(nowyCzytelnik.get_idCzytelnika())
            + " jest już zapisany do tej biblioteki ";
        }
    }
    //W przeciwnym przypadku dodaję czytelnika do listy czytelników tej biblioteki.
    czytelnicy.push_back(nowyCzytelnik);
    return "Czytelnik " + nowyCzytelnik.get_imieNazwisko() + " został zapisany do biblioteki.";
}

//Tworzę funkcję służącą do wypożyczania produktów. Przyjmuje ona tytuł produktu,
//który czytelnik chce wypożyczyć oraz id tego czytelnika.
std::string Biblioteka::wypozyczProdukt(std::string tytul, int idCzytelnika) {
    //Szukam produktu o takim tytule przechodząc pętlą po liście produktów
    //dostępnych w bibliotece.
    for (auto it = produkty.begin(); it != produkty.end(); it++) {
        //Gdy natrafię na taki produkt,
        if (it->get_tytul() == tytul) {
            //Przechodzę pętlą po liście czytelników zapisanych do biblioteki,
            //aby sprawdzic, czy czytelnik, który chce wypożyczyć produkt się na niej znajduje.
            for (auto jt = czytelnicy.begin(); jt != czytelnicy.end(); jt++) {
                //Jeżeli czytelnik jest zapisany do biblioteki, to
                if (jt->get_idCzytelnika() == idCzytelnika) {
                    //dodaję produkt do listy aktualnie wypożyczonych produktów z biblioteki,
                    aktualnieWypozyczone.push_back(*it);
                    //usuwam go z listy produktów biblioteki,
                    produkty.erase(it);
                    //zmieniam stan jego dostepności
                    it->set_dostepnoscProduktu(false);
                    //oraz dodaję do listy aktualnie wypożyczonych produktów przez czytelnika.
                    jt->dodajDoWypozyczonychProduktow(*it);
                    return "Produkt " + tytul + " został wypożyczony";
                }
            }
            //Jeżeli czytelnik nie jest zapisany do biblioteki, z której chce
            //wypożyczyć produkt, zalecam mu zapisanie się do tej biblioteki
            //oraz ponowną próbę wypożyczenia produktu.
            return "Czytelnik o numerze id " + std::to_string(idCzytelnika)
            + " nie jest zapisany do tej biblioteki. "
                   "Załóż kartę biblioteczną i spróbuj wypożyczyć ponownie.";
        }
    }
    //Jeżeli produktu nie ma na liście produktów dostępnych w bibliotece, sprawdzam, czy jest
    //wśród produktów aktualnie wypożyczonych z biblioteki.
    for (auto it = aktualnieWypozyczone.begin();
    it != aktualnieWypozyczone.end(); it++) {
        //Jeżeli tak, to informuję o tym użytkownika i zalecam ponowną
        // próbę wypożyczenia w najbliższej przyszłości.
        if (it->get_tytul() == tytul) {
            return "Wszystkie kopie " + tytul + " są aktualnie wypożyczone. "
                   "Spróbuj ponownie niedługo.";
        }
    }
    //W przeciwnym wypadku informuję, że dany produkt nie jest dostępny w tej bibliotece.
    return "Nie posiadamy produktu " + tytul  + " w naszej bibliotece.";
}

//Tworzę funkcję służącą do zwracania produktów. Przyjmuje ona tytuł produktu,
//który czytelnik chce zwrócić oraz id tego czytelnika.
std::string Biblioteka::zwrocProdukt(std::string tytul, int idCzytelnika) {
    //Szukam produktu o takim tytule przechodząc pętlą po liście produktów
    //aktualnie wypożyczonych z biblioteki.
    for (auto it = aktualnieWypozyczone.begin()
            ; it != aktualnieWypozyczone.end(); it++) {
        //Gdy natrafię na taki produkt,
        if (it->get_tytul() == tytul) {
            //Przechodzę pętlą po liście czytelników zapisanych do biblioteki,
            //aby sprawdzic, czy czytelnik, który chce zwrócić produkt się na niej znajduje.
            for (auto jt = czytelnicy.begin(); jt != czytelnicy.end(); jt++) {
                //Jeżeli czytelnik jest zapisany do biblioteki,
                if (jt->get_idCzytelnika() == idCzytelnika) {
                    //Przechodzę pętlą po liście wypożyczonych przez czytelnika produktów,
                    // aby sprawdzić czy jest wśród nich dany tytuł.
                    for (auto kt = jt->wypozyczoneProdukty.begin(); kt != jt->wypozyczoneProdukty.end(); kt++) {
                        //Jeśli jest, dodaję ten produkt na listę produktów w bibliotece
                        //oraz usuwam go z listy aktualnie wypożyczonych produktów z biblioteki.
                        //Następnie zmieniam dostępność produktu i wywołuje funkcję, która
                        //usuwa ten produkt z listy aktualnie wypożyczonych produktów przez czytelnika
                        //i dodaje go na listę produktów wypożyczonych przez czytelnika w przeszłości.
                        if (kt->get_tytul() == tytul) {
                            produkty.push_back(*it);
                            aktualnieWypozyczone.erase(it);
                            it->set_dostepnoscProduktu(true);
                            jt->usunZWypozyczonychProduktow(*it);
                            return "Książka została zwrócona";
                        }
                    }
                    //Jeżeli wśród produktów wypożyczonych przez czytelnika, nie było danego tytułu,
                    //zwracam ową informację użytkownikowi.
                    return "Dany czytelnik nie ma aktualnie wypożyczonej książki o danym tytule.";
                }
            }
            //Jeżeli dany czytelnik nie jest zapisany do biblioteki, zwracam użytkownikowi taką informację.
            return "Czytelnik o podanym numerze id nie jest zapisany do tej biblioteki. "
                   "Nie miał możliwości wypożyczenia książki.";
        }
    }
    //Gdy danego tytułu nie ma na liście aktualnie wypożyczonych produktów, zwracam użytkownikowi taką informację.
    return "Produkt, który próbujesz zwrócić nie jest aktualnie wypożyczony";
}

//Tworzę funkcję służącą do sprawdzenia stanu dostępności produktu.
std::string Biblioteka::sprawdzStatusProduktu(std::string tytul) {
    //Szukam produktu o takim tytule przechodząc pętlą po liście produktów dostępnych w bibliotece.
    for (auto it = produkty.begin(); it != produkty.end(); it++) {
        //Jeżeli produkt jest dostępny, zwracam taką informację.
        if (it->get_tytul() == tytul) {
            return "Książka jest dostępna w bibliotece";
        }
    }
    //W przeciwnym przypadku, szukam produktu o takim tytule przechodząc
    //pętlą po liście produktów aktualnie wypożyczonych z biblioteki.
    for (auto it = aktualnieWypozyczone.begin(); it != aktualnieWypozyczone.end(); it++) {
        //Jeśli znajdę produkt na tej liście, informuję o tym użytkownika.
        if (it->get_tytul() == tytul) {
            return "Wszystkie egzemplarze tego tytułu są aktualnie wypożyczone.";
        }
    }
    //Jeżeli produkt nie jest dostepny w bibliotece oraz nie jest aktualnie wypożyczony,
    //informuję, że produkt nie jest dostępny.
    return "Nie posiadamy tego tytułu w naszej bibliotece.";
}



