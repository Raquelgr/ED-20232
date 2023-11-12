#include <iostream>
#include <getopt.h>

#include <Grafo.hpp>
#include <BubbleSort.hpp>
#include <SelectionSort.hpp>
#include <InsertionSort.hpp>
#include <QuickSort.hpp>
#include <MergeSort.hpp>
#include <HeapSort.hpp>
#include <PairSort.hpp>

using namespace std;

void ordena(char metodoEscolhido, Vertice* itens, int tamanho) {
	switch (metodoEscolhido) {
		case 'b':
			defineFaseMemLog(1);
      		BubbleSort(itens, tamanho);
			break;
		case 's':
      		defineFaseMemLog(1);
			SelectionSort(itens, tamanho);
			break;
		case 'i':
      		defineFaseMemLog(1);
			InsertionSort(itens, tamanho);
			break;
		case 'q':
		    defineFaseMemLog(1);
      		QuickSort(itens, tamanho);
			break;
		case 'm':
			defineFaseMemLog(1);
      		MergeSort(itens, tamanho);
			break;
		case 'p':
		    defineFaseMemLog(1);
			HeapSort(itens, tamanho);
			break;
		case 'y':
		    defineFaseMemLog(1);
			PairSort(itens, tamanho);
			break;
		default:
			throw std::invalid_argument("OPCAO DE ORDENACAO INVALIDA!");
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
	cout << temColorocaoGulosa;

  	if (temColorocaoGulosa) {
		ordena(metodoEscolhido, grafo->vertices, grafo->tamanho);

		for (int i = 0; i < numVertices; i++) {
      		cout << " " << grafo->vertices[i].rotulo;
    	}
  	} 

	cout << endl;

	grafo->~Grafo();
}

int main(int argc, char* argv[]) try {
	const char* log_mem = "log.txt";

	char metodoEscolhido;
	int numVertices = 0;

	cin >> metodoEscolhido >> numVertices;
	
	iniciaMemLog(log_mem);
    ativaMemLog();
    defineFaseMemLog(0);

	uso(numVertices, metodoEscolhido);

	desativaMemLog();
    finalizaMemLog();

  	return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}