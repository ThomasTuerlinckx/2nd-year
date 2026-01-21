#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  for (;;) {
    /* give prompt, read command and null terminate it */
    fprintf(stdout, "$ ");
    char buf[1024];
    char *command = fgets(buf, sizeof(buf), stdin);
    if (command == NULL)
      break;
    command[strlen(buf) - 1] = '\0';
    FILE *fptr;
    fptr = fopen("history.txt", "a");
    /* call fork and check return value */
    if (strcmp(command, "exit") == 0) {
      fclose(fptr);
      exit(EXIT_SUCCESS);
    }
    if (strncmp(command, "myhistory", 9) == 0) {
      char *ptr = command + 9;
      int number = atoi(ptr);
      char str[16];
      sprintf(str, "%d", number);
      char *tail_arg[] = {"tail", "-n", str, "history.txt", NULL};
      pid_t pid = fork();
      if (pid == 0) {
        execvp("tail", tail_arg);
      }
      waitpid(pid, NULL, 0);
      continue;
    }
    fprintf(fptr, "%s\n", command);
    fflush(fptr);

    pid_t pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    if (pid == 0) {
      fprintf(fptr, "%s\n", command);
      char *args[64];
      char *token = strtok(command, " ");
      int i = 0;
      while (token != NULL && i < 63) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
      }
      args[i] = NULL;

      int retv = execvp(args[0], args);
      if (retv == -1) {
        perror("execlp");
        exit(EXIT_FAILURE);
      }
    }
    /* shell waits for command to finish before giving prompt again */
    int retv = waitpid(pid, NULL, 0);
    if (retv == -1) {
      perror("waitpid");

      exit(EXIT_FAILURE);
    }
    fclose(fptr);
  }

  exit(EXIT_SUCCESS);
}
