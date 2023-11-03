#ifndef METODOS_CONHECIDOS_HPP
#define METODOS_CONHECIDOS_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <grafo.hpp>

using namespace std;

void TrocaPosicao(Vertice* a, Vertice* b);
bool NecessitaTroca(Vertice a, Vertice b);

void BubbleSort(Vertice *vertices, int tamanho);
void SelectionSort(Vertice *vertices, int tamanho);
void InserctionSort(Vertice *vertices, int tamanho);

#endif