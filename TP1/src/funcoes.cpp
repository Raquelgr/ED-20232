#include <funcoes.h>

bool Funcoes::IsNot(char caracter) {
    if(caracter == '~') {
        return true;
    } 

    return false;
}

bool Funcoes::IsAnd(char caracter) {
    if(caracter == '&') {
        return true;
    } 

    return false;
}

bool Funcoes::IsOr(char caracter) {
    if(caracter == '|') {
        return true;
    } 

    return false;
}

bool Funcoes::IsOperator(char caracter) {
    if(caracter == '(' || caracter == ')') {
        return true;
    } 

    if(IsNot(caracter)) return true;
    if(IsAnd(caracter)) return true;
    if(IsOr(caracter)) return true;

    return false;
}

bool Funcoes::IsNotOperator(char caracter) {
    return !IsOperator(caracter);
}

int Funcoes::Priority(char op) {
    if(IsNot(op)) {
        return 3;
    } else if(IsAnd(op)) {
        return 2;
    } else if(IsOr(op)) {
        return 1;
    } 
        
    return -1;
}

int Funcoes::CheckPriority(char first, char second) {
    if(Priority(first) <= Priority(second)) {
        return 1;
    }

    return 0;
}