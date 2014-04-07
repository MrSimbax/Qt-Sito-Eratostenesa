#ifndef SITOERATOSTENESA_H
#define SITOERATOSTENESA_H

#include <string>

// sitoeratostenesa.h
// Klasa podstawowa.

class SitoEratostenesa
{
public:
    // KONSTRUKTORY I DESTRUKTORY
    SitoEratostenesa(int Zakres = CnMaximum);
    ~SitoEratostenesa();

    // FUNKCJE DOSTĘPOWE DO ZMIENNYCH
    int getMaximum() const;
    int getMinimum() const;
    int getZakres() const;
    bool getCzyLiczbaPierwsza(int Liczba) const; // Czy podana liczba jest pierwsza?
    std::string getstrLiczbyPierwsze() const;

    void setstrLiczbyPierwsze(int Min, int Max);

protected:
    // WARTOSCI STALE
    static const int CnMaximum = 10000000;// Maksymalna liczba jaka mozna podac w zakresie,
                                            // nie powinna przekraczac sizeof(int)
    static const int CnMinimum = 2;        // Minimalna liczba jaka mozna podac w zakresie,
                                            // Nie mniej niz 2 (0 i 1 to nie
                                            // liczby pierwsze)

    // ZWYKLE ZMIENNE
    int nZakres;                            // Przechowuje wielkosc tablicy bapLiczbyPierwsze
    bool *bapLiczbyPierwsze;                // Tablica do przechowywania Stosu Eratostenesa
                                            // false = liczba nieskreslona
                                            // true = liczba skreslona

    std::string strLiczbyPierwsze;
};

#endif // SITOERATOSTENESA_H
