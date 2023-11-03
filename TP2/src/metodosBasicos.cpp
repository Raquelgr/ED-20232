#include <metodosBasicos.hpp>

void TrocaPosicao(Vertice* a, Vertice* b) {
    Vertice aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

bool NecessitaTroca(Vertice a, Vertice b) {
    if (a.cor < b.cor) {
        return true;
    } else if (a.cor == b.cor) { 
        if (a.rotulo < b.rotulo) { 
            return true;
        }
    }

    return false;
}

void BubbleSort(Vertice *vertices, int tamanho) {
    bool trocou;
    Vertice aux;
    
    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false;

        for (int j = 1; j < tamanho - i; j++) {
            if (NecessitaTroca(vertices[j], vertices[j-1])) {
                TrocaPosicao(&vertices[j-1], &vertices[j]);
                trocou = true;
            }
        }

        if (!trocou) break;
    }
}

void SelectionSort(Vertice *vertices, int tamanho) { 
    int min;

    for (int i = 0; i < tamanho - 1; i++) {
        min = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (NecessitaTroca(vertices[j], vertices[min])) {
                min = j;
            }
        }

        TrocaPosicao(&vertices[i], &vertices[min]); 
    }

}

void InserctionSort(Vertice *vertices, int tamanho) {
    int j = 0;
    Vertice aux;

    for (int i = 1; i < tamanho; i++) {
        aux = vertices[i];
        j = i - 1;

        while (j >= 0 && NecessitaTroca(aux, vertices[j])) {
            vertices[j + 1] = vertices[j];
            j--;
        }

        vertices[j + 1] = aux;
    } 
}