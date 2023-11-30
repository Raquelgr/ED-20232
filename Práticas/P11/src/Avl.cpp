#include <Avl.hpp>

AVLNode::AVLNode(string str) {
    palavra = str;
    esquerda = nullptr;
    direita = nullptr;
    altura = 1;
    ocorrencias = new StringSet(1);
}

AVLNode:: ~AVLNode() { delete ocorrencias; }

AVLTree::AVLTree() {
    raiz = nullptr;
}

int AVLTree::Altura(AVLNode* no) {
    if (no == nullptr) {
        return 0;
    }

    return no->altura;
}

int AVLTree::FatorBalanceamento(AVLNode* no) {
    if (no == nullptr) {
        return 0;
    }

    return Altura(no->esquerda) - Altura(no->direita);
}

int AVLTree::Maximo(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* AVLTree::RotacaoDireita(AVLNode* y) {
    AVLNode* x = y->esquerda;
    AVLNode* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = Maximo(Altura(y->esquerda), Altura(y->direita)) + 1;
    x->altura = Maximo(Altura(x->esquerda), Altura(x->direita)) + 1;

    return x;
}

AVLNode* AVLTree::RotacaoEsquerda(AVLNode* x) {
    AVLNode* y = x->direita;
    AVLNode* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = Maximo(Altura(x->esquerda), Altura(x->direita)) + 1;
    y->altura = Maximo(Altura(y->esquerda), Altura(y->direita)) + 1;

    return y;
}

void AVLTree::Inserir(string palavra, int pagina) {
    raiz = Inserir(raiz, palavra, pagina);
}

AVLNode* AVLTree::Inserir(AVLNode* no, string palavra, int pagina) {
    if (no == nullptr) {
        AVLNode* novoNo = new AVLNode(palavra);
        novoNo->ocorrencias->Inserir(to_string(pagina));

        return novoNo;
    }

    if (palavra == no->palavra) {
        no->ocorrencias->Inserir(to_string(pagina));
        return no;
    }

    if (palavra < no->palavra) {
        no->esquerda = Inserir(no->esquerda, palavra, pagina);
    } else if (palavra > no->palavra) {
        no->direita = Inserir(no->direita, palavra, pagina);
    }

    no->altura = 1 + Maximo(Altura(no->esquerda), Altura(no->direita));

    int balanceamento = FatorBalanceamento(no);

    if (balanceamento > 1) {
        if (palavra < no->esquerda->palavra) {
            return RotacaoDireita(no);
        } else if (palavra > no->esquerda->palavra) {
            no->esquerda = RotacaoEsquerda(no->esquerda);
            return RotacaoDireita(no);
        }
    }

    if (balanceamento < -1) {
        if (palavra > no->direita->palavra) {
            return RotacaoEsquerda(no);
        } else if (palavra < no->direita->palavra) {
            no->direita = RotacaoDireita(no->direita);
            return RotacaoEsquerda(no);
        }
    }

    return no;
}

void AVLTree::Imprimir() {
    Imprimir(raiz);
}

void AVLTree::Imprimir(AVLNode* no) {
    if (no != nullptr) {
        Imprimir(no->esquerda);

        cout << no->palavra << ": ";
        no->ocorrencias->Imprimir();

        Imprimir(no->direita);
    }
}