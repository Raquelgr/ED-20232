#include <selectionSort.hpp>

void SelectionSort(Vertice *vertices, int tamanho) { 
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