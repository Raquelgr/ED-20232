#include <iostream>
#include <sstream>
#include <string>

#include <getopt.h>

#include <infixToPostfix.h>
#include <avaliacao.h>

using namespace std;

int main(int argc, char* argv[]) {
  int opt;
  
  string formula;
  string valoracao;

  bool ehAvaliacao = false;
  bool ehSatisfabilidade = false;

  InfixToPostfix conversao;
  string posfixa;

  Avaliacao avaliacao;
  char resultadoAvaliacao;

  while ((opt = getopt(argc, argv, "as::")) != EOF) {
    switch (opt) {
      case 'a':
        ehAvaliacao = true;
        break;
      case 's':
        ehSatisfabilidade = true;
        break;
      default:
        break;
    }
  }

  if (optind < argc) {
    formula = argv[optind];
    optind++;
  } 

  if (optind < argc) {
    valoracao = argv[optind];
  }

  posfixa = conversao.ConvertToPostfix(formula, valoracao);

  resultadoAvaliacao = avaliacao.Avaliar(posfixa);

  cout << resultadoAvaliacao << endl;

  return 0;
}