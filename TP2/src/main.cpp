#include <iostream>
#include <sstream>
#include <string>

#include <getopt.h>

#include <grafo.hpp>
#include <bubbleSort.hpp>
#include <selectionSort.hpp>
#include <inserctionSort.hpp>
#include <quickSort.hpp>
#include <mergeSort.hpp>
#include <heapSort.hpp>

using namespace std;

#define BUBBLE 1
#define SELECTION 2
#define INSERCTION 3
#define QUICK 4
#define MERGE 5
#define HEAP 6
#define MINE 7

void ordena(char metodoEscolhido, Vertice* itens, int tamanho) {
	switch (metodoEscolhido) {
		case 'b':
      		BubbleSort(itens, tamanho);
			break;
		case 's':
      		SelectionSort(itens, tamanho);
			break;
		case 'i':
      		InserctionSort(itens, tamanho);
			break;
		case 'q':
      		QuickSort(itens, tamanho);
			break;
		case 'm':
      		MergeSort(itens, tamanho);
			break;
		case 'p':
			HeapSort(itens, tamanho);
			break;
		case 'y':
			metodoEscolhido = MINE;
			break;
		default:
			throw invalid_argument("OPCAO DE ORDENACAO INVALIDA!");
			break;
	}
}

void uso(int numVertices, char metodoEscolhido) {
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
		ordena(metodoEscolhido, grafo->vertices, grafo->tamanho);
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
	char metodoEscolhido;
	int numVertices = 0;

	cin >> metodoEscolhido >> numVertices;
	uso(numVertices, metodoEscolhido);

  	return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}