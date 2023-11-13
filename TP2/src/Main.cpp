#include <iostream>
#include <getopt.h>
#include <sys/resource.h>

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
      		BubbleSort(itens, tamanho);
			break;
		case 's':
      		SelectionSort(itens, tamanho);
			break;
		case 'i':
      		InsertionSort(itens, tamanho);
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

	delete grafo;
}

int main(int argc, char* argv[]) try {
	char metodoEscolhido;
	int numVertices = 0;

	cin >> metodoEscolhido >> numVertices;

	uso(numVertices, metodoEscolhido);

	/* Contagem de tempo */
	// double utime, stime, total_time; // contagem de tempo
	// struct rusage resources;
    // int rc;

	// if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    //     perror("getrusage failed");
    // utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    // stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    // total_time = utime+stime;
	
    // cout << "User time: " << utime << " System time: " << stime << " Total time: " << total_time << endl;


  	return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}