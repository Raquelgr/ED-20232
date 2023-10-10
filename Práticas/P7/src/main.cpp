#include <iostream>
#include <sstream>
#include <string>

#include <heap.hpp>

using namespace std;

int main(int argc, char* argv[]) {
    int tamanho = 0;
    cin >> tamanho;

    Heap heap(tamanho);

    for (int i = 0; i < tamanho; i++) {
        int num = 0;
        cin >> num;

        heap.Inserir(num);
    }    

    while (!heap.Vazio()) {
        cout << heap.Remover() << " ";
    }

    cout << endl;

    return 0;
}