#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <vertice.hpp>

using namespace std;

bool ComparaMenor(Vertice a, Vertice b);
bool ComparaMenor(Vertice a, Vertice b);

void Refaz(Vertice* vertices, int esq, int dir);
void Constroi(Vertice *vertices, int tamanho);
void HeapSort(Vertice *vertices, int tamanho); 

#endif