#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Funcoes {
    public:
        bool IsNot(char caracter);
        bool IsAnd(char caracter);
        bool IsOr(char caracter);
        bool IsValidOperator(char caracter);
        int Priority(char op);
        int CheckPriority(char first, char second);
};

#endif