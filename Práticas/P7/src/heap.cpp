#include <iostream>
#include <sstream>
#include <string>

#include <heap.hpp>

using namespace std;

Heap::Heap(int maxsize) { 
    data = new int[maxsize];
    tamanho = 0; 
}

Heap::~Heap() { delete[] data; }

void Heap::Inserir(int x) {
    data[tamanho] = x;
    
    int auxTam = tamanho;
    int midAux = GetAncestral(auxTam);
    
    while (data[auxTam] < data[midAux]) {
        int aux = data[midAux];
        data[midAux] = data[auxTam];
        data[auxTam] = aux;

        auxTam = midAux;
        midAux = GetAncestral(auxTam);
    }

    tamanho++;
}

int Heap::Remover() {
    int aux = data[0];
    data[0] = data[tamanho - 1];

    tamanho--;

    int i = 0;
    
    int esq = GetSucessorEsq(i);
    int dir = GetSucessorDir(i);
    int s = data[dir] < data[esq] ? dir : esq;

    while (data[i] > data[s] && (esq < tamanho || dir < tamanho)) {
        int temp = data[s];
        data[s] = data[i];
        data[i] = temp;

        i = s;
        esq = GetSucessorEsq(i);
        dir = GetSucessorDir(i);

        s = data[dir] < data[esq] ? dir : esq;
    }

    return aux;
}

bool Heap::Vazio() {
    return tamanho == 0;
}

int Heap::GetAncestral(int i) {
    return (i-1)/2;
}

int Heap::GetSucessorEsq(int i) {
    return 2 * i + 1;
}

int Heap::GetSucessorDir(int i) {
    return 2 * i + 2;
}