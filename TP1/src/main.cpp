#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <getopt.h>

// #include <caixas_de_entrada.h>

using namespace std;

int main(int argc, char* argv[]) {
  int opt;
  
  string formula;
  string valoracao;

  bool ehAvaliacao = false;
  bool ehSatisfabilidade = false;

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

  cout << "Avaliacao" << ehAvaliacao << endl;
  cout << "Satisf" << ehSatisfabilidade << endl;
  cout << "Formula" << formula << endl;
  cout << "Valoracao" << valoracao << endl;

  return 0;
}