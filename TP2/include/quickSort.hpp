#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <vertice.hpp>

using namespace std;

bool ElementoMaiorQuePivo(Vertice a, Vertice b);
bool ElementoMenorQuePivo(Vertice a, Vertice b);

void Particao(int esq, int dir, int *i, int *j, Vertice *a); 
void Ordena(int esq, int dir, Vertice *vertices); 
void QuickSort(Vertice *vertices, int tamanho); 

#endif