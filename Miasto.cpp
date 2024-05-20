/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Miasto.cpp"
 * 20.06.2023
 */
#include "Miasto.h"

Miasto::Miasto(std::string nazwaMiasta_h, std::string wojewodztwo_h) {
    nazwaMiasta = nazwaMiasta_h;
    wojewodztwo = wojewodztwo_h;
}


std::string Miasto::get_nazwaMiasta() {
    return nazwaMiasta;
}

std::string Miasto::get_wojewodztwo() {
    return wojewodztwo;
}


std::string Miasto::dodajBiblioteke(Biblioteka nowaBiblioteka) {
    //Sprawdzam, czy biblioteka o takiej nazwie istnieje w mieście.
    for (auto it = biblioteki.begin(); it != biblioteki.end(); ++it) {
        //Jeżeli tak, to informuję użytkownika, że nie może dodać
        //biblioteki o takiej nazwie.
        if (it->get_nazwaBiblioteki() == nowaBiblioteka.get_nazwaBiblioteki()) {
            return "Biblioteka o nazwie " + nowaBiblioteka.get_nazwaBiblioteki() + " już istnieje w tym mieście. "
                   "Wymyśl nową nazwę i spróbuj ponownie.";

        }
    }
    //Jeżeli nie, to dodaję bibliotekę do listy bibliotek tego miasta.
    biblioteki.push_back(nowaBiblioteka);
    return "Biblioteka " + nowaBiblioteka.get_nazwaBiblioteki() + " została dodana.";
}

std::string Miasto::usunBiblioteke(std::string nazwaBiblioteki) {
    //Przechodzę po liście bibliotek w danym mieście i szukam tej,
    //którą chcę usunąć.
    for (auto it = biblioteki.begin(); it != biblioteki.end(); ++it) {
        //Gdy ją znajdę, usuwam ją z listy bibliotek.
        if (it->get_nazwaBiblioteki() == nazwaBiblioteki) {
            biblioteki.erase(it);
            return "Biblioteka o nazwie " + nazwaBiblioteki + " została usunięta.";
        }
    }
    //Jeżeli biblioteki o takiej nazwie nie ma w mieście,
    //informuję o tym użytkownika.
    return "Biblioteka o podanej nazwie nie istnieje, zatem nie da się jej usunąć.";
}




