#include <graph.hpp>

Grafo::Grafo() {}

Grafo::~Grafo() {}

void Grafo::InsereVertice() {
    vertices.AdicionarVertice();
}

void Grafo::InsereAresta(int v, int w) {
    vertices.AdicionarAresta(v, w);
}

int Grafo::QuantidadeVertices() {
    return vertices.Tamanho();
}

int Grafo::QuantidadeArestas() {
    int numArestas = 0;

    for (int i = 0; i < vertices.Tamanho(); ++i) {
        numArestas += vertices.QuantidadeCelulas(i);
    }

    return numArestas / 2;
}

int Grafo::GrauMinimo() {
    if (vertices.Tamanho() == 0) {
        return 0;
    }

    int grauMinimo = vertices.QuantidadeCelulas(0);

    for (int i = 1; i < vertices.Tamanho(); ++i) {
        int grauAtual = vertices.QuantidadeCelulas(i);

        if(grauAtual < grauMinimo) {
            grauMinimo = grauAtual;
        }
    }

    return grauMinimo;
}

int Grafo::GrauMaximo() {
    if (vertices.Tamanho() == 0) {
        return 0;
    }

    int grauMaximo = vertices.QuantidadeCelulas(0);

    for (int i = 1; i < vertices.Tamanho(); ++i) {
        int grauAtual = vertices.QuantidadeCelulas(i);

        if(grauAtual > grauMaximo) {
            grauMaximo = grauAtual;
        }
    }

    return grauMaximo;
}

void Grafo::ImprimeVizinhos(int v) {
    vertices.ImprimirVizinhos(v);
}