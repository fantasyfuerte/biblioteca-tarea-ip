struct libro {
  char id[15];
  char nombre[100];
  char autor[100];
  char publicacion[100];
  char materia[100];
  int cantidadDeCopias;
  int prestamosPorCadaMes[12][2];
};

struct libroResultado {
  char titulo[100];
  char id[15];
  int mes;
};
