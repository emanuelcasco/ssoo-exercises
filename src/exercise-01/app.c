#include "app.h"

char* string_concat (const char*, const char*);
void string_concat_dinamyc(const char*, const char*, char**);
void mail_split(const char* mail, char** user, char** dominio);

int main(void) {
// Punto a
  char* nombre = "Ema";
  char * string = string_concat("Hola ", nombre);
  printf("1)   %s!!\n", string);
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
  printf("3)  User: %s & Dominio: %s!!\n", user, dominio);
  
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
  char* new_str = malloc(sizeof(str1) + sizeof(str2));
  return strcat(strcat(new_str, str1), str2);
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
void string_concat_dinamyc (const char* str1, const char* str2, char* *new_str) {
  *new_str = malloc(sizeof(str1) + sizeof(str2));
  strcat(strcat(*new_str, str1), str2);
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
void mail_split(const char* mail, char** user, char** dominio) {
  char *ret = memchr(mail, '@', strlen(mail));
  *dominio = ret + 1;
  // printf("%s", dominio);
}