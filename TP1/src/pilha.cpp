#include <pilha.hpp>

TipoCelula::TipoCelula() {
    prox = nullptr;
}

Pilha::Pilha() {
    topo = nullptr;
    tamanho = 0;
}

Pilha::~Pilha() {
    Limpa();
}

void Pilha::Empilha(char item) {
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;

    topo = nova;
    tamanho++;
}

char Pilha::Desempilha() {
    TipoCelula *p;
    char aux;

    if (Vazia()) {
        throw invalid_argument("A pilha esta vazia!");
    }

    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;

    return aux;
}

void Pilha::Limpa() {
    while (!Vazia()) {
        Desempilha();
    }
}

char Pilha::GetValorTopo() {
    return topo->item;
}