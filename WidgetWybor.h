#ifndef WIDGETWYBOR_H
#define WIDGETWYBOR_H

#include <QtWidgets/QWidget>
#include "QSitoEratostenesa.h"

#include <QtWidgets/QSpinBox>

class WidgetWybor : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetWybor(QSitoEratostenesa *QSito, QWidget *parent = 0);
    
    QSpinBox * getLiczba() const;
    QSpinBox * getMin() const;
    QSpinBox * getMax() const;
private:
    QSpinBox *qsbLiczba;
    QSpinBox *qsbMin;
    QSpinBox *qsbMax;
signals:
    
public slots:
    void changeLiczbaMin(int);
    void changeLiczbaMax(int);
    void changeMinMax(int);
    void changeMaxMin(int);
};

#endif // WIDGETWYBOR_H
