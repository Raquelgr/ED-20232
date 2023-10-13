#include <arvore.hpp>
#include <satisfabilidade.hpp>

string Satisfabilidade::CriaArvore(string formula, string valoracao) {
    Arvore* arvore = new Arvore();
    arvore->Insere(valoracao);

    arvore->CaminhaEResolve(formula, arvore->raiz);

    string resposta = arvore->raiz->item; 
    arvore->Limpa();

    return resposta;
}