#include "interfaz.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void menu() {
  int opcion;
  int entradaValida;
  bool poblado;

  struct libro libros[100];
  int size = agregarDatosDePrueba(libros, &poblado);

  struct libroResultado results[100];
  int resultsSize = 0;

  struct libro seleccionDeLibros[100];
  int seleccionDeLibrosSize = 0;

  struct libro nuevoLibro;
  char materia[100];

  struct libro libroSeleccionado;
  char id[100];

  char aniosDeLibros[50][5];
  int sizeAniosDeLibros = 0;
  do {
    printf("\n MEN\23 CENTRO DE INVESTIGACION. Opciones funcionales: "
           "1,2,3,4,7,0 \n");
    printf("1. Agregar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Libros que en alg\243n mes fueron prestados todos sus "
           "ejemplares\n");
    printf("4. Libros que pertenecen a una materia dada\n");
    printf("5. A\244os de publicacion de los libros\n");
    printf("6. Libro que m\240s veces se ha prestado\n");
    printf("7. Devolver libro por identificador\n");
    printf("0. Salir\n");
    printf("Seleccione una opci\242n: ");
    entradaValida = scanf("%d", &opcion);
    if (!entradaValida) {
      printf("Error al leer opci\242n. Intente de nuevo.\n");
      fflush(stdin);
    } else {
      switch (opcion) {
      case 1:
        nuevoLibro = pedirLibro(libros, size);
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
        obtenerAniosDeLibros(aniosDeLibros, &sizeAniosDeLibros, libros, size);
        mostrarLibrosPorAnio(libros, size, aniosDeLibros, &sizeAniosDeLibros);
        break;
      case 6:
        buscarLibroMasPrestado(libros, size, &libroSeleccionado);
        mostrarLibroFullData(libroSeleccionado);
        break;
      case 7:
        pedirDatos("Introduzca el id del libro: ", id, 1, 15);
        libroSeleccionado = buscarLibroPorId(libros, size, id);
        mostrarLibroFullData(libroSeleccionado);
        break;
      case 0:
        printf("Saliendo del programa...\n");
        break;
      default:
        printf("Opc\242n no v\240lida. Intente de nuevo.\n");
      }
    }
    printf("Presiona Enter para continuar...");
    getchar();
    getchar();
    system("clear");
    printf("%d\n", entradaValida);
  } while (opcion != 0 || !entradaValida);
}
