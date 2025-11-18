#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    int fd = open(argv[i], O_RDONLY);
    if (fd == -1) {
      perror(argv[i]);
      continue;
    }

    struct stat st;
    fstat(fd, &st);
    off_t size = st.st_size;

    for (off_t pos = size - 1; pos >= 0; pos--) {
      char c;
      pread(fd, &c, 1, pos);
      write(STDOUT_FILENO, &c, 1);
    }

    close(fd);
  }
  return 0;
}
