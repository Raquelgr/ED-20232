#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <funcoes.hpp>

using namespace std;

class Avaliacao : public Funcoes {
    private:
        string RemoverEspacos(string str);
        string ConverterInfixaParaPosfixa(string formula, string valoracao);
        
    public:
        char Avaliar(string formula, string valoracao);
};

#endif