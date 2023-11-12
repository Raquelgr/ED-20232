#include <BubbleSort.hpp>

void BubbleSort(Vertice *vertices, int tamanho) {
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho invalido!");
    }

    bool trocou;
    
    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false;

        for (int j = 1; j < tamanho - i; j++) {
            if (vertices[j].cor < vertices[j-1].cor) {
                Troca(&vertices[j-1], &vertices[j]);
                trocou = true;
            }
        }

        if (!trocou) break;
    }
}