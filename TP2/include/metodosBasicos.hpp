#ifndef METODOS_BASICOS_HPP
#define METODOS_BASICOS_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <iostream>
#include <sstream>
#include <string>

#include <vertice.hpp>

using namespace std;

void TrocaPosicao(Vertice* a, Vertice* b);
bool NecessitaTroca(Vertice a, Vertice b);

void BubbleSort(Vertice *vertices, int tamanho);
void SelectionSort(Vertice *vertices, int tamanho);
void InserctionSort(Vertice *vertices, int tamanho);

#endif