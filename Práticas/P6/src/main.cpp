#include <iostream>
#include <getopt.h>

#include <graph.hpp>

using namespace std;


int main(int argc, char* argv[]) try {
    int opt;

    bool dadosBasicos = false;
    bool vizinhancas = false;
    bool propriedade = false;


    while ((opt = getopt(argc, argv, "dnk")) != EOF) {
        switch (opt) {
        case 'd':
            dadosBasicos = true;
            break;
        case 'n':
            vizinhancas = true;
            break;
        case 'k':
            propriedade = true;
            break;
        default:
            throw invalid_argument("OPCAO INVALIDA!");
            break;
        }
    }
    
    Grafo* grafo = new Grafo();
    
    int numVertices = 0;
    cin >> numVertices;

    for (int i = 0; i < numVertices; i++) {
        grafo->InsereVertice();
    }

    for (int i = 0; i < numVertices; i++) {
        int numVizinhos;
        cin >> numVizinhos;

        for (int j = 0; j < numVizinhos; j++) {
            int vizinho;
            cin >> vizinho;

            grafo->InsereAresta(i, vizinho);
        }
    }

    if (dadosBasicos) {
        cout << grafo->QuantidadeVertices() << endl;
        cout << grafo->QuantidadeArestas() << endl;
        cout << grafo->GrauMinimo() << endl;
        cout << grafo->GrauMaximo() << endl;
    }

    if (vizinhancas) {
        for (int i = 0; i < numVertices; i++) {
            grafo->ImprimeVizinhos(i);
        }
    }

    if (propriedade) {
        int qtdVertices = grafo->QuantidadeVertices();
        int qtdArestas = grafo->QuantidadeArestas();

        int qtdArestasParaSerCompleto = (qtdVertices * (qtdVertices - 1)) / 2;

        qtdArestasParaSerCompleto == qtdArestas ? cout << 1 : cout << 0;
        cout << endl;
    }
    
    delete grafo;

  	return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}