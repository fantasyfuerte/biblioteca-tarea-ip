#include "datos.h"
#include <stdbool.h>

int agregarDatosDePrueba(struct libro librosQueSePrestan[100], bool *poblado);

void agregarLibro(int *size, struct libro librosQueSePrestan[100],
                  struct libro nuevoLibro);

void buscarLibrosPorMateria(struct libro libros[100], int size,
                            struct libro seleccionDeLibros[100],
                            int *seleccionDeLibrosSize, char materia[100]);

void librosPrestadosCompletamante(struct libro libros[], int numLibros,
                                  struct libroResultado resultado[], int *size);

struct libro buscarLibroPorId(struct libro libros[100], int size, char id[100]);

void buscarLibroMasPrestado(struct libro libros[100], int size,
                            struct libro *libro);

void obtenerAniosDeLibros(char aniosDeLibros[50][5], int *sizeAniosDeLibros,
                          struct libro libros[], int size);
