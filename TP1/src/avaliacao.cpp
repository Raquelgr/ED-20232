#include <pilha.h>
#include <infixToPostfix.h>
#include <avaliacao.h>

char Avaliacao::Avaliar(string formulaPosfixa) {
    Pilha* pilhaDeAvaliacao = new Pilha();
    
    for(int i = 0; i < formulaPosfixa.length(); i++) {    
        char caracter = formulaPosfixa[i];

        if(IsNotOperator(caracter)) {
            pilhaDeAvaliacao->Empilha(caracter);
        } else if(IsNot(caracter)) { 
            int resultadoNot = !(pilhaDeAvaliacao->Desempilha() - 48);
            char resultadoConvertido = to_string(resultadoNot)[0];

            pilhaDeAvaliacao->Empilha(resultadoConvertido);
        } else {
            int primeiroValor = pilhaDeAvaliacao->Desempilha() - 48;
            int segundoValor = pilhaDeAvaliacao->Desempilha() - 48;

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

    return pilhaDeAvaliacao->GetValorTopo();
}