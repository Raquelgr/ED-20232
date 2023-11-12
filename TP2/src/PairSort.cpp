#include <PairSort.hpp>

void PairSort(Vertice *vertices, int tamanho) {
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho invalido!");
    } 

    bool ordenado = false;
    
    while (!ordenado) {
        ordenado = true; // Até que se prove o contrário, o array está ordenado 

        /* Compara as posições pares adjacentes de indice impar */
        for (int i = 0; i < tamanho - 1; i+=2) {

            /* Se o vertice da primeira posição for maior que o da segunda, realiza a troca e marca que ainda não está ordenado */
            if (vertices[i].cor > vertices[i+1].cor) {
                Troca(&vertices[i+1], &vertices[i]);
                ordenado = false;
            }
        }

        /* Compara as posições pares adjacentes de indice par */
        for (int i = 1; i < tamanho - 1; i+=2) {

            /* Se o vertice da primeira posição for maior que o da segunda, realiza a troca e marca que ainda não está ordenado */
            if (vertices[i].cor > vertices[i+1].cor) {
                Troca(&vertices[i+1], &vertices[i]);
                ordenado = false;
            }
        }
    }
}