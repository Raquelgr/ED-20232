#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int i;
  int *a = malloc(sizeof(int) * 11); // mudamos para alocar 11 posicoes ao inves de 10
  
  if (!a) return -1; /*malloc failed*/
  
  for (i = 0; i < 11; i++) {
    a[i] = i;
  }

  free(a);
  return 0;
}