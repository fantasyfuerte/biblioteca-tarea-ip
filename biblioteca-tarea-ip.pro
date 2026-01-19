TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    interfaz/interfaz.c \
    interfaz/menu.c \
    logica/logica.c \
    interfaz/validaciones.c

HEADERS += \
    interfaz/interfaz.h \
    logica/datos.h \
    logica/logica.h \
    interfaz/validaciones.h

OTHER_FILES += \
    logica/logica.h.pch

