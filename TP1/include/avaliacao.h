#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <iostream>
#include <sstream>
#include <string>

#include <funcoes.h>

using namespace std;

class Avaliacao : public Funcoes {
    public:
        char Avaliar(string formulaPosfixa);
};

#endif