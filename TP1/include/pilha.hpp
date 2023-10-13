#ifndef PILHA_HPP
#define PILHA_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class TipoCelula {
    public: 
        TipoCelula();
    
    private:
        char item;
        TipoCelula *prox;
    
    friend class Pilha;
};

class Pilha {
    private: 
        TipoCelula* topo;

    protected:
        int tamanho;

    public:
        Pilha();
        ~Pilha();

        void Empilha(char item);
        char Desempilha();
        void Limpa();

        char GetValorTopo();

        bool Vazia() {
            return tamanho == 0;
        }
};

#endif