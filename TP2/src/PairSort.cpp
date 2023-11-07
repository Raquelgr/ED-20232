#include <PairSort.hpp>

void PairSort(Vertice *vertices, int tamanho) {
    bool ordenado = false;
    
    while (!ordenado) {
        ordenado = true;

        for (int i = 0; i < tamanho - 1; i+=2) {
            if (EhMaior(vertices[i], vertices[i+1])) {
                Troca(&vertices[i+1], &vertices[i]);
                ordenado = false;
            }
        }

        for (int i = 1; i < tamanho - 1; i+=2) {
            if (EhMaior(vertices[i], vertices[i+1])) {
                Troca(&vertices[i+1], &vertices[i]);
                ordenado = false;
            }
        }
    }
}