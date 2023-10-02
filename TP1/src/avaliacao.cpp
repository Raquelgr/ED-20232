#include <pilha.h>
#include <infixToPostfix.h>
#include <avaliacao.h>

char Avaliacao::Avaliar(string formula, string valoracao) {
    InfixToPostfix conversao;
    string formulaPosfixa;

    formulaPosfixa = conversao.ConvertToPostfix(formula, valoracao);

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