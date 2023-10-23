#ifndef METODOS_CONHECIDOS_HPP
#define METODOS_CONHECIDOS_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// class TipoNo {
//     public: 
//         TipoNo();
//         string item;

//     private:
//         TipoNo *esq;
//         TipoNo *dir;

//     friend class ArvoreDeSatisfabilidade;
// };

class MetodosConhecidos {
    public:
        void BubbleSort(int *item, int tamanho);
        void SelectionSort(int *item, int tamanho);
        void InserctionSort(int *item, int tamanho);
};

#endif