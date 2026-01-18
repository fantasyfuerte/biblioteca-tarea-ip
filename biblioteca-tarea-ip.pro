TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    interfaz/interfaz.c \
    interfaz/menu.c \
    logica/logica.c

HEADERS += \
    interfaz/interfaz.h \
    logica/datos.h \
    logica/logica.h

OTHER_FILES += \
    logica/logica.h.pch

