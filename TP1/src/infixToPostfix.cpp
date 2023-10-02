#include <pilha.h>
#include <infixToPostfix.h>

string InfixToPostfix::CleanSpaces(string str) {
    string stringLimpa = "";

    for(int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            stringLimpa += str[i];
        }
    }

    return stringLimpa; 
}

string InfixToPostfix::ConvertToPostfix(string formula, string valoracao) {
    Pilha* pilhaDeConversao = new Pilha();
    
    string formulaLimpa = CleanSpaces(formula);
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