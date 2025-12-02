#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct stat info;

  for (int i = 1; i < argc; i++) {
    char *filename = argv[i];

    stat(filename, &info);

    printf("File: %s\n", filename);
    printf("Size: %ld\n", info.st_size);
    printf("Blocks: %ld\n", (long)info.st_blksize);
    printf("Modified: %s", ctime(&info.st_mtime));
    printf("Owner UID: %ls", &info.st_uid);
  }
}
