#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define LINESIZE 256
int main(int argc, char *argv[]) {
  int fd[2];
  pid_t pid;
  if (argc != 2) {
    fprintf(stderr, "Uso: %s <ficheiro_de_entrada>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (pipe(fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  if ((pid = fork()) == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid > 0) { /* parent */
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
    }

    close(fd[0]);

    char buffer[LINESIZE];
    size_t nread;
    while ((nread = fread(buffer, 1, sizeof(buffer), f)) > 0) {
      if (write(fd[1], buffer, nread) == -1) {
        perror("write");
        fclose(f);
        close(fd[1]);
        exit(EXIT_FAILURE);
      }
    }
    fclose(f);
    close(fd[1]);

    if (wait(NULL) == -1) {
      perror("wait");
      exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
  }

  else {          /* child */
    close(fd[1]); /* fecha escrita da pipe */

    char buffer[LINESIZE];
    ssize_t nbytes;

    while ((nbytes = read(fd[0], buffer, sizeof(buffer))) > 0) {
      if (write(STDOUT_FILENO, buffer, nbytes) == -1) {
        perror("write");
        close(fd[0]);
        exit(EXIT_FAILURE);
      }
    }

    if (nbytes == -1) {
      perror("read");
      close(fd[0]);
      exit(EXIT_FAILURE);
    }

    close(fd[0]);
    exit(EXIT_SUCCESS);
  }
}
