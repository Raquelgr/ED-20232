#include <iostream>
#include <sstream>
#include <string>

#include <getopt.h>

#include <avaliacao.hpp>
#include <arvoreDeSatisfabilidade.hpp>

using namespace std;

#define TAMANHO_MAXIMO_FORMULA 1000000
#define TAMANHO_MAXIMO_VALORACAO 1000
 
int main(int argc, char* argv[]) try {
  int opt;
  
  string formula;
  string valoracao;

  bool ehAvaliacao = false;
  bool ehSatisfabilidade = false;

  Avaliacao avaliacao;
  string resultadoAvaliacao;

  ArvoreDeSatisfabilidade satisfabilidade;
  string resultadoSatisfabilidade;

  while ((opt = getopt(argc, argv, "as::")) != EOF) {
    switch (opt) {
      case 'a':
        ehAvaliacao = true;
        break;
      case 's':
        ehSatisfabilidade = true;
        break;
      default:
        throw invalid_argument("OPCAO INVALIDA!");
        break;
    }
  }

  formula = argv[2];
  if (formula.length() > TAMANHO_MAXIMO_FORMULA) {
    throw length_error("A formula excedeu o tamanho permitido!");
  }

  valoracao = argv[3];
  if (valoracao.length() > TAMANHO_MAXIMO_VALORACAO) {
    throw length_error("A valoracao excedeu o tamanho permitido!");
  }

  if (ehAvaliacao) {
    resultadoAvaliacao = avaliacao.Avaliar(formula, valoracao);

    cout << resultadoAvaliacao << endl;
  }
  
  if (ehSatisfabilidade) {
    resultadoSatisfabilidade = satisfabilidade.VerificarSatisfablidade(formula, valoracao);

    if (resultadoSatisfabilidade == "0") {
      cout << resultadoSatisfabilidade << endl; 
    } else {
      cout << "1 " << resultadoSatisfabilidade << endl;
    }
  }

  return 0;
}  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}