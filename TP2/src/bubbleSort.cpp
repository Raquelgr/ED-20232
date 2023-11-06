#include <bubbleSort.hpp>

void BubbleSort(Vertice *vertices, int tamanho) {
    bool trocou;
    Vertice aux;
    
    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false;

        for (int j = 1; j < tamanho - i; j++) {
            if (EhMenor(vertices[j], vertices[j-1])) {
                Troca(&vertices[j-1], &vertices[j]);
                trocou = true;
            }
        }

        if (!trocou) break;
    }
}