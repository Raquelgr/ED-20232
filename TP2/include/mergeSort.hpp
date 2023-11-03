#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <vertice.hpp>

using namespace std;

bool ElementoMenor(Vertice a, Vertice b);

void Merge(Vertice* vertices, int inicio, int meio, int fim);
void Ordena(Vertice *vertices, int inicio, int fim);
void MergeSort(Vertice *vertices, int tamanho); 

#endif