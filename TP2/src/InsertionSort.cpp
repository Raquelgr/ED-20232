#include <InsertionSort.hpp>

void InsertionSort(Vertice *vertices, int tamanho) {
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho invalido!");
    } 

    int j = 0;
    Vertice aux;

    for (int i = 1; i < tamanho; i++) {
        aux = vertices[i];
        j = i - 1;

        while (j >= 0 && aux.cor < vertices[j].cor) {
            vertices[j + 1] = vertices[j];
            j--;
        }

        vertices[j + 1] = aux;
    } 
}