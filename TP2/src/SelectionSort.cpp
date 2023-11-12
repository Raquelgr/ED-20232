#include <SelectionSort.hpp>

void SelectionSort(Vertice *vertices, int tamanho) { 
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho invalido!");
    }

    int min;

    for (int i = 0; i < tamanho - 1; i++) {
        min = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (EhMenor(vertices[j], vertices[min])) {
                min = j;
            }
        }

        Troca(&vertices[i], &vertices[min]); 
    }
}