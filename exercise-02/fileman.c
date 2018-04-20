#include "fileman.h"

fileman * fm_open (char * name, char * method) {
  fileman * fm = malloc(sizeof(fileman));
  fm->name = name;
  fm->method = method;
  fm->fp = fopen(fm->name, fm->method);
  if (fm->fp == NULL) {
    perror ("Error opening file");
  }
  return fm;
}

void fm_write(fileman * fm, char * text) {
  fprintf(fm->fp, "%s\n", text);
}

int fm_countlines(int maxlength, fileman * fm) {
  int count = 0;
  char line[maxlength];
  while (fgets(line, maxlength * sizeof(char), fm->fp) != NULL) {
    count++;
  }
  return count;
}

char* fm_read(int maxlength, fileman * fm) {
  int count = 0;
  char * line = malloc(maxlength * sizeof(char));
  while (fgets(line, maxlength * sizeof(char), fm->fp) != NULL) {
    count++;
  }
  return line;
}

char* fm_readline(int lineNumber, int maxlength, fileman * fm) {
  int count = 0;
  char * line = malloc(maxlength * sizeof(char));
  while (fgets(line, maxlength * sizeof(char), fm->fp) != NULL && count != lineNumber) {
    count++;
  }
  return line;
}

void fm_mapfile(int maxlength, void (*f)(char*),fileman * fm) {
  int count = 0, length = maxlength * sizeof(char);
  char * line = malloc(length);
  while (fgets(line, length, fm->fp) != NULL) {
    (*f)(line);
  }
}

void fm_maplist(node_t* head, char* (*f)(char*), fileman * fm) {
  node_t * current = head;

  while (current != NULL) {
    fm_write(fm, current->data);
    current = current->next;
  }
}

void fm_close(fileman * fm) {
  fclose(fm->fp);
  free(fm);
}
