#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <string>

#include <Set.hpp>

using namespace std;

class AVLNode {
    protected:
        string palavra;
        AVLNode* esquerda;
        AVLNode* direita;

        int altura;
    
        StringSet* ocorrencias; 

        AVLNode(string str);
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
        AVLNode* Inserir(AVLNode* no, string palavra, int pagina);

        void Imprimir(AVLNode* no);

    public:
        AVLTree();
        void Inserir(string palavra, int pagina);
        void Imprimir();
};

#endif