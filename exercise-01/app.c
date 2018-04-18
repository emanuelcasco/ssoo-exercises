#include "app.h"

int main(void) {
// Punto a
  char* nombre = "Ema";
  char * string = string_concat("Hola ", nombre);
  printf("1)   %s!!\n", string);
  free(string);
// Punto b
  char* cat;
  string_concat_dinamyc("Hola ", nombre, &cat);
  printf("2)   %s!!\n", cat);
  free(cat);
// Punto c
  char* mail = "ritchie@ansic.com.ar";
  char* user;
  char* dominio;
  mail_split(mail, &user, &dominio);
  printf("3)   user: '%s'/dominio: '%s'\n", user, dominio);
  free(user);
  
  return 0;
}

/* 
*   Retorna un String nuevo que es la concatenación
*   de los dos Strings pasados por parámetro
*   Ejemplo:
*   char* nombre = "Ritchie";
*   char* saludo = string_concat("Hola ", nombre);
*   =>
*   saludo = "Hola Ritchie"
*/
char* string_concat (const char* str1, const char* str2) {
  char* result = malloc(sizeof(str1) + sizeof(str2) + 1);
  strcpy(result, str1);
  strcat(result, str2);
  return result;
}

/*
*   Asigna en el tercer parámetro, la concatenación
*   de los primeros dos Strings
*   Ejemplo:
*   char* nombre = "Ritchie";
*   char* saludo;
*   string_concat("Hola ", nombre, &saludo);
*   =>
*   saludo = "Hola Ritchie"
*/
void string_concat_dinamyc (const char* str1, const char* str2, char** result) {
  *result = malloc(sizeof(str1) + sizeof(str2) + 1);
  strcpy(*result, str1);
  strcat(*result, str2);
}

/*
*   Separa el mail en un usuario y un dominio.
*   Ejemplo:
*   char* mail = "ritchie@ansic.com.ar";
*   char* user;
*   char* dominio;
*   mail_split(mail, &user, &dominio);
*   =>
*   user = "ritchie"
*   dominio = "ansic.com.ar"
*/

void splitAfter(const char* string, char ch, char** result) {
  *result = strchr(string, ch) + 1;
}

void splitBefore(const char* string, char ch, char** result) {
  int i = 0;
  while(i < strlen(string)) {
    if (string[i] == ch) break;
    i++;
  }
  *result = strndup(string, i);
}

void mail_split(const char* mail, char** user, char** dominio) {
  int c = '@';
  splitAfter(mail, c, dominio);
  splitBefore(mail, c, user);
}