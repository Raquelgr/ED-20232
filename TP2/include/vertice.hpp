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

#endif