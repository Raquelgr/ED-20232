#include <SegTree.hpp>

SegTree::SegTree(int n) {
    tamanho = n;
    int tamanhoMaximo = 4 * n;
    arvore = new Matriz[tamanhoMaximo];

    for (int i = 0; i < tamanhoMaximo; i++) { // Inicialmente, todas as matrizes são identidades
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
            long long produto = 0; // Inicializa com 0 para evitar lixo de memória 
            for (int k = 0; k < 2; k++) {
                produto += a.m[i][k] * b.m[k][j];
            }

            resultado.m[i][j] = produto % 100000000; // Salva apenas os 8 dígitos menos significativos
        }
    }
    
    return resultado;
}

void SegTree::Atualiza(int posicaoDeAtualizacao, Matriz matrizDeAtualizacao) {
    // Verifica se a posição de atualização é válida
    if (posicaoDeAtualizacao < 0 || posicaoDeAtualizacao >= tamanho) {
        throw std::invalid_argument("Posição de atualização inválida!");
    }
    
    AtualizaArvore(1, 0, tamanho - 1, posicaoDeAtualizacao, matrizDeAtualizacao);
}

void SegTree::AtualizaArvore(int pos, int intervaloEsq, int intervaloDir, int posicaoDeAtualizacao, Matriz matrizDeAtualizacao) {
    if (intervaloEsq == intervaloDir) { // O intervalo é exatamente uma posição
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
    // Verifica se os instantes não estão fora dos limites da árvore
    if (nascimento < 0 || nascimento >= tamanho || morte < 0 || morte >= tamanho) {
        throw std::invalid_argument("Instante fora dos limites da árvore!");
    }

    Matriz matrizDoIntervalo = BuscaIntervalo(1, nascimento, morte, 0, tamanho - 1);
    return matrizDoIntervalo;
}

Matriz SegTree::BuscaIntervalo(int pos, int intervaloEsq, int intervaloDir, int intervaloInicio, int intervaloFim) {
    if (intervaloInicio > intervaloDir || intervaloFim < intervaloEsq) { // Se o intervalo [intervaloEsq, intervaloDir] está completamente fora do intervalo [intervaloInicio, intervaloFim]
        Matriz identidade;
        identidade.m[0][0] = identidade.m[1][1] = 1;
        identidade.m[0][1] = identidade.m[1][0] = 0;
        return identidade;
    } else if (intervaloInicio >= intervaloEsq && intervaloFim <= intervaloDir) { // Se o intervalo [intervaloInicio, intervaloFim] está completamente dentro do intervalo [intervaloEsq, intervaloDir]
        return arvore[pos];
    } else {
        int novaPosicao = (intervaloInicio + intervaloFim) / 2;

        Matriz noEsquerda = BuscaIntervalo(2 * pos, intervaloEsq, intervaloDir, intervaloInicio, novaPosicao);
        Matriz noDireita = BuscaIntervalo(2 * pos + 1, intervaloEsq, intervaloDir, novaPosicao + 1, intervaloFim);

        Matriz resultado;

        // Combina as matrizes dos nós esquerdo e direito, dependendo de como o intervalo [intervaloInicio, intervaloFim] se sobrepõe aos intervalos dos nós
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