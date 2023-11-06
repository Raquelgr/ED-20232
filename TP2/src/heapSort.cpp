#include <heapSort.hpp>

// void Refaz(Vertice* vertices, int esq, int dir) {
//     int i, j; 
//     Vertice aux;
    
//     i = esq;
//     j = i * 2;
//     aux = vertices[i];

//     while (j <= dir) {
//         if (j < dir && ComparaMenor(vertices[j], vertices[j+1])) j++;
//         if (EhMaior(aux, vertices[j])) break;

//         vertices[i] = vertices[j];
//         i = j; 
//         j = i * 2;
//     }

//     vertices[i] = aux;
// }

// void Constroi(Vertice *vertices, int tamanho) {
//     int esq;
    
//     esq = tamanho / 2 + 1;
//     while (esq > 1) { 
//         esq--;
//         Refaz(vertices, esq, tamanho);
//     }
// }

// void HeapSort(Vertice *vertices, int tamanho) { 
//     int esq, dir;
//     Vertice aux;
//     Constroi(vertices, tamanho);

//     esq = 1; 
//     dir = tamanho - 1;
    
//     while (dir > 0) {
//         aux = vertices[1];
//         vertices[1] = vertices[dir];
//         vertices[dir] = aux;

//         dir--;

//         Refaz(vertices, esq, dir);
//     }
// }

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