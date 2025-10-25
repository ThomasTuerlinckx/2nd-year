#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  FILE *file1 = fopen(argv[1], "r");
  FILE *file2 = fopen(argv[2], "w");
  if (file1 == NULL) {
    printf("error: could not open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
}
