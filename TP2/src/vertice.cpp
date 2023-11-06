#include <vertice.hpp>

Vertice::Vertice() { 
    rotulo = -1;
    cor = -1;
    qtdVizinhos = 0; 
    vizinhos = nullptr;
}

void Troca(Vertice* a, Vertice* b) {
    Vertice aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

bool EhMenor(Vertice a, Vertice b) {
    if (a.cor < b.cor) {
        return true;
    } else if (a.cor == b.cor) { 
        if (a.rotulo < b.rotulo) { 
            return true;
        }
    }

    return false;
}

bool EhMaior(Vertice a, Vertice b) {
    if (a.cor > b.cor) {
        return true;
    } else if (a.cor == b.cor) { 
        if (a.rotulo > b.rotulo) { 
            return true;
        }
    }

    return false;
}