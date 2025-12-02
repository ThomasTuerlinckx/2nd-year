#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    int fd = open(argv[i], O_RDONLY);
    char buffer[BUFFER_SIZE] = {0};

    int dwarf = read(fd, buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, dwarf);
    printf(" \n");
    close(fd);
  }
}
