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
  string resultadoAvaliacao;

  Satisfabilidade satisfabilidade;
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
        cout << "OPCAO INVALIDA!";
        break;
    }
  }


  //TODO: validar tamanho
  formula = argv[2];

  //TODO: validar tamanho
  valoracao = argv[3];

  if (ehAvaliacao) {
    resultadoAvaliacao = avaliacao.Avaliar(formula, valoracao);

    cout << resultadoAvaliacao << endl;
  }
  

  if (ehSatisfabilidade) {
    resultadoSatisfabilidade = satisfabilidade.CriaArvore(formula, valoracao);

    if (resultadoSatisfabilidade == "0") {
      cout << resultadoSatisfabilidade << endl; 
    } else {
      cout << "1 " << resultadoSatisfabilidade << endl;
    }
  }

  return 0;
}