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
