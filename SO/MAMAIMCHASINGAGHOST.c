#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("FRick u for using wrongly the command");
    exit(EXIT_FAILURE);
  }

  char *p1 = strdup(argv[1]);

  for (int i = 0; i < strlen(argv[1]); i++) {
    p1[i] = tolower(p1[i]);
  }
  printf("return:%s\n", p1);
  free(p1);
  exit(EXIT_SUCCESS);
}
