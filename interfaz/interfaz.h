#include "../logica/logica.h"

void menu();
void mostrarLibros(struct libro libros[], int size);
void mostrarLibrosResultados(struct libroResultado libros[], int size);
struct libro pedirLibro();
void pedirAlpha(char mensaje[30], char buffer[100], int minLen, int maxLen);
void mostrarVariosLibrosFullData(struct libro libros[], int size);
