#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define PAL_MAX 30

int main(int argc, char const *argv[]) {
  char comando[PAL_MAX];
  char arquivo[PAL_MAX];

  // Inicio da shell:
  while (1) {
    printf("mac422shell> ");
    scanf("%s", comando);
    if (strcmp(comando, "sair") == 0) return 0; // termina shell
    scanf("%s", arquivo);

    // Bloco "protecao":
    if (strcmp(comando, "protegepracaramba") == 0) {
      if (fork() == 0) {
        long protecao = 0000;
        chmod(arquivo, protecao);
        exit(0);
      }
    }
    if (strcmp(comando, "liberageral") == 0) {
      if (fork() == 0) {
        long protecao = 0777;
        chmod(arquivo, protecao);
        exit(0);
      }
    }

    // Bloco "rode":
    char* const args[] = {arquivo, NULL}; // prepara args de execve
    char* const env_args[] = {NULL};      // prepara env de execve
    if (strcmp(comando, "rodeveja") == 0) {
      int codigo;
      pid_t pid = fork();
      if (pid == 0) {
        execve(args[0], args, env_args);
        exit(0);
      }
      waitpid(pid, &codigo, 0);
      codigo = WEXITSTATUS(codigo);
      printf("programa '%s' retornou com o codigo %d.\n", arquivo, codigo);
    }
    if (strcmp(comando, "rode") == 0) {
      if (fork() == 0) {
        execve(args[0], args, env_args);
        exit(0);
      }
    }
  }

  return 0;
}
