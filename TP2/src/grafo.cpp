#include <iostream>
#include <sstream>
#include <string>

#include <grafo.hpp>

using namespace std;

TipoItem::TipoItem() { 
    qtdVizinhos = 0; 
    cor = -1;
    vizinhos = nullptr;
}

Grafo::Grafo(int qtdVertices) {
    tamanho = qtdVertices;  
    vertices = new TipoItem[qtdVertices];
}

Grafo::~Grafo() { 
     for (int i = 0; i < tamanho; i++) {
        delete[] vertices[i].vizinhos;
    }

    delete[] vertices;
}

void Grafo::DefinirQuantidadeDeVizinhos(int vertice, int qtdVizinhos) { 
    vertices[vertice].qtdVizinhos = qtdVizinhos;
    vertices[vertice].vizinhos = new int[qtdVizinhos];
}

void Grafo::InserirVizinho(int vertice, int posicaoVizinho, int vizinho) {
    vertices[vertice].vizinhos[posicaoVizinho] = vizinho;
}

void Grafo::DefinirCor(int vertice, int cor) { 
    vertices[vertice].cor = cor;
}

void Grafo::Imprime() {
    for (int i = 0; i < tamanho; i++) {
        cout << "Vértice " << i << " Cor " << vertices[i].cor << " ";

        for (int j = 0; j < vertices[i].qtdVizinhos; j++) {
            cout << vertices[i].vizinhos[j] << " ";
        }

        cout << endl;
    }
}