#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <iostream>
#include <sstream>
#include <string>

#include <funcoes.h>

using namespace std;

class Avaliacao : public Funcoes {
    private:
        string RemoverEspacos(string str);
        string ConverterInfixaParaPosfixa(string formula, string valoracao);
        
    public:
        char Avaliar(string formula, string valoracao);
};

#endif