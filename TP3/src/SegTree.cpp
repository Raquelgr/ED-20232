#include <SegTree.hpp>

SegTree::SegTree(int n) {
    tamanho = n;
    int tamanhoMaximo = 4 * n;
    arvore = new Matriz[tamanhoMaximo];

    for (int i = 0; i < tamanhoMaximo; i++) {
        arvore[i].m[0][0] = arvore[i].m[1][1] = 1;
        arvore[i].m[0][1] = arvore[i].m[1][0] = 0;
    }
}

SegTree::~SegTree() {
    delete[] arvore;
}

Matriz SegTree::MultiplicaMatrizes(Matriz a, Matriz b) {
    Matriz resultado;

    //O tamanho da matriz é sempre 2x2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultado.m[i][j] = 0; //Inicializa com 0 para evitar lixo de memória 
            for (int k = 0; k < 2; k++) {
                resultado.m[i][j] += (a.m[i][k] * b.m[k][j]) % 100000000;
            }
        }
    }

    return resultado;
}

void SegTree::Atualiza(int posicaoDeAtualizacao, Matriz matrizDeAtualizacao) {
    AtualizaArvore(0, 0, tamanho - 1, posicaoDeAtualizacao, matrizDeAtualizacao);
}

void SegTree::AtualizaArvore(int pos, int intervaloEsq, int intervaloDir, int posicaoDeAtualizacao, Matriz matrizDeAtualizacao) {
    if (intervaloEsq == intervaloDir) { // Significa que o intervalo era exatamente o de uma posição apenas
        arvore[pos] = matrizDeAtualizacao;
    } else {
        int novaPosicao = (intervaloEsq + intervaloDir) / 2;
        
        //Chama recursivamente para ir buscando os intervalos 
        if (posicaoDeAtualizacao <= novaPosicao) {
            AtualizaArvore(2 * pos, intervaloEsq, novaPosicao, posicaoDeAtualizacao, matrizDeAtualizacao); // Nós à esquerda
        } else {
            AtualizaArvore(2 * pos + 1, novaPosicao + 1, intervaloDir, posicaoDeAtualizacao, matrizDeAtualizacao); // Nós à direita
        }

        arvore[pos] = MultiplicaMatrizes(arvore[2 * pos], arvore[2 * pos + 1]);
    }
}

Matriz SegTree::Consulta(int nascimento, int morte) {
    Matriz matrizDoIntervalo = BuscaIntervalo(0, nascimento, morte, 0, tamanho - 1);
    return matrizDoIntervalo;
}

Matriz SegTree::BuscaIntervalo(int pos, int intervaloEsq, int intervaloDir, int intervaloInicio, int intervaloFim) {
    if (intervaloInicio > intervaloDir || intervaloFim < intervaloEsq) { // Não achou, identidade
        Matriz identidade;
        identidade.m[0][0] = identidade.m[1][1] = 1;
        identidade.m[0][1] = identidade.m[1][0] = 0;
        return identidade;
    } else if (intervaloInicio >= intervaloEsq && intervaloFim <= intervaloDir) { //Acha nó exato
        return arvore[pos];
    } else {
        int novaPosicao = (intervaloInicio + intervaloFim) / 2;

        Matriz noEsquerda = BuscaIntervalo(2 * pos, intervaloEsq, intervaloDir, intervaloInicio, novaPosicao);
        Matriz noDireita = BuscaIntervalo(2 * pos + 1, intervaloEsq, intervaloDir, novaPosicao + 1, intervaloFim);

        Matriz resultado;

        if (intervaloInicio <= novaPosicao && intervaloFim >= novaPosicao + 1) {
            resultado = MultiplicaMatrizes(noEsquerda, noDireita);
        } else if (intervaloInicio <= novaPosicao) {
            resultado = noEsquerda;
        } else {
            resultado = noDireita;
        }
        
        return resultado;
    }    
}