#include <arvore.hpp>
#include <avaliacao.hpp>

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

void Arvore::CaminhaEResolve(string formula, TipoNo *p) {
    if(p->esq != nullptr || p->dir != nullptr) {
        CaminhaEResolve(formula, p->esq);
        CaminhaEResolve(formula, p->dir);
    } 
    
    if(p->esq == nullptr && p->dir == nullptr) {
        Avaliacao avaliacao;
        char resultadoAvaliacao;
        //TODO: melhorar o código pra n precisar de conversao
        resultadoAvaliacao = avaliacao.Avaliar(formula, p->item);
        p->item = {resultadoAvaliacao};
    } else {      
        int posicaoDaVariavel = -1;

        for (int i = 0; i < p->item.length(); i++) {
            if(!(isdigit(p->item[i]))) {
                posicaoDaVariavel = i;
            }
        }

        if (posicaoDaVariavel != -1) {
            if (p->esq->item.length() == 1 && p->dir->item.length() == 1) {
                if (p->esq->item == "1" && p->dir->item == "1") {  
                    p->item = p->item.replace(posicaoDaVariavel, 1, "a");
                } else if (p->esq->item == "1" && p->dir->item == "0") {  
                    p->item = p->item.replace(posicaoDaVariavel, 1, "0");
                } else if (p->esq->item == "0" && p->dir->item == "1") {  
                    p->item = p->item.replace(posicaoDaVariavel, 1, "1");
                } else if (p->esq->item == "0" && p->dir->item == "0"){
                    p->item = "0";
                }
            } else {
                if (p->esq->item == "0") {  
                    p->item = p->dir->item;
                } else  {
                    p->item = p->esq->item;
                }
            } 
        }       
    }    
}

// void Arvore::CaminhPosOrdem(TipoNo *p) {
//     if(p != nullptr) {
//         CaminhPosOrdem(p->esq);
//         CaminhPosOrdem(p->dir);
//         cout << p->item << endl;
//     }    
// }

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