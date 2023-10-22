#include <iostream>
#include <sstream>
#include <string>

#include <unionFind.hpp>
#include <heap.hpp>

using namespace std;

int main(int argc, char* argv[]) {
    int vertices = 0;
    int arestas = 0;
    cin >> vertices >> arestas;

    Heap heap(vertices * vertices);
    UnionFind uniao(vertices);

    for (int i = 0; i < arestas; i++) {
        int u, v, custo;
        cin >> u >> v >> custo;

        Aresta aux;
        aux.u = u;
        aux.v = v;
        aux.custo = custo;

        heap.Inserir(aux);
    }    

    int tamanho = 0;
    int resultado = 0;

    while (tamanho < vertices - 1) { 
        Aresta aresta = heap.Remover();
        int representanteU = uniao.Find(aresta.u);
        int representanteV = uniao.Find(aresta.v);
        
        if (representanteU != representanteV) { 
            resultado += aresta.custo;
            uniao.Union(representanteU, representanteV);
            tamanho++;
        }
    }

    cout << resultado << endl;
    
    return 0;
}