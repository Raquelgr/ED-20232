#include <iostream>
#include <sstream>
#include <string>

#include <getopt.h>
#include <grafo.hpp>

using namespace std;

#define BUBBLE 1
#define SELECTION 2
#define INSERCTION 3
#define QUICK 4
#define MERGE 5
#define HEAP 6
#define MINE 7
 
int main(int argc, char* argv[]) try {
  int opcaoEscolhida = 0;

  char metodo;
  int numVertices = 0;

  cin >> metodo >> numVertices;

  switch (metodo) {
    case 'b':
      opcaoEscolhida = BUBBLE;
      break;
    case 's':
      opcaoEscolhida = SELECTION;
      break;
    case 'i':
      opcaoEscolhida = INSERCTION;
      break;
    case 'q':
      opcaoEscolhida = QUICK;
      break;
    case 'm':
      opcaoEscolhida = MERGE;
      break;
    case 'p':
      opcaoEscolhida = HEAP;
      break;
    case 'y':
      opcaoEscolhida = MINE;
      break;
    default:
      throw invalid_argument("OPCAO INVALIDA!");
      break;
  }

  Grafo* grafo = new Grafo(numVertices);

  for (int i = 0; i < numVertices; i++) {
    int numVizinhos = 0;
    cin >> numVizinhos;

    grafo->DefinirQuantidadeDeVizinhos(i, numVizinhos);

    for (int j = 0; j < numVizinhos; j++) {
      int vizinho;
      cin >> vizinho;

      grafo->InserirVizinho(i, j, vizinho);
    }
  }

  for (int i = 0; i < numVertices; i++) {
    int cor = 0;
    cin >> cor;

    grafo->DefinirCor(i, cor);
  }

  grafo->Imprime();

  return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}