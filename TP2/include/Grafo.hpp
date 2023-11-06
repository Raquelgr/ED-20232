#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <Vertice.hpp>

class Grafo {
    public:
		Grafo(int qtdVertices);
		~Grafo();

		int tamanho;
		Vertice* vertices;

		void DefinirQuantidadeDeVizinhos(int vertice, int qtdVizinhos);
		void InserirVizinho(int vertice, int posicaoVizinho, int vizinho);
		void DefinirCor(int vertice, int cor);

		bool VerificarColoracaoGulosa();
};

#endif