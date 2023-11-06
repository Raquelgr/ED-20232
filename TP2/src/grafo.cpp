#include <grafo.hpp>

Grafo::Grafo(int qtdVertices) {
    tamanho = qtdVertices;  
    vertices = new Vertice[qtdVertices];

    for (int i = 0; i < qtdVertices; i++) {
        vertices[i].rotulo = i;
    }
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

bool Grafo::VerificarColoracaoGulosa() {
    Vertice vertice;

    for (int i = 0; i < tamanho; i++) {
        vertice = vertices[i];

        if (vertice.cor > 1) {
            int qtdDeCoresNecessarias = (vertice.cor) - 1;
            int contador = 0;

            if (vertice.qtdVizinhos < qtdDeCoresNecessarias) { 
                return false;
            }

            int aux = qtdDeCoresNecessarias;

            for (int aux = qtdDeCoresNecessarias; aux > 0; aux--) {
                for (int j = 0; j < vertice.qtdVizinhos; j++) {
                    int vizinho = vertice.vizinhos[j];

                    if (vertices[vizinho].cor == aux) {
                        contador++;
                        break;
                    }
                }
            }

            if (contador < qtdDeCoresNecessarias) {
                return false;
            }
        }
    }

    return true;
}