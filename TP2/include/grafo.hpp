#ifndef GRAFO_HPP
#define GRAFO_HPP

class TipoItem {
    public: 
        TipoItem();
        int qtdVizinhos;
        int cor;
        int* vizinhos;

    friend class Grafo;
};

class Grafo {
    public:
        Grafo(int qtdVertices);
        ~Grafo();

        void DefinirQuantidadeDeVizinhos(int vertice, int qtdVizinhos);
        void InserirVizinho(int vertice, int posicaoVizinho, int vizinho);
        void DefinirCor(int vertice, int cor);

        void Imprime();
        
    private:
        int tamanho;
        TipoItem* vertices;
};

#endif