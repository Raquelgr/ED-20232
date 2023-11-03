#ifndef GRAFO_HPP
#define GRAFO_HPP

class Vertice {
    protected:
        int qtdVizinhos;
        int* vizinhos;

    public: 
        Vertice();
        int rotulo;
        int cor;

    friend class Grafo;
};

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