#include <QuickSort.hpp>

void Particao(int esq, int dir, int *i, int *j, Vertice *vertices) { 
    Vertice aux;
    *i = esq; 
    *j = dir;

    aux = vertices[(*i + *j)/2]; 
    
    do { 
        while (EhMaior(aux, vertices[*i])) (*i)++;
        while (EhMenor(aux, vertices[*j])) (*j)--;

        if (*i <= *j) { 
            Troca(&vertices[*i], &vertices[*j]);

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