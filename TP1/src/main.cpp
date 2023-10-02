#include <iostream>
#include <sstream>
#include <string>

#include <getopt.h>

#include <avaliacao.h>

using namespace std;

int main(int argc, char* argv[]) {
  int opt;
  
  string formula;
  string valoracao;

  bool ehAvaliacao = false;
  bool ehSatisfabilidade = false;

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
        cout << "OPCAO INVALIDA!";
        break;
    }
  }

  formula = argv[2];
  //TODO: validar tamanho
  valoracao = argv[3];
  //TODO: validar tamanho

  resultadoAvaliacao = avaliacao.Avaliar(formula, valoracao);

  cout << resultadoAvaliacao << endl;

  return 0;
}