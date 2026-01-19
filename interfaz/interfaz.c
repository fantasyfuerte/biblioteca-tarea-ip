#include "interfaz.h"
#include "validaciones.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pedirDatos(char mensaje[30], char buffer[100], int minLen, int maxLen) {
  do {
    printf("%s", mensaje);

    fgets(buffer, maxLen + 2, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
      len--;
    } else {
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    } // esta manera de eliminar el salto de linea y de limpiar el buffer es la
      // unica que me funciono en la mac para esta funcion fgets, gets si ni pa
      // atras ni pa alante

    if (len < minLen || len > maxLen) {
      printf("El tama\244o de la entrada debe ser entre %d y %d caracteres.\n",
             minLen, maxLen);
    }
  } while (strlen(buffer) < minLen || strlen(buffer) > maxLen);
}

void pedirAno(char buffer[50], int minAnio, int maxAnio) {
  int esValido;

  do {
    esValido = 1;
    pedirDatos("Ingrese el a\244o: ", buffer, 4, 4);
    if (!validarDigitos(buffer)) {
      printf("El a\244o debe contener solo digitos.\n");
      esValido = 0;
    } else {
      int anio = atoi(buffer);

      if (anio < minAnio || anio > maxAnio) {
        printf("El a\244o debe estar entre %d y %d\n", minAnio, maxAnio);
        esValido = 0;
      }
    }
  } while (!esValido);
}

void pedirAlpha(char mensaje[30], char buffer[100], int minLen, int maxLen) {
  bool salir;
  do {
    salir = true;
    pedirDatos(mensaje, buffer, minLen, maxLen);
    int i;
    for (i = 0; (buffer[i] != '\0' && salir); i++) {
      if (!isalpha(buffer[i]) && buffer[i] != ' ') {
        salir = false;
      }
    }
  } while (!salir);
}

int pedirCantidadCopiasInt(int minCant, int maxCant) {
  char buffer[20];
  int cantidad;
  int esValido;

  do {
    esValido = 1;
    bool stop = false;

    char mensaje[50];
    snprintf(mensaje, sizeof(mensaje),
             "Ingrese cantidad de copias (entre %d y %d): ", minCant, maxCant);

    pedirDatos(mensaje, buffer, 1, 10);
    int i;
    for (i = 0; (buffer[i] != '\0' || stop); i++) {
      if (!isdigit(buffer[i])) {
        printf("Error: Solo se permiten digitos. Caracter inv\240lido: '%c'\n",
               buffer[i]);
        esValido = 0;
        stop = true;
      }
    }

    if (esValido) {
      cantidad = atoi(buffer);

      if (cantidad < minCant || cantidad > maxCant) {
        printf("Error: La cantidad debe estar entre %d y %d.\n", minCant,
               maxCant);
        esValido = 0;
      }
    }

  } while (!esValido);

  return cantidad;
}

int pedirCopiasPrestadas(int cantidadDeCopias, int mes) {
  int cantidad;
  char tempCantidad[100];
  bool esValido;
  do {
    printf("Ingrese cantidad de copias (entre 1 y %d) para el mes %d: ",
           cantidadDeCopias, mes);
    pedirDatos("", tempCantidad, 1, 4);
    esValido = validarDigitos(tempCantidad);
    if (!esValido) {
      printf("La cantidad debe contener solo digitos.\n");
    }
    cantidad = atoi(tempCantidad);
    if (cantidad < 1 || cantidad > cantidadDeCopias) {
      printf("La cantidad debe estar entre 1 y %d.\n", cantidadDeCopias);
      esValido = false;
    }
  } while (!esValido);
  cantidad = atoi(tempCantidad);
  return cantidad;
}

struct libro pedirLibro() {
  struct libro nuevo;

  pedirDatos("Id del libro: ", nuevo.id, 3, 15);
  pedirAlpha("Nombre del libro: ", nuevo.nombre, 1, 100);
  pedirAlpha("Autor del libro: ", nuevo.autor, 1, 100);
  pedirAno(nuevo.publicacion, 1100, 2026);
  pedirAlpha("Materia/Género: ", nuevo.materia, 1, 100);
  nuevo.cantidadDeCopias = pedirCantidadCopiasInt(1, 10);
  int i;
  for (i = 0; i < 12; i++) {
    int j;
    for (j = 0; j < 2; j++) {
      nuevo.prestamosPorCadaMes[i][j] =
          pedirCopiasPrestadas(nuevo.cantidadDeCopias, i + 1);
    }
  }

  printf("\nLibro agregado correctamente.\n");
  return nuevo;
}

void mostrarLibros(struct libro libros[], int size) {
  printf("Mostrando libros:\n");
  if (size == 0) {
    printf("No hay libros en la biblioteca.\n");
  } else {
    int i;
    for (i = 0; i < size; i++) {
      printf("%s - %s\n", libros[i].id, libros[i].nombre);
    }
  }
}

void mostrarLibrosResultados(struct libroResultado libros[], int size) {
  printf("Mostrando libros:\n");
  if (size == 0) {
    printf("Ning\242n libro se agot\242.\n");
  } else {
    int i;
    for (i = 0; i < size; i++) {
      printf("%s - %s\n", libros[i].id, libros[i].titulo);
    }
  }
}

void mostrarLibroFullData(struct libro libro) {
  printf("Id: %s\n", libro.id);
  printf("Nombre: %s\n", libro.nombre);
  printf("Autor: %s\n", libro.autor);
  printf("Publicaci\242n: %s\n", libro.publicacion);
  printf("Materia: %s\n", libro.materia);
  printf("Cantidad de copias: %d\n", libro.cantidadDeCopias);
  printf("Pr\202stamos:\n");
  int mes;
  for (mes = 0; mes < 12; mes++) {
    printf("%d - %d\n", mes + 1, libro.prestamosPorCadaMes[mes][0]);
  }
}

void mostrarVariosLibrosFullData(struct libro libros[], int size) {
  int i;
  if (size == 0) {
    printf("No se encontraron libros con esa materia\n");
  } else {
    for (i = 0; i < size; i++) {
      mostrarLibroFullData(libros[i]);
      printf("\n---\n");
    }
  }
}
