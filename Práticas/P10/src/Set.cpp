#include "Set.hpp"

StringSet::StringSet(int tamanho) {
    tamanhoOriginal = tamanho;
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

void StringSet::Resize(size_t novoTamanho) {
    if (novoTamanho <= tamanhoTabela) {
        return;
    }

    ElementoTabela* novaTabela = new ElementoTabela[novoTamanho];
    for (size_t i = 0; i < novoTamanho; i++) {
        novaTabela[i].vazio = true;
        novaTabela[i].retirada = false;
    }

    for (size_t i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            size_t novaPos = Hash(tabela[i].dado);
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
        // Rehash para evitar colisões
        Rehash(Hash(s));
    }

    int pos = Hash(s);
    while (!tabela[pos].vazio && tabela[pos].dado != s) {
        pos = (pos + 1) % tamanhoTabela;
    }

    if (tabela[pos].vazio || tabela[pos].retirada) {
        tabela[pos].dado = s;
        tabela[pos].vazio = false;
        tabela[pos].retirada = false;
        tamanhoConjunto++;
    }
}

void StringSet::Remover(string s) {
    int pos = Hash(s);
    while (!tabela[pos].vazio) {
        if (!tabela[pos].retirada && tabela[pos].dado == s) {
            tabela[pos].retirada = true;
            tamanhoConjunto--;
            return;
        }
        pos = (pos + 1) % tamanhoTabela;
    }
}

bool StringSet::Pertence(string s) {
    int pos = Hash(s);
    while (!tabela[pos].vazio) {
        if (!tabela[pos].retirada && tabela[pos].dado == s) {
            return true;
        }
        pos = (pos + 1) % tamanhoTabela;
    }
    return false;
}

StringSet* StringSet::Intersecao(StringSet* S) {
    StringSet* resultado = new StringSet(1);

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada && S->Pertence(tabela[i].dado)) {
            resultado->Inserir(tabela[i].dado);
        }
    }

    return resultado;
}

StringSet* StringSet::Uniao(StringSet* S) {
    StringSet* resultado = new StringSet(1);

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            resultado->Inserir(tabela[i].dado);
        }
    }

    for (int i = 0; i < S->tamanhoTabela; i++) {
        if (!S->tabela[i].vazio && !S->tabela[i].retirada) {
            resultado->Inserir(S->tabela[i].dado);
        }
    }

    return resultado;
}

StringSet* StringSet::DiferencaSimetrica(StringSet* S) {
    StringSet* resultado = new StringSet(1);

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada && !S->Pertence(tabela[i].dado)) {
            resultado->Inserir(tabela[i].dado);
        }
    }

    for (int i = 0; i < S->tamanhoTabela; i++) {
        if (!S->tabela[i].vazio && !S->tabela[i].retirada && !Pertence(S->tabela[i].dado)) {
            resultado->Inserir(S->tabela[i].dado);
        }
    }

    return resultado;
}

void StringSet::Imprimir() {
    if (tamanhoConjunto == 0) {
        cout << "{ }" << endl;
        return;
    }

    cout << "{ ";
    int elementosImpressos = 0;
    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            cout << tabela[i].dado;
            elementosImpressos++;

            if (elementosImpressos < tamanhoConjunto) {
                cout << ", ";
            }
        }
    }
    cout << " }" << endl;
}