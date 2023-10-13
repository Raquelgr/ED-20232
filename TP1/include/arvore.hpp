#ifndef ARVORE_HPP
#define ARVORE_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class TipoNo {
    public: 
        TipoNo();
        string item;

    private:
        TipoNo *pai;
        TipoNo *esq;
        TipoNo *dir;

    friend class Arvore;
    friend class Satisfabilidade;
};

class Arvore {
    private: 
        void InsereRecursivo(TipoNo* &p, string item);
        void ApagaRecursivo(TipoNo *p);

    public:
        Arvore();
        ~Arvore();

        void Insere(string item);
        void CaminhaEResolve(string formula, TipoNo *p);
        void Limpa();

        TipoNo *raiz;
};

#endif