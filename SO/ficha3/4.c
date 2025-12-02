#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      printf("frick u that ain't no file");
      exit(EXIT_FAILURE);
    } else {
      char buffer[BUFFER_SIZE];
      int nchar = fread(buffer, sizeof(char), BUFFER_SIZE, file);
      while (nchar > 0) {
      }
    }
  }
}
