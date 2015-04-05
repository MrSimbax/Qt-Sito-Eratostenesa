#include "WidgetWybor.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

WidgetWybor::WidgetWybor(QSitoEratostenesa *QSito, QWidget *parent) :
    QWidget(parent)
{
    QLabel* qlLiczba = new QLabel("LICZBA -> ");
    QLabel* qlZakres = new QLabel("ZAKRES -> ");
    QLabel* qlMin = new QLabel("Minimum: ");
    QLabel* qlMax = new QLabel("Maximum: ");

    qsbLiczba = new QSpinBox;
    qsbMin = new QSpinBox;
    qsbMax = new QSpinBox;

    qsbLiczba->setRange(QSito->getMinimum(), QSito->getZakres());
    qsbMin->setRange(QSito->getMinimum(), QSito->getZakres());
    qsbMax->setRange(QSito->getMinimum(), QSito->getZakres());

    qsbLiczba->setValue(QSito->getMinimum());
    qsbMin->setValue(QSito->getMinimum());
    qsbMax->setValue(QSito->getZakres());

    connect(qsbMin, SIGNAL(valueChanged(int)), this, SLOT(changeLiczbaMin(int)));
    connect(qsbMax, SIGNAL(valueChanged(int)), this, SLOT(changeLiczbaMax(int)));

    connect(qsbMin, SIGNAL(valueChanged(int)), this, SLOT(changeMinMax(int)));
    connect(qsbMax, SIGNAL(valueChanged(int)), this, SLOT(changeMaxMin(int)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(qlLiczba);
    layout->addWidget(qsbLiczba);
    layout->addWidget(qlZakres);
    layout->addWidget(qlMin);
    layout->addWidget(qsbMin);
    layout->addWidget(qlMax);
    layout->addWidget(qsbMax);

    setLayout(layout);
}

QSpinBox * WidgetWybor::getLiczba() const
{
    return qsbLiczba;
}

QSpinBox * WidgetWybor::getMax() const
{
    return qsbMax;
}

QSpinBox * WidgetWybor::getMin() const
{
    return qsbMin;
}

void WidgetWybor::changeLiczbaMin(int Min)
{
    qsbLiczba->setMinimum(Min);
}

void WidgetWybor::changeLiczbaMax(int Max)
{
    qsbLiczba->setMaximum(Max);
}

void WidgetWybor::changeMinMax(int Min)
{
    qsbMax->setMinimum(Min);
}

void WidgetWybor::changeMaxMin(int Max)
{
    qsbMin->setMaximum(Max);
}
