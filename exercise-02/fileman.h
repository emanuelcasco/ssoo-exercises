#ifndef FILEMAN_H_
#define FILEMAN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
  char* name;
  char* method;
  FILE* fp;
} fileman;

typedef struct node {
  char* data;
  struct node * next;
} node_t;

#endif /* FILEMAN_H_ */