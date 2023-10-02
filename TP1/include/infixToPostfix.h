#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include <iostream>
#include <sstream>
#include <string>

#include <funcoes.h>

using namespace std;

class InfixToPostfix : public Funcoes {
    private:
        string CleanSpaces(string str);
    
    protected:
        string ConvertToPostfix(string formula, string valoracao);

    friend class Avaliacao;
};

#endif