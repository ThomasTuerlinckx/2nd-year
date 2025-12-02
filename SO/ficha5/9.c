#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    pid_t pid = fork();
    if (pid == 0) {
      printf("compiling %s\n", argv[i]);
      char *args[] = {"gcc", "-Wall", argv[i], NULL};
      execvp("gcc", args);
      perror("execvp");

      exit(EXIT_SUCCESS);
    }
  }
  for (int i = 1; i < argc; i++)
    wait(NULL);
  exit(EXIT_SUCCESS);
}
