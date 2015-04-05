#include "WidgetCzyPierwsza.h"

#include <QFont>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

#include "QSitoEratostenesa.h"
#include "WidgetWybor.h"


WidgetCzyPierwsza::WidgetCzyPierwsza(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Sito Eratostenesa");

    // Proram sie dlugo uruchamia z powodu konstruktora
    // w ktorej wypelnia on dosyc duza tablice.
    // To moze trwac nawet 10 sekund!
    QSito = new QSitoEratostenesa();

    QLabel *label = new QLabel("Czy liczba jest pierwsza?");
    label->setFont(QFont("Times", 18, QFont::Bold));

    wybor = new WidgetWybor(QSito);

    bLabel = new QLabel("TAK");
    bLabel->setFont(QFont("Times", 18, QFont::Bold));

    textedit = new QTextEdit;
    textedit->setReadOnly(true);

    QPushButton *button = new QPushButton("Oblicz zakres");
    QLabel *label2 = new QLabel("UWAGA! Duzy zakres moze spowolnic lub nawet zawiesic program!");

    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(button);
    layout2->addWidget(label2);

    connect(wybor->getLiczba(), SIGNAL(valueChanged(int)), QSito, SLOT(setCzyLiczbaPierwsza(int)));
    connect(QSito, SIGNAL(usedCzyLiczbaPierwsza(bool)), this, SLOT(changebLabel(bool)));
    connect(button, SIGNAL(clicked()), this, SLOT(changeDocument()));
    connect(wybor->getLiczba(), SIGNAL(valueChanged(QString)), this, SLOT(findNumber(QString)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(wybor);
    layout->addWidget(bLabel);
    layout->addLayout(layout2);
    layout->addWidget(textedit);

    setLayout(layout);
}

WidgetCzyPierwsza::~WidgetCzyPierwsza()
{
    delete bLabel;
    delete textedit;
    delete wybor;
    delete QSito;
}

void WidgetCzyPierwsza::changebLabel(bool b)
{
    if(b == true) bLabel->setText(QString("NIE"));
    else bLabel->setText(QString("TAK"));
}

void WidgetCzyPierwsza::changeDocument()
{
    QSito->setstrLiczbyPierwsze(wybor->getMin()->value(), wybor->getMax()->value());
    textedit->setHtml(QString(QSito->getstrLiczbyPierwsze().c_str()));
}

void WidgetCzyPierwsza::findNumber(QString qstring)
{
    textedit->find(qstring, QTextDocument::FindWholeWords);
    textedit->find(qstring, QTextDocument::FindWholeWords | QTextDocument::FindBackward);
}
