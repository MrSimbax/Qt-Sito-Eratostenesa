QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sitoeratostenesa
TEMPLATE = app
CONFIG += static


SOURCES += main.cpp \
    SitoEratostenesa.cpp \
    QSitoEratostenesa.cpp \
    WidgetCzyPierwsza.cpp \
    WidgetWybor.cpp

HEADERS  += SitoEratostenesa.h \
    QSitoEratostenesa.h \
    WidgetCzyPierwsza.h \
    WidgetWybor.h

QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
