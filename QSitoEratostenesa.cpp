#include "QSitoEratostenesa.h"

QSitoEratostenesa::QSitoEratostenesa(int Zakres)
    : SitoEratostenesa(Zakres)
{
    bCzyLiczbaPierwsza = true;
}

bool QSitoEratostenesa::getCzyLiczbaPierwsza()
{
    return bCzyLiczbaPierwsza;
}

void QSitoEratostenesa::setCzyLiczbaPierwsza(int Liczba)
{
    if(Liczba > nZakres || Liczba < CnMinimum) Liczba = CnMinimum;
    bCzyLiczbaPierwsza = bapLiczbyPierwsze[Liczba];

    emit usedCzyLiczbaPierwsza(bCzyLiczbaPierwsza);
}

void QSitoEratostenesa::setstrLiczbyPierwsze(int Min, int Max)
{
    SitoEratostenesa::setstrLiczbyPierwsze(Min, Max);

    emit usedstrLiczbyPierwsze(strLiczbyPierwsze);
}
