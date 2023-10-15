#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <funcoes.hpp>

using namespace std;

class Avaliacao : public Funcoes {
    private:
        // Remove todos os espaços da formula passada
        string RemoverEspacos(string str);

        /* Métodos de verificação */
        bool ParentesesBalanceados(string formula);
        bool UltimoCaractereValido(string formula);
        bool CaracteresValidos(string formula);

        // Converte a formula de infixa para posfixa para facilitar a avaliação
        string ConverterInfixaParaPosfixa(string formula, string valoracao);
        
    public:
        /*
            Recebe a fórmula passada e a valoração, 
            Dentro do método é chamado o método de conversão para posfixa
            Retorna 0 ou 1 para a fórmula e valoração passadas
        */ 
        char Avaliar(string formula, string valoracao);
};

#endif