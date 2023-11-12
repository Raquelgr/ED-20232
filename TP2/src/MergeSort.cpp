#include <MergeSort.hpp>

void Merge(Vertice* vertices, int inicio, int meio, int fim) {
    if (inicio < 0 || meio < 0 || fim < 0) {
        throw std::invalid_argument("Indice invalido!");
    } 

    int tamanhoEsq = meio - inicio + 1;
    int tamanhoDir = fim - meio; 

    Vertice* vetorEsq = new Vertice[tamanhoEsq];
    Vertice* vetorDir = new Vertice[tamanhoDir];

    for (int i = 0; i < tamanhoEsq; i++) {
        vetorEsq[i] = vertices[inicio + i];
    }

    for (int j = 0; j < tamanhoDir; j++) {
        vetorDir[j] = vertices[meio + 1 + j];
    }

    int indexEsq = 0;
    int indexDir = 0;
    int index = inicio;

    while (indexEsq < tamanhoEsq && indexDir < tamanhoEsq) {
        if (vetorEsq[indexEsq].cor < vetorDir[indexDir].cor) {
            vertices[index] = vetorEsq[indexEsq];
            indexEsq++;
        } else {
            vertices[index] = vetorDir[indexDir];
            indexDir++;
        }

        index++;
    }

    while (indexEsq < tamanhoEsq) {
        vertices[index] = vetorEsq[indexEsq];

        indexEsq++;
        index++;
    }

    while (indexDir < tamanhoDir) {
        vertices[index] = vetorDir[indexDir];

        indexDir++;
        index++;
    }

    delete[] vetorEsq;
    delete[] vetorDir;
}

void Ordena(Vertice *vertices, int inicio, int fim) { 
    if (inicio < 0 || fim < 0) {
        throw std::invalid_argument("Indice invalido!");
    } 

    if (inicio >= fim) return;
 
    int meio = inicio + (fim - inicio) / 2;

    Ordena(vertices, inicio, meio);
    Ordena(vertices, meio + 1, fim);

    Merge(vertices, inicio, meio, fim);
}

void MergeSort(Vertice *vertices, int tamanho) { 
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho invalido!");
    } 

    Ordena(vertices, 0, tamanho-1); 
}