#include <QuickSort.hpp>

void Particao(int esq, int dir, int *i, int *j, Vertice *vertices) { 
    if (esq < 0 || dir < 0) {
        throw std::invalid_argument("Indice invalido!");
    } 

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
    if (esq < 0 || dir < 0) {
        throw std::invalid_argument("Indice invalido!");
    } 

    int i = 0;
    int j = 0;
  
    Particao(esq, dir, &i, &j, vertices);
    if (esq < j) Ordena(esq, j, vertices);
    if (i < dir) Ordena(i, dir, vertices);
}

void QuickSort(Vertice *vertices, int tamanho) { 
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho invalido!");
    } 

    Ordena(0, tamanho-1, vertices); 
}