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
    if (p == nullptr) {
        p = new TipoNo();
        p->item = item;
    } 
    

    // Por padrão do projeto, entradas 0 vão para a esquerda e entradas 1 vão para a direita
    for (int i = 0; i < item.length(); i++) {
        if (!(isdigit(item[i]))) {
            if (item[i] != 'e' && item[i] != 'a') {
                throw invalid_argument("A valoracao contem uma variavel nao permitida!");
            }

            // Cria cópia para garantir que o item seja o original
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
        
        // Se não é nó folha, percorre o item do nó para fazer as mudanças necessárias 
        for (int posicao = 0; posicao < p->item.length(); posicao++) {
            // Se não é digito, é variável "e" ou "a"
            if (!(isdigit(p->item[posicao]))) {
                char variavel = p->item[posicao];

                if (p->esq->item.length() == 1 && p->dir->item.length() == 1) {
                    // Se os filhos tem apenas um número, houve solução única para os dois
                    if (variavel == 'e') {
                        if (p->esq->item == "1" && p->dir->item == "1") { // Os dois filhos são 1, logo, para todo valor existe uma satisfabilidade
                            p->item = p->item.replace(posicao, 1, "a");
                        } else if (p->esq->item == "1" && p->dir->item == "0") { // Se apenas o filho da esquerda é 1, só existe satisfabilidade para o caso em que a váriavel assumiu valor 0
                            p->item = p->item.replace(posicao, 1, "0");
                        } else if (p->esq->item == "0" && p->dir->item == "1") {  // Se apenas o filho da direita é 1, só existe satisfabilidade para o caso em que a váriavel assumiu valor 1
                            p->item = p->item.replace(posicao, 1, "1");
                        } else if (p->esq->item == "0" && p->dir->item == "0") { // Se nenhum filho é igual a 1, não existe satisfabilidade
                            p->item = "0";
                        }
                    } else if (variavel == 'a') {
                        if (p->esq->item != "1" || p->dir->item != "1") { // Se o filho da esquerda ou o da direita é igual a 0, não existe satisfabilidade PARA TODO valor assumido pela variável
                            p->item = "0";
                        }
                    }
                } else if (p->esq->item.length() == 1 && p->dir->item.length() > 1) {  // Se o filho da esquerda tem apenas um número mas o da direita não, significa que para o filho da esquerda houve solução única e para o direita houve solução múltipla
                    if (variavel == 'a') {
                        if (p->esq->item == "0") { // Se o filho da esquerda é 0, não existe satisfabilidade PARA TODO valor assumido pela variável
                            p->item[posicao] = '0';
                        } else {
                            p->item[posicao] = p->dir->item[posicao]; 
                        }
                    } else {
                        p->item[posicao] = p->dir->item[posicao]; 
                    }
                } else if (p->esq->item.length() > 1 && p->dir->item.length() == 1) { // Se o filho da direita tem apenas um número mas o da esquerda não, significa que para o filho da esquerda houve solução única e para o direita houve solução múltipla
                    if (variavel == 'a') {
                        if (p->dir->item == "0") { // Se o filho da direita é 0, não existe satisfabilidade PARA TODO valor assumido pela variável
                            p->item[posicao] = '0';
                        } else {
                            p->item[posicao] = p->esq->item[posicao]; 
                        }
                    } else {
                        p->item[posicao] = p->esq->item[posicao]; 
                    }
                } else { // Os dois filhos possuem soluções múltiplas
                    if (variavel == 'a') {
                        if ((p->esq->item[posicao] == '0' && p->dir->item[posicao] == '1')) {
                            p->item[posicao] = 'a';
                        } else if ((p->esq->item[posicao] != 'a' && p->dir->item[posicao] != 'a')) {
                            p->item[posicao] = p->esq->item[posicao];
                        }
                    } else {
                        if ((p->esq->item[posicao] == '0' && p->dir->item[posicao] == '1') || (p->esq->item[posicao] == '1' && p->dir->item[posicao] == '0')) {
                            p->item[posicao] = 'a';
                        } else if ((p->esq->item[posicao] == 'a' || p->dir->item[posicao] == 'a')) {
                            p->item[posicao] = 'a';
                        } else {
                            p->item[posicao] = p->esq->item[posicao];
                        }
                    }
                }
            }
        }

    } else {
        // Se é nó folha, não possui variavéis, logo, é possível fazer a avaliação 
        Avaliacao avaliacao;
        char resultadoAvaliacao;

        resultadoAvaliacao = avaliacao.Avaliar(formula, p->item);
        p->item = {resultadoAvaliacao}; 
    }     
}

void ArvoreDeSatisfabilidade::Limpa() {
    ApagaRecursivo(raiz);
    raiz = nullptr;
}

void ArvoreDeSatisfabilidade::ApagaRecursivo(TipoNo *p) {
    if (p != nullptr) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

string ArvoreDeSatisfabilidade::VerificarSatisfablidade(string formula, string valoracao) {
    ArvoreDeSatisfabilidade* arvore = new ArvoreDeSatisfabilidade();
   
    arvore->Insere(valoracao);
    arvore->CaminhaEResolve(formula, arvore->raiz);

    string resposta = arvore->raiz->item; 
    
    arvore->Limpa();

    return resposta;
}