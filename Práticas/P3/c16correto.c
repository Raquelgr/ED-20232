#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b){
  float c;

  if (b != 0) {
    c = a/b;
    printf("%f \n", c);
  } else {
    printf("Não é possível realizar divisão por 0! \n");
  }

  return 0;
}

int calc(){
  int a;
  int b;

  a = 13;
  b = 0;
  actual_calc(a, b);

  return 0;
}

int main(){
  calc();
  return 0;
}