//---------------------------------------------------------------------
// Arquivo	: func.c
// Conteudo	: implementacao das funcoes do arquivo func.h
// Autor	: Raquel Rosa (raquelgr@ufmg.br)
// Historico : 02/09/2023 - arquivo criado
//---------------------------------------------------

#include <stdio.h>
#include <math.h>
#include "func.h"
#include "msgassert.h"

int fatorialIterativo(int n) {
  int x = 1;

  while (n > 0) {
    x = x  * n;
    n--;
  }
  
  return x;
}

int fatorialRecursivo(int n) {
  // operação computacional intensa
  for (int i = 1; i < 1000; i++) {
    sin(1);
  };

  if (n == 0) {
    return 1;
  }

  return n * fatorialRecursivo(n - 1);
}


int fibonacciIterativo(int n) {
  int fn1 = 1;
  int fn2 = 1;
  int fn, i;

  if (n < 3) {
    return 1;
  }

  for (i = 3; i <= n; i++) {
    fn = fn1 + fn2;
    fn2 = fn1;
    fn1 = fn;
  }

  return fn;
}

int fibonacciRecursivo(int n) {
  if (n < 3) {
    return 1;
  }

  return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}