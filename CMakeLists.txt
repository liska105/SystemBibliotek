cmake_minimum_required(VERSION 3.24)
project(projekt_po)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekt_po main.cpp Miasto.cpp Miasto.h Biblioteka.cpp Biblioteka.h Produkt.cpp Produkt.h Ksiazka.cpp Ksiazka.h Czasopismo.cpp Czasopismo.h Czytelnik.cpp Czytelnik.h "ZmienneGlobalne.cpp" "ZmienneGlobalne.h")
