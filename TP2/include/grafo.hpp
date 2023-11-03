#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <vertice.hpp>

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