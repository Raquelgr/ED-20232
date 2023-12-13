#include <iostream>
#include <sstream>
#include <string>

#include <Avl.hpp>

using namespace std;

int main(int argc, char * argv[]) {
  AVLTree avl;

  int operacoes;
  cin >> operacoes;
  
  for (int i = 0; i < operacoes; i++) {
    char operacao;
    int chave;

    cin >> operacao >> chave;

    if (operacao == 'i') {
      avl.Inserir(chave);
    } else if (operacao == 'r') {
      avl.Remover(chave);
    }
  }

  avl.PreOrdem();
  avl.InOrdem();
  avl.PosOrdem();

  return 0;
}
