#include <InsertionSort.hpp>

void InsertionSort(Vertice *vertices, int tamanho) {
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho invalido!");
    } 

    int j = 0;
    Vertice aux;

    
    for (int i = 1; i < tamanho; i++) {
        aux = leitura(vertices, i, 1);
        j = i - 1;

        while (j >= 0 && aux.cor < leitura(vertices, j, 1).cor) {
            escrita(vertices, j + 1, 1) = leitura(vertices, j, 1);
            vertices[j + 1] = vertices[j];
            j--;
        }

        escrita(vertices, j + 1, 1) = aux;
    } 
}