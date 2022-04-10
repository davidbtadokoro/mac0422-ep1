#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define PAL_MAX 100
#define STD_IN 0

int main(int argc, char const *argv[]) {
  char comando[PAL_MAX];
  char arquivo[PAL_MAX];

  // Inicio da shell:
  while (1) {
    printf("mac422shell> ");

    // Captura de comandos da shell:
    scanf("%s", comando);
    if (strcmp(comando, "sair") == 0) return 0; // termina shell
    scanf("%s", arquivo);

    // Argumentos p/ execve():
    char* const args[] = {arquivo, NULL};
    char* const env[] = {NULL};

    // Bloco de protecao de arquivos:
    if (strcmp(comando, "protegepracaramba") == 0)
      chmod(arquivo, 0000);
    else if (strcmp(comando, "liberageral") == 0)
      chmod(arquivo, 0777);
    // Bloco de execucao de programas:
    else if (strcmp(comando, "rodeveja") == 0) {
      int codigo;
      pid_t pid = fork();
      if (pid == 0) // filho cumpre predicado
        execve(args[0], args, env);
      waitpid(pid, &codigo, 0); // espera processo criado acima terminar
      printf("programa '%s' retornou com o codigo %d.\n", arquivo, WEXITSTATUS(codigo));
    }
    else if (strcmp(comando, "rode") == 0) {
      if (fork() == 0)  { // filho cumpre predicado
        close(STD_IN);  // fecha STD_IN p/ shell monopolizar teclado
        execve(args[0], args, env);
      }
    }
    else printf("Comando invalido!\n");
  }

  return 0;
}
