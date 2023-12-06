#ifndef LISTA_ADJACENCIA_HPP
#define LISTA_ADJACENCIA_HPP

#include <iostream>

using namespace std;

class TipoCelula {
    public:
        TipoCelula();

    private:
        int item;
        TipoCelula *prox;

    friend class ListaEncadeada;
};

class ListaEncadeada {
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        void Insere(int item);
        void Imprime();
        void Limpa();
        
        int Tamanho();

    private:
        int tamanho;
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        
        ListaEncadeada *prox;

    friend class ListaAdjacencia;
};

class ListaAdjacencia {
    public:
        ListaAdjacencia();
        ~ListaAdjacencia();

        void AdicionarVertice();
        void AdicionarAresta(int v, int w);
        void ImprimirVizinhos(int v);
        void Limpa();

        int Tamanho();
        int QuantidadeCelulas(int v);

    private:
        int tamanho;
        ListaEncadeada* primeiro;
        ListaEncadeada* ultimo;

        ListaEncadeada* Posiciona(int pos);

};

#endif