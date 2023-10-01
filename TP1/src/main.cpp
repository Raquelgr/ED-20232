#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <getopt.h>
#include <infixToPostfix.h>

using namespace std;

int main(int argc, char* argv[]) {
  int opt;
  
  string formula;
  string valoracao;

  bool ehAvaliacao = false;
  bool ehSatisfabilidade = false;

  InfixToPostfix conversao;
  string posfixa;

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

  return 0;
}