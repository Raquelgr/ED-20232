#include <iostream>

#include <SegTree.hpp>

using namespace std;

int main(int argc, char* argv[]) try {
	int instantesDeTempo = 0;
	int operacoesRealizadas = 0;

	cin >> instantesDeTempo >> operacoesRealizadas;
  
    SegTree* arvoreDeSegmentacao = new SegTree(instantesDeTempo);

    for (int i = 0; i < operacoesRealizadas; i++) {
        char operacao;
        cin >> operacao;

        if (operacao == 'u') {
            int instante = 0;
            cin >> instante;

            int p1, p2, p3, p4;
            cin >> p1 >> p2 >> p3 >> p4;

            Matriz matrizDeAtualizacao;
            matrizDeAtualizacao.m[0][0] = p1;
            matrizDeAtualizacao.m[0][1] = p2;
            matrizDeAtualizacao.m[1][0] = p3;
            matrizDeAtualizacao.m[1][1] = p4;

            arvoreDeSegmentacao->Atualiza(instante, matrizDeAtualizacao);
        } else if (operacao == 'q') {
            int nascimento, morte;
            int x, y;

            cin >> nascimento >> morte >> x >> y;

            // Verifica se os instante de nascimento e morte são válidos
            if (nascimento > morte) {
                throw std::invalid_argument("O instante de nascimento deve ser menor que o instante de morte!");
            }

            Matriz matrizDoIntervalo = arvoreDeSegmentacao->Consulta(nascimento, morte);

            long long morteX = 0;
            long long morteY = 0;

            // Mod 100000000 para salvar apenas os 8 dígitos menos significativos 
            morteX = (matrizDoIntervalo.m[0][0] * x + matrizDoIntervalo.m[0][1] * y) % 100000000; //Transformação linear no ponto X
            morteY = (matrizDoIntervalo.m[1][0] * x + matrizDoIntervalo.m[1][1] * y) % 100000000; //Transformação linear no ponto Y
            
            cout << morteX << " " << morteY << endl;
        }
    }

    delete arvoreDeSegmentacao;

    return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}