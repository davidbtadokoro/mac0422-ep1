#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  char p[20];
  sleep(5);
  printf("BLA!\n");
  scanf("%s", p);
  printf("digitou: %s\n", p);
  return 35;
}
