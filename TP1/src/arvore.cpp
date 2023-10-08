#include <arvore.hpp>


// ideias: são no max 5 variaveis que podem ser e ou a, posso fazer um if tranquilamente....
// pra cada um desses ifs, faço as variações =D
// tem que pensar nas chaves que serão usadas, e na saída tb
// como vou saber quando usar o 'a'? vou ter que avaliar a expressao e ver se foi igual?








TipoNo::TipoNo() {
    //item.SetChave(-1);
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
    } else {
        //TODO: como comparar o que maior e o que é menor?
        if(item < p->item) {
            InsereRecursivo(p->esq, item);
        } else {
            InsereRecursivo(p->dir, item);
        }
    }
}

void Arvore::CaminhaPosOrdem(TipoNo *p) {
    if(p != nullptr) {
        CaminhaPosOrdem(p->esq);
        CaminhaPosOrdem(p->dir);
        //p->item.Imprime();
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
