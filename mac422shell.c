#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_WORD 30

int main(int argc, char const *argv[]) {
  char comando[MAX_WORD];
  char arquivo[MAX_WORD];

  while (1) {
    printf("mac422shell> ");
    scanf("%s", comando);
    scanf("%s", arquivo);

    if (strcmp(comando, "protegepracaramba") == 0) {
      if (fork() == 0) {
        char* const args[] = {"/bin/chmod", "000", arquivo, NULL};
        char* const env_args[] = {NULL};
        execve(args[0], args, env_args);
      }
    }

    if (strcmp(comando, "liberageral") == 0) {
      if (fork() == 0) {
        char* const args[] = {"/bin/chmod", "777", arquivo, NULL};
        char* const env_args[] = {NULL};
        execve(args[0], args, env_args);
      }
    }
    if (strcmp(comando, "rodeveja") == 0) {
      char* const args[] = {arquivo, NULL};
      char* const env_args[] = {NULL};
      int codigo = 0;
      if (fork() == 0) {
        codigo = execve(args[0], args, env_args);

      }
      wait(NULL);
      printf("programa '%s' retornou com o código %d.\n", arquivo, codigo);
    }
    if (strcmp(comando, "rode") == 0) {
      char* const args[] = {arquivo, NULL};
      char* const env_args[] = {NULL};
      if (fork() == 0) {
        execve(args[0], args, env_args);
      }
    }
  }

  return 0;
}
