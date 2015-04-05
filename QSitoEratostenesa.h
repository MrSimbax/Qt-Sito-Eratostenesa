#ifndef QSITOERATOSTENESA_H
#define QSITOERATOSTENESA_H

#include "SitoEratostenesa.h"
#include <QtWidgets/QWidget>

// qsitoeratostenesa.h
// Klasa powstala aby dodac dodatkowe obiekty
// do klasy i mogla byc uzywana razem z
// biblioteka Qt

class QSitoEratostenesa : public QWidget, public SitoEratostenesa
{
Q_OBJECT

public:
    // KONSTRUKTORY I DESTRUKTORY
    QSitoEratostenesa(int Zakres = CnMaximum);

    // FUNKCJE PRZELADOWANE
    bool getCzyLiczbaPierwsza(); // UWAGA! Zwroci wartosc ustawiona przez setCzyLiczbaPierwsza()

signals:
    void usedCzyLiczbaPierwsza(bool); //  Czy funkcja setCzyLiczbaPierwsza zostala uzyta?
    void usedstrLiczbyPierwsze(std::string);

public slots:
    void setCzyLiczbaPierwsza(int Liczba);
    void setstrLiczbyPierwsze(int Min, int Max);

private:
    bool bCzyLiczbaPierwsza; // zmienna pomocnicza
};

#endif // QSITOERATOSTENESA_H
