#include <ctype.h>
#include <stdbool.h>

bool validarDigitos(const char cadena[100]) {
  bool res = true;
  int i;
  for (i = 0; cadena[i] != '\0'; i++) {
    if (!isdigit(cadena[i])) {
      res = false;
    }
  }
  return res;
}
