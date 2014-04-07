#include "SitoEratostenesa.h"

#include <iostream>
#include <sstream>

SitoEratostenesa::SitoEratostenesa(int Zakres)
{
    if(Zakres > CnMaximum || Zakres < CnMinimum) Zakres = CnMaximum;
    else nZakres = Zakres;

    bapLiczbyPierwsze = new bool[nZakres + 1]; // + 1 bo indeksy
                                               // tablicy sa liczone od zera

    // WYPELNIENIE TABLICY (ALGORYTM SITA ERATOSTENESA)
    // Wypelnienie calej tablicy niewykreslonymi liczbami

    for(int i = 0; i < nZakres+1; i++)
        bapLiczbyPierwsze[i] = false;

    // Wlasciwy algorytm
    for(int i = 2; i*i <= nZakres; i++)
    {
        if(bapLiczbyPierwsze[i] == true)
            continue;
        for(int j = 2 * i; j <= nZakres; j += i)
            bapLiczbyPierwsze[j] = true;
    }
    // --------------------------------------------------

    // TRUE - LICZBA WYKRESLONA (NIE PIERWSZA)
    // FALSE - LICZBA NIEWYKRESLONA (PIERWSZA)
}

SitoEratostenesa::~SitoEratostenesa()
{
    delete [] bapLiczbyPierwsze;
}

int SitoEratostenesa::getMaximum() const
{
    return CnMaximum;
}

int SitoEratostenesa::getMinimum() const
{
    return CnMinimum;
}

int SitoEratostenesa::getZakres() const
{
    return nZakres;
}

bool SitoEratostenesa::getCzyLiczbaPierwsza(int Liczba) const
{
    if(Liczba > nZakres || Liczba < CnMinimum) Liczba = CnMinimum;
    return bapLiczbyPierwsze[Liczba];
}

std::string SitoEratostenesa::getstrLiczbyPierwsze() const
{
    return strLiczbyPierwsze;
}

void SitoEratostenesa::setstrLiczbyPierwsze(int Min, int Max)
{
    if(Min < CnMinimum) Min = CnMinimum;
    if(Max > nZakres) Max = nZakres;

    std::ostringstream text;

    for(int i = Min; i <= Max; i++)
        if(bapLiczbyPierwsze[i] == false) text << " " << i;

    strLiczbyPierwsze = text.str();
}
