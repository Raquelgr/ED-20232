#include "unionFind.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos) {
    tamanho = quantidade_subconjuntos;
    subconjuntos = new Subconjunto[tamanho];

    for (int i = 0; i < tamanho; i++) {
        subconjuntos[i].representante = i;
        subconjuntos[i].rank = 0;
    }
}

UnionFind::~UnionFind() { delete[] subconjuntos; }

void UnionFind::Make(int x) {
    subconjuntos[x].representante = x;
    subconjuntos[x].rank = 0;
}

int UnionFind::Find(int x) {
    if (x != subconjuntos[x].representante) {
        subconjuntos[x].representante = Find(subconjuntos[x].representante); 
    }

    return subconjuntos[x].representante;
}

void UnionFind::Union(int x, int y) {
    int representanteX = Find(x);
    int representanteY = Find(y);

    if (representanteX != representanteY) {
        if (subconjuntos[representanteX].rank < subconjuntos[representanteY].rank) {
            subconjuntos[representanteX].representante = representanteY;
        } else if (subconjuntos[representanteX].rank > subconjuntos[representanteY].rank) {
            subconjuntos[representanteY].representante = representanteX;
        } else {
            subconjuntos[representanteY].representante = representanteX;
            subconjuntos[representanteX].rank++;
        }
    }
}