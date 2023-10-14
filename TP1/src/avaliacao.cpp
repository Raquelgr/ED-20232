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

bool Avaliacao::ParentesesBalanceados(string formula) {
    int numParenteses = 0;
    int tamanho = formula.length();

    for (int i = 0; i < formula.length(); i++) {
        char caracterAtual = formula[i];

        if (caracterAtual == '(') {
            numParenteses++;
        } else if (caracterAtual == ')') {
            numParenteses--;

            if (numParenteses < 0) {
                return false;
            }
        }
    }

    return numParenteses == 0;
}

bool Avaliacao::UltimoCaractereValido(string formula) {
    char caracter = formula[formula.length() - 1];

    if (isdigit(caracter) || caracter == ')') {
        return true;
    }

    return false;
}

bool Avaliacao::CaracteresValidos(string formula) {
    bool naoPossuiCaracterInvalido = true;

    for (int i = 0; i < formula.length(); i++) {
        char caracterAtual = formula[i];

        if (!isdigit(caracterAtual) && !IsValidOperator(caracterAtual)) {
            naoPossuiCaracterInvalido = false;
        }
    }

    return naoPossuiCaracterInvalido;
}

string Avaliacao::ConverterInfixaParaPosfixa(string formula, string valoracao) {    
    string formulaLimpa = RemoverEspacos(formula);

    if(!ParentesesBalanceados(formulaLimpa)) throw invalid_argument("Os parenteses estao desbalanceados!");
    if(!UltimoCaractereValido(formulaLimpa)) throw invalid_argument("O ultimo caractere nao e valido!");
    if(!CaracteresValidos(formulaLimpa)) throw invalid_argument("A formula contem um caracter nao permitido!");

    Pilha* pilhaDeConversao = new Pilha();
    string posfixa = "";

    for(int i = 0; i < formulaLimpa.length(); i++) {    
        char caracter = formulaLimpa[i];
        
        if(isdigit(caracter)) {
            int posicao = (caracter - 48);

            if(posicao < 0 || posicao >= valoracao.length()) {
                throw out_of_range("Nao existe posicao " + to_string(posicao) + " na valoracao informada!");
            }

            posfixa += valoracao[posicao];
        } else if(caracter == '(') {
            pilhaDeConversao->Empilha('(');
        } else if (caracter == ')') {
            while(!pilhaDeConversao->Vazia() && pilhaDeConversao->GetValorTopo() != '(') {
                posfixa += pilhaDeConversao->Desempilha();
            }

            if (!pilhaDeConversao->Vazia()) {
                pilhaDeConversao->Desempilha();
            }
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
        
        if(isdigit(caracter)) {
            pilhaDeAvaliacao->Empilha(caracter);
        } else if(IsNot(caracter) && !pilhaDeAvaliacao->Vazia()) {
            char valorDesempilhado = pilhaDeAvaliacao->Desempilha(); 
            if (valorDesempilhado != '1' && valorDesempilhado != '0') throw invalid_argument("Valor invalido!");

            int resultadoNot = !(valorDesempilhado - 48);
            char resultadoConvertido = to_string(resultadoNot)[0];

            pilhaDeAvaliacao->Empilha(resultadoConvertido);
        } else if (!pilhaDeAvaliacao->Vazia()) {
            char primeiroValorDesempilhado = pilhaDeAvaliacao->Desempilha(); 
            if (primeiroValorDesempilhado != '1' && primeiroValorDesempilhado != '0') throw invalid_argument("Valor invalido!");

            char segundoValorDesempilhado = pilhaDeAvaliacao->Desempilha(); 
            if (segundoValorDesempilhado != '1' && segundoValorDesempilhado != '0') throw invalid_argument("Valor invalido!");
            
            int primeiroValor = primeiroValorDesempilhado - 48;
            int segundoValor = segundoValorDesempilhado - 48;

            if(IsAnd(caracter)) {
                int resultadoAnd = primeiroValor && segundoValor;
                char resultadoConvertido = to_string(resultadoAnd)[0];

                pilhaDeAvaliacao->Empilha(resultadoConvertido);
            } else if(IsOr(caracter)) {
                int resultadoOr = primeiroValor || segundoValor;
                char resultadoConvertido = to_string(resultadoOr)[0];

                pilhaDeAvaliacao->Empilha(resultadoConvertido);
            }
        }
    }
    
    char resposta = pilhaDeAvaliacao->Desempilha();
    
    pilhaDeAvaliacao->Limpa();

    return resposta;
}