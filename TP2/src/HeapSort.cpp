#include <HeapSort.hpp>

void Heapify(Vertice* vertices, int tamanho, int index) { 
    int maior = index; 
    int esq = 2 * index + 1;  
    int dir = 2 * index + 2;

    if (esq < tamanho && EhMaior(vertices[esq], vertices[maior])) {
        maior = esq;
    }

    if (dir < tamanho && EhMaior(vertices[dir], vertices[maior])) {
        maior = dir;
    } 

    if (maior != index) { 
        Troca(&vertices[index], &vertices[maior]);

        Heapify(vertices, tamanho, maior); 
    } 
} 
 
void HeapSort(Vertice* vertices, int tamanho) {     
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        Heapify(vertices, tamanho, i); 
    }
  
    for (int i = tamanho - 1; i >= 0; i--) {
        Troca(&vertices[i], &vertices[0]);    
            
        Heapify(vertices, i, 0); 
    } 
} 