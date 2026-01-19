#include "logica.h"
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

struct libro DatosDePrueba[10] = {{"LIB001",
                                   "Cien años de soledad",
                                   "Gabriel García Márquez",
                                   "1967",
                                   "Realismo",
                                   5,
                                   {{1, 1},
                                    {2, 2},
                                    {3, 3},
                                    {4, 1},
                                    {5, 2},
                                    {6, 3},
                                    {7, 1},
                                    {8, 2},
                                    {9, 3},
                                    {10, 1},
                                    {11, 2},
                                    {12, 3}}},
                                  {"LIB002",
                                   "Don Quijote de la Mancha",
                                   "Miguel de Cervantes",
                                   "1605",
                                   "Caballeros",
                                   3,
                                   {{1, 1},
                                    {2, 2},
                                    {3, 1},
                                    {4, 2},
                                    {5, 1},
                                    {6, 2},
                                    {7, 1},
                                    {8, 2},
                                    {9, 1},
                                    {10, 2},
                                    {11, 1},
                                    {12, 2}}},
                                  {"LIB003",
                                   "1984",
                                   "George Orwell",
                                   "1949",
                                   "Ciencia ficción distópica",
                                   7,
                                   {{1, 1},
                                    {2, 2},
                                    {3, 3},
                                    {4, 4},
                                    {5, 1},
                                    {6, 2},
                                    {7, 3},
                                    {8, 4},
                                    {9, 1},
                                    {10, 2},
                                    {11, 3},
                                    {12, 4}}},
                                  {"LIB004",
                                   "Orgullo y prejuicio",
                                   "Jane Austen",
                                   "1813",
                                   "Romance",
                                   4,
                                   {{1, 2},
                                    {2, 3},
                                    {3, 2},
                                    {4, 3},
                                    {5, 2},
                                    {6, 3},
                                    {7, 2},
                                    {8, 3},
                                    {9, 2},
                                    {10, 3},
                                    {11, 2},
                                    {12, 3}}},
                                  {"LIB005",
                                   "Crimen y castigo",
                                   "Fiódor Dostoievski",
                                   "1866",
                                   "Novela",
                                   2,
                                   {{1, 0},
                                    {2, 1},
                                    {3, 2},
                                    {4, 0},
                                    {5, 1},
                                    {6, 2},
                                    {7, 0},
                                    {8, 1},
                                    {9, 2},
                                    {10, 0},
                                    {11, 1},
                                    {12, 2}}},
                                  {"LIB006",
                                   "El principito",
                                   "Antoine de Saint-Exupéry",
                                   "1943",
                                   "Novela",
                                   10,
                                   {{1, 1},
                                    {2, 2},
                                    {3, 3},
                                    {4, 4},
                                    {5, 5},
                                    {6, 1},
                                    {7, 2},
                                    {8, 3},
                                    {9, 4},
                                    {10, 5},
                                    {11, 1},
                                    {12, 10}}},
                                  {"LIB007",
                                   "Un mundo feliz",
                                   "Aldous Huxley",
                                   "1932",
                                   "Ciencia ficcion",
                                   6,
                                   {{1, 2},
                                    {2, 3},
                                    {3, 4},
                                    {4, 2},
                                    {5, 3},
                                    {6, 4},
                                    {7, 2},
                                    {8, 3},
                                    {9, 4},
                                    {10, 2},
                                    {11, 3},
                                    {12, 4}}},
                                  {"LIB008",
                                   "El Gran Gatsby",
                                   "F. Scott Fitzgerald",
                                   "1925",
                                   "Novela",
                                   4,
                                   {{1, 0},
                                    {2, 1},
                                    {3, 0},
                                    {4, 1},
                                    {5, 0},
                                    {6, 1},
                                    {7, 0},
                                    {8, 1},
                                    {9, 0},
                                    {10, 1},
                                    {11, 0},
                                    {12, 1}}},
                                  {"LIB009",
                                   "Moby Dick",
                                   "Herman Melville",
                                   "1851",
                                   "Aventura",
                                   3,
                                   {{1, 0},
                                    {2, 1},
                                    {3, 2},
                                    {4, 3},
                                    {5, 0},
                                    {6, 1},
                                    {7, 2},
                                    {8, 3},
                                    {9, 0},
                                    {10, 1},
                                    {11, 2},
                                    {12, 3}}},
                                  {"LIB010",
                                   "La Odisea",
                                   "Homero",
                                   "Siglo VIII a.C.",
                                   "Épica",
                                   8,
                                   {{1, 3},
                                    {2, 4},
                                    {3, 5},
                                    {4, 3},
                                    {5, 4},
                                    {6, 5},
                                    {7, 3},
                                    {8, 4},
                                    {9, 5},
                                    {10, 3},
                                    {11, 4},
                                    {12, 5}}}};

int agregarDatosDePrueba(struct libro librosQueSePrestan[100], bool *poblado) {
  int count = 0;
  *poblado = true;

  int i;
  for (i = 0; i < 10; i++) {
    librosQueSePrestan[i] = DatosDePrueba[i];
    count++;
  }

  return count;
}

void toLowerCase(char str[100]) {
  int i;
  for (i = 0; str[i] != '\0' && i < 100; i++) {
    str[i] = tolower((unsigned char)str[i]);
  }
}

void buscarLibrosPorMateria(struct libro libros[100], int size,
                            struct libro seleccionDeLibros[100],
                            int *seleccionDeLibrosSize, char materia[100]) {
  int i = 0;
  int contador = 0;
  char tempMateria[100];
  toLowerCase(materia);
  for (i = 0; i < size; i++) {
    strcpy(tempMateria, libros[i].materia);
    toLowerCase(tempMateria);
    if (strcmp(tempMateria, materia) == 0) {
      strcpy(seleccionDeLibros[contador].id, libros[i].id);
      strcpy(seleccionDeLibros[contador].nombre, libros[i].nombre);
      strcpy(seleccionDeLibros[contador].autor, libros[i].autor);
      strcpy(seleccionDeLibros[contador].publicacion, libros[i].publicacion);
      strcpy(seleccionDeLibros[contador].materia, libros[i].materia);
      seleccionDeLibros[contador].cantidadDeCopias = libros[i].cantidadDeCopias;
      int mes;
      for (mes = 0; mes < 12; mes++) {
        seleccionDeLibros[contador].prestamosPorCadaMes[mes][0] =
            libros[i].prestamosPorCadaMes[mes][0];
        seleccionDeLibros[contador].prestamosPorCadaMes[mes][1] =
            libros[i].prestamosPorCadaMes[mes][1];
      }
      contador++;
    }
  }

  *seleccionDeLibrosSize = contador;
}

void agregarLibro(int *size, struct libro librosQueSePrestan[100],
                  struct libro nuevoLibro) {
  librosQueSePrestan[*size] = nuevoLibro;
  *size = *size + 1;
}

void librosPrestadosCompletamante(struct libro libros[], int numLibros,
                                  struct libroResultado resultado[],
                                  int *size) {
  int contador = 0;

  int i;
  for (i = 0; i < numLibros; i++) {
    int encontrado = 0;
    int mes;
    for (mes = 0; mes < 12; mes++) {
      if (libros[i].prestamosPorCadaMes[mes][1] >= libros[i].cantidadDeCopias) {
        strcpy(resultado[contador].titulo, libros[i].nombre);
        strcpy(resultado[contador].id, libros[i].id);
        resultado[contador].mes = mes + 1;
        contador++;
        encontrado = 1;
        mes = 12;
      }
    }
  }

  *size = contador;
}
