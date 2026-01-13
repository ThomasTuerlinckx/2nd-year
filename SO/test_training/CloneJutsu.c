#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Shadow clone summon! (fork)\n");

  pid_t pid = fork();
  if (pid == 0) {
    printf("Im the Clone, Ill take the hit (PID: %d)\n", getpid());
  } else {
    printf("Im the original. Ill fight. PID: %d", pid);
  }

  return 0;
}
