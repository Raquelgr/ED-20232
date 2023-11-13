#include <Grafo.hpp>

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
            int qtdDeCoresNecessarias = (vertice.cor) - 1; //É necessário que ele tenha todas as cores abaixo da dele.
            int contador = 0;

            /* Caso a quantidade de vizinhos seja menor que as cores necessárias, já não é possível ter a coloração gulosa */
            if (vertice.qtdVizinhos < qtdDeCoresNecessarias) { 
                return false;
            }

            int aux = qtdDeCoresNecessarias;

            for (int aux = qtdDeCoresNecessarias; aux > 0; aux--) { // Para cada cor menor, é necessário ver se algum vizinho à possui
                for (int j = 0; j < vertice.qtdVizinhos; j++) { // Percorre todos os vizinhos procurando a cor
                    int vizinho = vertice.vizinhos[j];

                    if (vertices[vizinho].cor == aux) {
                        contador++; // Caso ache, incremeta o contador auxiliar, break para voltar ao for das cores.
                        break;
                    }
                }
            }

            if (contador < qtdDeCoresNecessarias) { //Se o contador não atingiu as cores necessárias, a coloração não é gulosa!
                return false;
            }
        }
    }

    return true;
}