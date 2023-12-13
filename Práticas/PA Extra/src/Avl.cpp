#include <Avl.hpp>

AVLNode::AVLNode(int n) {
    chave = n;
    esquerda = nullptr;
    direita = nullptr;
    altura = 1;
}

AVLNode:: ~AVLNode() { }

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

AVLNode* AVLTree::RotacaoDireita(AVLNode* no) {
    AVLNode* x = no->esquerda;
    AVLNode* aux = x->direita;

    x->direita = no;
    no->esquerda = aux;

    no->altura = Maximo(Altura(no->esquerda), Altura(no->direita)) + 1;
    x->altura = Maximo(Altura(x->esquerda), Altura(x->direita)) + 1;

    return x;
}

AVLNode* AVLTree::RotacaoEsquerda(AVLNode* no) {
    AVLNode* y = no->direita;
    AVLNode* aux = y->esquerda;

    y->esquerda = no;
    no->direita = aux;

    no->altura = Maximo(Altura(no->esquerda), Altura(no->direita)) + 1;
    y->altura = Maximo(Altura(y->esquerda), Altura(y->direita)) + 1;

    return y;
}

void AVLTree::Inserir(int chave) {
    raiz = Inserir(raiz, chave);
}

AVLNode* AVLTree::Inserir(AVLNode* no, int chave) {
    if (no == nullptr) {
        AVLNode* novoNo = new AVLNode(chave);

        return novoNo;
    }

    if (chave == no->chave) {
        return no;
    }

    if (chave < no->chave) {
        no->esquerda = Inserir(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = Inserir(no->direita, chave);
    }

    no->altura = 1 + Maximo(Altura(no->esquerda), Altura(no->direita));

    int balanceamento = FatorBalanceamento(no);

    if (balanceamento > 1) {
        if (chave < no->esquerda->chave) {
            return RotacaoDireita(no);
        } else if (chave > no->esquerda->chave) {
            no->esquerda = RotacaoEsquerda(no->esquerda);
            return RotacaoDireita(no);
        }
    }

    if (balanceamento < -1) {
        if (chave > no->direita->chave) {
            return RotacaoEsquerda(no);
        } else if (chave < no->direita->chave) {
            no->direita = RotacaoDireita(no->direita);
            return RotacaoEsquerda(no);
        }
    }

    return no;
}

AVLNode* AVLTree::NoMinimo(AVLNode* no) {
    AVLNode* atual = no;
    while (atual->esquerda != nullptr) {
        atual = atual->esquerda;
    }

    return atual;
}

void AVLTree::Remover(int chave) {
    raiz = Remover(raiz, chave);
}

AVLNode* AVLTree::Remover(AVLNode* no, int chave) {
    if (no == nullptr) {
        return no;
    }

    if (chave < no->chave) {
        no->esquerda = Remover(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = Remover(no->direita, chave);
    } else {
        if ((no->esquerda == nullptr) || (no->direita == nullptr)) { 
            AVLNode* aux = (no->esquerda != nullptr) ? no->esquerda : no->direita;
    
            if (aux == nullptr) {
                aux = no;
                no = nullptr;
            } else {
                *no = *aux; 
            }

            delete aux;       
        } else {
            AVLNode* aux = NoMinimo(no->direita);

            no->chave = aux->chave;
            no->direita = Remover(no->direita, aux->chave);
        }
    }

    if (no == nullptr) {
        return no;
    }

    no->altura = 1 + Maximo(Altura(no->esquerda), Altura(no->direita));

    int balanceamento = FatorBalanceamento(no);

    if (balanceamento > 1) {
        if (FatorBalanceamento(no->esquerda) >= 0) {
            return RotacaoDireita(no);
        } else {
            no->esquerda = RotacaoEsquerda(no->esquerda);
            return RotacaoDireita(no);
        }
    }

    if (balanceamento < -1) {
        if (FatorBalanceamento(no->direita) <= 0) {
            return RotacaoEsquerda(no);
        } else {
            no->direita = RotacaoDireita(no->direita);
            return RotacaoEsquerda(no);
        }
    }

    return no;
}

void AVLTree::PreOrdem() {
    ImprimirPreOrdem(raiz);
    cout << endl;
}

void AVLTree::ImprimirPreOrdem(AVLNode* no) {
    if (no != nullptr) {
        cout << no->chave << " ";

        ImprimirPreOrdem(no->esquerda);
        ImprimirPreOrdem(no->direita);
    }
}

void AVLTree::InOrdem() {
    ImprimirInOrdem(raiz);
    cout << endl;
}

void AVLTree::ImprimirInOrdem(AVLNode* no) {
    if (no != nullptr) {
        ImprimirInOrdem(no->esquerda);

        cout << no->chave << " ";

        ImprimirInOrdem(no->direita);
    }
}

void AVLTree::PosOrdem() {
    ImprimirPosOrdem(raiz);
    cout << endl;
}

void AVLTree::ImprimirPosOrdem(AVLNode* no) {
    if (no != nullptr) {
        ImprimirPosOrdem(no->esquerda);
        ImprimirPosOrdem(no->direita);

        cout << no->chave << " ";
    }
}