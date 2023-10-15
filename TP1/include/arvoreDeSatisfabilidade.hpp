#ifndef ARVORE_DE_SATISFABILIDADE_HPP
#define ARVORE_DE_SATISFABILIDADE_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class TipoNo {
    public: 
        TipoNo();
        string item;

    private:
        TipoNo *esq;
        TipoNo *dir;

    friend class ArvoreDeSatisfabilidade;
};

class ArvoreDeSatisfabilidade {
    private: 
        // Recebe a string passada e chama o método InsereRecursivo para inserir na posição correta
        void Insere(string item);
        void InsereRecursivo(TipoNo* &p, string item);

        // Realiza o caminhamento pela árvore e resolve a satisfabilidade nó por nó
        void CaminhaEResolve(string formula, TipoNo *p);
        
        void Limpa();
        void ApagaRecursivo(TipoNo *p);

        TipoNo *raiz;
    
    public:
        ArvoreDeSatisfabilidade();
        ~ArvoreDeSatisfabilidade();

        /*
            Recebe a formulá passada e a valoração, 
            Dentro do método são feitas todas as chamadas para resolver a satisfabilidade: Insere, CaminhaEResolve
            Ao final, pega o valor da raiz e limpa a árvore
            Em geral, esse método faz o encapsulamento dos demais métodos da classe
        */ 
        string VerificarSatisfablidade(string formula, string valoracao);
};

#endif