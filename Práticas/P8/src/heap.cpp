#include <iostream>
#include <sstream>
#include <string>

#include <heap.hpp>

using namespace std;

Heap::Heap(int maxsize) { 
    data = new Aresta[maxsize];
    tamanho = 0; 
}

Heap::~Heap() { delete[] data; }

void Heap::Inserir(Aresta x) {
    data[tamanho] = x;
    
    int auxTam = tamanho;
    int midAux = GetAncestral(auxTam);
    
    while (data[auxTam].custo < data[midAux].custo) {
        Aresta aux = data[midAux];
        data[midAux] = data[auxTam];
        data[auxTam] = aux;

        auxTam = midAux;
        midAux = GetAncestral(auxTam);
    }

    tamanho++;
}

Aresta Heap::Remover() {
    Aresta aux = data[0];
    data[0] = data[tamanho - 1];

    tamanho--;

    int i = 0;
    
    int esq = GetSucessorEsq(i);
    int dir = GetSucessorDir(i);
    int s = data[dir].custo < data[esq].custo ? dir : esq;

    while (data[i].custo > data[s].custo && (esq < tamanho || dir < tamanho)) {
        Aresta temp = data[s];
        data[s] = data[i];
        data[i] = temp;

        i = s;
        esq = GetSucessorEsq(i);
        dir = GetSucessorDir(i);

        s = data[dir].custo < data[esq].custo ? dir : esq;
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