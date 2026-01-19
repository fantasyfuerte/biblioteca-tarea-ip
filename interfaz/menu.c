#include "interfaz.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void menu() {
  int opcion;
  bool poblado;

  struct libro libros[100];
  int size = agregarDatosDePrueba(libros, &poblado);

  struct libroResultado results[100];
  int resultsSize = 0;

  struct libro seleccionDeLibros[100];
  int seleccionDeLibrosSize = 0;

  struct libro nuevoLibro;
  char materia[100];
  do {
    printf("\n MENÚ CENTRO DE INVESTIGACION \n");
    printf("1. Agregar libro\n");
    printf("2. Mostrar libros\n");
    printf(
        "3. Libros que en algún mes fueron prestados todos sus ejemplares\n");
    printf("4. Libros que pertenecen a una materia dada\n");
    printf("5. Años de publicacion de los libros\n");
    printf("6. Libro que más veces se ha prestado\n");
    printf("0. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      nuevoLibro = pedirLibro();
      agregarLibro(&size, libros, nuevoLibro);
      printf("Se agrego %s satisfactoriamente\n", nuevoLibro.nombre);
      break;
    case 2:
      mostrarLibros(libros, size);
      break;
    case 3:
      librosPrestadosCompletamante(libros, size, results, &resultsSize);
      mostrarLibrosResultados(results, resultsSize);
      break;
    case 4:
      pedirAlpha("Introduzca la materia: ", materia, 3, 50);
      buscarLibrosPorMateria(libros, size, seleccionDeLibros,
                             &seleccionDeLibrosSize, materia);
      mostrarVariosLibrosFullData(seleccionDeLibros, seleccionDeLibrosSize);
      break;
    case 5:
      printf("Años de publicacion de los libros\n");
      break;
    case 6:
      printf("Libro que más veces se ha prestado\n");
      break;
    case 0:
      printf("Saliendo del programa...\n");
      break;
    default:
      printf("Opción no válida. Intente de nuevo.\n");
    }
    printf("Presiona Enter para continuar...");
    getchar(); // profe cambiar esto por system("pause") y system("cls") para
               // windows
    getchar();
    system("clear");
  } while (opcion != 0);
}
