#include <listaAdjacencia.hpp>

TipoCelula::TipoCelula() {
    prox = NULL;
}

ListaEncadeada::ListaEncadeada() {
    tamanho = 0;
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada() {
    Limpa();
    delete primeiro;
}

void ListaEncadeada::Insere(int item) {
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;

    tamanho++;
}

void ListaEncadeada::Imprime() {
    TipoCelula *p;

    p = primeiro->prox;

    while (p != NULL) {
        cout << p->item << " ";
        p = p->prox;
    }

    cout << endl;
}

void ListaEncadeada::Limpa() {
    TipoCelula *p;

    p = primeiro->prox;

    while (p != NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }

    ultimo = primeiro;
}

int ListaEncadeada::Tamanho() {
    return tamanho;
}

/**/

ListaAdjacencia::ListaAdjacencia() {
    tamanho = 0;
    primeiro = new ListaEncadeada();
    ultimo = primeiro;
}

ListaAdjacencia::~ListaAdjacencia() {
    Limpa();
    delete primeiro;
}

void ListaAdjacencia::AdicionarVertice() {
    ListaEncadeada *nova;

    nova = new ListaEncadeada();
    ultimo->prox = nova;
    ultimo = nova;

    tamanho++;
}

ListaEncadeada* ListaAdjacencia::Posiciona(int pos){
    ListaEncadeada *p;
    p = primeiro;

    for (int i = 0; i < pos; i++) {
        p = p->prox;
    }
   
    return p;
}

void ListaAdjacencia::AdicionarAresta(int v, int w) {
    ListaEncadeada *l;
    l = Posiciona(v);

    l->Insere(w);
}

void ListaAdjacencia::ImprimirVizinhos(int v) {
    ListaEncadeada *l;
    l = Posiciona(v);

    l->Imprime();
}

void ListaAdjacencia::Limpa() {
    ListaEncadeada *p;

    p = primeiro->prox;

    while (p != NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }

    ultimo = primeiro;
}

int ListaAdjacencia::Tamanho() {
    return tamanho;
}

int ListaAdjacencia::QuantidadeCelulas(int v) {
    ListaEncadeada *l;
    l = Posiciona(v);

    return l->Tamanho();
}