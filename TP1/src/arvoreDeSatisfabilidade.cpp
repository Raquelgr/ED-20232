#include <arvoreDeSatisfabilidade.hpp>
#include <avaliacao.hpp>

TipoNo::TipoNo() {
    esq = nullptr;
    dir = nullptr;
}

ArvoreDeSatisfabilidade::ArvoreDeSatisfabilidade() {
    raiz = nullptr;
}

ArvoreDeSatisfabilidade::~ArvoreDeSatisfabilidade() {
    Limpa();
}

void ArvoreDeSatisfabilidade::Insere(string item) {
    InsereRecursivo(raiz, item);
}

void ArvoreDeSatisfabilidade::InsereRecursivo(TipoNo* &p, string item) {
    if(p == nullptr) {
        p = new TipoNo();
        p->item = item;
    } 
    
    for (int i = 0; i < item.length(); i++) {
        if(!(isdigit(item[i]))) {
            if (item[i] != 'e' && item[i] != 'a') {
                throw invalid_argument("A valoracao contem uma variavel nao permitida!");
            }

            string copiaDoItem = item;
            
            string valoracaoEsq = item.replace(i, 1, "0");
            InsereRecursivo(p->esq, valoracaoEsq);

            string valoracaoDir = copiaDoItem.replace(i, 1, "1");
            InsereRecursivo(p->dir, valoracaoDir);
        }
    }
}

void ArvoreDeSatisfabilidade::CaminhaEResolve(string formula, TipoNo *p) {
    if(p->esq != nullptr || p->dir != nullptr) {
        CaminhaEResolve(formula, p->esq);
        CaminhaEResolve(formula, p->dir);
    } 

    if(p->esq == nullptr && p->dir == nullptr) {
        Avaliacao avaliacao;
        char resultadoAvaliacao;

        resultadoAvaliacao = avaliacao.Avaliar(formula, p->item);
        p->item = {resultadoAvaliacao};
    } else {      
        int posicaoDaVariavel = -1;
        char variavel;

        for (int i = 0; i < p->item.length(); i++) {
            if(!(isdigit(p->item[i]))) {
                posicaoDaVariavel = i;
                variavel = p->item[i];
            }
        }

        if (posicaoDaVariavel != -1) {
            if (p->esq->item.length() == 1 && p->dir->item.length() == 1) {
                if (variavel == 'e') {
                    if (p->esq->item == "1" && p->dir->item == "1") {  
                        p->item = p->item.replace(posicaoDaVariavel, 1, "a");
                    } else if (p->esq->item == "1" && p->dir->item == "0") {  
                        p->item = p->item.replace(posicaoDaVariavel, 1, "0");
                    } else if (p->esq->item == "0" && p->dir->item == "1") {  
                        p->item = p->item.replace(posicaoDaVariavel, 1, "1");
                    } else if (p->esq->item == "0" && p->dir->item == "0") {
                        p->item = "0";
                    }
                } else if (variavel == 'a') {
                    if (p->esq->item != "1" || p->dir->item != "1") {
                        p->item = "0";
                    }
                } else {
                    if (p->esq->item == "0") {  
                        p->item = p->dir->item;
                    } else {
                        p->item = p->esq->item;
                    }
                }
            } else {
                if (p->esq->item.length() == 1 && p->dir->item.length() > 1) { 
                    if (variavel == 'a') {
                        p->item = p->esq->item;
                    } else {
                        p->item = p->dir->item;
                    }
                } else if (p->esq->item.length() > 1 && p->dir->item.length() == 1) {
                    if (variavel == 'a') {
                        p->item = p->dir->item;
                    } else {
                        p->item = p->esq->item;
                    }
                } else {
                    for (int j = 0; j < p->item.length(); j++) {
                        if ((p->esq->item.find("0") != string::npos && p->dir->item.find("1") != string::npos && p->esq->item.find("0") == p->dir->item.find("1"))) {
                            p->item = p->item.replace(p->esq->item.find("0"), 1, "a");
                        } 
    
                        if ((p->esq->item.find("1") != string::npos && p->dir->item.find("0") != string::npos && p->esq->item.find("1") == p->dir->item.find("0"))) {
                            p->item = p->item.replace(p->esq->item.find("1"), 1, "a");
                        } 
                        
                        if ((p->esq->item.find("1") != string::npos && p->dir->item.find("a") != string::npos && p->esq->item.find("1") == p->dir->item.find("a"))) {
                            p->item = p->item.replace(p->esq->item.find("1"), 1, "1");
                        } 
                        
                        if ((p->esq->item.find("0") != string::npos && p->dir->item.find("a") != string::npos && p->esq->item.find("0") == p->dir->item.find("a"))) {
                            p->item = p->item.replace(p->esq->item.find("0"), 1, "0");
                        } 

                        if ((p->esq->item.find("a") != string::npos && p->dir->item.find("1") != string::npos && p->esq->item.find("a") == p->dir->item.find("1"))) {
                            p->item = p->item.replace(p->dir->item.find("1"), 1, "1");
                        } 
                        
                        if ((p->esq->item.find("a") != string::npos && p->dir->item.find("0") != string::npos && p->esq->item.find("a") == p->dir->item.find("0"))) {
                            p->item = p->item.replace(p->esq->item.find("a"), 1, "0");
                        }
                    }
                }
            } 
        }  
    }  
}

void ArvoreDeSatisfabilidade::Limpa() {
    ApagaRecursivo(raiz);
    raiz = nullptr;
}

void ArvoreDeSatisfabilidade::ApagaRecursivo(TipoNo *p) {
    if(p != nullptr) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

string ArvoreDeSatisfabilidade::VerificarSatisfablidade(string formula, string valoracao) {
    ArvoreDeSatisfabilidade* arvore = new ArvoreDeSatisfabilidade();
   
    arvore->Insere(valoracao);
    arvore->CaminhaEResolve(formula, arvore->raiz);

    //Verifica a presença de "e" na raiz, todo "e" na raiz final deve ser alterado por "a"
    for (int i = 0; i < arvore->raiz->item.length(); i++) {
        if(arvore->raiz->item[i] == 'e') {
            arvore->raiz->item = arvore->raiz->item.replace(i, 1, "a");
        }
    }

    string resposta = arvore->raiz->item; 
    
    arvore->Limpa();

    return resposta;
}