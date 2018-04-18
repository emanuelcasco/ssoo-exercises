#include "fileman.h"

typedef struct file {
  char* name;
  char* method;
  FILE* fp;
} fileman;

// open_file (file, method)
// close_file (file)
// read_file_line (line_number, file)
// map_file_lines (function, file)
// map_list_and_save (list, function, file)

fileman * fmopen (char * name, char * method) {
  fileman * fm = malloc(sizeof(fileman));
  fm->name = name;
  fm->method = method;
  fm->fp = fopen(fm->name, fm->method);
  if (fm->fp == NULL) {
    perror ("Error opening file");
  }
  return fm;
}

void fmwrite(fileman * fm, char * text) {
  fprintf(fm->fp, "%s\n", text);
}

int fmcountlines(int maxlength, fileman * fm) {
  int count = 0;
  char line[maxlength];
  while (fgets(line, maxlength * sizeof(char), fm->fp) != NULL) {
    count++;
  }
  return count;
}

char* fmread(int maxlength, fileman * fm) {
  int count = 0;
  char * line = malloc(maxlength * sizeof(char));
  while (fgets(line, maxlength * sizeof(char), fm->fp) != NULL) {
    count++;
  }
  return line;
}

char* fmreadline(int lineNumber, int maxlength, fileman * fm) {
  int count = 0;
  char * line = malloc(maxlength * sizeof(char));
  while (fgets(line, maxlength * sizeof(char), fm->fp) != NULL && count != lineNumber) {
    count++;
  }
  return line;
}

void fmmaplines(int maxlength, fileman * fm) {
  int count = 0;
  char * line = malloc(maxlength * sizeof(char));
  while (fgets(line, maxlength * sizeof(char), fm->fp) != NULL) {
    printf("%s", line);
  }
}

void fmclose(fileman * fm) {
  fclose(fm->fp);
  free(fm);
}
