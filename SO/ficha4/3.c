#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct stat info;

  for (int i = 0; i < argc; i++) {
    int retv = stat(argv[i], &info);
    if (retv == -1) {
      fprintf(stderr, "fsize: Can’t stat %s\n", argv[i]);
      exit(EXIT_FAILURE);
    }
    char *timer = ctime(&info.st_mtime);
    printf("%s size: %d bytes, disk_blocks: %d, time: %s\n", argv[i],
           (int)info.st_size, (int)info.st_blocks, timer);
  }

  exit(EXIT_SUCCESS);
}
