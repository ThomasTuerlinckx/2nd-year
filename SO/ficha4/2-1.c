#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define BUFFER_SIZE 1
int main(int argc, char *argv[]) {
  /* if (argc != 2) {
     printf("usage: cat filename\n");
     exit(EXIT_FAILURE);
   }
   */

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    printf("error: cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  char buffer[BUFFER_SIZE];
  int nbytes = lseek(fd, 0, SEEK_END);
  for (int i = 0; i <= nbytes; i++) {
    lseek(fd, -i, SEEK_END);
    write(STDOUT_FILENO, buffer, BUFFER_SIZE);
    read(fd, buffer, BUFFER_SIZE);
  }
  close(fd);
  exit(EXIT_SUCCESS);
}
