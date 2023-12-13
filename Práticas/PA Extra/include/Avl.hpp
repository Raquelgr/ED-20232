#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <string>

using namespace std;

class AVLNode {
    protected:
        int chave;
        AVLNode* esquerda;
        AVLNode* direita;

        int altura;
    
        AVLNode(int chave);
        ~AVLNode();

    friend class AVLTree;
};

class AVLTree {
    private:
        AVLNode* raiz;

        int Altura(AVLNode* no);
        int FatorBalanceamento(AVLNode* no);
        int Maximo(int a, int b);

        AVLNode* RotacaoDireita(AVLNode* y);
        AVLNode* RotacaoEsquerda(AVLNode* x);
        AVLNode* Inserir(AVLNode* no, int chave);

        AVLNode* NoMinimo(AVLNode* no);
        AVLNode* Remover(AVLNode* no, int chave);

        void ImprimirPreOrdem(AVLNode* no);
        void ImprimirInOrdem(AVLNode* no);
        void ImprimirPosOrdem(AVLNode* no);

    public:
        AVLTree();
        void Inserir(int chave);
        void Remover(int chave);
        void PreOrdem();
        void InOrdem();
        void PosOrdem();
};

#endif