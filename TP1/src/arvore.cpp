#include <arvore.hpp>

TipoNo::TipoNo() {
    pai = nullptr;
    esq = nullptr;
    dir = nullptr;
}

Arvore::Arvore() {
    raiz = nullptr;
}

Arvore::~Arvore() {
    Limpa();
}

void Arvore::Insere(string item) {
    InsereRecursivo(raiz, item);
}

void Arvore::InsereRecursivo(TipoNo* &p, string item) {
    if(p == nullptr) {
        p = new TipoNo();
        p->item = item;
    } 
    
    for (int i = 0; i < item.length(); i++) {
        if(!(isdigit(item[i]))) {
            string valoracaoEsq = item.replace(i, 1, "0");
            InsereRecursivo(p->esq, valoracaoEsq);

            string valoracaoDir = item.replace(i, 1, "1");
            InsereRecursivo(p->dir, valoracaoDir);

            //Define o pai 
            p->esq->pai = p;
            p->dir->pai = p;
        }
    }
}

void Arvore::CaminhaPosOrdem(TipoNo *p) {
    if(p != nullptr) {
        CaminhaPosOrdem(p->esq);
        CaminhaPosOrdem(p->dir);
        cout << p->item << endl;
    }
}

void Arvore::Limpa() {
    ApagaRecursivo(raiz);
    raiz = nullptr;
}

void Arvore::ApagaRecursivo(TipoNo *p) {
    if(p != nullptr) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}
