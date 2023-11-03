#include <iostream>
#include <sstream>
#include <string>

#include <getopt.h>

#include <grafo.hpp>
#include <metodosConhecidos.hpp>

using namespace std;

#define BUBBLE 1
#define SELECTION 2
#define INSERCTION 3
#define QUICK 4
#define MERGE 5
#define HEAP 6
#define MINE 7

void ordena(int opcaoEscolhida, Vertice* itens, int tamanho) {
  switch (opcaoEscolhida) {
    case 1:
      BubbleSort(itens, tamanho);
      break;
    case 2:
      SelectionSort(itens, tamanho);
      break;
    case 3:
      InserctionSort(itens, tamanho);
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
  }
}

void uso(int numVertices, int opcaoEscolhida) {
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

  bool temColorocaoGulosa = grafo->VerificarColoracaoGulosa();

  if (temColorocaoGulosa) {
		ordena(opcaoEscolhida, grafo->vertices, grafo->tamanho);
		cout << temColorocaoGulosa << " ";

		for (int i = 0; i < numVertices; i++) {
      cout << grafo->vertices[i].rotulo << " ";
    }

		cout << endl;
  } else {
		cout << temColorocaoGulosa << endl;
	}
}

int main(int argc, char* argv[]) try {
  char metodo;
  int numVertices = 0;

  int opcaoEscolhida = 0;

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

	uso(numVertices, opcaoEscolhida);

  // //ideia: criar um método só para inicializacao do grafo...
  // Grafo* grafo = new Grafo(numVertices);

  // for (int i = 0; i < numVertices; i++) {
  //   int numVizinhos = 0;
  //   cin >> numVizinhos;

  //   grafo->DefinirQuantidadeDeVizinhos(i, numVizinhos);

  //   for (int j = 0; j < numVizinhos; j++) {
  //     int vizinho;
  //     cin >> vizinho;

  //     grafo->InserirVizinho(i, j, vizinho);
  //   }
  // }

  // for (int i = 0; i < numVertices; i++) {
  //   int cor = 0;
  //   cin >> cor;

  //   grafo->DefinirCor(i, cor);
  // }

  // grafo->Imprime();

  // bool temColorocaoGulosa = grafo->VerificarColoracaoGulosa();

  // if (temColorocaoGulosa) {

  //   //criar um metodo pra chamar as ordenacoes
  //   SelectionSort(grafo->vertices, grafo->tamanho);
  // }


  //ideia: criar um novo vetor só para ordenação e não mexer no grafo...criar um vetor só com rotulo e coloracao
  // cout << temColorocaoGulosa << endl;
  // grafo->Imprime();


  return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}