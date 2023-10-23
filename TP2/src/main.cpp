#include <iostream>
#include <sstream>
#include <string>

#include <getopt.h>

using namespace std;

 
int main(int argc, char* argv[]) try {
  int opt;

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

  return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}