#ifndef SET_HPP
#define SET_HPP

#include <bits/stdc++.h>

using namespace std;

typedef struct s_table_elem{
    string dado;
    bool vazio;
    bool retirada;
} ElementoTabela;

class StringSet{
    public:
        StringSet(int tamanho);
        ~StringSet();

        void Inserir(string s);
        void Imprimir();

        int tamanhoTabela;
        int tamanhoConjunto;
        ElementoTabela* tabela;

        int Hash(string s);
        void Rehash(int pos);
        bool Contem(string s);
};

void BubbleSort(string *palavras, int tamanho);

#endif