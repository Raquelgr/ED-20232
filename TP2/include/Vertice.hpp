#ifndef VERTICE_HPP
#define VERTICE_HPP

class Vertice {
    private:
        int qtdVizinhos;
        int* vizinhos;

    public: 
        Vertice();
        int rotulo;
        int cor;
        
    friend class Grafo;
};

void Troca(Vertice* a, Vertice* b);
bool EhMenor(Vertice a, Vertice b);
bool EhMaior(Vertice a, Vertice b);

#endif