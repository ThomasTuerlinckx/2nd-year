#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_HISTORY 100
char *history[MAX_HISTORY];
int history_count = 0;

#define MAX_ARGS 64
int main(int argc, char *argv[]) {

  for (;;) {
    /* give prompt, read command and null terminate it */
    fprintf(stdout, "$ ");
    char buf[1024];
    char *command = fgets(buf, sizeof(buf), stdin);
    if (strlen(command) > 0) {
      if (history[history_count])
        free(history[history_count]);
      history[history_count] = strdup(command);
      history_count = (history_count + 1) % MAX_HISTORY;
    }

    if (strncmp(command, "myhistory", 9) == 0) {
      int n = atoi(command + 10);
      if (n > MAX_HISTORY)
        n = MAX_HISTORY;
      int start = (history_count - n + MAX_HISTORY) % MAX_HISTORY;
      for (int i = 0; i < n; i++) {
        int idx = (start + i) % MAX_HISTORY;
        if (history[idx])
          printf("%s\n", history[idx]);
      }
      continue;
    }
    if (command == NULL)
      break;
    command[strlen(buf) - 1] = '\0';
    /* call fork and check return value */
    pid_t pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    if (pid == 0) {
      /* child */
      char *args[MAX_ARGS];
      int i = 0;

      char *token = strtok(command, "\t");
      while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, "\t\n");
      }

      args[i] = NULL;
      if (args[0] == NULL)
        exit(EXIT_SUCCESS);
      int retv = execvp(args[0], args);
      if (retv == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
      }
    }
    /* shell waits for command to finish before giving prompt again */
    int retv = waitpid(pid, NULL, 0);
    if (retv == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}
