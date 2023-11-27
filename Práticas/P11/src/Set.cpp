#include <Set.hpp>

StringSet::StringSet(int tamanho) {
    tamanhoTabela = 2 * tamanho;
    tamanhoConjunto = 0;
    tabela = new ElementoTabela[tamanhoTabela];
    
    for (int i = 0; i < tamanhoTabela; i++) {
        tabela[i].vazio = true;
        tabela[i].retirada = false;
    }
}

StringSet::~StringSet() {
    delete[] tabela;
}

int StringSet::Hash(string s) {
    int hash = 0;

    for (char c : s) {
        hash = (hash * 31 + c) % tamanhoTabela;
    }

    hash = (hash * 31 + s.length()) % tamanhoTabela;

    return hash;
}

void StringSet::Rehash(int pos) {
    int novoTamanho = tamanhoTabela * 2;
    ElementoTabela* novaTabela = new ElementoTabela[novoTamanho];

    for (int i = 0; i < novoTamanho; i++) {
        novaTabela[i].vazio = true;
        novaTabela[i].retirada = false;
    }

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            int novaPos = Hash(tabela[i].dado);
            while (!novaTabela[novaPos].vazio) {
                novaPos = (novaPos + 1) % novoTamanho;
            }
            novaTabela[novaPos] = tabela[i];
        }
    }

    delete[] tabela;
    tabela = novaTabela;
    tamanhoTabela = novoTamanho;
}

void StringSet::Inserir(string s) {
    if (tamanhoConjunto >= tamanhoTabela / 2) {
        Rehash(Hash(s));
    }

    int pos = Hash(s);
    while (!tabela[pos].vazio && tabela[pos].dado != s) {
        pos = (pos + 1) % tamanhoTabela;
    }

    bool existe = false;

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && tabela[i].dado == s) {
            existe = true;
            break;
        }
    }

    if (!existe) {
        tabela[pos].dado = s;
        tabela[pos].vazio = false;
        tabela[pos].retirada = false;
        tamanhoConjunto++;
    }
}

void BubbleSort(string *palavras, int tamanho) {
    string aux;
    bool trocou;
    
    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false;

        for (int j = 1; j < tamanho - i; j++) {
            string p1 = palavras[j];
            string p2 = palavras[j-1];
            if (stoi(p1) < stoi(p2)) {

                aux = palavras[j-1];
                palavras[j-1] = palavras[j];
                palavras[j] = aux;

                trocou = true;
            }
        }

        if (!trocou) break;
    }
}

void StringSet::Imprimir() {
    string* entradas = new string[tamanhoTabela];
    int cont = 0;

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            entradas[cont++] = tabela[i].dado;
        }
    }

    BubbleSort(entradas, cont);

    for (int i = 0; i < cont; i++) {
        cout << entradas[i] << " ";
    }

    cout << endl;
}