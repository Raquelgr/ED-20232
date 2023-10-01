#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Funcoes {
    public:
        bool IsNot(char caracter);
        bool IsAnd(char caracter);
        bool IsOr(char caracter);
        bool IsOperator(char caracter);
        bool IsNotOperator(char caracter);
        int Priority(char op);
        int CheckPriority(char first, char second);
};

#endif