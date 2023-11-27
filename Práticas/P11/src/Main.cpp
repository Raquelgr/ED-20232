#include <iostream>
#include <sstream>
#include <string>

#include <Avl.hpp>

using namespace std;

int main(int argc, char * argv[]) {
  AVLTree avl;

  string palavra;
  int pagina;

  while (cin >> palavra >> pagina) {
    avl.Inserir(palavra, pagina);
  }

  avl.Imprimir();

  return 0;
}
