//----------------------------------------------------
// Arquivo	: main.c
// Conteudo	: implementacao da funcao principal
// Autor	: Raquel Rosa (raquelgr@ufmg.br)
// Historico : 02/09/2023 - arquivo criado
//---------------------------------------------------

#include <getopt.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"
#include "tempo.h"
#include "msgassert.h"

// definicoes de operacoes a serem testadas
#define FATITER 1
#define FATREC 2
#define FIBITE 3
#define FIBREC 4

// variaveis globais para opcoes
static int opescolhida;
int n;

void uso() {
  fprintf(stderr, "\t-a \t(Fatorial iterativo) \n");
  fprintf(stderr, "\t-b \t(Fatorial recursivo) \n");
  fprintf(stderr, "\t-c \t(Fibonacci iterativo) \n");
  fprintf(stderr, "\t-d \t(Fibonacci recursivo) \n");
}

void parse_args(int argc, char **argv) {

  // variavel auxiliar
  int aux;

  // inicializacao variaveis globais para opcoes
  opescolhida = -1;
  n = -1;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  // no caso de escolher mais de uma operacao, vale a ultima
  while ((aux = getopt(argc, argv, "abcdn:")) != EOF){
    switch (aux) {
      case 'a':
        opescolhida = FATITER;
        break;
      case 'b':
        opescolhida = FATREC;
        break;
      case 'c':
        opescolhida = FIBITE;
        break;
      case 'd':
        opescolhida = FIBREC;
        break;
      case 'n':
        n = atoi(optarg);
        break;
      default:
    uso();
    exit(1);
    }
  }

  erroAssert(opescolhida > 0, "necessario escolher operacao");
}

int main(int argc, char **argv) {
  // avaliar linha de comando
  parse_args(argc, argv);

  int A[] = {1, 3, 5, 10, 15, 20, 25, 30, 35, 40};
  int B[] = {100, 300, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000};
  int A_length = sizeof(A) / sizeof(A[0]);

  int64_t unixTimestampRecursive[A_length];
  int64_t unixTimestampIteractive[A_length];
  float userTimeRecursive[A_length];
  float userTimeIteractive[A_length];
  float systemTimeIteractive[A_length];
  float systemTimeRecursive[A_length];

  
  for (int i = 0; i < A_length; i++) {
    switch (opescolhida) {
      case FATITER:
        int64_t antes = getUnixTimestamp(MICROSECONDS_OPTION);           
        fatorialIterativo(B[i]);
        int64_t depois = getUnixTimestamp(MICROSECONDS_OPTION);
        
        unixTimestampIteractive[i] = antes - depois;
        break;
      case FATREC:
        antes = getUnixTimestamp(MICROSECONDS_OPTION);           
        fatorialRecursivo(B[i]);
        depois = getUnixTimestamp(MICROSECONDS_OPTION);
        
        unixTimestampRecursive[i] = antes - depois;
        break;
      case FIBITE:
        //estrutura para armazenar o tempo de usuario e sistema decorrido
        struct rusage start, end; 

        getrusage(RUSAGE_SELF, &start); //o inteiro
        fibonacciIterativo(A[i]);
        getrusage(RUSAGE_SELF, &end); //aqui terminamos o processo da thread atual (Fatorial Recursivo) passando o endereço &end do objeto 'rusage' como argumento pra função
        
        userTimeIteractive[i] = difUserTime(&start, &end);
        systemTimeIteractive[i] = difSystemTime(&start, &end);
        break;
      case FIBREC:
        getrusage(RUSAGE_SELF, &start); //o inteiro
        fibonacciRecursivo(A[i]);
        getrusage(RUSAGE_SELF, &end); //aqui terminamos o processo da thread atual (Fatorial Recursivo) passando o endereço &end do objeto 'rusage' como argumento pra função
        
        userTimeRecursive[i] = difUserTime(&start, &end);
        systemTimeRecursive[i] = difSystemTime(&start, &end);
        break;
      default:
        // nao deve ser executado, pois ha um erroAssert em parse_args
        uso();
        exit(1);
      }
  }
  
  
  for (int i = 0; i < A_length; i++) {
    switch (opescolhida) {
      case FATITER:
        printf("Fatorial interativo unix time = %" PRId64 "", unixTimestampIteractive[i]);
        printf("\n");
        printf("Fatorial interativo user time = %d ", userTimeIteractive[i]);
        printf("\n");
        printf("Fatorial interativo system time = %d", systemTimeIteractive[i] );
        printf("\n");
        break;
      case FATREC:
        printf("Fatorial recursivo unix time = %" PRId64 "", unixTimestampRecursive[i]);
        printf("\n");
        printf("Fatorial recursivo user time = %d ", userTimeRecursive[i]);
        printf("\n");
        printf("Fatorial recursivo system time = %d", systemTimeRecursive[i] );
        printf("\n");
        break;
      case FIBITE:
        printf("Fibonacci interativo unix time = %" PRId64 "", unixTimestampIteractive[i]);
        printf("\n");
        printf("Fibonacci interativo user time = %d ", userTimeIteractive[i]);
        printf("\n");
        printf("Fibonacci interativo system time = %d", systemTimeIteractive[i] );
        printf("\n");
        break;
      case FIBREC:
        printf("Fibonacci recursivo unix time = %" PRId64 "", unixTimestampRecursive[i]);
        printf("\n");
        printf("Fibonacci recursivo user time = %d ", userTimeRecursive[i]);
        printf("\n");
        printf("Fibonacci recursivo system time = %d", systemTimeRecursive[i] );
        printf("\n");
        break;
      default:
        exit(1);
      }
  }

  // conclui registro de acesso
  return 0;
}
