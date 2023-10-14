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
        void InsereRecursivo(TipoNo* &p, string item);
        void ApagaRecursivo(TipoNo *p);

    protected:
        void Insere(string item);
        void CaminhaEResolve(string formula, TipoNo *p);
        
        void Limpa();

        TipoNo *raiz;
    
    public:
        ArvoreDeSatisfabilidade();
        ~ArvoreDeSatisfabilidade();

        string VerificarSatisfablidade(string formula, string valoracao);
};

#endif