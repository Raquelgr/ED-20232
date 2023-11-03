#include <heapSort.hpp>

bool ComparaMenor(Vertice a, Vertice b) {
    if (a.cor < b.cor) {
        return true;
    } else if (a.cor == b.cor) { 
        if (a.rotulo < b.rotulo) { 
            return true;
        }
    }

    return false;
}

bool ComparaMaior(Vertice a, Vertice b) {
    if (a.cor > b.cor) {
        return true;
    } else if (a.cor == b.cor) { 
        if (a.rotulo > b.rotulo) { 
            return true;
        }
    }

    return false;
}

void Refaz(Vertice* vertices, int esq, int dir) {
    int i, j; 
    Vertice aux;
    
    i = esq;
    j = i * 2;
    aux = vertices[i];

    while (j <= dir) {
        if (j < dir && ComparaMenor(vertices[j], vertices[j+1])) j++;
        if (ComparaMaior(aux, vertices[j])) break;

        vertices[i] = vertices[j];
        i = j; 
        j = i * 2;
    }

    vertices[i] = aux;
}

void Constroi(Vertice *vertices, int tamanho) {
    int esq;
    
    esq = tamanho / 2 + 1;
    
    while (esq > 1) { 
        esq--;
        Refaz(vertices, esq, tamanho);
    }
}

void HeapSort(Vertice *vertices, int tamanho) { 
    int esq, dir;
    Vertice aux;
    Constroi(vertices, tamanho);

    esq = 1; 
    dir = tamanho;

    while (dir > 1) {
        aux = vertices[1];
        vertices[1] = vertices[dir];
        vertices[dir] = aux;

        dir--;

        Refaz(vertices, esq, dir);
    }
}