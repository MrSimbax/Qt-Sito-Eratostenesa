#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include "WidgetWybor.h"

// Klasa obiektu QWidget, ktora odpowiada
// za stworzenie okna, jego wyswietlanie
// i ewentualna zmiane.

class WidgetCzyPierwsza : public QWidget
{
    Q_OBJECT
    
public:
    WidgetCzyPierwsza(QWidget *parent = 0);
    ~WidgetCzyPierwsza();
    
private:
    QLabel *bLabel; // zmienna pomocnicza
                    // (wyswietla TAK lub NIE)
    QTextEdit *textedit;
    WidgetWybor *wybor;
    QSitoEratostenesa *QSito;
private slots:
    void changebLabel(bool); // zmienia zmienna pomocnicza label2
                            // (na TAK lub NIE)
    void changeDocument();
    void findNumber(QString);
};

#endif // WIDGET_H
