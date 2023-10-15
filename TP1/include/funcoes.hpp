#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Funcoes {
    public:
        /* Funções para facilitar a verificação dos caracteres */
        bool IsNot(char caracter);
        bool IsAnd(char caracter);
        bool IsOr(char caracter);

        /* Encapsula as lógicas para operadores válidos e prioridade entre eles */
        bool IsValidOperator(char caracter);
        int Priority(char op);
        int CheckPriority(char first, char second);
};

#endif