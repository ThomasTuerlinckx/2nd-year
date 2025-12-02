#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDONLY);
  char buffer[BUFFER_SIZE];

  off_t pos = lseek(fd, 0, SEEK_END);
  for (int i = 0; i <= pos + 1; i++) {
    read(fd, buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, sizeof(buffer));
    lseek(fd, -i, SEEK_END);
    ;
  }

  close(fd);
  exit(EXIT_SUCCESS);
}
