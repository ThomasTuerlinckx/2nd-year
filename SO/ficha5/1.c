#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  fork();
  printf(" PID1 - %d \n", getpid());
  fork();
  printf(" PID2 - %d \n", getpid());
  fork();
  printf(" PID3 - %d \n", getpid());

  exit(EXIT_SUCCESS);
}
