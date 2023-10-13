#include <pilha.hpp>
#include <avaliacao.hpp>

string Avaliacao::RemoverEspacos(string str) {
    string stringLimpa;

    for(int i = 0; i < str.length(); i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            stringLimpa += str[i];
        }
    }

    return stringLimpa; 
}

string Avaliacao::ConverterInfixaParaPosfixa(string formula, string valoracao) {
    Pilha* pilhaDeConversao = new Pilha();
    
    string formulaLimpa = RemoverEspacos(formula);
    string posfixa;

    for(int i = 0; i < formulaLimpa.length(); i++) {    
        char caracter = formulaLimpa[i];
        
        if(IsNotOperator(caracter)) {
            int posicao = caracter - 48;
            //TODO: se a posicao não existir no array, dar erro
            posfixa += valoracao[posicao];
        } else if(caracter == '(') {
            pilhaDeConversao->Empilha('(');
        } else if (caracter == ')') {
            while(pilhaDeConversao->GetValorTopo() != '(') {
                posfixa += pilhaDeConversao->Desempilha();
            }

            pilhaDeConversao->Desempilha();
        } else {
            while(!pilhaDeConversao->Vazia() && CheckPriority(caracter, pilhaDeConversao->GetValorTopo())) {
                posfixa += pilhaDeConversao->Desempilha();
            }

            pilhaDeConversao->Empilha(caracter);
        }

    }

    while(!pilhaDeConversao->Vazia()) {
        posfixa += pilhaDeConversao->Desempilha();
    }

    return posfixa;
}

char Avaliacao::Avaliar(string formula, string valoracao) {
    string formulaPosfixa;
    formulaPosfixa = ConverterInfixaParaPosfixa(formula, valoracao);

    Pilha* pilhaDeAvaliacao = new Pilha();

    for(int i = 0; i < formulaPosfixa.length(); i++) {    
        char caracter = formulaPosfixa[i];

        if(IsNotOperator(caracter)) {
            pilhaDeAvaliacao->Empilha(caracter);
        } else if(IsNot(caracter)) { 
            int resultadoNot = !(pilhaDeAvaliacao->Desempilha() - 48);
            //TODO: verificar se primeiro e segundo valor são digitos validos
            char resultadoConvertido = to_string(resultadoNot)[0];

            pilhaDeAvaliacao->Empilha(resultadoConvertido);
        } else {
            int primeiroValor = pilhaDeAvaliacao->Desempilha() - 48;
            int segundoValor = pilhaDeAvaliacao->Desempilha() - 48;
            //TODO: verificar se primeiro e segundo valor são digitos validos
            if(IsAnd(caracter)) {
                int resultadoAnd = primeiroValor && segundoValor;
                char resultadoConvertido = to_string(resultadoAnd)[0];

                pilhaDeAvaliacao->Empilha(resultadoConvertido);
            }

            if(IsOr(caracter)) {
                int resultadoOr = primeiroValor || segundoValor;
                char resultadoConvertido = to_string(resultadoOr)[0];

                pilhaDeAvaliacao->Empilha(resultadoConvertido);
            }
        }
    }
    
    return pilhaDeAvaliacao->Desempilha();
}