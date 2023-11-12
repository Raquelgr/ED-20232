#include <Vertice.hpp>

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

/* O método EhMenor é usado apenas para os algortimos não estáveis, em que é necessário analisar o empate das cores */
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

/* O método EhMaior é usado apenas para os algortimos não estáveis, em que é necessário analisar o empate das cores */
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