#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include <iostream>

using namespace std;

struct Matriz {
    int m[2][2];
};

class SegTree {
    private:
        Matriz *arvore;
        int tamanho;

        Matriz MultiplicaMatrizes(Matriz a, Matriz b);
        void AtualizaArvore(int pos, int intervaloEsq, int intervaloDir, int posicaoDeAtualizacao, Matriz matrizDeAtualizacao);
        Matriz BuscaIntervalo(int pos, int intervaloEsq, int intervaloDir, int intervaloInicio, int intervaloFim);

    public:
        SegTree(int n);
		~SegTree();

        void Atualiza(int posicaoDeAtualizacao, Matriz matrizDeAtualizacao);
        Matriz Consulta(int nascimento, int morte);
};

#endif