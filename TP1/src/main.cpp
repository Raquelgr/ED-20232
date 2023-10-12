#include <iostream>
#include <sstream>
#include <string>

#include <getopt.h>

#include <avaliacao.hpp>
#include <satisfabilidade.hpp>

using namespace std;

int main(int argc, char* argv[]) {
  int opt;
  
  string formula;
  string valoracao;

  bool ehAvaliacao = false;
  bool ehSatisfabilidade = false;

  Avaliacao avaliacao;
  char resultadoAvaliacao;

  Satisfabilidade satisfabilidade;
  //char resultadoAvaliacao;

  cout << "oi";

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

    cout << "oi";


  //TODO: validar tamanho
  formula = argv[2];

  //TODO: validar tamanho
  valoracao = argv[3];
  cout << "oi";
  if (ehAvaliacao) {
    resultadoAvaliacao = avaliacao.Avaliar(formula, valoracao);
  cout << "oi1";

    cout << resultadoAvaliacao << endl;
  }
  

  if (ehSatisfabilidade) {
      cout << "oi2";

    satisfabilidade.CriaArvore(formula, valoracao);
  }

  return 0;
}