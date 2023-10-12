#ifndef ARVORE_HPP
#define ARVORE_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class TipoNo {
    public: 
        TipoNo();
    
    private:
        string item;
        TipoNo *pai;
        TipoNo *esq;
        TipoNo *dir;
        
    friend class Arvore;
};

class Arvore {
    private: 
        void InsereRecursivo(TipoNo* &p, string item);
        void ApagaRecursivo(TipoNo *p);

    public:
        Arvore();
        ~Arvore();

        void Insere(string item);
        void CaminhaPosOrdem(TipoNo *p);
        void Limpa();

        TipoNo *raiz;
};

#endif