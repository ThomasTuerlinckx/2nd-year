#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    pid_t pid = fork();
    if (pid == 0) {
      printf("compiling %s\n", argv[i]);
      char *args[] = {"padoc", argv[i], "-o", NULL};
      execvp("gcc", args);
      perror("execvp");

      exit(EXIT_SUCCESS);
    }
  }
  for (int i = 1; i < argc; i++)
    wait(NULL);
  exit(EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Uso: %s livro1.txt livro2.txt ...\n", argv[0]);
    return 1;
  }

  pid_t *pids = malloc((argc - 1) * sizeof(pid_t));
  if (!pids) {
    perror("malloc");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    pid_t pid = fork();
    if (pid == 0) {
      // Filho
      printf("[pid:%d] converting %s ...\n", getpid(), argv[i]);

      // Criar o nome do ficheiro de saída substituindo .txt por .epub
      char epub_name[512];
      strncpy(epub_name, argv[i], sizeof(epub_name));
      char *ext = strrchr(epub_name, '.');
      if (ext && strcmp(ext, ".txt") == 0) {
        strcpy(ext, ".epub");
      } else {
        strcat(epub_name, ".epub"); // caso não tenha extensão .txt
      }

      char *args[] = {"pandoc", argv[i], "-o", epub_name, NULL};
      execvp("pandoc", args);

      perror("execvp do pandoc falhou");
      exit(EXIT_FAILURE);
    }
    pids[i - 1] = pid;
  }

  // Pai espera pelos filhos
  for (int i = 0; i < argc - 1; i++) {
    waitpid(pids[i], NULL, 0);
  }

  // Criar argumento para zip: "ebooks.zip book1.epub book2.epub ..."
  int length = 10; // espaço para "zip ebooks.zip" mais espaços
  for (int i = 1; i < argc; i++) {
    length += strlen(argv[i]) + 5; // para a extensão e espaço extra
  }
  char *zip_command = malloc(length);
  if (!zip_command) {
    perror("malloc");
    return 1;
  }
  strcpy(zip_command, "zip ebooks.zip ");

  for (int i = 1; i < argc; i++) {
    char epub_name[512];
    strncpy(epub_name, argv[i], sizeof(epub_name));
    char *ext = strrchr(epub_name, '.');
    if (ext && strcmp(ext, ".txt") == 0) {
      strcpy(ext, ".epub");
    } else {
      strcat(epub_name, ".epub");
    }
    strcat(zip_command, epub_name);
    strcat(zip_command, " ");
  }

  // Executar comando zip via system (poderia-se usar exec se preferir)
  printf("Criando arquivo zip: %s\n", zip_command);
  int ret = system(zip_command);
  if (ret == -1) {
    perror("system zip");
  }

  free(pids);
  free(zip_command);

  return 0;
}
