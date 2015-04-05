QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sitoeratostenesa
TEMPLATE = app


SOURCES += main.cpp \
    SitoEratostenesa.cpp \
    QSitoEratostenesa.cpp \
    WidgetCzyPierwsza.cpp \
    WidgetWybor.cpp

HEADERS  += SitoEratostenesa.h \
    QSitoEratostenesa.h \
    WidgetCzyPierwsza.h \
    WidgetWybor.h
