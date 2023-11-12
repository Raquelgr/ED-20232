#include <InsertionSort.hpp>

void InsertionSort(Vertice *vertices, int tamanho) {
    const char* log_mem = "log_insertionSort.txt";

    iniciaMemLog(log_mem);
    ativaMemLog();
    defineFaseMemLog(0);

    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho invalido!");
    } 

    int j = 0;
    Vertice aux;

    defineFaseMemLog(1);

    
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

    desativaMemLog();
    finalizaMemLog();
}