#include <pilha.h>
#include <infixToPostfix.h>

using namespace std;

string InfixToPostfix::CleanSpaces(string str) {
    string stringLimpa = "";

    for(int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            stringLimpa += str[i];
        }
    }

    return stringLimpa; 
}

bool InfixToPostfix::IsOperator(char caracter) {
    if(caracter == '(' || caracter == ')' || caracter == '~' || caracter == '&' || caracter == '|') {
        return true;
    } 

    return false;
}

int InfixToPostfix::Priority(char op) {
    if(op == '~') {
        return 3;
    } else if(op == '&') {
        return 2;
    } else if(op == '|') {
        return 1;
    } 
        
    return -1;
}

int InfixToPostfix::CheckPriority(char first, char second) {
    if(Priority(first) <= Priority(second)) {
        return 1;
    }

    return 0;
}

string InfixToPostfix::ConvertToPostfix(string formula, string valoracao) {
    Pilha *pilha = new Pilha();
    
    string formulaLimpa = CleanSpaces(formula);
    string posfixa;

    int proxValor = 0;

    for(int i = 0; i < formulaLimpa.length(); i++) {    
        char caracter = formulaLimpa[i];

        if(!IsOperator(caracter)) {
            posfixa += valoracao[proxValor];
            proxValor++;
        } else if(caracter == '(') {
            pilha->Empilha('(');
        } else if (caracter == ')') {
            while(pilha->GetValorTopo() != '(') {
                posfixa += pilha->Desempilha();
            }
            pilha->Desempilha();
        } else {
            while(!pilha->Vazia() && CheckPriority(caracter, pilha->GetValorTopo())) {
                posfixa += pilha->Desempilha();
            }
            pilha->Empilha(caracter);
        }

    }

    while(!pilha->Vazia()) {
        posfixa += pilha->Desempilha();
    }

    cout << posfixa << endl;

    delete pilha;

    return posfixa;
}

