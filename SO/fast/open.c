#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main(int argc, char *argv[]) {
  char buffer[BUFFER_SIZE] = {0};
  int fd = open(argv[1], O_RDONLY);
  int n = read(fd, buffer, BUFFER_SIZE);

  write(STDOUT_FILENO, buffer, n);
  close(fd);
  exit(EXIT_SUCCESS);
}
