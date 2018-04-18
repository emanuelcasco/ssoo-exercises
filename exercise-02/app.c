// Se pide modelar un TAD que represente un Archivo, se debe poder: 
//   - Abrir (definir la forma: read/write/append). DONE
//   - Cerrar. DONE
//   - Leer una linea determinada.
//   - Exponer una operación que reciba una función y la ejecute por cada línea del archivo.
//   - Exponer otra operación que dada una lista y una función,
//     itere la lista y escriba sobre el archivo abierto lo que devuelve dicha función (string).




#include "app.h"

int main(void) {
  fileman * fm = fmopen("holamundo.txt", "r");
  int len = fmcountlines(MAXLINE, fm);
  printf("%d", len);
  fmclose(fm);
  return 0;
}
