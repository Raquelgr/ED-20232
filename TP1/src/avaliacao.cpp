#include <pilha.hpp>
#include <avaliacao.hpp>

string Avaliacao::RemoverEspacos(string str) {
    string stringLimpa;

    for (int i = 0; i < str.length(); i++) {
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

    if (!ParentesesBalanceados(formulaLimpa)) throw invalid_argument("Os parenteses estao desbalanceados!");
    if (!UltimoCaractereValido(formulaLimpa)) throw invalid_argument("O ultimo caractere nao e valido!");
    if (!CaracteresValidos(formulaLimpa)) throw invalid_argument("A formula contem um caracter nao permitido!");

    Pilha* pilhaDeConversao = new Pilha();
    string posfixa = "";

    int pos = 0;
    for (pos = 0; pos < formulaLimpa.length(); pos++) {    
        char caracter = formulaLimpa[pos];
        
        //É possível chegar até a posição 99, logo é necessário verificar se o próximo caracter é um digito
        if (isdigit(caracter)) {
            int primeiraPosicao = (caracter - 48);

            if (primeiraPosicao < 0 || primeiraPosicao >= valoracao.length()) {
                throw out_of_range("Nao existe posicao " + to_string(primeiraPosicao) + " na valoracao informada!");
            } 

            char proximoCaracter = formulaLimpa[pos+1];
            if (isdigit(proximoCaracter)) {
                int segundaPosicao = (proximoCaracter - 48);                

                if (segundaPosicao < 0 || segundaPosicao >= valoracao.length()) {
                    throw out_of_range("Nao existe posicao " + to_string(segundaPosicao) + " na valoracao informada!");
                }

                //Necessário converter para string para concatenar as duas posições
                string primeiraPosicaoEmString = to_string(primeiraPosicao); 
                string segundaPosicaoEmString = to_string(segundaPosicao); 
                string posicaoDoDigitoEmString = primeiraPosicaoEmString + segundaPosicaoEmString; 

                //Depois é necessário converter para achar a posição no array
                int posicaoFinal = stoi(posicaoDoDigitoEmString);

                posfixa += valoracao[posicaoFinal];

                //Incrementa o i para pular o próximo caracter que já foi considerado
                pos++;
            } else {
                posfixa += valoracao[primeiraPosicao];
            }

        } else if (caracter == '(') {
            pilhaDeConversao->Empilha('(');
        } else if (caracter == ')') {
            while (!pilhaDeConversao->Vazia() && pilhaDeConversao->GetValorTopo() != '(') {
                posfixa += pilhaDeConversao->Desempilha();
            }

            if (!pilhaDeConversao->Vazia()) {
                pilhaDeConversao->Desempilha();
            }
        } else {
            while (!pilhaDeConversao->Vazia() && CheckPriority(caracter, pilhaDeConversao->GetValorTopo())) {
                posfixa += pilhaDeConversao->Desempilha();
            }

            pilhaDeConversao->Empilha(caracter);
        }

    }

    while (!pilhaDeConversao->Vazia()) {
        posfixa += pilhaDeConversao->Desempilha();
    }

    return posfixa;
}

char Avaliacao::Avaliar(string formula, string valoracao) {
    string formulaPosfixa;
    formulaPosfixa = ConverterInfixaParaPosfixa(formula, valoracao);

    Pilha* pilhaDeAvaliacao = new Pilha();

    for (int i = 0; i < formulaPosfixa.length(); i++) {    
        char caracter = formulaPosfixa[i];
        
        if (isdigit(caracter)) {
            pilhaDeAvaliacao->Empilha(caracter);
        } else if (IsNot(caracter) && !pilhaDeAvaliacao->Vazia()) {
            char valorDesempilhado = pilhaDeAvaliacao->Desempilha(); 
            if (valorDesempilhado != '1' && valorDesempilhado != '0') throw invalid_argument("Valor invalido!");

            int resultadoNot = !(valorDesempilhado - 48);
            char resultadoConvertido = to_string(resultadoNot)[0];

            pilhaDeAvaliacao->Empilha(resultadoConvertido);
        } else if (!pilhaDeAvaliacao->Vazia()) {
            char primeiroValorDesempilhado = pilhaDeAvaliacao->Desempilha();

            // Confere se é um digito, caso seja um operador retorna erro
            if (primeiroValorDesempilhado != '1' && primeiroValorDesempilhado != '0') throw invalid_argument("Valor invalido!");

            char segundoValorDesempilhado = pilhaDeAvaliacao->Desempilha(); 
            
            // Confere se é um digito, caso seja um operador retorna erro 
            if (segundoValorDesempilhado != '1' && segundoValorDesempilhado != '0') throw invalid_argument("Valor invalido!");
            
            // Converte para inteiro para facilitar a operação, já que sendo inteiro realiza a função básica booleana que não precisa de implementação específica
            int primeiroValor = primeiroValorDesempilhado - 48;
            int segundoValor = segundoValorDesempilhado - 48;

            if (IsAnd(caracter)) {
                int resultadoAnd = primeiroValor && segundoValor;
                char resultadoConvertido = to_string(resultadoAnd)[0];

                pilhaDeAvaliacao->Empilha(resultadoConvertido);
            } else if (IsOr(caracter)) {
                int resultadoOr = primeiroValor || segundoValor;
                char resultadoConvertido = to_string(resultadoOr)[0];

                pilhaDeAvaliacao->Empilha(resultadoConvertido);
            }
        }
    }
    
    // Salva a resposta para poder limpar a pilha
    char resposta = pilhaDeAvaliacao->Desempilha();
    
    pilhaDeAvaliacao->Limpa();

    return resposta;
}