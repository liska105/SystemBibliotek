/*
 * Katarzyna Jodłowska
 * Programowanie Obiektowe, Zadanie Końcowe, "Miasto.h"
 * 20.06.2023
 */
#pragma once
#include <iostream>
#include <vector>
#include "Biblioteka.h"

class Miasto {
private:
    std::string nazwaMiasta;
    std::string wojewodztwo;
    std::vector<Biblioteka> biblioteki;

public:
    Miasto(std::string nazwaMiasta_h, std::string wojewodztwo_h);

    std::string get_nazwaMiasta();
    std::string get_wojewodztwo();

    std::string dodajBiblioteke(Biblioteka nowaBiblioteka);
    std::string usunBiblioteke(std::string nazwaBiblioteki);
};




