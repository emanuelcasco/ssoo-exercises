#ifndef EJERCICIO1_H_
#define EJERCICIO1_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_concat (const char*, const char*);
void string_concat_dinamyc(const char*, const char*, char**);
void mail_split(const char* mail, char** user, char** dominio);

#endif /* EJERCICIO1_H_ */