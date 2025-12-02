#include <stdio.h>    // for printf()
#include <stdlib.h>   // for exit() and EXIT_FAILURE/SUCCESS
#include <sys/stat.h> // for stat(), struct stat, S_IRUSR, etc.

int main(int argc, char *argv[]) {

  struct stat info;
  char *fileinfo = argv[1];
  stat(argv[1], &info);
  printf(" %ls\n", &info.st_dev), exit(EXIT_SUCCESS);
}
