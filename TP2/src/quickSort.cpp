#include <quickSort.hpp>

bool ElementoMaiorQuePivo(Vertice a, Vertice b) {
    if (a.cor > b.cor) {
        return true;
    } else if (a.cor == b.cor) { 
        if (a.rotulo > b.rotulo) { 
            return true;
        }
    }

    return false;
}

bool ElementoMenorQuePivo(Vertice a, Vertice b) {
    if (a.cor < b.cor) {
        return true;
    } else if (a.cor == b.cor) { 
        if (a.rotulo < b.rotulo) { 
            return true;
        }
    }

    return false;
}

void Particao(int esq, int dir, int *i, int *j, Vertice *vertices) { 
    Vertice firstAux, secondAux;
    *i = esq; 
    *j = dir;

    firstAux = vertices[(*i + *j)/2]; 
    
    do { 
        while (ElementoMaiorQuePivo(firstAux, vertices[*i])) (*i)++;
        while (ElementoMenorQuePivo(firstAux, vertices[*j])) (*j)--;

        if (*i <= *j) { 
            secondAux = vertices[*i]; 
            vertices[*i] = vertices[*j]; 
            vertices[*j] = secondAux;

            (*i)++; (*j)--;
        }

    } while (*i <= *j);
}


void Ordena(int esq, int dir, Vertice *vertices) { 
    int i = 0;
    int j = 0;
  
    Particao(esq, dir, &i, &j, vertices);
    if (esq < j) Ordena(esq, j, vertices);
    if (i < dir) Ordena(i, dir, vertices);
}

void QuickSort(Vertice *vertices, int tamanho) { 
    Ordena(0, tamanho-1, vertices); 
}